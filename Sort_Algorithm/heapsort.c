#include <stdio.h>
void produce(int zz[],int i,int length);
void sort(int zz[],int length);
void produce(int zz[],int i,int length){
    int child;
    int tmp;
    for(tmp = zz[i];i * 2 + 1 < length;i = child) /*交换顶部和尾部后有可能会打乱原有的结点满足的关系，因此要一直遍历到堆的最底端*/
        {
            child = i * 2 + 1;
            if(child != length - 1 && zz[child + 1] > zz[child]) 
                child++;
            if(tmp < zz[child])
                zz[i] = zz[child];
            else break;
        }
        zz[i] = tmp;
}
void sort(int zz[],int length){
    int i;
    for( i = length / 2; i >= 0;i--) produce(zz,i,length);/*从最后一个非页结点开始，构造大顶堆*/
    for(i = length - 1; i > 0; i--)
    {
        int swap;
        swap = zz[0];
        zz[0] = zz[i];
        zz[i] = swap; /*交换顶部和尾部*/
        produce(zz,0,i);
    }
}

int main(){
    int length;
    printf("请先输入要输入的数字总数，仅支持整数！\n"); 
    scanf("%d",&length);
    int zz[100];
    for(int k = 0;k <= length - 1; k++) scanf("%d",&zz[k]);
    sort(zz,length);
    for(int k = 0;k <= length - 1; k++)
    {
        printf("%d ",zz[k]);
    }
}