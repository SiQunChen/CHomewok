#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ctrl(char str[100],char command[100]){
    int i=0,cursor=0;
    char temp;
    while(command[i]!=0){
        switch(command[i]){
            case '0':
                cursor=0;
                break;
            case '$':
                cursor=strlen(str);
                break;
            case 'x':
                if(cursor!=strlen(str)){
                    for(int j=cursor;j<=strlen(str);j++){
                        str[j]=str[j+1];
                    }
                }
                break;
            case 's':
                if(cursor!=strlen(str) || cursor!=strlen(str)-1){
                    temp=str[cursor];
                    str[cursor]=str[cursor+1];
                    str[cursor+1]=temp;
                }
                break;
            case 'i':
                for(int j=strlen(str);j>=cursor;j--){
                    str[j+1]=str[j];
                    if(j==cursor){
                        str[j]=command[i+1];
                    }
                }
                cursor++;
                i++;
                break;
            case 'u':
                if(str[cursor]>='a' && str[cursor]<='z'){
                    str[cursor]-=32;
                    cursor++;
                }
                else cursor++;
                break;
            case '+':
                cursor++;
                break;
            case '-':
                cursor--;
                break;
        }
        i++;
    }
    for(int i=0;i<100;i++){
        if(str[i]!=0)printf("%c",str[i]);
    }
}
int main(){
    char str[100],command[100];
    for(int i=0;i<100;i++){
        str[i]=0;
        command[i]=0;
    }
    gets(str);
    gets(command);
    ctrl(str,command);
}
