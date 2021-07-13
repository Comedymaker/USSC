#include <stdio.h>
int main()
{
	int length;
	int p, j;
	printf("请先输入要输入的数字总数，仅支持整数！\n");
	scanf("%d", &length);
	int zz[length];
	for (int k = 0; k <= length - 1; k++)
	{
		scanf("%d", &zz[k]);
	}
	for (p = 1; p <= length - 1; p++)
	{
		int tmp = zz[p];
		for (j = p; j >= 0 && tmp < zz[j - 1]; j--) /*从第p个数往前遍历，若前面的数比p大，则将第j个数的位置放入第j-1个数的值*/
			zz[j] = zz[j - 1];
		zz[j] = tmp; /*最后将第p个数的值放到应放的位置*/
	}
	for (int k = 0; k <= length - 1; k++)
	{
		printf("%d ", zz[k]);
	}
	return 0;
}
