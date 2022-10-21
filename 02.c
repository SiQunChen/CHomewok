#include<stdio.h>
int main() {
    char x;
    int x1=0,x2=0,x3=0;
    for(int i=1;i<=5;i++){
        scanf(" %c",&x);
        if(x=='1'){
            x3=x2;
            x2=x1;
            x1=1;
        }
        else if(x=='2'){
            x3=x1;
            x2=1;
            x1=0;
        }
        else if(x=='3'){
            x3=1;
            x2=0;
            x1=0;
        }
        else if(x=='H'){
            x3=0;
            x2=0;
            x1=0;
        }
    }
    printf("%d\n",x1);
    printf("%d\n",x2);
    printf("%d\n",x3);
    return 0;
}
