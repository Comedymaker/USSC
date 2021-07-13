#include<stdio.h>
int length;
void divide(int zz[],int left,int right);
void merge(int zz[],int left,int center,int right);
void divide(int zz[],int left,int right){
	int center = (right + left) / 2;
	if(left < right)
	{
		divide(zz,left,center);
		divide(zz,center + 1,right);
		merge(zz,left,center,right);
	}
}
void merge(int zz[],int left,int center,int right){
	int tmp[length];
	int k,i,h = left;
	for(k = left, i = center + 1; k <= center && i <= right;h++)
	{
		if(zz[k] <= zz[i]) {
			tmp[h] = zz[k];
			k++;
			}
		else {
			tmp[h] = zz[i];
			i++;
		}
	}
	if(k > center){
		while(i <= right){
			tmp[h++] = zz[i];
			i++;
		}
	}
	else {
		while(k <= right){
			tmp[h++] = zz[k];
			k++;
		}
	}
	for(int i = left;i <= right;i++)
	{
		zz[i] = tmp [i];
	}
}
int main(){
	printf("请先输入要输入的数字总数，仅支持整数！\n"); 
	scanf("%d",&length);
	int zz[length],tmp[length];
		for(int k = 0;k <= length - 1;k++)
	{
		scanf("%d",&zz[k]);
	}
	divide(zz,0,length - 1);
		for(int k = 0;k <= length - 1;k++)
	{
		printf("%d ",zz[k]);
	}
}