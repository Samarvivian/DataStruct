#define OK 1
#define ERROR 0
#define _CRT_SECURE_NO_WARNINGS 1
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct {
	int weight;
	int parent, lchild, rchild;
	char value;
} HTNode, * HuffmanTree;
 
typedef char** HuffmanCode;
 
int m;//赫夫曼树节点数
 
void Select(HuffmanTree HT, int n, int& s1, int& s2) {
	int min = n;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent != 0) continue;
		else {
			if (HT[i].weight <= HT[min].weight) min = i;
		}
	}
	s1 = min; min = 1;
	while (HT[min].parent != 0 || min == s1) min++;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent != 0||i==s1) continue;
		else {
			if (HT[i].weight <= HT[min].weight) min = i;
		}
	}
	s2 = min;
}
 
void HuffmanCoding(HuffmanTree& HT, HuffmanCode& HC, int* w, int n,char *c) {
	FILE* fp1, * fp2;
	int f,i;
	fp1 = fopen("HfmTree.txt", "w+");
	fp2 = fopen("CodeFile.txt", "w+");
	HuffmanTree p;
	if (n <= 1) return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元未用
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w,++c) *p = { *w,0,0,0,*c };
	for (; i <= m; ++i, ++p) *p = { 0,0,0,0,'0' };
	for (i = n + 1; i <= m; ++i) {//建赫夫曼树
	//在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1，s2
		int s1, s2;
		Select(HT, i - 1, s1, s2);
		//printf("%d\t%d\t%d\t%d\n", HT[s1].weight, HT[s2].weight,s1,s2);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for (int i = 1; i <= m; i++) {
		fprintf(fp1, "%d  %c\t\t%d\t%d\t%d\t%d\n",i,HT[i].value, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	fclose(fp1);
	//从叶子到根逆向求每个字符的赫夫曼编码
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针向量
	char* cd = (char*)malloc(n * sizeof(char));//分配求编码的工作空间
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) {
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	for (int i = 1; i <= n ; i++)
	{
		 fprintf(fp2,"%c\t\t\t",HT[i].value);fputs(HC[i], fp2); fprintf(fp2, "\n");
	}
	fclose(fp2);
}
 
void Encrypt(HuffmanTree HT,HuffmanCode HC)
{
	char a[40],c,mood;
	FILE* fp2, * fp4;
	if ((fp2 = fopen("ToBeTran.txt", "w+")) == NULL) {
		printf("无法打开待加密的文件！\n");
 
	}
	else {
		printf("请输入待加密的内容(以'#'结束)：\n");
		rewind(stdin);
		mood = getchar();
		while (mood != '#')
		{	
			
			fprintf(fp2, "%c", mood);
			mood = getchar();
		}
		rewind(fp2);
		fgets(a, 30, fp2);
		if ((fp4 = fopen("Result.txt", "w+")) == NULL) printf("无法打开加密结果文件！\n");
		else {
			for (int i = 0; a[i] != '\0'; i++) {
				for (int j = 1; j <= 27; j++)
				{
					if (a[i] == HT[j].value) fputs(HC[j], fp4);
				}
				
			}
			rewind(fp2);
			printf("待加密文件的内容：\n");
			c = fgetc(fp2);
			while (c != EOF)
			{
				putchar(c);
				c = fgetc(fp2);
			}
			
		}
		printf("\n加密的结果：\n");
		rewind(fp4);
		c = fgetc(fp4);
		while (c != EOF)
		{
			putchar(c);
			c = fgetc(fp4);
		}
		fclose(fp4);
	}
	fclose(fp2);
}
 
void Translate(HuffmanTree HT)
{
	FILE* fp1,*fp2;
	char c;
	int i=m;
	if ((fp1 = fopen("Result.txt", "r")) == NULL) printf("无法打开待翻译文件！\n");
	if ((fp2 = fopen("TextFile.txt", "w+")) == NULL) printf("无法打翻译结果文件！\n");
	else
	{
		printf("待翻译文件的内容：\n");
		c = fgetc(fp1);
		while (c != EOF)
		{
			putchar(c);
			c = fgetc(fp1);
		}
		rewind(fp1);
		c = fgetc(fp1);
		 while (c != EOF)
		{
			if (HT[i].value != '0')
			{
				fputc(HT[i].value, fp2);
				i = m;
			}
			else
				{
					if (c == '0')	i = HT[i].lchild;
					else if (c == '1') i = HT[i].rchild;c = fgetc(fp1);
			}
			 //printf("%d\t", i);
		}
		 fputc(HT[i].value, fp2);
	}
	printf("\n翻译结果：\n");
	rewind(fp2);
	c = fgetc(fp2);
	while (c != EOF)
	{
		putchar(c);
		c = fgetc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
 
int Interface(){
	printf("\t\t\t\n\n\n请选择要进行的操作：\n");
	printf("\t\t\t\t\n1.加密文档\n\n2.文档解密\n\n3.退出程序\n");
	int ans;
	scanf("%d", &ans);
	return ans;
}
 
int main(){
	FILE *fp1,*fp3;
	HuffmanTree HT;
	HuffmanCode HC;
	char ciphercode[30];
	int w[30];
	
	printf("使用说明：\n\n1.待加密内容由大写字母和空格组成！\
			\n2.待加密的内容存放在ToBeTran.txt文件中\
			\n3.加密后的内容存放在Result.txt文件中!\
			\n4.翻译后的内容存放在TextFile.txt文件中!\n");
 
 
	if ((fp1 = fopen("FreqData.txt", "r")) == NULL) printf("无法打开频度数据文件！\n");
	else if ((fp3 = fopen("CharSet.txt", "r")) == NULL) printf("无法打开字符集文件！\n");
	else {
		for (int i = 0; i < 27; i++)
		{
			fscanf(fp1, "%d", &w[i]);
			fscanf(fp3, "%C", &ciphercode[i]);
		}
		HuffmanCoding(HT, HC, w, 27,ciphercode);//for (int i = 0; i < 27; i++) printf("%d\t", w[i]);
		
	
		do {
			int temp = Interface();
			switch (temp)
				{
				
				case 1:Encrypt(HT, HC); break;
				case 2:Translate(HT); break;
				case 3:exit(0);
				default: printf("该选项不存在！请重新选择：\n"); 
				};
		} while (1);
	
		
	}	
	return 0;
}