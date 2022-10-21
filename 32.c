#include<stdio.h>
#include<stdlib.h>
typedef struct _information{
    int a[100];
}information;
void sort(information x[100],int i,int j,int k,int M){
    int temp=0;
    if(x[j].a[i]>x[k].a[i]){
        for(int l=0;l<M;l++){
            temp=x[j].a[l];
            x[j].a[l]=x[k].a[l];
            x[k].a[l]=temp;
        }
    }
    else if(x[j].a[i]==x[k].a[i]){
        i++;
        sort(x,i,j,k,M);
    }
}
int main(){
    int N,M,temp=0;
    information x[100];
    scanf(" %d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %d",&x[i].a[j]);
        }
    }
    for(int j=0;j<N;j++){
        for(int k=j+1;k<N;k++){
            if(x[j].a[0]>x[k].a[0]){
                for(int i=0;i<M;i++){
                    temp=x[j].a[i];
                    x[j].a[i]=x[k].a[i];
                    x[k].a[i]=temp;
                }
            }
            else if(x[j].a[0]==x[k].a[0]){
                temp=1;
                sort(x,temp,j,k,M);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",x[i].a[j]);
            if(j!=M-1)printf(" ");
        }
        if(i!=N-1)printf("\n");
    }
}
