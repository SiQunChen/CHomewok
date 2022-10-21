#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
typedef struct binaryTree_s{
    char data;
    struct binaryTree_s *left,*right;
}binaryTree_t;
binaryTree_t *create(char data){
    binaryTree_t *newNode=(binaryTree_t *)malloc(sizeof(binaryTree_t));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void printBinaryTree(binaryTree_t *root){
    binaryTree_t **binaryTreeArray = (binaryTree_t **)malloc(SIZE * sizeof(binaryTree_t *));
    int length = 0, index = 0;
    binaryTreeArray[length++] = root;
    while (index < length){
        printf("%c", binaryTreeArray[index]->data);
        if (binaryTreeArray[index]->left != NULL)
            binaryTreeArray[length++] = binaryTreeArray[index]->left;
        if (binaryTreeArray[index]->right != NULL)
            binaryTreeArray[length++] = binaryTreeArray[index]->right;
        index++;
    }
    free(binaryTreeArray);
}
int search(char *inOrder,int start,int end,char data){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==data)
            return i;
    }
    return -1;
}
binaryTree_t *buildBinaryTree(char *inOrder,char *pOrder,int start,int end,int *pIndex,int isPreOrder){
    if(start>end)
        return NULL;
    char data=isPreOrder?pOrder[(*pIndex)++]:pOrder[(*pIndex)--];
    binaryTree_t *newNode=create(data);
    int inIndex=search(inOrder,start,end,data);
    if(isPreOrder){
        newNode->left=buildBinaryTree(inOrder,pOrder,start,inIndex-1,pIndex,isPreOrder);
        newNode->right=buildBinaryTree(inOrder,pOrder,inIndex+1,end,pIndex,isPreOrder);
    }
    else{
        newNode->right=buildBinaryTree(inOrder,pOrder,inIndex+1,end,pIndex,isPreOrder);
        newNode->left=buildBinaryTree(inOrder,pOrder,start,inIndex-1,pIndex,isPreOrder);
    }
    return newNode;
}
int main(){
    binaryTree_t *root;
    char code,inOrder[SIZE],pOrder[SIZE];
    int isPreOrder=0,pIndex;
    for(int i=0;i<2;i++){
        scanf(" %c",&code);
        if(code=='P')
            isPreOrder=1;
        if(code=='I')
            scanf(" %s",inOrder);
        else
            scanf(" %s",pOrder);
    }
    pIndex=isPreOrder?0:strlen(inOrder)-1;
    root=buildBinaryTree(inOrder,pOrder,0,strlen(inOrder)-1,&pIndex,isPreOrder);
    printBinaryTree(root);
    return 0;
}
