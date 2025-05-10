//题目一：顺序、折半查找
//1  实验目的：熟悉并掌握顺序、折半查找的过程及方法。
//2  实验内容：
//（1）	在输入数组的记录中顺序查找所需的记录；
//（2）	对已有的有序序列进行折半查找
//3  实验要求：在上机前写出全部源程序完毕并调试完毕。

#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	printf("请输入十个数字： ");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("请输入你想要查找的数字：");
	int num = 0;
	scanf_s("%d", &num);
	//顺序查找
	
	for (i = 0; i < 10; i++)
	{
		if (arr[i] == num)
		{
			printf("找到了，下标为%d\n", i);
			break;
		}
	}
	if (i == 10)
	{
		printf("该数字没有找到\n");
	}
	//折半查找
	int arr1[10] = { 0 };
	int num1 = 0;
	printf("请输入十个有序数字: ");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr1[i]);
	}
	printf("请输入你想要查找的数字:");
	scanf_s("%d", &num1);
	int left = 0;
	int right = 10 - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr1[mid] > num1)
		{
			right = mid - 1;
		}
		else if (arr1[mid] < num1)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标为%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("没有找到该数字\n");
	}
	return 0;
}