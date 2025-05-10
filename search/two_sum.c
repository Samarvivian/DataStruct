//给定一个整数数组 nums 和一个目标元素 target ，
//请在数组中搜索“和”为 target 的两个元素，并返回它们的数组索引。返回任意一个解即可。

//用哈希表大大减少时间复杂度
#include"uthash.h"//基于这个库实现
#include<stdlib.h>
#include<stdio.h>
typedef struct hashtable
{
    int val;//元素的下标
    int key;//元素的数值
    UT_hash_handle hh; // 基于 uthash.h 实现
}hashtable;

//哈希表查找
hashtable* HashFind(hashtable* h,int key)
{
    hashtable* temp;
    HASH_FIND_INT(h,&key,temp);//用temp储存key所在的位置，若找不到返回NULL
    return temp;
}

//哈希表插入
void HashInsert(hashtable** h,int val,int key)
{
    hashtable* t=HashFind(*h,key);
    if(t==NULL)
    {
        //没有找到对应元素，将该元素插入
        hashtable* temp=(hashtable*)malloc(sizeof(hashtable));
        temp->key=key;
        temp->val=val;
        HASH_ADD_INT(*h,key,temp);
    }
    else
    {
        //找到了，将val值赋给t->val
        t->val=val;
    }
}

//功能实现
int* two_sum(int* nums,int target,hashtable* h,int n)
{
    hashtable *t=NULL;
    for(int i=0;i<n;i++)
    {
        t=HashFind(h,target-nums[i]);
        if(t!=NULL)
        {
            //找到，返回两个下标
            int* arr=(int*)malloc(sizeof(int)*2);
            arr[0]=i;
            arr[1]=t->val;
            return arr;
        }
        HashInsert(&h,i,nums[i]);
    }
    int* arr=NULL;
    return arr;
}

int main()
{
    int nums[]={1,2,3,5,7,9,10};
    hashtable* h=NULL;
    int* arr=two_sum(nums,15,h,sizeof(nums)/sizeof(nums[0]));
    if(arr)
    {
        printf("找到了，下标为%d和%d\n",arr[0],arr[1]);
    }
    else
    {
        printf("找不到\n");
    }
    return 0;
}