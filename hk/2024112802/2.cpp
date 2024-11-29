//题目二：电话号码的查询
//1 实验目的：熟练并掌握查找的过程、方法和应用
//2 实验内容：
//	问题描述：
//设计一个电话号码查找程序，为来查询人提供电话号码的查询服务。
//	基本要求：
//（1）	以你所在的班级为查询范围，假设人名为中国人姓名的汉语拼音形式。人数不能少于10人。
//（2）	完成根据人名来查找相应的电话号码。
//	测试数据
//由同学们根据实际情况指定
//3 实验要求：在上机前写出全部源程序完毕并调试完毕。

#define _CRT_SECURE_NO_WARNINGS 1
#define max 100
#include<stdio.h>
#include<string.h>
int main()
{
	//记录名字与电话号码的数组
	const char* arr[10][2] =
	{
		"aaa","00000000",
		"bbb","00000001",
		"ccc","00000002",
		"ddd","00000003",
		"fff","00000004",
		"eee","00000005",
		"ggg","00000006",
		"hhh","00000007",
		"iii","00000008",
		"jjj","00000000"

	};
	char name[100];
	printf("--------电话号码查询服务---------\n");
	printf("         A.查询    B.结束\n        ");
	printf("请输入你想要的服务:\n");
	char ch = 0;
	scanf_s("%c", &ch);
	while (ch != 'B')
	{
		printf("请输入你想要查询的同学的姓名:");
		scanf_s("%s", name,max);
		getchar();//清空换行符
		//遍历
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			if (strcmp((char*)arr[i][0], name) == 0)
			{
				printf("找到了，%s同学的电话号码为%s\n", arr[i][0], arr[i][1]);
				break;
			}
		}
		if (i == 10)
		{
			printf("抱歉，没有找到%s同学的电话号码\n");
		}
		printf("         A.查询    B.结束\n        ");
		printf("请输入你想要的服务:\n");
		scanf_s("%c", &ch);
	}
	return 0;
}