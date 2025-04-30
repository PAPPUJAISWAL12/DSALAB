#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *left;
struct Node *right;
};
typedef struct Node NodeType;

NodeType *createNode(int val){
   NodeType *newNode=(NodeType*)malloc(sizeof(NodeType));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;    
}
NodeType *insertTree(struct Node *root,int val){

    if(root==NULL){
        return createNode(val);
    }
    
    if(val< root->data){
        root->left=insertTree(root->left,val);
    }else{
        root->right= insertTree(root->right,val);
    }
    return root;
}
NodeType *search(struct Node *root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

NodeType * FindMin(NodeType *root){
    while (root->left!=NULL)
    {
        root->left=FindMin(root->left);
    }
    return root;    
}

NodeType *Delete(struct Node *root,int key){
     NodeType *result=search(root,key);
    if(result==NULL){
        printf("Data is not found in the tree.\n");
        return 0;
    }

    if(root==NULL || root->data==key){
        return root;
    }else if(key<root->data){
        root->left=Delete(root->left,key);
    }else if(key>root->data){
        root->right=Delete(root->right,key);
    }else{
        if(root->left==NULL || root->right==NULL){
            free(root);
        }
        
        if(root->left==NULL){
            struct Node *temp=root->left;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
            NodeType *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
            return temp;

        
    }
}
void InorderTraversal(NodeType *root){
    if(root !=NULL){
        InorderTraversal(root->left);
        printf("%d\t",root->data);
        InorderTraversal(root->right);
    }
}

int main(){
   NodeType *root=NULL;
   root=insertTree(root,30);
     root = insertTree(root,40);
     root=insertTree(root,10);
     root=insertTree(root,15);
     root = insertTree(root,5);   
   printf("Data inserted successfully");
    
    printf("\nInorder Traversal:");
    InorderTraversal(root);
    printf("\n");
    NodeType *result=search(root,5);
    if(result!=NULL){
        printf("Found node with data:%d",result->data);

    }
     printf("After deletion of 20, in-order traversal: ");
     root = Delete(root, 10);   
    InorderTraversal(root);
    printf("\n");

}