#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define ok 1
#define error 0

#define MAX_NAME_LENGTH 50  // 每个名字的最大长度

typedef char ElemType1[MAX_NAME_LENGTH];  // 使用数组来表示字符串
typedef float ElemType2;
typedef int Status;

typedef struct GradeRecord {
    char subject[MAX_NAME_LENGTH];  // 科目名称
    ElemType1 *std;                 // 学生名字的数组
    ElemType2 *grade;               // 学生成绩的数组
    int size;                       // 已记录的学生个数
    int capacity;                   // 容量
} Grade;

Status GradeInit(Grade *pt) {
    strncpy(pt->subject, "所要记录的科目", MAX_NAME_LENGTH);
    pt->std = NULL;
    pt->grade = NULL;
    pt->size = pt->capacity = 0;
    return ok;
}

Status GradeInsert(Grade *pt, ElemType1 name, ElemType2 e) {
    if (pt->size == pt->capacity) {
        int newcapacity = pt->capacity == 0 ? 10 : pt->capacity * 2;

        // 分配新内存并复制旧数据
        ElemType1 *temp1 = (ElemType1 *) realloc(pt->std, sizeof(ElemType1) * newcapacity);
        if (!temp1) {
            exit(-1);
        }
        pt->std = temp1;

        ElemType2 *temp2 = (ElemType2 *) realloc(pt->grade, sizeof(ElemType2) * newcapacity);
        if (!temp2) {
            exit(-1);
        }
        pt->grade = temp2;
        pt->capacity = newcapacity; // 更新容量
    }

    // 复制学生名字
    strncpy(pt->std[pt->size], name, MAX_NAME_LENGTH);
    pt->grade[pt->size] = e;
    pt->size++;
    return ok;
}

Status GradeDelete(Grade *pt, ElemType1 name) {
    assert(pt);
    for (int i = 0; i < pt->size; i++) {
        if (strcmp(pt->std[i], name) == 0) {
            pt->grade[i] = 0; // 将该学生成绩设置为0，实际操作可根据需求修改
            return ok;
        }
    }
    perror("The student isn't existing\n");
    return error;
}

Status GradePrint(Grade pt) {
    printf("     %s成绩表\n", pt.subject);
    for (int i = 0; i < pt.size; i++) {
        printf("%s  ", pt.std[i]);
    }
    printf("\n");
    for (int i = 0; i < pt.size; i++) {
        printf("%.2f   ", pt.grade[i]);
    }
    printf("\n");
}

int main() {
    Grade pt;
    GradeInit(&pt); // 初始化结构体

    ElemType1 name1 = "小明";
    ElemType1 name2 = "小华";
    ElemType1 name3 = "小红";
    ElemType1 name4 = "小刚";
    ElemType1 name5 = "小强";

    GradeInsert(&pt, name1, 90);
    GradeInsert(&pt, name2, 97);
    GradeInsert(&pt, name3, 60);
    GradeInsert(&pt, name4, 50);
    GradeInsert(&pt, name5, 90);

    GradePrint(pt);

    // 释放动态分配的内存
    free(pt.std);
    free(pt.grade);

    return 0;
}
