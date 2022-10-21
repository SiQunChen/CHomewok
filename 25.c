#include<stdio.h>
#include<string.h>
int main(){
    int k,len=0;
    char str[100];
    for(int i=0;i<100;i++){
        str[i]=0;
    }
    scanf(" %d",&k);
    scanf(" %s",str);
    for(int i=0;i<strlen(str);i++){
        if(len==strlen(str))break;
        for(int j=i;j<strlen(str);j++){
            if(str[j]>='a' && str[j]<='z'){
                if((j+1-i)%k==0 && str[j+1]>='a' && str[j+1]<='z'){
                    if((j+1-i)>len)len=j+1-i;
                    break;
                }
                else if((j+1-i)%k!=0 && str[j+1]>='A' && str[j+1]<='Z'){
                    if((j+1-i)-((j+1-i)%k)>len)len=(j+1-i)-((j+1-i)%k);
                    break;
                }
            }
            else if(str[j]>='A' && str[j]<='Z'){
                if((j+1-i)%k==0 && str[j+1]>='A' && str[j+1]<='Z'){
                    if((j+1-i)>len)len=j+1-i;
                    break;
                }
                else if((j+1-i)%k!=0 && str[j+1]>='a' && str[j+1]<='z'){
                    if((j+1-i)-((j+1-i)%k)>len)len=(j+1-i)-((j+1-i)%k);
                    break;
                }
            }
            if(j+1==strlen(str)){
                if((j+1-i)%k==0 && (j+1-i)>len)len=(j+1-i)-((j+1-i)%k);
                else if((j+1-i)<k)len=len;
                else if((j+1-i)%k!=0 && (j+1-i)>len)len=(j+1-i)-((j+1-i)%k);
            }
        }
    }
    printf("%d",len);
}
