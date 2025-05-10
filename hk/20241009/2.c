#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define ok 1
#define error 0
#define MAXSIZE 20

typedef char ElemType1[MAXSIZE];
typedef float ElemType2;
typedef int Status;
typedef struct GradeRecord
{
    char subject[MAXSIZE];//表示科目
    ElemType1 *std;//记录学生名字的数组
    ElemType2 *grade;//记录学生成绩的数组
    int size;//表示目前已经记录成绩的学生个数
    int capacity;//表示能够容纳记录个数的容量
}Grade;

Status GradeInit(Grade *pt)
{
    strncpy(pt->subject, "所要记录的科目",MAXSIZE);
    pt->std=NULL;
    pt->grade=NULL;
    pt->size=pt->capacity=0;
    return ok;
}

Status GradeInsert(Grade *pt,ElemType1 name,ElemType2 e)
{
    assert(pt);
    if(pt->size==pt->capacity)
    {
        int newcapacity=pt->capacity==0?20:pt->capacity*2;
        ElemType1 *temp1=(ElemType1*)realloc(pt->std,sizeof(ElemType1)*newcapacity);
        if(!temp1)
        {
            exit(-1);
        }
        pt->std=temp1;
        ElemType2 *temp2=(ElemType2*)realloc(pt->grade,sizeof(ElemType2)*newcapacity);
        if(!temp2)
        {
            exit(-1);
        }
        pt->grade=temp2;
        pt->capacity=newcapacity;

    }
    strncpy(pt->std[pt->size], name,MAXSIZE);
    pt->grade[pt->size]=e;
    pt->size++;
    return ok;
}

Status GradeDelete(Grade *pt,ElemType1 name)
{
    assert(pt);
    int i=0;
    for(i=0;i<pt->size;i++)
    {
        if(strcmp(pt->std[i],name)==0)
        {
            pt->grade[i]=0;
            return ok;
        }
        
    } 
    perror("The student isn't existing\n");
    return error;
}

void GradePrint(Grade pt)
{
    assert(&pt);
    printf("     %s成绩表\n",pt.subject);
    for(int i=0;i<pt.size;i++)
    {
        printf("%s\t",pt.std[i]);
    }
    printf("\n");
    for(int i=0;i<pt.size;i++)
    {
        printf("%.2f   ",pt.grade[i]);
    }
    printf("\n");
}

Status GradeFind(Grade pt,ElemType1 name)
{
    assert(&pt);
    for(int i=0;i<pt.size;i++)
    {
        if(strcmp(pt.std[i],name)==0)
        {
            printf("The grade of %s is %.2f\n",pt.std[i],pt.grade[i]);
            return ok;
        }
        
    }
    printf("The name isn't existing\n");
    return error;
}

Status GradeChange(Grade *pt,ElemType1 name,ElemType2 newgrade)
{
    assert(pt);
    for(int i=0;i<pt->size;i++)
    {
        if(strcmp(pt->std[i],name)==0)
        {
            pt->grade[i]=newgrade;
            return ok;
        }
    }
    printf("The name isn't existing\n");
    return error;
}

int main()
{
    Grade pt;
    GradeInit(&pt);
    ElemType1 name1="小明";
    ElemType1 name2="小红";
    ElemType1 name3="小明";
    ElemType1 name4="小明";
    GradeInsert(&pt,name1,90);
    GradeInsert(&pt,name2,97);
    GradeInsert(&pt,name3,60);
    GradeInsert(&pt,name4,50);
    

    GradePrint(pt);

    GradeFind(pt,name2);

    GradeChange(&pt,name2,88);
    GradePrint(pt);

    free(pt.std);
    free(pt.grade);

    return 0;

}