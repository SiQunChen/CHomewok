#include<stdio.h>
#include<string.h>
void swap(char a[50],char b[50]){
    char temp[50];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}
void sort(char str[50][50]){
    char count[50][50],sortt[50][50],sorttt[50][50];
    int cou[50],len=0,flag=0,flag2=0;
    for(int i=0;i<50;i++){
        cou[i]=0;
        for(int j=0;j<50;j++){
            count[i][j]=0;
        }
    }
    for(int i=0;i<50;i++){
        if(str[i][0]==0){
                break;
        }
        for(int j=0;j<50;j++){
            if(strncmp(count[j],str[i],50)==0){
                cou[j]+=1;
                flag=1;
            }
        }
        if(flag==0){
            strcpy(count[len],str[i]);
            cou[len]+=1;
            len++;
        }
        flag=0;
    }
    for(int i=0;i<50;i++){
        if(count[i]==0)break;
        else{

        }
    }
    for(int i=20;i>0;i--){
        flag=0;
        for(int k=0;k<50;k++){
            for(int j=0;j<50;j++){
                sortt[k][j]=0;
            }
        }
        for(int j=0;j<50;j++){
            if(count[j]==0)break;
            if(cou[j]==i){
                strcpy(sortt[flag],count[j]);
                flag++;
            }
        }
        if(flag>1){
            for(int j=1;j<20;j++){
                flag2=0;
                for(int k=0;k<50;k++){
                    for(int j=0;j<50;j++){
                        sorttt[k][j]=0;
                    }
                }
                for(int k=0;k<flag;k++){
                    if(strlen(sortt[k])==j){
                        strcpy(sorttt[flag2],sortt[k]);
                        flag2++;
                    }
                }
                if(flag2>1){
                    for(int j=0;j<flag2;j++){
                        for(int k=j;k<flag2;k++){
                            if(strncmp(sorttt[j],sorttt[k],50)>0){
                                swap(sorttt[j],sorttt[k]);
                            }
                        }
                    }
                    for(int j=0;j<flag2;j++){
                        printf("%s %d\n",sorttt[j],i);
                    }
                }
                else if(flag2==1){
                    printf("%s %d\n",sorttt[0],i);
                }
            }
        }
        else if(flag==1){
            printf("%s %d\n",sortt[0],i);
        }
    }
}
void del(char str[50][50],char p[50],char q[50]){
    for(int i=0;i<50;i++){
        if(strncmp(str[i],p,50)!=0){
            printf("%s ",str[i]);
        }
    }
    printf("\n");
}
void insert(char str[50][50],char p[50],char q[50]){
    for(int i=0;i<50;i++){
        if(strncmp(str[i],p,50)==0){
            printf("%s %s ",q,str[i]);
        }
        else{
            printf("%s ",str[i]);
        }
    }
    printf("\n");
}
void replace(char str[50][50],char p[50],char q[50]){
    for(int i=0;i<50;i++){
        if(strncmp(str[i],p,50)==0){
            printf("%s ",q);
        }
        else{
            printf("%s ",str[i]);
        }
    }
    printf("\n");
}
void split(char temp[500],char str[50][50]){
    int len=0;
    char *space=" ";
    char *pch;
    pch=strtok(temp,space);
    while(pch!=NULL){
        strcpy(str[len],pch);
        len++;
        pch=strtok(NULL,space);
    }
}
int main(){
    char temp[500],str[50][50],p[50],q[50];
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            str[i][j]=0;
        }
    }
    gets(temp);
    split(temp,str);
    scanf(" %s",p);
    scanf(" %s",q);
    replace(str,p,q);
    insert(str,p,q);
    del(str,p,q);
    sort(str);
}
