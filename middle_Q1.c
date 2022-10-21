#include<stdio.h>
int main(){
    int choose,number;
    scanf(" %d",&choose);
    switch(choose){
    case 1:
        scanf(" %d",&number);
        for(int i=1;i<number+1;i++){
            for(int j=1;j<i+1;j++){
                printf("%d",j);
            }
            printf("\n");
        }
        for(int i=number;i>0;i--){
            for(int j=1;j<i+1;j++){
                printf("%d",i+1-j);
            }
            printf("\n");
        }
        for(int i=1;i<number+1;i++){
            for(int j=1;j<i+1;j++){
                printf("%d",i);
            }
            if(number!=i){
                printf("\n");
            }
        }
        break;
    case 2:
        scanf(" %d",&number);
        for(int i=1;i<number+1;i++){
            for(int j=1;j<i+1;j++){
                printf("%d",j);
            }
            for(int j=i-1;j>0;j--){
                printf("%d",j);
            }
            printf("\n");
        }
        for(int i=1;i<number;i++){
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
            printf("\n");
        }
        for(int i=number-1;i>0;i--){
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
            if(i!=1){
                printf("\n");
            }
        }
        break;
    }
}
