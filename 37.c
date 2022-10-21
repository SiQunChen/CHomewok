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
void insertFromFront(nodep_t *p, int data) {
    nodep_t newNode = create(data);
    if ((*p)==NULL) {
        (*p) = newNode;
    }
    else {
        newNode->next = (*p);
        (*p) = newNode;
    }
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
void printList(nodep_t p,int l){
    int len,flag=0;
    len=l-1;
    if(p==NULL)printf("None any node");
    else{
        while (p!=NULL){
            if(p->data!=0){
                if(len>1){
                    if(p->data==1){
                        if(len!=l-1)printf("+x^%d",len--);
                        else printf("x^%d",len--);
                        p = p->next;
                    }
                    else if(p->data==-1){
                        printf("-x^%d",len--);
                        p = p->next;
                    }
                    else if(p->data<0 ||(len==l-1 && p->data!=0)){
                        printf("%dx^%d",p->data,len--);
                        p = p->next;
                    }
                    else if(p->data>0){
                        printf("+%dx^%d",p->data,len--);
                        p = p->next;
                    }
                }
                else if(len==1){
                    if(p->data==1){
                        printf("+x");
                        p = p->next;
                    }
                    else if(p->data==-1){
                        printf("-x");
                        p = p->next;
                    }
                    else if(p->data>0){
                        printf("+%dx",p->data);
                        p = p->next;
                    }
                    else if(p->data<0){
                        printf("%dx",p->data);
                        p = p->next;
                    }
                    len--;
                }
                else{
                    if(p->data<0 || flag==0){
                        printf("%d\n",p->data);
                        p = p->next;
                    }
                    else if(p->data>0){
                        printf("+%d\n",p->data);
                        p = p->next;
                    }
                }
                flag=1;
            }
            else if(len<1 && flag==1){
                printf("\n");
                p = p->next;
                len--;
            }
            else{
                p = p->next;
                len--;
            }
        }
        if(flag==0)printf("0\n");
    }
}
void add(int A,int B,int f,int len,nodep_t *a){
    if(f==1){
        printList((*a),len);
    }
    else{
        insertFromFront(a,A+B);
    }
}
void sub(int A,int B,int f,int len,nodep_t *s){
    if(f==1){
        printList((*s),len);
    }
    else{
        insertFromFront(s,A-B);
    }
}
void pro(int B,int f,int len,nodep_t *p,nodep_t pA,int lenA,int j){
    int A;
    nodep_t cur;
    cur=*p;
    if(f==1){
        printList((*p),len);
    }
    else{
        if(j==0){
            for(int i=0;i<lenA;i++){
                A=pA->data;
                insertFromBack(p,A*B);
                pA=pA->next;
            }
        }
        else{
            A=pA->data;
            insertFromFront(p,A*B);
            pA=pA->next;
            for(int i=0;i<lenA-1;i++){
                A=pA->data;
                cur->data+=A*B;
                cur=cur->next;
                pA=pA->next;
            }
        }
    }
}
void pr(nodep_t pA,int lenA,nodep_t pB,int lenB){
    int B,flag=0,len,i=0;
    nodep_t pre,cur,p=NULL;
    len=lenA+lenB-1;
    while(pB!=NULL){
        pre=cur=pB;
        if(pre->next==NULL){
            B=pre->data;
            free(pre);
            pB=NULL;
            pro(B,flag,len,&p,pA,lenA,i);
        }
        else{
            while(pre->next!=NULL){
                if(cur->next==NULL){
                    B=cur->data;
                    pre->next=NULL;
                    free(cur);
                    pro(B,flag,len,&p,pA,lenA,i);
                    i++;
                }
                else{
                    pre = cur;
                    cur = cur->next;
                }
            }
        }
    }
    flag=1;
    pro(B,flag,len,&p,pA,lenA,i);
}
void ope(nodep_t pA,int lenA,nodep_t pB,int lenB){
    int A,B,flag=0,len;
    nodep_t pre1,cur1,pre2,cur2,a=NULL,s=NULL;
    if(lenA>=lenB)len=lenA;
    else len=lenB;
    while(pA!=NULL && pB!=NULL){
        pre1=cur1=pA;
        pre2=cur2=pB;
        if(pre1->next==NULL){
            A=pre1->data;
            free(pre1);
            pA=NULL;
        }
        else{
            while(pre1->next!=NULL){
                if(cur1->next==NULL){
                    A=cur1->data;
                    pre1->next=NULL;
                    free(cur1);
                }
                else{
                    pre1 = cur1;
                    cur1 = cur1->next;
                }
            }
        }
        if(pre2->next==NULL){
            B=pre2->data;
            free(pre2);
            pB=NULL;
        }
        else{
            while(pre2->next!=NULL){
                if(cur2->next==NULL){
                    B=cur2->data;
                    pre2->next=NULL;
                    free(cur2);
                }
                else{
                    pre2 = cur2;
                    cur2 = cur2->next;
                }
            }
        }
        add(A,B,flag,len,&a);
        sub(A,B,flag,len,&s);
    }
    while(pA!=NULL){
        pre1=cur1=pA;
        if(pre1->next==NULL){
            A=pre1->data;
            free(pre1);
            pA=NULL;
        }
        else{
            while(pre1->next!=NULL){
                if(cur1->next==NULL){
                    A=cur1->data;
                    pre1->next=NULL;
                    free(cur1);
                }
                else{
                    pre1 = cur1;
                    cur1 = cur1->next;
                }
            }
        }
        add(A,0,flag,len,&a);
        sub(A,0,flag,len,&s);
    }
    while(pB!=NULL){
        pre2=cur2=pB;
        if(pre2->next==NULL){
            B=pre2->data;
            free(pre2);
            pB=NULL;
        }
        else{
            while(pre2->next!=NULL){
                if(cur2->next==NULL){
                    B=cur2->data;
                    pre2->next=NULL;
                    free(cur2);
                }
                else{
                    pre2 = cur2;
                    cur2 = cur2->next;
                }
            }
        }
        add(0,B,flag,len,&a);
        sub(0,B,flag,len,&s);
    }
    flag=1;
    add(0,0,flag,len,&a);
    sub(0,0,flag,len,&s);
}
void split(char str[20],nodep_t *p,int *len,nodep_t *p1){
    int data;
    char *space = " ";
    char * pch;
    pch = strtok(str,space);
    while (pch != NULL) {
        data=atoi(pch);
        insertFromBack(p,data);
        insertFromBack(p1,data);
        pch = strtok (NULL, space);
        (*len)++;
    }
}
int main(){
    nodep_t p1=NULL,p2=NULL,p3=NULL,p4=NULL;
    int lenA=0,lenB=0;
    char A[20],B[20];
    for(int i=0;i<20;i++){
        A[i]=0;
        B[i]=0;
    }
    gets(A);
    gets(B);
    split(A,&p1,&lenA,&p3);
    split(B,&p2,&lenB,&p4);
    ope(p1,lenA,p2,lenB);
    pr(p3,lenA,p4,lenB);
}
