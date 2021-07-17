#include"stdio.h"
#include"def.h"
#include"string.h"
#include"fun.h"
int main(){
    ALGraph G;
    G.arcnum = 0;
    G.vexnum = 0;
    if(G.vexnum != 0)   printf("The graph already exist!\n\n");
    else {VertexType V[30];
    KeyType VR[100][2];
    int i=0,j;
    do {
        scanf("%d%s",&V[i].key,V[i].others);
    } while(V[i++].key!=-1);
    i=0;
    do {
        scanf("%d%d",&VR[i][0],&VR[i][1]);
    } while(VR[i++][0]!=-1);
    if(CreateCraph(G,V,VR) == ERROR)
        printf("Invalid graph!\n\n");
    else printf("Create graph succeeded!\n\n");

    DFSTraverse(G,visit);

    printf("\n");

    BFSTraverse(G,visit);

    printf("\n");

    DAG(G,visit);
    }
}