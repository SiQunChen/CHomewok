#include<stdio.h>
#include <stdlib.h>//malloc()
void function(int bits,int cin){
    if (bits==0){printf("0");}
    int* bi=(int*)malloc(sizeof(int)*bits);
    int* gr=(int*)malloc(sizeof(int)*bits);
    for (int i=bits-1;i>=0;i--){
        bi[i]=cin%2;
        cin/=2;}
    gr[0]=bi[0];
    for (int i=1;i<bits;i++){
        gr[i]=bi[i-1]^bi[i];}
    for (int i=0;i<bits;i++){
        printf("%d",gr[i]);}
}
void main(){
    int* input1=(int*)malloc(sizeof(int));
    int* input2=(int*)malloc(sizeof(int));
    int check=0,i;
    for (i=0;check!=-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        input1[i]=a;
        input2[i]=b;
        scanf("%d",&check);
    }
    for (int j=0;j<i;j++){
        if (j!=0){printf("\n");}
        function(input1[j],input2[j]);
    }
}
