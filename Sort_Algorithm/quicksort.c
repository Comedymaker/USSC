#include<stdio.h>
int sort(int zz[], int low, int high);
int sort(int zz[], int low, int high){
    int key = zz[low];
    while(low < high)
    {
        while(low < high && zz[high] >= key) high--;
        zz[low] = zz[high];
        while (low < high && zz[low] <= key) low++;
        zz[high] = zz[low];
        
    }
    zz[low] = key;
    return low;
}
void Qsort(int zz[],int low, int high)
{   
    int key;
    if(low < high){
        key = sort(zz,low,high);
        Qsort(zz,low,key-1);
        Qsort(zz,key+1,high);
    }
}
int main(){
    int length;
	printf("请先输入要输入的数字总数，仅支持整数！\n"); 
	scanf("%d",&length);
	int zz[length];
		for(int k = 0;k <= length - 1;k++)
	{
		scanf("%d",&zz[k]);
	}
    Qsort(zz,0,length - 1);
    for(int k = 0;k <= length-1;k++)
	{
		printf("%d ",zz[k]);
	}
}