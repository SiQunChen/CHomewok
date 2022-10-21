#include<stdio.h>
int main(){
    int time[60],cource,hours,temp,ans[10],s=0,name;
    for(int i=0;i<59;i++){
        time[i]=0;
    }
    for(int i=0;i<10;i++){
        ans[i]=0;
    }
    scanf(" %d",&cource);
    for(int i=0;i<cource;i++){
        scanf(" %d",&name);
        scanf(" %d",&hours);
        for(int j=0;j<hours;j++){
            scanf(" %d",&temp);
            if(time[temp]!=0){
                ans[s]+=time[temp];
                ans[s+1]+=name;
                ans[s+2]+=temp;
                s+=3;
            }
            else{
                time[temp]+=name;
            }
        }
    }
    for(int i=0;i<10;i+=3){
        if(ans[i]!=0){
            printf("%d and %d conflict on %d",ans[i],ans[i+1],ans[i+2]);
        }
        else{
            break;
        }
    }
}
