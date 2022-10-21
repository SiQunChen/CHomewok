#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[20];
    int age,year,month,day;
    struct node* next;
}node_t;
typedef node_t * nodep_t;

nodep_t create(char name[20],int age,int year,int month,int day) {
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->year = year;
    newNode->month = month;
    newNode->day = day;
    newNode->next=NULL;
    return newNode;
}
void insertFromFront(nodep_t *stack,char name[20],int age,int year,int month,int day) {
    nodep_t newNode = create(name,age,year,month,day);
    if ((*stack)==NULL) {
        (*stack) = newNode;
    }
    else {
        newNode->next = (*stack);
        (*stack) = newNode;
    }
}
void pop(nodep_t *stack,int p,int com){
    if(*stack==NULL)printf("The Stack is empty\n");
    else{
        nodep_t temp;
        if(com==3){
            while(*stack!=NULL){
                temp=*stack;
                if((*stack)->next==NULL){
                    printf("%s %d %d_%d_%d\n",(*stack)->name,(*stack)->age,(*stack)->year,(*stack)->month,(*stack)->day);
                    *stack=NULL;
                }
                else{
                    printf("%s %d %d_%d_%d\n",(*stack)->name,(*stack)->age,(*stack)->year,(*stack)->month,(*stack)->day);
                    *stack=(*stack)->next;
                    free(temp);
                }
            }
        }
        else{
            temp=*stack;
            switch(p){
                case 1:
                    printf("%s\n",(*stack)->name);
                    break;
                case 2:
                    printf("%d\n",(*stack)->age);
                    break;
                case 3:
                    printf("%d_%d_%d\n",(*stack)->year,(*stack)->month,(*stack)->day);
                    break;
            }
            *stack=(*stack)->next;
            free(temp);
        }
    }
}
void print(nodep_t stack){
    if(stack==NULL)printf("The Stack is empty\n");
    else{
        while(stack!=NULL){
            printf("%s %d %d_%d_%d\n",stack->name,stack->age,stack->year,stack->month,stack->day);
            stack=stack->next;
        }
    }
}
int count(nodep_t stack){
    if(stack==NULL)return 0;
    else{
        int c=0;
        while(stack!=NULL){
            c++;
            stack=stack->next;
        }
        return c;
    }
}
int main(){
    nodep_t stack=NULL;
    char name[20];
    int command,p,age,year,month,day,flag=0;
    while(1){
        for(int i=0;i<20;i++)name[i]=0;
        scanf(" %d",&command);
        switch(command){
            case 1:
                scanf(" %s %d %d %d %d",name,&age,&year,&month,&day);
                insertFromFront(&stack,name,age,year,month,day);
                break;
            case 2:
                scanf(" %d",&p);
                pop(&stack,p,command);
                break;
            case 3:
                pop(&stack,p,command);
                break;
            case 4:
                print(stack);
                break;
            case 5:
                printf("%d\n",count(stack));
                flag=1;
                break;
        }
        if(flag==1)break;
    }
}
