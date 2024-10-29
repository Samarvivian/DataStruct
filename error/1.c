#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, * BiTree;

// ��������
int CreateBiTree(BiTree* T);
int PrintElement(TElemType e);
int InOrderTraverse(BiTree T, int(*Visit)(TElemType e));
void SwapChildren(BiTree T);

int main() {
    BiTree T = NULL;

    printf("��������������Ķ������ڵ㣨�ÿո��ʾ�սڵ㣩��\n");
    CreateBiTree(&T);

    printf("��������������������������Ϊ��\n");
    SwapChildren(T);
    InOrderTraverse(T, PrintElement);

    return 0;
}

// ����������
int CreateBiTree(BiTree* T) {
    TElemType ch=0;
    scanf("%c", &ch); // ��ȡ�ַ��ͽڵ�ֵ��ǰ��ӿո������հ��ַ�
    if (ch == ' ') {
        *T = NULL; // �ո��ַ���ʾ����
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T) exit(OVERFLOW);
        (*T)->data = ch; // ���ɸ��ڵ�
        CreateBiTree(&((*T)->lchild)); // ����������
        CreateBiTree(&((*T)->rchild)); // ����������
    }
    return OK;
}

// ���ʽڵ�ĺ���
int PrintElement(TElemType e) {
    printf("%c ", e);
    return OK;
}

// �������������
int InOrderTraverse(BiTree T, int(*Visit)(TElemType e)) {
    if (T) {
        InOrderTraverse(T->lchild, Visit); // �������������
        Visit(T->data); // ���ʸ��ڵ�
        InOrderTraverse(T->rchild, Visit); // �������������
    }
    return OK;
}

// ��������������������
void SwapChildren(BiTree T) {
    if (T) {
        // ������������
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;

        // �ݹ齻����������
        SwapChildren(T->lchild);
        SwapChildren(T->rchild);
    }
}

