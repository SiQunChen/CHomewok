#include<stdio.h>
#include<string.h>
int main(){
    int len=0,len1=0,big=0;
    char number1[200],number2[200],ans[200];
    for(int i=0;i<200;i++){
        ans[i]=0;
        number1[i]=0;
        number2[i]=0;
    }
    scanf(" %s",number1);
    scanf(" %s",number2);
    len=strlen(number2);
    len1=strlen(number1);
    for(int i=len-1;i<199;i++){
        if(number1[i]>=48){
            while(1){
                for(int j=i-len+1;j<=i;j++){
                    if(number1[j]>number2[j-(i-len+1)]){
                        big=0;
                        break;
                    }
                    else if(number1[j]<number2[j-(i-len+1)]){
                        big=1;
                        if(number1[i-len+1]!=0){
                            number1[i-len+2]+=(number1[i-len+1]-48)*10;
                        }
                        break;
                    }
                    else if(number1[j]==number2[j-(i-len+1)] && j==i){
                        big=0;
                        break;
                    }
                    else{
                        continue;
                    }
                }
                if(big==0){
                    ans[i-len+1]+=1;
                    for(int j=i;j>i-len;j--){
                        if(number1[j]>=number2[j-(i-len+1)]){
                            number1[j]=number1[j]-number2[j-(i-len+1)]+48;
                        }
                        else{
                            number1[j]=number1[j]-number2[j-(i-len+1)]+58;
                            number1[j-1]-=1;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    for(int i=0;i<len1-len+1;i++){
        if(ans[i]==0 && i==0){
            continue;
        }
        else{
            printf("%d",ans[i]);
        }
    }
}
