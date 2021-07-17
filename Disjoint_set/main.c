#include"stdio.h"
int fa[1000],rank[1000];
struct arc
{
    int in, out ,length;
}edge[1000];

int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}

int merge(int i, int j)
{
    int x = find(i), y = find(j);    //先找到两个根节点
    if(x == y) return 0;
    if(rank[x] > rank[y]) fa[y] = x;
    else{
        fa[x] = y;
        if (rank[x] == rank[y]) rank[y]++;  //深度相同，则默认将x附在y上并令y深度加1
        }
    return 1;
}





int main(){
    int vex,arc,total = 0;
    scanf("%d%d",&vex,&arc);
    for(int i = 0; i < arc; i++)
    {
        int in, out, length;
        scanf("%d%d%d",&in,&out,&length);
        edge[i].in = in;
        edge[i].out = out;
        edge[i].length = length;
    }
    for(int i = 0; i < arc - 1; i++)
    {
        for (int k = i + 1; k < arc; k++)
        {
            if(edge[i].length > edge[k].length)
            {
                int sw ;
                sw = edge[i].length;
                edge[i].length = edge[k].length;
                edge[k].length = sw;
            }
        }
    }
    init(vex);
    for (int i = 0; i < arc; i++)
    {
        if(merge(edge[i].in,edge[i].out) == 1)
            total += edge[i].length;
    }
    printf("%d",total);
     
}