void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}

status judge_same1(VertexType V[]){
    int length = 0;
    while(V[length].key != -1) length++;
    int k, i, flag = 0;
    for( k = 0; k < length - 1; k++){
        for( i = k + 1; i < length; i++)
        {
            if(V[k].key == V[i].key){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) return ERROR;
    return OK;
}

status judge_same2(VertexType V[],KeyType VR[][2]){
   for(int k = 0; VR[k][0] != -1; k++ )
   {
        int flag = 0;
       for(int i = 0; V[i].key != -1; i++ )
       {
           if(V[i].key == VR[k][0] ) flag = 1;
       }
       if(flag == 0) return ERROR;
   }
   for(int k = 0; VR[k][0] != -1; k++ )
   {
        int flag = 0;
       for(int i = 0; V[i].key != -1; i++ )
       {
           if(V[i].key == VR[k][1] ) flag = 1;
       }
       if(flag == 0) return ERROR;
   }
   return OK; 
}

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int ans, length = 0;
    G.arcnum = 0;
    ans = judge_same1(V);
    if(ans == ERROR) return ERROR;
    ans = judge_same2(V,VR);
    if(ans == ERROR) return ERROR;
    while(V[length].key != - 1) length++;
    G.vexnum = length;
    if(length > MAX_VERTEX_NUM) return ERROR;
    for( int k = 0; k <= length - 1; k++)
    {
        G.vertices[k].data.key = V[k].key;
        strcpy(G.vertices[k].data.others , V[k].others);
    }
    for(int k = 0; k <= length - 1; k++)
    {
        int vr_order = 0;
        ArcNode *tail,*tail1;
        G.vertices[k].firstarc = NULL;
        while(VR[vr_order][0] != -1){
            if(VR[vr_order][0] == V[k].key){
                //printf("%d",VR[vr_order][0]);
                //tail1 = tail;
                
                tail = (ArcNode *)malloc(sizeof(ArcNode));
                int i;
                for(i = 0; i < length; i++)
                {
                    if(G.vertices[i].data.key == VR[vr_order][1]) break;
                }
                
                tail -> adjvex = i;
                tail -> nextarc = G.vertices[k].firstarc;
                G.vertices[k].firstarc = tail;
                tail = NULL;
                G.arcnum++;
            }

            if(VR[vr_order][1] == V[k].key){
                
                tail = (ArcNode *)malloc(sizeof(ArcNode));
                int i;
                for(i = 0; i < length; i++)
                {
                    if(G.vertices[i].data.key == VR[vr_order][0]) break;
                }
                tail -> adjvex = i;
                tail -> nextarc = G.vertices[k].firstarc;
                G.vertices[k].firstarc = tail;
                tail = NULL;
                
            }
            
            vr_order++;
        }
        
    }
    //printf("%d",G.arcnum);
    if(G.vexnum == 0) return ERROR;
    return OK;
    /********** End **********/
}




status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int judge[G.vexnum],stack[MAX_VERTEX_NUM];
    int last = 0;
    memset(judge,0,sizeof(judge));
    for(int i = 0;i < G.vexnum; i++)    //每个点操作一次防止为非连通图
    {
        if(judge[i] == 0)
        {
            visit(G.vertices[i].data);
            judge[i] = 1;
            stack[last++] = i;
            }
        while(last != 0){
            ArcNode *node = G.vertices[stack[last - 1]].firstarc;
            int flag = 0;
            while(node){
                if(judge[node -> adjvex] == 0){
                    visit(G.vertices[node -> adjvex].data);
                    judge[node -> adjvex] = 1;
                    stack[last++] = node -> adjvex;
                    flag = 1;
                    break;
                }
                node = node -> nextarc;
            }
            if(!flag && last != 0)  last--;      
        }
        
    }

    /********** End **********/
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int judge[G.vexnum];
    memset(judge,0,sizeof(judge));
    for(int i = 0;i < G.vexnum; i++)
    {   
        if(judge[i] == 0){
            visit(G.vertices[i].data);
            judge[i] = 1;
        }
        ArcNode *tail = G.vertices[i].firstarc;
        while(tail){
            if(judge[tail -> adjvex] == 0)  
            {
                visit(G.vertices[tail -> adjvex].data);
                judge[tail -> adjvex] = 1;
                }
            tail = tail -> nextarc;
        }
    }

    /********** End **********/
}


status DAG(ALGraph &G, void (*visit)(VertexType)){
    int n = G.vexnum;
    int in_degree[n];
    memset(in_degree, 0, sizeof(in_degree));
    for (int i = 0; i < n; i++)
    {
        ArcNode *tail = G.vertices[i].firstarc;
        while(tail)
        {
            in_degree[tail -> adjvex]++;
            tail = tail -> nextarc;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        while(in_degree[k] != 0 && k < n){
            k++;
        }
        visit(G.vertices[k].data);
        in_degree[k]--;
        ArcNode *tail = G.vertices[k].firstarc;
        while(tail)
        {
            in_degree[tail -> adjvex]--;
            tail = tail -> nextarc;
        }
    }
}