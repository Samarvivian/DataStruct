#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct {
    char data;  // 字符
    int count;  // 字符的出现频率（权重）
} Alphabet;

typedef struct {
    int weight;  // 表示权重
    char info;   // 表示对应字母
    int lchild;  // 左孩子
    int rchild;  // 右孩子
} TreeNode, *HuffmanTree;

typedef struct {
    HuffmanTree tree;
    int len;  // 原始字符数量
} HFTree;

// 函数声明
Status fileread(Alphabet *a, int *n);
HFTree* HuffmanTreeInit(Alphabet *a, int n);
Status createHFTree(HFTree *T);
void saveHuffmanTreeToFile(HFTree *T, const char *filename);
HFTree* loadHuffmanTreeFromFile(const char *filename);
void generateHuffmanCode(HFTree *T, int index, char *code, int codeLength, char *codes[MAX_CHAR]);
void encodeFile(const char *inputFilename, const char *outputFilename, HFTree *T);
void decodeFile(const char *inputFilename, const char *outputFilename, HFTree *T);

// 从终端读入字符集大小n，以及n个字符和n个权值
Status fileread(Alphabet *a, int *n) {
    printf("请输入字符集的大小n: ");
    scanf("%d", n);
    getchar(); // 清除缓冲区的换行符
    printf("请输入这n个字符，以及它们对应的权值:\n");
    for (int i = 0; i < *n; i++) {
        printf("字符: ");
        scanf(" %c", &a[i].data);
        printf("权值: ");
        scanf("%d", &a[i].count);
    }
    return OK;
}

// 初始化哈夫曼树
HFTree* HuffmanTreeInit(Alphabet *a, int n) {
    HFTree *T = (HFTree *)malloc(sizeof(HFTree));
    T->tree = (HuffmanTree)malloc((2 * n - 1) * sizeof(TreeNode));
    T->len = n;
    for (int i = 0; i < n; i++) {
        T->tree[i].weight = a[i].count;
        T->tree[i].info = a[i].data;
        T->tree[i].lchild = -1;
        T->tree[i].rchild = -1;
    }
    return T;
}

// 建立哈夫曼树
Status createHFTree(HFTree *T) {
    int n = T->len;
    for (int i = n; i < 2 * n - 1; i++) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < i; j++) {
            if (T->tree[j].lchild == -1) {
                if (min1 == -1) {
                    min1 = j;
                } else if (T->tree[j].weight < T->tree[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || T->tree[j].weight < T->tree[min2].weight) {
                    min2 = j;
                }
            }
        }
        T->tree[i].weight = T->tree[min1].weight + T->tree[min2].weight;
        T->tree[i].lchild = min1;
        T->tree[i].rchild = min2;
        T->tree[min1].lchild = T->tree[min2].lchild = i;
    }
    return OK;
}

// 将哈夫曼树保存到文件
void saveHuffmanTreeToFile(HFTree *T, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for saving Huffman tree");
        exit(-1);
    }
    fwrite(&T->len, sizeof(int), 1, file);
    fwrite(T->tree, sizeof(TreeNode), T->len * 2 - 1, file);
    fclose(file);
}

// 从文件读取哈夫曼树
HFTree* loadHuffmanTreeFromFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for loading Huffman tree");
        exit(-1);
    }
    HFTree *T = (HFTree *)malloc(sizeof(HFTree));
    fread(&T->len, sizeof(int), 1, file);
    T->tree = (HuffmanTree)malloc((T->len * 2 - 1) * sizeof(TreeNode));
    fread(T->tree, sizeof(TreeNode), T->len * 2 - 1, file);
    fclose(file);
    return T;
}

// 生成哈夫曼编码
void generateHuffmanCode(HFTree *T, int index, char *code, int codeLength, char *codes[MAX_CHAR]) {
    if (index == -1) return;
    if (T->tree[index].lchild == -1 && T->tree[index].rchild == -1) {
        codes[T->tree[index].info] = (char *)malloc(codeLength + 1);
        strcpy(codes[T->tree[index].info], code);
        return;
    }
    code[codeLength] = '0';
    generateHuffmanCode(T, T->tree[index].lchild, code, codeLength + 1, codes);
    code[codeLength] = '1';
    generateHuffmanCode(T, T->tree[index].rchild, code, codeLength + 1, codes);
}

// 文件编码
void encodeFile(const char *inputFilename, const char *outputFilename, HFTree *T) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    char codes[MAX_CHAR][MAX_CHAR];
    char code[MAX_CHAR];
    code[0] = '\0';
    generateHuffmanCode(T, 2 * T->len - 2, code, 0, codes);
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 0 && ch < MAX_CHAR) {
            fputs(codes[ch], outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
}

// 文件译码
void decodeFile(const char *inputFilename, const char *outputFilename, HFTree *T) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    char codes[MAX_CHAR][MAX_CHAR];
    char code[MAX_CHAR];
    code[0] = '\0';
    generateHuffmanCode(T, 2 * T->len - 2, code, 0, codes);
    int index = 2 * T->len - 2;
    while (!feof(inputFile)) {
        char bit;
        fscanf(inputFile, "%c", &bit);
        code[strlen(code) + 1] = '\0';
        code[strlen(code)] = bit;
        if (bit == '0') {
            index = T->tree[index].lchild;
        } else {
            index = T->tree[index].rchild;
        }
        if (T->tree[index].lchild == -1 && T->tree[index].rchild == -1) {
            fputc(T->tree[index].info, outputFile);
            index = 2 * T->len - 2;
        }
    }
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    Alphabet a[MAX_CHAR];
    int n;
    if (fileread(a, &n) != OK) {
        printf("Error reading input.\n");
        return ERROR;
    }
    HFTree *T = HuffmanTreeInit(a, n);
    if (createHFTree(T) != OK) {
        printf("Error creating Huffman tree.\n");
        return ERROR;
    }
    saveHuffmanTreeToFile(T, "hfmTree");

    encodeFile("input.txt", "CodeFile", T);
    decodeFile("CodeFile", "TextFile", T);

    // 释放内存
    free(T->tree);
    free(T);

    return OK;
}