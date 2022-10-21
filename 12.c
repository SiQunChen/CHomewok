#include <stdio.h>
int gcd(int a,int b){
    int temp;
    while(a%b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return b;
}
void change(int up,int down){
    if(abs(up)>abs(down) && up%down!=0){
        printf("%d(%d/%d)\n",up/down,abs(up%down),abs(down));
    }
    else if(abs(up)<abs(down) && up%down!=0){
        if(down<0)
            printf("-%d/%d\n",up,abs(down));
        else
            printf("%d/%d\n",up,down);
    }
    else{
        printf("%d\n",up);
    }
}
int main(){
    int a1,a2,b1,b2,ans_up,ans_down,gc;
    char judge,choose;
    while(1){
        scanf(" %d/%d",&a1,&a2);
        scanf(" %d/%d",&b1,&b2);
        scanf(" %c",&judge);
        if(a2==0 || b2==0){
            printf("ERROR\n");
        }
        else{
            switch(judge){
                case '+':
                    if(a2==b2){
                        ans_up=a1+b1;
                        gc=gcd(ans_up,a2);
                        ans_up=ans_up/gc;
                        ans_down=a2/gc;
                        change(ans_up,ans_down);
                    }
                    else{
                        ans_up=a1*b2+b1*a2;
                        ans_down=a2*b2;
                        gc=gcd(ans_up,ans_down);
                        ans_up=ans_up/gc;
                        ans_down=ans_down/gc;
                        change(ans_up,ans_down);
                    }
                    break;
                case '-':
                    if(a2==b2){
                        ans_up=a1-b1;
                        gc=gcd(ans_up,a2);
                        ans_up=ans_up/gc;
                        ans_down=a2/gc;
                        change(ans_up,ans_down);
                    }
                    else{
                        ans_up=a1*b2-b1*a2;
                        ans_down=a2*b2;
                        gc=gcd(ans_up,ans_down);
                        ans_up=ans_up/gc;
                        ans_down=ans_down/gc;
                        change(ans_up,ans_down);
                    }
                    break;
                case '*':
                    ans_up=a1*b1;
                    ans_down=a2*b2;
                    gc=gcd(ans_up,ans_down);
                    ans_up=ans_up/gc;
                    ans_down=ans_down/gc;
                    change(ans_up,ans_down);
                    break;
                case '/':
                    ans_up=a1*b2;
                    ans_down=a2*b1;
                    gc=gcd(ans_up,ans_down);
                    ans_up=ans_up/gc;
                    ans_down=ans_down/gc;
                    change(ans_up,ans_down);
                    break;
            }
        }
        scanf(" %c",&choose);
        if(choose=='n')
            break;
    }
}

