#include <stdio.h>
typedef struct node *ptrnode;
int length = 0;
struct node
{
    int data;
    ptrnode left;
    ptrnode right;
};
void construct(ptrnode first,int depth);
void postorder_print(ptrnode first,int depth);
void inorder_print(ptrnode first,int depth);
void preorder_print(ptrnode first,int depth);
void bfsorder(ptrnode first,int depth,int zz[],int space[],int i);
void construct(ptrnode first,int depth){                                                   
    ptrnode tail;
    int tmp;
    
    if(!(first -> left))
    {   
        scanf("%d",&tmp);
        if(tmp != 0) length++;
        if(tmp == 0) return ;
        tail = first -> left = (ptrnode)malloc(sizeof(struct node));
        tail -> left = NULL;
        tail -> right = NULL;
        tail -> data = tmp;
        construct(tail,depth+1);
    }
    
        if(first -> left && !(first -> right))
        {
        scanf("%d",&tmp);
        if(tmp != 0) length++;
        if(tmp == 0) return ;
        tail = first -> right = (ptrnode)malloc(sizeof(struct node));
        tail -> data = tmp;
        tail -> left = NULL;
        tail -> right = NULL;
        construct(tail,depth+1);
        }
    
return ;
}

void preorder_print(ptrnode first,int depth){  /*先序*/
    for(int k = 0; k <= depth; k++) printf(" ");
    printf("%d\n",first -> data);
    if(first -> left) preorder_print(first -> left, depth + 1);
    if(first -> right) preorder_print(first -> right, depth + 1);
}

void inorder_print(ptrnode first,int depth){  /*中序*/
    int flag = 1;
    if(first -> left) inorder_print(first -> left, depth + 1);
    for(int k = 0; k <= depth; k++) printf(" ");
        
        printf("%d\n",first -> data);
        
    if(first -> right) inorder_print(first -> right, depth + 1);
    
       
}

void postorder_print(ptrnode first,int depth){ /*后序*/
    if(first -> left) postorder_print(first -> left, depth + 1);
    if(first -> right) postorder_print(first -> right, depth + 1);
    
        for(int k = 0; k <= depth; k++) printf(" ");
        printf("%d\n",first -> data);
    
}

void bfsorder(ptrnode first,int depth,int zz[],int space[],int i){/*层次,递归版只能支持完全二叉树*/
    if(first -> left){
        zz[i * 2] = first -> left -> data;
        space[i * 2] = depth + 1;
        bfsorder(first -> left, depth + 1, zz,space, i * 2) ;
    }
    if(first -> right){
        zz[i * 2 + 1] = first -> right -> data;
        space[i * 2 + 1] = depth + 1;
        bfsorder(first -> right, depth + 1, zz,space, i * 2 + 1);
    }
}

int main(){
    int s;
    ptrnode root;
    root = (ptrnode)malloc(sizeof(struct node));
    root -> left = root -> right = NULL;
    printf("首先构造一棵二叉树，输入零表示到达叶结点\n");
    scanf("%d",&root -> data);
    length++;
    construct(root,0);
    int zz[length + 1],space[length + 1];
    printf("请选择遍历方式，输入1先序，输入2中序，输入3后序，输入4层序，输入0退出\n");
    scanf("%d",&s);
    printf("以下为输出内容：\n");
    while(s)
    {
        switch (s)
    {
    case 1:
        preorder_print(root,0);
        break;
    
    case 2:
        inorder_print(root,0);
        break;

    case 3:
        postorder_print(root,0);
        break;

    case 4:
        printf(" %d\n",root -> data);
        bfsorder(root,0,zz,space,1);
        for(int k = 2; k <= length; k++)
        {
            for(int i = 0; i <= space[k] ;i++)
            {
                printf(" ");
            }
            printf("%d\n",zz[k]);
        }
        
        break;
    default:
        break;
    }
    scanf("%d",&s);
}
    
}