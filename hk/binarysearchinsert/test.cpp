//二分查找插入点（不存在重复元素)
#include<stdio.h>
int binarysearchinsert(int* arr, int len, int num)
{
	int left = 0;
	int right = len - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return left;
}
int main()
{
	int arr[5] = { 0 };
	int num = 0;
	printf("请输入五个有序数字:");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("请输入你想要插入的数字:");
	scanf_s("%d", &num);
	int seat=binarysearchinsert(arr, 5, num);
	printf("该数字应该插在第%d个位置\n", seat+1);
	return 0;
}