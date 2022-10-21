#include<stdio.h>
void turn_left(int a,int up[9],int back[9],int down[9],int forward[9],int left[9],int right[9]){
    int temp=0;
    for(int j=0+a*3;j<3+a*3;j++){
        temp=back[j];
        back[j]=right[j];
        right[j]=forward[j];
        forward[j]=left[j];
        left[j]=temp;
    }
    if(a==0){
        temp=up[0];
        up[0]=up[6];
        up[6]=up[8];
        up[8]=up[2];
        up[2]=temp;
        temp=up[1];
        up[1]=up[3];
        up[3]=up[7];
        up[7]=up[5];
        up[5]=temp;
    }
    else if(a==2){
        temp=down[0];
        down[0]=down[6];
        down[6]=down[8];
        down[8]=down[2];
        down[2]=temp;
        temp=down[1];
        down[1]=down[3];
        down[3]=down[7];
        down[7]=down[5];
        down[5]=temp;
    }
}
void turn_forward(int a,int up[9],int back[9],int down[9],int forward[9],int left[9],int right[9]){
    int temp=0;
    for(int j=a;j<9;j=j+3){
        temp=up[j];
        up[j]=back[j];
        back[j]=down[j];
        down[j]=forward[j];
        forward[j]=temp;
    }
}
int main(){
    int up[9]={1,1,1,1,1,1,1,1,1},back[9]={4,4,4,4,4,4,4,4,4},down[9]={6,6,6,6,6,6,6,6,6},forward[9]={3,3,3,3,3,3,3,3,3},left[9]={5,5,5,5,5,5,5,5,5},right[9]={2,2,2,2,2,2,2,2,2};
    int time=0,ope;
    scanf(" %d",&time);
    for(int i=0;i<time;i++){
        scanf(" %d",&ope);
        switch(ope){
            case 10:
                turn_forward(0,up,back,down,forward,left,right);
                break;
            case 11:
                turn_forward(1,up,back,down,forward,left,right);
                break;
            case 12:
                turn_forward(2,up,back,down,forward,left,right);
                break;
            case 20:
                turn_left(0,up,back,down,forward,left,right);
                break;
            case 21:
                turn_left(1,up,back,down,forward,left,right);
                break;
            case 22:
                turn_left(2,up,back,down,forward,left,right);
                break;
        }
    }
    for(int i=0;i<9;i=i+3){
        printf("%d %d %d\n",up[i],up[i+1],up[i+2]);
    }
}
