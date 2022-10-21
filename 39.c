#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[20];
    int age,year,month,day;
    struct node* next;
}node_t;
typedef node_t* nodep_t;
nodep_t create(char name[20],int a,int y,int m,int d){
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    strcpy(newNode->name,name);
    newNode->age=a;
    newNode->year=y;
    newNode->month=m;
    newNode->day=d;
    newNode->next=NULL;
    return newNode;
}
void in(nodep_t *p,char name[20],int a,int y,int m,int d){
    nodep_t newNode=create(name,a,y,m,d);
    if((*p)==NULL){(*p)=newNode;}
    else{
        newNode->next=(*p);
        (*p)=newNode;
    }
}
void dequeue(nodep_t *p,int d,int c){
    if((*p)==NULL)printf("The Queue is empty\n");
    else{
        nodep_t cur,pre;
        if(c==3){
            while((*p)!=NULL){
                cur=pre=*p;
                if((*p)->next==NULL){
                    printf("%s %d %d_%d_%d\n",cur->name,cur->age,cur->year,cur->month,cur->day);
                    free(*p);
                    (*p)=NULL;
                }
                else{
                    while(cur->next!=NULL){
                        pre=cur;
                        cur=cur->next;
                    }
                    printf("%s %d %d_%d_%d\n",cur->name,cur->age,cur->year,cur->month,cur->day);
                    pre->next=NULL;
                    free(cur);
                }
            }
        }
        else{
            cur=pre=*p;
            while(cur->next!=NULL){
                pre=cur;
                cur=cur->next;
            }
            if(d==1){printf("%s\n",cur->name);}
            else if(d==2){printf("%d\n",cur->age);}
            else{printf("%d_%d_%d\n",cur->year,cur->month,cur->day);}
            if((*p)->next==NULL){
                free(*p);
                (*p)=NULL;
            }
            else{
                pre->next=NULL;
                free(cur);
            }
        }
    }
}
void print(nodep_t p){
    if(p==NULL)printf("The Queue is empty\n");
    else{
        nodep_t tar=NULL,cur;
        while(p!=tar){
            cur=p;
            while(cur->next!=tar){cur=cur->next;}
            printf("%s %d %d_%d_%d\n",cur->name,cur->age,cur->year,cur->month,cur->day);
            tar=cur;
        }
    }
}
int count(nodep_t p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int main(){
    nodep_t p=NULL;
    int com,a,y,m,d,deq,flag=0;
    char n[20];
    while(1){
        scanf(" %d",&com);
        switch(com){
            case 1:
                scanf(" %s %d %d %d %d",n,&a,&y,&m,&d);
                in(&p,n,a,y,m,d);
                break;
            case 2:
                scanf(" %d",&deq);
                dequeue(&p,deq,com);
                break;
            case 3:
                dequeue(&p,deq,com);
                break;
            case 4:
                print(p);
                break;
            case 5:
                flag=1;
                printf("%d",count(p));
                break;
        }
        if(flag==1)break;
    }
}
