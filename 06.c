#include<stdio.h>
int main(){
    int q,w,e,r,t,a,b,c;
    scanf(" %d",&q);
    scanf(" %d",&w);
    scanf(" %d",&e);
    scanf(" %d",&r);
    scanf(" %d",&t);
    a=q*0.08+w*0.1393+e*0.1349+r*1.1287+t*1.4803;
    b=q*0.07+w*0.1304+e*0.1217+r*1.1127+t*1.2458;
    c=q*0.06+w*0.1087+e*0.1018+r*0.9572+t*1.1243;
    if(a<183){
        a=183;
    }
    if(b<383){
        b=383;
    }
    if(c<983){
        c=983;
    }
    if(a<b && a<c){
        printf("%d",183);
    }
    else if (b<a && b<c){
        printf("%d",383);
    }
    else{
        printf("%d",983);
    }
}
