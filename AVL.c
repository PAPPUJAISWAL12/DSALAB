#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *right,*left;
    int ht;
}node;
int height(node *root){
    return (root==NULL)?0:root->ht;
}

int BF(node * root){
    if(root==NULL){
        return 0;
    }
    int lh,rh;
    lh=(root->left==NULL)?0:1+root->left->ht;
    rh=(root->right==NULL)?0:1+root->right->ht;
    return(lh-rh);
}
node *RotateRight(node* root){
    node *x=root->left;
    node *t2=x->right;
    x->right=root;
    root->left=t2;
    t2->ht=height(root->left)>height(root->right) ?height(root->left)+1: height(root->right)+1;
    x->ht=height(root->left)>height(root->right)?height(root->left)+1:height(root->right);
    return x;
}
node *RotateLeft(node* root){
    node * y=root->right;
    node * t2=y->left;

    y->left=root;
    root->right=t2;

    t2->ht=height(root->left)>height(root->right)?height(root->left)+1:height(root->left)+1;
    y->ht=height(root->left)>height(root->right)?height(root->left)+1:height(root->left)+1;
    return y;
}

node *LL(node * root){
    return RotateRight(root);
}
node *RR(node *root){
    return RotateLeft(root);
}
node *LR(node * root){
    root=RotateLeft(root);
    return RotateRight(root);
}
node *RL(node * root){
    root=RotateRight(root);
    return RotateLeft(root);
}

node *InsertBstData(node *root,int key){
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->data=key;
        root->left=root->right=NULL;
        root->ht=1;
        return root;       
    }else{
        if(key>root->data){
            root->right=InsertBstData(root->right,key);
        }else{
            root->left=InsertBstData(root->left,key);
        }        
    }
    root->ht=1+(height(root->left)>height(root->right)?height(root->left):height(root->right));
        int balance=BF(root);
        if(balance>1 && key<root->left->data){
            return LL(root);
        }
        
        if(balance<-1 && key>root->right->data){
            return RR(root);
        }
        if(balance>1 && key>root->left->data){
            return LR(root);
        }
        
        if(balance<-1 && key<root->right->data){
            return RL(root);
        }
        return root;
}
node * Preorder(node * root){
   if(root!=NULL){
     printf("%d BF=%d ",root->data,BF(root));
    Preorder(root->left);
    Preorder(root->right);
   }
}

int main(){
    node *root=NULL;
    root=InsertBstData(root,30);
    root=InsertBstData(root,20);
    root=InsertBstData(root,40);
    root=InsertBstData(root,10);
    root=InsertBstData(root,25);
    root=InsertBstData(root,35);
    root=InsertBstData(root,50);

    printf("preorder traversal of AVL tree:\n ");
    Preorder(root);
    printf("\n");
}
