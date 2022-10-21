#include<stdio.h>
int main(){
    int choose,number,a=0;
    scanf(" %d",&choose);
    scanf(" %d",&number);
    if(choose==1){
        for(int i=1;i<number+1;i++){
            a=1;
            two(a,i);
            printf("\n");
        }
        for(int i=number;i>0;i--){
            a=2;
            two(a,i);
            printf("\n");
        }
        for(int i=1;i<number+1;i++){
            a=3;
            two(a,i);
            if(number!=i){
            printf("\n");
        }
        }
    }
    else{
        for(int i=1;i<number+1;i++){
            a=4;
            two(a,i,number);
            printf("\n");
        }
        for(int i=1;i<number;i++){
            a=5;
            two(a,i,number);
            printf("\n");
        }
        for(int i=number-1;i>0;i--){
            a=6;
            two(a,i,number);
            if(i!=1){
                printf("\n");
            }
        }
    }
}
void two(int a,int i,int number){
    if(a==1){
        for(int j=1;j<i+1;j++){
            printf("%d",j);
        }
    }
    else if(a==2){
        for(int j=1;j<i+1;j++){
            printf("%d",i+1-j);
        }
    }
    else if(a==3){
        for(int j=1;j<i+1;j++){
            printf("%d",i);
        }
    }
    else if(a==4){
        for(int j=1;j<i+1;j++){
            printf("%d",j);
        }
        for(int j=i-1;j>0;j--){
            printf("%d",j);
        }
    }
    else if(a==5){
        for(int j=number-1;j>0;j--){
            if(j<=i){
                printf("%d",j);
            }
            else{
                printf("_");
            }
        }
        for(int j=2;j<number;j++){
            if(j<=i){
                printf("%d",j);
            }
            else{
                printf("_");
            }
        }
    }
    else{
        for(int j=number-1;j>0;j--){
            if(j<=i){
                printf("%d",j);
            }
            else{
                printf("_");
            }
        }
        for(int j=2;j<number;j++){
            if(j<=i){
                printf("%d",j);
            }
            else{
                printf("_");
            }
        }
    }
}
