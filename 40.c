#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}node_t;
typedef node_t* nodep_t;
nodep_t create(char data){
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
typedef struct nodee{
    nodep_t data;
    struct nodee* next;
}nodee_t;
typedef nodee_t* nodeep_t;
nodeep_t createe(nodep_t data){
    nodeep_t newNode;
    newNode = (nodeep_t)malloc(sizeof(nodee_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void in(nodep_t *p,char data,int cho){
    nodep_t newNode=create(data);
    if(cho==1){
        (*p)->left=newNode;
        (*p)=(*p)->left;
    }
    else{
        (*p)->right=newNode;
        (*p)=(*p)->right;
    }
}
char FindTop(nodep_t *p,char oth,char str2[20]){
    if(oth=='P'){
        (*p)=create(str2[0]);
        return str2[0];
    }
    else{
        (*p)=create(str2[strlen(str2)-1]);
        return str2[strlen(str2)-1];
    }
}
int FindMidPoint(char str[20],char split){
    for(int i=0;i<20;i++){
        if(str[i]==split)return i;
    }
    return 0;
}
void draw(nodep_t *p,char str1[20],char oth,char str2[20],char split){
    nodep_t cur=*p;
    char left1[20],right1[20],left2[20],right2[20];
    int index,cho=0;
    for(int i=0;i<20;i++){
        left1[i]=0;
        left2[i]=0;
        right1[i]=0;
        right2[i]=0;
    }
    index=FindMidPoint(str1,split);
    for(int i=0;i<index;i++){
        left1[i]=str1[i];
    }
    if(oth=='P'){
        for(int i=1;i<index+1;i++){
            left2[i-1]=str2[i];
        }
    }
    else{
        for(int i=0;i<index;i++){
            left2[i]=str2[i];
        }
    }
    cho=1;
    if(strlen(left1)==1){
        in(p,left2[0],cho);
    }
    else if(strlen(left1)>1){
        if(oth=='P'){
            in(p,left2[0],cho);
            draw(p,left1,oth,left2,left2[0]);
        }
        else{
            in(p,left2[strlen(left2)-1],cho);
            draw(p,left1,oth,left2,left2[strlen(left2)-1]);
        }
    }
    (*p)=cur;
    for(int i=index+1;i<20;i++){
        right1[i-index-1]=str1[i];
    }
    if(oth=='P'){
        for(int i=strlen(left2)+1;i<20;i++){
            right2[i-strlen(left2)-1]=str2[i];
        }
    }
    else{
        for(int i=index;i<strlen(str2)-1;i++){
            right2[i-index]=str2[i];
        }
    }
    cho=2;
    if(strlen(right1)==1){
        in(p,right2[0],cho);
    }
    else if(strlen(right1)>1){
        if(oth=='P'){
            in(p,right2[0],cho);
            draw(p,right1,oth,right2,right2[0]);
        }
        else{
            in(p,right2[strlen(right2)-1],cho);
            draw(p,right1,oth,right2,right2[strlen(right2)-1]);
        }
    }
}
void insert(nodeep_t *queue,nodep_t cur){
    nodeep_t newNode = createe(cur);
    if((*queue)==NULL){
        (*queue)=newNode;
    }
    else{
        newNode->next=(*queue);
        (*queue)=newNode;
    }
}
void print(nodep_t c){
    nodeep_t queue=NULL,pre,cur;
    insert(&queue,c);
    while(queue!=NULL){
        cur=pre=queue;
        while(cur->next!=NULL){//找到最後一個值
            pre=cur;
            cur=cur->next;
        }
        if((cur->data)->left!=NULL){insert(&queue,(cur->data)->left);}//如果左節點有資料就加入佇列
        if((cur->data)->right!=NULL){insert(&queue,(cur->data)->right);}//如果右節點有資料就加入佇列
        printf("%c",(cur->data)->data);//印出目前佇列的最後一個值
        if(cur!=pre){//pop
            pre->next=NULL;
            free(cur);
        }
        else{//一開始佇列剩下一個值
            cur=pre=queue;
            while(cur->next!=NULL){//看他是否依舊剩一個值(可能加入左右節點)
                pre=cur;
                cur=cur->next;
            }
            if(cur!=pre){//有左右節點->free掉最後
                pre->next=NULL;
                free(cur);
            }
            else{
                queue=NULL;//沒有左右節點->跳出迴圈
            }
        }
    }
}
int main(){
    nodep_t p=NULL,cur;
    char mid,str1[20],oth,str2[20],top;
    for(int i=0;i<20;i++){
        str1[i]=0;
        str2[i]=0;
    }
    scanf(" %c",&mid);
    if(mid=='I'){
        scanf(" %s",str1);
        scanf(" %c",&oth);
        scanf(" %s",str2);
    }
    else{
        oth=mid;
        scanf(" %s",str2);
        scanf(" %c",&mid);
        scanf(" %s",str1);
    }
    top=FindTop(&p,oth,str2);
    cur=p;
    draw(&p,str1,oth,str2,top);
    print(cur);
}
