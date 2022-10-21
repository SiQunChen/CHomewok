#include<stdio.h>
int main(){
    int up[]={1,1,1,1},down[]={6,6,6,6},right[]={2,2,2,2},left[]={5,5,5,5},forward[]={4,4,4,4},back[]={3,3,3,3},time,command[5],temp=0;
    scanf(" %d",&time);
    for(int i=0;i<time;i++){
        scanf(" %d %d %d %d",&command[0],&command[1],&command[2],&command[3]);
        for(int j=0;j<4;j++){
            switch (command[j]){
                case 1:
                    temp=up[j];
                    up[j]=forward[j];
                    forward[j]=down[j];
                    down[j]=back[j];
                    back[j]=temp;
                    break;
                case 2:
                    temp=up[j];
                    up[j]=back[j];
                    back[j]=down[j];
                    down[j]=forward[j];
                    forward[j]=temp;
                    break;
                case 3:
                    temp=up[j];
                    up[j]=left[j];
                    left[j]=down[j];
                    down[j]=right[j];
                    right[j]=temp;
                    break;
                case 4:
                    temp=up[j];
                    up[j]=right[j];
                    right[j]=down[j];
                    down[j]=left[j];
                    left[j]=temp;
                    break;
            }
        }
    }
    printf("%d",score(up));
}
int score(int up[]){
    int count[]={0,0,0,0,0,0},pair=0,one_pair=0;
    for(int i=0;i<4;i++){
        switch(up[i]){
        case 1:
            count[0]++;
            break;
        case 2:
            count[1]++;
            break;
        case 3:
            count[2]++;
            break;
        case 4:
            count[3]++;
            break;
        case 5:
            count[4]++;
            break;
        case 6:
            count[5]++;
            break;
        }
    }
    for(int i=0;i<6;i++){
        if(count[i]==4){
            return 18;
        }
        else if(count[i]==3){
            return 0;
        }
        else if(count[i]==2){
            pair++;
            if(pair==2){
                return 2*(i+1);
            }
        }
        else if(count[i]==1){
            one_pair+=i+1;
        }
    }
    if(pair==1){
        return one_pair;
    }
    else{
        return 0;
    }
}
