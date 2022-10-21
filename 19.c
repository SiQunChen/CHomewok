#include<stdio.h>
#include<string.h>
int main(){
    char exp[200];
    int wid,time=1,add_i=0,add_j=0,len=0,draw[30][30];
    scanf(" %s",exp);
    scanf(" %d",&wid);
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            draw[i][j]=0;
        }
    }
    if(exp[0]=='0'){
        printf("all white");
    }
    else if(exp[0]=='1'){
        for(int i=0;i<wid;i++){
            for(int j=0;j<wid;j++){
                printf("%d,%d\n",i,j);
            }
        }
    }
    else{
        split(exp,wid,time,add_i,add_j,draw);
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                if(draw[i][j]==1){
                    printf("%d,%d\n",i,j);
                }
            }
        }
    }
}

int split(char exp[],int wid,int time,int add_i,int add_j,int draw[30][30]){
    for(int k=0;k<4;k++){
        if(exp[time]=='1'){
            time+=1;
            ans(k,wid,time,add_i,add_j,draw);
        }
        else if(exp[time]=='2'){
            time+=1;
            if(k==2 || k==3){
                add_i+=wid/2;
            }
            if(k==1 || k==3){
                add_j+=wid/2;
            }
            time=split(exp,wid/2,time,add_i,add_j,draw);
            if(k==2 || k==3){
                add_i-=wid/2;
            }
            if(k==1 || k==3){
                add_j-=wid/2;
            }
        }
        else{
            time+=1;
        }
    }
    return time;
}

void ans(int k,int wid,int time,int add_i,int add_j,int draw[30][30]){
    switch(k){
    case 0:
        for(int i=0;i<wid/2;i++){
            for(int j=0;j<wid/2;j++){
                draw[i+add_i][j+add_j]=1;
            }
        }
        break;
    case 1:
        for(int i=0;i<wid/2;i++){
            for(int j=wid/2;j<wid;j++){
                draw[i+add_i][j+add_j]=1;
            }
        }
        break;
    case 2:
        for(int i=wid/2;i<wid;i++){
            for(int j=0;j<wid/2;j++){
                draw[i+add_i][j+add_j]=1;
            }
        }
        break;
    case 3:
        for(int i=wid/2;i<wid;i++){
            for(int j=wid/2;j<wid;j++){
                draw[i+add_i][j+add_j]=1;
            }
        }
        break;
    }
}
