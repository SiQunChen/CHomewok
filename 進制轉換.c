#include<stdio.h>
int main(){
    int input,output,len=0,ten=0,temp,a=0;
    char number[10],ans[20];
    for(int i=0;i<10;i++){
        number[i]=0;
        ans[i]=0;
    }
    scanf(" %d",&input);
    scanf(" %d",&output);
    scanf(" %s",number);
    for(int i=0;i<10;i++){
        if(number[i]>47){
            len+=1;
            number[i]-=48;
        }
        else{
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        ten+=number[len-i-1]*pow(input,i);
    }
    for(int i=10;i>=0;i--){
        ans[i]=ten/pow(output,i);
        temp=pow(output,i);
        ten%=temp;
    }
    for(int i=10;i>=0;i--){
        if(ans[i]==0 && a==0){
            continue;
        }
        else{
            a=1;
            printf("%d",ans[i]);
        }
    }
}
