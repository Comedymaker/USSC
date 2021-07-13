#include"stdio.h"
#include"stdlib.h"
int main(){
    FILE *fp;
    fp = fopen("text1","w");
    fprintf(fp,"%d ",1);
    fclose(fp);
    return 0;
}