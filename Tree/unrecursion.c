#include <stdio.h>
#define MAX_SIZE 300
typedef struct node *ptrnode;
struct node
{
    int data;
    ptrnode left;
    ptrnode right;
};
void construct(ptrnode first);
void pre_order(ptrnode first);
void in_order(ptrnode first);
void post_order(ptrnode first);
void bfs_order(ptrnode first);
void construct(ptrnode first){    
    ptrnode tail;
    int tmp;
    
    if(!(first -> left))
    {   
        scanf("%d",&tmp);
        if(tmp == 0) return ;
        tail = first -> left = (ptrnode)malloc(sizeof(struct node));
        tail -> left = NULL;
        tail -> right = NULL;
        tail -> data = tmp;
        construct(tail);
    }
    
        if(first -> left && !(first -> right))
        {
        scanf("%d",&tmp);
        if(tmp == 0) return ;
        tail = first -> right = (ptrnode)malloc(sizeof(struct node));
        tail -> data = tmp;
        tail -> left = NULL;
        tail -> right = NULL;
        construct(tail);
        }
    
return ;
}
void pre_order(ptrnode first){  /*错了！！*/
    ptrnode p = first,stack[MAX_SIZE];
    int top = 0;
    stack[top] = p;
    while(top > -1)
    {
        p = stack[top];
        top--;
        printf("%d ",p -> data);
        if(p -> left){
            top++;
            stack[top] = p -> left;
        }
        if(p -> right){
            top++;
            stack[top] = p -> right;
        }
    }
   
}
void in_order(ptrnode first){
    ptrnode stack[MAX_SIZE];
    int base = 0, top = 0;
    ptrnode p = first;
        stack[top] = p;
            top ++;
            p = p -> left;
    while(top > -1){
        while(p)
        {
            stack[top] = p;
            top ++;
            p = p -> left;
        }
        if(top > -1 ){
            top --;
            if(top > -1) printf("%d ",stack[top] -> data);
            p = stack[top];
            p = p -> right;
        }
    }
}

void post_order(ptrnode first){
    ptrnode stack[MAX_SIZE],p;
    int top = -1,sign;
    p = first;
    if(first){
        do{
            while(first){
                top++;
                stack[top] = first;
                first = first -> left;
            }
            p = NULL;
            sign = 1;
            while(top != -1 && sign){
                first = stack[top];
                if(first -> right == p)
                {
                    printf("%d ",first -> data);
                    top--;
                    p = first;
                }
                else{
                    first = first -> right;
                    sign = 0;
                }
            }
        }while (top != -1);
        
        
    }
            
}

void bfs_order(ptrnode first){
    ptrnode zz[MAX_SIZE];
    int rear = 0, front = 0;
    ptrnode p = first;
    if(p){
        zz[rear] = first;
        rear ++;
    }
    while(rear != front)
    {   
        p = zz[front];
        printf("%d ",p -> data);
        front++;
        if(p -> left){
            zz[rear] = p -> left;
            rear ++;
        }
        if(p -> right){
            zz[rear] = p -> right;
            rear ++;
        }
    }
}
int main(){
    ptrnode root;
    int s;
    root = (ptrnode)malloc(sizeof(struct node));
    root -> left = root -> right = NULL;
    scanf("%d",&root -> data);
    construct(root);
    printf("请选择遍历方式，输入1先序，输入2中序，输入3后序，输入4层序，输入0退出\n");
    scanf("%d",&s);
    while(s)
    {
        switch (s)
    {
    case 1:
        printf("以下为输出内容：\n");
        pre_order(root);
        printf("\n");
        break;
    
    case 2:
        printf("以下为输出内容：\n");
        in_order(root);
        printf("\n");
        break;

    case 3:
        printf("以下为输出内容：\n");
        post_order(root);
        printf("\n");
        break;

    case 4:
        printf("以下为输出内容：\n");
        bfs_order(root);
        printf("\n");
        break;
    default:
        break;
    }
    scanf("%d",&s);
}
}