//给定一个长度为n的有序数组 nums ，其中可能包含重复元素。请返回数组中最右一个元素 target 的索引。若数组中不包含该元素，则返回-1 
//运用二分查找
#include<stdio.h>
int binarysearch(int* nums,int n,int target)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            left=mid+1;//缩小区间
        }
    }
    
    if(nums[right]==target)
    {
        return right;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int nums[]={1,1,1,2,2,3,3,4};
    int n=sizeof(nums)/sizeof(nums[0]);
    int target=1;
    int res=binarysearch(nums,n,target);
    if(res!=-1)
    {
        printf("找到了，索引为%d\n",res);
    }
    else
    {
        printf("找不到\n");
    }
    return 0;
} 