
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(!T) return ERROR;
    FILE *fp;
    fp = fopen(FileName,"w");
    /*BiTree queue[100], p = T;
    int order_queue[100],order = 1;
    int first = 0, tail = 0;
    queue[tail] = p;
    tail++;
    while(first != tail){
        if(p -> lchild){
            
        }
    }*/
    BiTree queue[100],p = T;
    int order_queue[100],order = 1;
    int first = 0, tail = 0;
    queue[tail] = p;
    order_queue[tail] = 1;
    tail++;
    while(tail != first){
        p = queue[first];
        order = order_queue[first];
        fprintf(fp,"%d %d %s ",order,p->data.key,p->data.others);
        first++;
        if(p -> lchild){
            queue[tail] = p -> lchild;
            order_queue[tail] = order * 2;
            tail++;
        }
        if(p -> rchild){
            queue[tail] = p -> rchild;
            order_queue[tail] = order * 2 + 1;
            tail++;
        }
    }
    fclose(fp);
    return OK;
    /********** End 1 **********/
}

status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    

    /********** End 2 **********/
}
