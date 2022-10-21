#include<stdio.h>
#include<string.h>
int main(){
    int finish=0,del=0,car=0,a=0;
    char number1[200],number2[200],ans[200],temp[200],time[200];
    for(int i=0;i<200;i++){
        time[i]=0;
    }
    scanf(" %s",&number1);
    scanf(" %s",&number2);
    for(int i=199;i>=0;i--){
        if((199-i)<strlen(number1)){
            number1[i]=number1[strlen(number1)-1-(199-i)];
        }
        else{
            number1[i]='0';
        }
    }
    for(int i=199;i>=0;i--){
        if((199-i)<strlen(number2)){
            number2[i]=number2[strlen(number2)-1-(199-i)];
        }
        else{
            number2[i]='0';
        }
    }
    while(1){
        for(int i=0;i<200;i++){
            ans[i]=0;
        }
        time[199]+=1;
        for(int i=199;i>=100;i--){
            if(time[i]>9){
                time[i]%=10;
                time[i-1]+=1;
            }
            else{
                break;
            }
        }
        for(int i=199;i>=100;i--){
            for(int j=199;j>=100;j--){
                temp[j]=time[j]*(number2[i]-48)+car;
                car=0;
                if(temp[j]>=10){
                    car=temp[j]/10;
                    ans[j+i-199]+=temp[j]%10;
                }
                else{
                    ans[j+i-199]+=temp[j];
                }
                if(ans[j+i-199]>9){
                    ans[j+i-199]%=10;
                    ans[j+i-200]+=1;
                }
            }
        }
        /*a=0;
        for(int i=100;i<200;i++){
            if(a==0 && ans[i]==0 && i!=199){
                continue;
            }
            else{
                a=1;
                printf("%d",time[i]);
            }
        }
        printf("\n");*/
        for(int i=100;i<200;i++){
            if(ans[i]>number1[i]-48){
                finish=1;
                for(int i=199;i>=100;i--){
                    if(time[i]>0){
                        time[i]-=1;
                        break;
                    }
                    else{
                        time[i]=9;
                    }
                }
                for(int j=100;j<200;j++){
                    if(time[j]==0 && del==0){
                        continue;
                    }
                    else{
                        del=1;
                        printf("%d",time[j]);
                    }
                }
                break;
            }
            else if(i==199 && ans[199]==(number1[199])-48){
                finish=1;
                for(int j=100;j<200;j++){
                    if(time[j]==0 && del==0){
                        continue;
                    }
                    else{
                        del=1;
                        printf("%d",time[j]);
                    }
                }
                break;
            }
            else if(ans[i]==(number1[i]-48)){
                continue;
            }
            else{
                break;
            }
        }
        if(finish==1){
            break;
        }
    }
}
