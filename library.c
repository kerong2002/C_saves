#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
    int data;                   //樹枝資料
    struct tree * left,*right;  //建立左方跟右方分支
};
typedef struct tree node;       //建立初始節點
typedef node *btree;            //建立二元結構數

btree create_tree(btree root,int value){
    btree newnode,current,backup;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
        return root;
    }
    else{
        for(current=root;current!=NULL){
            backup=current;
            if(current->data>value){
                current=current->
            }
        }
    }
}