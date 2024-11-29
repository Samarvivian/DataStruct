//用递归实现二分查找
#include<stdio.h>
int binarysearchrecursion(int num, int* arr, int left, int right)
{
	if (left == right)
	{
		if (arr[left] == num)
		{
			return left;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		int mid = (left + right) / 2;
		if (arr[mid] > num)
		{
			return binarysearchrecursion(num, arr, left, mid - 1);
		}
		else if (arr[mid] < num)
		{
			return binarysearchrecursion(num, arr, mid + 1, right);
		}
		else
		{
			return mid;
		}
	}
}
int main()
{
	int arr[5] = { 0 };
	int num = 0;
	printf("请输入5个有序数:");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("请输入想要查找的数字:");
	scanf_s("%d", &num);
	if (binarysearchrecursion(num, arr, 0, 4) != -1)
	{
		printf("找到了，下标为%d\n", binarysearchrecursion(num, arr, 0, 4));
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}