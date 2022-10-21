#include<stdio.h>
#include<string.h>
int main(){
    char seq[100],temp[20];
    int len=0,seq_len=0,count=0,stop=0;
    scanf(" %s",seq);
    scanf(" %d",&len);
    seq_len=strlen(seq);
    for(int i=0;i<seq_len-len+1;i++){
        stop=0;
        for(int j=0;j<len;j++){
            temp[j]=0;
        }
        for(int j=i;j<i+len;j++){
            temp[j]=seq[j];
            for(int k=i;k<j;k++){
                if(temp[k]==temp[j]){
                    stop=1;
                    break;
                }
                else if(temp[k]!=temp[j] && j==(i+len-1) && k==(j-1)){
                    count+=1;
                }
                else{
                    continue;
                }
            }
            if(stop==1){
                break;
            }
        }
    }
    if(len==1){
        printf("%d",seq_len);
    }
    else{
        printf("%d",count);
    }
}
