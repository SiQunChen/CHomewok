#include<stdio.h>
#include <string.h>
int compare(char *a,char *b){
    for (;(*a!='\0')&&(*b!='\0');a++, b++) {
        if (*a>*b) return 0;
        else if (*a<*b) return 0;
    }
    if (*a!='\0') return 0;
    else if (*b!='\0') return 0;
    return 1;
}
int repeat(int a1,int a2,int b1,int b2,int ini,char str1[50][20]){
    int check[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<ini;i++)check[i]=1;
    for(int i=a1;i<a2;i++){
        for(int j=b1;j<b2;j++){
            if(compare(str1[i],str1[j])==1){
                return 0;
            }
        }
    }
    for(int i=a1;i<a2;i++){
        int flag=0;
        for(int j=0;j<ini;j++){
            if(compare(str1[i],str1[j])==1){
                check[j]=0;
                flag=1;
            }
        }
        if(flag==0)return 0;
    }
    for(int i=b1;i<b2;i++){
        int flag=0;
        for(int j=0;j<ini;j++){
            if(compare(str1[i],str1[j])==1){
                check[j]=0;
                flag=1;
            }
        }
        if(flag==0)return 0;
    }
    for(int i=0;i<20;i++){
        if(check[i]==1)return 0;
    }
    return 1;
}
void split(char a[50],char b[50][20],int *c){
    char *space = " ";
    char * pch;
    pch = strtok(a,space);
    while (pch != NULL) {
        strcpy(b[*c], pch);
        (*c)++;
        pch = strtok (NULL, space);
    }
}
int main(){
    int id=0,*len=&id,time,ans=0,len1[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},score=0;
    char str[20][50],str1[50][20];
    gets(str[0]);
    split(str[0],str1,len);
    len1[1]=id;
    scanf(" %d",&time);
    getchar();
    for(int i=0;i<time;i++){
        gets(str[i+1]);
        split(str[i+1],str1,len);
        len1[i+2]=id;
    }
    for(int i=1;i<20;i++){
        if(len1[i+1]==0)break;
        else{
            for(int j=i+1;j<20;j++){
                if(len1[j+1]==0)break;
                else{
                    score+=repeat(len1[i],len1[i+1],len1[j],len1[j+1],len1[1],str1);
                }
            }
        }
    }
    printf("%d",score);
}
