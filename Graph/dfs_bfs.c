#include"stdio.h"
#include"stdlib.h"
//图的邻接矩阵储存结构
#define maxsize 100
//边结点的类型定义
typedef struct edgenode
{
    int adjvex;//存放邻接的点在顶点表的下标，邻接点
    struct edgenode *next;//指向Vi下一个邻接点的边结点
    int weight;/*权值*/
}edgenode;
//顶点结点类型定义
typedef struct vexnode
{
    int data; //存储顶点的名称或其相关信息
    edgenode *firstedge;//边表头指针
}vexnode;
//图的邻接表数据类型
typedef struct{
    vexnode vexlist[maxsize];//顶点表
    int n,e;
}graph;
vexnode queue[100];
//在图g中查找顶点v,存在顶点数组中的下标，不存在返回-1
int locatevex(graph g,int v)
{
    int i;
    for(i=0;i<g.n;i++)
        if(g.vexlist[i].data==v)return i;
    return -1;
}
//打印图信息
void print(graph g)
{
     int i;
     edgenode *p;
     printf("图的邻接表表示：");
     for(i=0;i<g.n;i++){
         printf("\n%4d",g.vexlist[i].data);
         p=g.vexlist[i].firstedge;
         while(p!=NULL){
             printf("-->%d",p->adjvex);p=p->next;
         }
     }
     printf("\n");
 }
 void creategraph(graph *g){
     int i,j,k;
     int v1,v2;
     edgenode *s;
     printf("请输入图的顶点数及边数\n");
     printf("顶点数 n=");scanf("%d",&g->n);
     printf("边  数 e=");scanf("%d",&g->e);
     printf("请输入图的顶点信息：\n");
     for(i=0;i<=g->n-1;i++){
         scanf("%d",&g->vexlist[i].data); //构造顶点信息
         g->vexlist[i].firstedge=NULL;
     }
     printf("请输入图的边的信息：\n");
     for(k=0;k<g->e;k++)
     {
         printf("请输入第%d条边的两个端点下标：",k+1);
         scanf("%d%d",&v1,&v2);//输入一条边的两个顶点
         i=locatevex(*g,v1);
         j=locatevex(*g,v2);
         if(i>=0&&j>=0){
         //建立无向图的邻接表
         /*s=(edgenode *)malloc(sizeof(edgenode));
         s->adjvex=j;
         s->next=g->vexlist[i].firstedge;
         g->vexlist[i].firstedge=s;
 
         s=(edgenode *)malloc(sizeof(edgenode));
         s->adjvex=i; 
         s->next=g->vexlist[j].firstedge;
         g->vexlist[j].firstedge=s;*/
             //建立有向图的邻接表
             s=(edgenode *)malloc(sizeof(edgenode));
             s->adjvex=j;
             s->next=g->vexlist[i].firstedge;
             g->vexlist[i].firstedge=s;
         }
     }
 }
 int visited[maxsize];/* 访问标志数组*/
  /*从第i个顶点出发递归地深度优先遍历图G*/
 void DFS(graph g,int i)
 {
     edgenode *p;
     printf("%3d",g.vexlist[i].data);/*访问第i个项点*/
     visited[i]=1;
     p=g.vexlist[i].firstedge;
     while(p!=NULL)    {
         if(visited[p->adjvex]==0)
           DFS(g,p->adjvex);/*对i的尚未访问的邻接顶点j递归调用DFS*/
         p=p->next;
     }
 }
 void DFStraverse(graph  g) /*对图G进行深度优先遍历*/
 {
     int v;
     for (v=0; v<g.n;v++)visited[v]=0; /*初始化标志数组*/
     for  (v=0; v<g.n;v++) /*保证非连通图的遍历*/
 /*从第v个顶点出发递归地深度优先遍历图G*/
         if (!visited[v])DFS(g,v);        
 }
 
 void BFS(graph g,int i)
 {
     edgenode *p;
     int h = 0;
     int flag = h;
     queue[h] = g.vexlist[i];
     h++;
     visited[i] = 1;
     p=g.vexlist[i].firstedge;
     while(flag <= g.n - 1 )
     {
         while(p!=NULL)    {
         if(visited[p->adjvex]==0)
           {
               queue[h++] = g.vexlist[p -> adjvex];
               visited[p -> adjvex] = 1;
               }
         p=p->next;
     }
     printf("%3d",queue[flag].data);
     flag++;
     p = g.vexlist[flag].firstedge;
     }
 }

void BFStraverse(graph g)
 {
     int v;
     for (v=0; v<g.n;v++)visited[v]=0; /*初始化标志数组*/
     for  (v=0; v<g.n;v++) /*保证非连通图的遍历*/
 /*从第v个顶点出发递归地深度优先遍历图G*/
         if (!visited[v])BFS(g,v);        
 }
 
 int main()
 {
     graph g;
     creategraph(&g);
     print(g);
     printf("\n");
     printf("图的深度优先遍历序列：\n");
     DFStraverse(g);
     printf("\n");
     printf("图的广度优先遍历序列：\n");
     BFStraverse(g);
     printf("\n");
     return 0;
 }
