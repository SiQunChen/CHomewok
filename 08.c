#include<stdio.h>
int main(){
    int choose,line;
    scanf("%d",&choose);
    scanf("%d",&line);
    switch(choose){
    case 1:
        for(int i=1;i<(line/2+1);i++){
            for(int j=1;j<=i;j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=(line/2+1);i>0;i--){
            for(int j=1;j<=i;j++){
                printf("*");
            }
            printf("\n");
        }
        break;
    case 2:
        for(int i=1;i<=(line/2+1);i++){
            for(int j=1;j<=(line/2+1);j++){
                if(j<=((line/2+1)-i))
                    printf(".");
                else
                    printf("*");
            }
            printf("\n");
        }
        for(int i=(line/2);i>0;i--){
            for(int j=1;j<=(line/2+1);j++){
                if(j<=((line/2+1)-i))
                    printf(".");
                else
                    printf("*");
            }
            printf("\n");
        }
        break;
    case 3:
        for(int i=1;i<=(line/2+1);i++){
            for(int j=1;j<=(line/2+i);j++){
               if(j<=((line/2+1)-i))
                    printf(".");
                else
                    printf("*");
            }
            printf("\n");
        }
        for(int i=(line/2);i>0;i--){
            for(int j=1;j<=(line/2+i);j++){
               if(j<=((line/2+1)-i))
                    printf(".");
                else
                    printf("*");
            }
            printf("\n");
        }
        break;
    }
}
