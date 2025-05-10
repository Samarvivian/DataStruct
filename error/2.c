// 项目3


#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int num[20] = {};
	// (a+d)+(a-d)+(a-3*d)+(a+3*d)=26
	// (a+d)*(a-d)*(a-3*d)*(a+3*d)=880
	
	double a = 26.0 / 4;
	double d = 0;
	while (1) {
		if ((a + d) * (a - d) * (a - 3 * d) * (a + 3 * d) == 880) {
			break;
		}
		d += 0.000001;
		if (d > 1000) {
			printf("精度不足，计算失败。\n");
			return 0;
		}
	}
	for (int i = 0; i < 20; i++) {
		num[i] = a - 3 * d + i * 2 * d;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0 + i * 5; j < 5 + i * 5; j++) {
			printf("%d ", num[j]);
		}
		printf("\n");
	}
	


	return 0;
}