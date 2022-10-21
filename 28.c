#include<stdio.h>
#include<stdlib.h>
typedef struct baseball{
    int time;
    char infor[50];
}baseball_t;
int main(){
    baseball_t player[9];
    int baba[3]={100,100,100},out_number,out_time=0,score=0,hits[9],save[9],flag=0;
    for(int i=0;i<9;i++){
        hits[i]=0;
        save[i]=0;
        scanf(" %d",&player[i].time);
        getchar();
        gets(player[i].infor);
    }
    scanf(" %d",&out_number);
    for(int i=0;i<50;i=i+2){
        for(int j=0;j<9;j++){
            if(player[j].time*2>i){
                if(player[j].infor[i]=='3'){
                    hits[j]++;
                    for(int k=0;k<3;k++){
                        if(baba[k]!=100){
                            score++;
                            save[baba[k]]++;
                        }
                    }
                    baba[2]=j;
                    baba[1]=100;
                    baba[0]=100;
                }
                else if(player[j].infor[i]=='2'){
                    hits[j]++;
                    for(int k=1;k<3;k++){
                        if(baba[k]!=100){
                            score++;
                            save[baba[k]]++;
                        }
                    }
                    baba[2]=baba[0];
                    baba[1]=j;
                    baba[0]=100;
                }
                else if(player[j].infor[i]=='1'){
                    hits[j]++;
                    if(baba[2]!=100){
                        score++;
                        save[baba[2]]++;
                    }
                    baba[2]=baba[1];
                    baba[1]=baba[0];
                    baba[0]=j;
                }
                else if(player[j].infor[i]=='H'){
                    hits[j]++;
                    score++;
                    save[j]++;
                    for(int k=0;k<3;k++){
                        if(baba[k]!=100){
                            score++;
                            save[baba[k]]++;
                        }
                    }
                    baba[2]=100;
                    baba[1]=100;
                    baba[0]=100;
                }
                else{
                    out_time++;
                    if(out_time%3==0){
                        baba[2]=100;
                        baba[1]=100;
                        baba[0]=100;
                    }
                    if(out_time==out_number){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1)break;
    }
    printf("%d\n",score);
    for(int i=0;i<9;i++){
        printf("%d %d %d\n",i+1,hits[i],save[i]);
    }
}
