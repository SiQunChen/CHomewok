#include<stdio.h>
#include<math.h>
int main(){
    int len=0,ans=0;
    char num[30],ans7[10];
    scanf(" %s",num);
    for(int i=0;i<15;i++){
        if(num[i]>=48){
            len+=1;
            num[i]-=48;
        }
        else{
            break;
        }
    }
    for(int i=0;i<len;i++){
        if(num[i]>1){
            printf("ERROR");
            return 0;
        }
    }
    for(int i=0;i<len;i++){
        ans+=num[i]*pow(2,len-1-i);
    }
    for(int i=0;i<10;i++){
        if(ans<7){
            len=i;
            ans7[i]=ans;
            break;
        }
        else{
            ans7[i]=ans%7;
            ans/=7;
        }
    }
    for(int i=len;i>=0;i--){
        printf("%d",ans7[i]);
    }
}
