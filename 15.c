#include<stdio.h>
int main(){
    int choose,len,len1,add=0,del=0,big=0,car=0;
    char number1[200],number2[200],ans[200],temp[200];
    for(int i=0;i<200;i++){
        ans[i]=0;
    }
    scanf(" %d",&choose);
    scanf(" %s",&number1);
    scanf(" %s",&number2);
    if(strlen(number1)>=strlen(number2)){
        len=strlen(number1);
        len1=strlen(number2);
    }
    else{
        len=strlen(number2);
        len1=strlen(number1);
        big=1;
    }
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
    switch(choose){
    case 1:
    for(int i=199;i>=0;i--){
        if(add==0){
            ans[i]=number1[i]-48+number2[i]-48;
        }
        else{
            ans[i]=number1[i]-48+number2[i]-48+1;
            add=0;
        }
        if(ans[i]>=10){
            add=1;
            ans[i]%=10;
        }
    }
    if(ans[200-len-1]!=0){
        for(int i=200-len-1;i<200;i++){
            printf("%d",ans[i]);
        }
    }
    else{
        for(int i=200-len;i<200;i++){
            printf("%d",ans[i]);
        }
    }
    break;
    case 2:
    if(big==1){
        for(int i=0;i<200;i++){
            temp[i]=number1[i];
            number1[i]=number2[i];
            number2[i]=temp[i];
        }
        printf("-");
    }
    for(int i=199;i>=0;i--){
        if(add==0){
            ans[i]=number1[i]-number2[i];
        }
        else{
            ans[i]=number1[i]-number2[i]-1;
            add=0;
        }
        if(ans[i]<0){
            add=1;
            ans[i]+=10;
        }
    }
    if(ans[200-len-1]!=0){
        for(int i=200-len-1;i<200;i++){
            if(del==0 && ans[i]==0){
                continue;
            }
            else{
                del=1;
                printf("%d",ans[i]);
            }
        }
    }
    else{
        for(int i=200-len;i<200;i++){
            if(del==0 && ans[i]==0 && i!=199){
                continue;
            }
            else{
                del=1;
                printf("%d",ans[i]);
            }
        }
    }
    break;
    case 3:
    for(int i=199;i>=100;i--){
        for(int j=199;j>=100;j--){
            temp[j]=(number1[j]-48)*(number2[i]-48)+car;
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
    for(int i=200-len-len1;i<200;i++){
        if(del==0 && ans[i]==0 && i!=199){
            continue;
        }
        else{
            del=1;
            printf("%d",ans[i]);
        }
    }
    break;
    }
}
