#include<stdio.h>
int gcd(int up,int down){
    int a;
    while(up%down!=0){
        a=down;
        down=up%down;
        up=a;
    }
    return down;
}
void change(int up,int down){
    if(abs(up)<abs(down)){
        if((down<0 && up>0) || (down>0 && up<0)){
            printf("-%d/%d\n",abs(up),abs(down));
        }
        else{
            printf("%d/%d\n",abs(up),abs(down));
        }
    }
    else if(abs(up)>abs(down)){
        if((down<0 && up>0) || (down>0 && up<0)){
            printf("-%d(%d/%d)\n",abs(up)/abs(down),abs(up)%abs(down),abs(down));
        }
        else{
            printf("%d(%d/%d)\n",abs(up)/abs(down),abs(up)%abs(down),abs(down));
        }
    }
}
int main(){
    char sym,choose;
    int up_a,up_b,down_a,down_b,up,down,temp;
    while(1){
        scanf(" %d/%d",&up_a,&down_a);
        scanf(" %d/%d",&up_b,&down_b);
        scanf(" %c",&sym);
        if(down_b==0 || down_a==0){
            printf("ERROR");
        }
        else{
            switch(sym){
            case '+':
                up=up_a*down_b+up_b*down_a;
                down=down_a*down_b;
                temp=gcd(up,down);
                up/=temp;
                down/=temp;
                change(up,down);
                break;
            case '-':
                up=up_a*down_b+up_b*down_a;
                down=down_a*down_b;
                temp=gcd(up,down);
                up/=temp;
                down/=temp;
                change(up,down);
                break;
            case '*':
                up=up_a*down_b+up_b*down_a;
                down=down_a*down_b;
                temp=gcd(up,down);
                up/=temp;
                down/=temp;
                change(up,down);
                break;
            case '/':
                up=up_a*down_b+up_b*down_a;
                down=down_a*down_b;
                temp=gcd(up,down);
                up/=temp;
                down/=temp;
                change(up,down);
                break;
            }
        }
        scanf(" %c",&choose);
        if(choose=='n')
            break;
    }
}
