#include<stdio.h>
int compare(int min[20],int M){
    for(int i=0;i<500;i++){
        for(int j=0;j<M;j++){
            if(min[j]==i){
                return j;
            }
        }
    }
}
int main(){
    int N,M,P[20],infor[20][50],time[20][50],machine[20],flag=0,min[20],temp,ans=0,count[20];
    for(int i=0;i<20;i++){
        P[i]=0;
        count[i]=1;
        for(int j=0;j<50;j++){
            infor[i][j]=1000;
        }
    }
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        machine[i]=0;
    }
    for(int i=0;i<M;i++){
        scanf(" %d",&P[i]);
        for(int j=0;j<2*P[i];j++){
            scanf(" %d",&infor[i][j]);
        }
    }
    while(1){
        for(int i=0;i<20;i++)min[i]=1000;
        for(int i=0;i<M;i++){
            if(count[i]==1)min[i]=infor[i][1]+machine[infor[i][0]];
            else if((infor[i][count[i]]+machine[infor[i][count[i]-1]])<(time[i][count[i]-2]+infor[i][count[i]]))min[i]=time[i][count[i]-2]+infor[i][count[i]];
            else min[i]=infor[i][count[i]]+machine[infor[i][count[i]-1]];
        }
        temp=compare(min,M);
        machine[infor[temp][count[temp]-1]]=min[temp];
        time[temp][count[temp]]=machine[infor[temp][count[temp]-1]];
        if(count[temp]==P[temp]*2-1){
            ans+=machine[infor[temp][count[temp]-1]];
            flag++;
            infor[temp][count[temp]]=1000;
        }
        else count[temp]+=2;
        if(flag==M)break;
    }
    printf("%d",ans);
}
