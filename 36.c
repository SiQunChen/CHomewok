#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node_t;
typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}
void insertFromBack(nodep_t *p, int data) {
    nodep_t current;
    nodep_t newNode = create(data);
    if ((*p)==NULL) {
        (*p) = newNode;
    }
    else {
        current = (*p);
        while (current->next!=NULL)
            current = current->next;
        current->next = newNode;
    }
}
void insertBehindKey(nodep_t *p, int key, int data) {
    nodep_t newp;
    if((*p) != NULL){
        if (((*p)->data) == key) {
            newp = create(data);
            newp->next = (*p)->next;
            (*p)->next = newp;
            newp->data = data;
        }
        else {
            insertBehindKey(&(*p)->next, key, data);
        }
    }
}
void deleteKey(nodep_t *p,int key){
    nodep_t previous, current;
    previous = current = (*p);
    if ((current->data) == key) {
        (*p) = (*p)->next;
        free(current);
    }
    else{
        while (current!=NULL) {
            if ((current->data) == key) {
                previous->next = current->next;
                free(current);
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    }
}
void deleteini(nodep_t *p){
    if((*p)!=NULL){
        nodep_t initial;
        initial = (*p);
        (*p) = (*p)->next;
        free(initial);
    }
}
void deletefin(nodep_t *p){
    if((*p)!=NULL){
        if((*p)->next==NULL){
            (*p)=NULL;
        }
        else{
            nodep_t fin,nu;
            nu = fin = (*p);
            while ((nu->next)!=NULL) {
                fin = nu;
                nu = nu->next;
            }
            fin->next = NULL;
            free(nu);
        }
    }
}
void printList(nodep_t *p){
    if((*p)==NULL)printf("None any node");
    else{
        while ((*p)!=NULL){
            printf("%d ",(*p)->data);
            (*p) = (*p)->next;
        }
    }
}

int main(){
    int a,data,ctrl,one,two1,two2,three,flag=0;
    nodep_t p=NULL;
    scanf(" %d",&a);
    for(int i=0;i<a;i++){
        scanf(" %d",&data);
        insertFromBack(&p,data);
    }
    while(1){
        scanf(" %d",&ctrl);
        switch(ctrl){
            case 1:
                scanf(" %d",&one);
                insertFromBack(&p,one);
                break;
            case 2:
                scanf(" %d",&two1);
                scanf(" %d",&two2);
                insertBehindKey(&p,two1,two2);
                break;
            case 3:
                scanf(" %d",&three);
                deleteKey(&p,three);
                break;
            case 4:
                deleteini(&p);
                break;
            case 5:
                deletefin(&p);
                break;
            case 6:
                flag=1;
                break;
        }
        if(flag==1){
            break;
        }
    }
    printList(&p);
}
