#include<stdio.h>
//交换两个数
void exchange(int* nums, int i,int left)
{
	int temp = nums[i];
	nums[i] = nums[left];
	nums[left] = temp;
}
//哨兵划分
int partition(int* nums, int left, int right)
{
	//以nums[left]为基准数
	int i = left, j = right;
	while (i < j)
	{
		
		while(i<j&&nums[j] > nums[left])
		{
			j--;
		}
		while (i < j && nums[i] < nums[left])
		{
			i++;
		}
		exchange(nums,i,j);
	}
	exchange(nums,i,left);
	return i;
}
//快速排序
void quicksort(int* nums, int left, int right)
{
	if (left >= right)
	{
		return;//只剩一个元素时停止递归

	}
	int pivot=partition(nums, left, right);
	partition(nums, left, pivot - 1);
	partition(nums, pivot+1, right);
}
int main()
{
	int nums[] = { 7,11,2,9,18,17,21,6 };
	int len = sizeof(nums) / sizeof(nums[0]);
	quicksort(nums, 0, len - 1);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}