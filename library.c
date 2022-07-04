#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
    int data;                   //樹枝資料
    struct tree * left,*right;  //建立左方跟右方分支
};
typedef struct tree node;       //建立初始節點
typedef node *btree;            //建立二元結構數

btree create_tree(btree,int);
void inorder(btree ptr){    //中序
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("[%2d]",ptr->data);
        inorder(ptr->right);
    }
}
void postorder(btree ptr){ //後序
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("[%2d]",ptr->data);
    }
}
void preorder(btree ptr){   //前序
    if(ptr!=NULL){
        printf("[%2d]",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
int main(){
    int data[]={7,4,1,5,16,8,11,12,15,9,2};
    btree ptr=NULL;
    btree root=NULL:
    for(int x=0;x<11;x++){
        prt=create_tree(ptr,data[x]);
    }
    printf("preorder=\n");
    preorder(ptr);
    printf("inorder=\n");
    inorder(ptr);
    printf("postorder=\n");
    postorder(ptr);
    return 0;
}
btree create_tree(btree root,int val){  //建立二元樹
    btree newnode,current,backup;
    newnode=(btreee)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
        return root;
    }
    else{
        for(current=root;current!=NULL){
            backup=current;
            if(current->data>val){
                current=current->left;
            }
            else{
                current=current->right;
            }
            
        }
        if(backup->data>val){
            backup->left=newnode;
        }
        elseP
        back->right=newnode;
    }
    return root;
}
