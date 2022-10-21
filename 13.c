#include<stdio.h>
int gcd(int a,int b){
    int temp;
    while(a%b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return b;
}
int main(){
    int x1,y1,x2,y2,b1,b2,gc,m1,m2;
    scanf(" %d,%d",&x1,&y1);
    scanf(" %d,%d",&x2,&y2);
    if(y1-y2==0 && (x2*y1-x1*y2)%(x2-x1)==0){
        printf("y=%d",(x2*y1-x1*y2)/(x2-x1));
        return 0;
    }
    else if(x2*y1-x1*y2==0 && (y1-y2)%(x1-x2)==0){
            if((y1-y2)/(x1-x2)!=1 && (y1-y2)/(x1-x2)!=-1)
                printf("y=%dx",(y1-y2)/(x1-x2));
            else if((y1-y2)/(x1-x2)==1)
                printf("y=x");
            else
                printf("y=-x");
        return 0;
    }
    else if(x2*y1-x1*y2==0 && (y1-y2)%(x1-x2)!=0){
        gc=gcd(y1-y2,x1-x2);
        m1=(y1-y2)/gc;
        m2=(x1-x2)/gc;
        if(abs(m1)<abs(m2)){
            if(m2<0)
                printf("y=-%d/%dx",abs(m1),abs(m2));
            else
                printf("y=%d/%dx",abs(m1),abs(m2));
        }
        else if(abs(m1)>abs(m2)){
            printf("y=%d(%d/%d)x",m1/m2,abs(m1%m2),abs(m2));
        }
        return 0;
    }
    else if((y1-y2)%(x1-x2)!=0){
        gc=gcd(y1-y2,x1-x2);
        m1=(y1-y2)/gc;
        m2=(x1-x2)/gc;
    }
    if((x2*y1-x1*y2)%(x2-x1)!=0){
        gc=gcd(x2*y1-x1*y2,x2-x1);
        b1=(x2*y1-x1*y2)/gc;
        b2=(x2-x1)/gc;
    }
    if((y1-y2)%(x1-x2)==0 && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)>0){
        printf("y=%dx+%d",(y1-y2)/(x1-x2),(x2*y1-x1*y2)/(x2-x1));
    }
    else if((y1-y2)%(x1-x2)==0 && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)<0){
        printf("y=%dx%d",(y1-y2)/(x1-x2),(x2*y1-x1*y2)/(x2-x1));
    }
    else if(((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b1>0) || ((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b2>0)){
        printf("y=%dx+%d/%d",(y1-y2)/(x1-x2),b1,b2);
    }
    else if(((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b1<0) || ((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b2<0)){
        printf("y=%dx-%d/%d",(y1-y2)/(x1-x2),abs(b1),abs(b2));
    }
    else if(((y1-y2)%(x1-x2)==0 && abs(b1)>abs(b2) && b1>0) || ((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b2>0)){
        printf("y=%dx+%d(%d/%d)",(y1-y2)/(x1-x2),b1/b2,b1%b2,b2);
    }
    else if(((y1-y2)%(x1-x2)==0 && abs(b1)>abs(b2) && b1<0) || ((y1-y2)%(x1-x2)==0 && abs(b1)<abs(b2) && b2<0)){
        printf("y=%dx-%d(%d/%d)",(y1-y2)/(x1-x2),abs(b1/b2),abs(b1%b2),abs(b2));
    }
    else if(abs(m1)<abs(m2) && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)>0){
        if(m2<0)
            printf("y=-%d/%dx+%d",m1,m2,(x2*y1-x1*y2)/(x2-x1));
        else
            printf("y=%d/%dx+%d",m1,m2,(x2*y1-x1*y2)/(x2-x1));
    }
    else if(abs(m1)<abs(m2) && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)<0){
        if(m2<0)
            printf("y=-%d/%dx-%d",m1,m2,(x2*y1-x1*y2)/(x2-x1));
        else
            printf("y=%d/%dx-%d",m1,m2,(x2*y1-x1*y2)/(x2-x1));
    }
    else if(abs(m1)>abs(m2) && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)>0){
        printf("y=%d(%d/%d)x+%d",m1/m2,abs(m1%m2),abs(m2),(x2*y1-x1*y2)/(x2-x1));
    }
    else if(abs(m1)>abs(m2) && (x2*y1-x1*y2)%(x2-x1)==0 && (x2*y1-x1*y2)/(x2-x1)<0){
        printf("y=%d(%d/%d)x%d",m1/m2,abs(m1%m2),abs(m2),(x2*y1-x1*y2)/(x2-x1));
    }
    else if(abs(m1)>abs(m2) && abs(b1)>abs(b2) && b1/b2>=0){
        printf("y=%d(%d/%d)x+%d(%d/%d)",m1/m2,abs(m1%m2),abs(m2),b1/b2,b1%b2,b2);
    }
    else if((abs(m1)>abs(m2) && abs(b1)>abs(b2) && b1<0) || (abs(m1)>abs(m2) && abs(b1)>abs(b2) && b2<0)){
        printf("y=%d(%d/%d)x-%d(%d/%d)",m1/m2,abs(m1%m2),abs(m2),abs(b1/b2),abs(b1%b2),abs(b2));
    }
    else if((abs(m1)<abs(m2) && abs(b1)<abs(b2) && b1>0) && (abs(m1)<abs(m2) && abs(b1)<abs(b2) && b2>0)){
        if(m2<0)
            printf("y=-%d/%dx+%d/%d",m1,abs(m2),abs(b1),abs(b2));
        else
            printf("y=%d/%dx+%d/%d",m1,abs(m2),abs(b1),abs(b2));
    }
    else if((abs(m1)<abs(m2) && abs(b1)<abs(b2) && b1<0) || (abs(m1)<abs(m2) && abs(b1)<abs(b2) && b2<0)){
        if(m2<0)
            printf("y=-%d/%dx-%d/%d",m1,abs(m2),abs(b1),abs(b2));
        else
            printf("y=%d/%dx-%d/%d",m1,abs(m2),abs(b1),abs(b2));
    }
    else if((abs(m1)>abs(m2) && abs(b1)<abs(b2) && b1>0) && (abs(m1)>abs(m2) && abs(b1)<abs(b2) && b2>0)){
        printf("y=%d(%d/%d)x+%d/%d",m1/m2,abs(m1%m2),abs(m2),b1,b2);
    }
    else if((abs(m1)>abs(m2) && abs(b1)<abs(b2) && b1<0) || (abs(m1)>abs(m2) && abs(b1)<abs(b2) && b2<0)){
        printf("y=%d(%d/%d)x-%d/%d",m1/m2,abs(m1%m2),abs(m2),abs(b1),abs(b2));
    }
    else if((abs(m1)<abs(m2) && abs(b1)>abs(b2) && b1>0) && (abs(m1)<abs(m2) && abs(b1)>abs(b2) && b2>0)){
        if(m2<0)
            printf("y=-%d/%dx+%d(%d/%d)",m1,abs(m2),abs(b1/b2),abs(b1%b2),abs(b2));
        else
            printf("y=%d/%dx+%d(%d/%d)",m1,abs(m2),abs(b1/b2),abs(b1%b2),abs(b2));
    }
    else{
        if(m2<0)
            printf("y=-%d/%dx-%d(%d/%d)",m1,abs(m2),abs(b1/b2),abs(b1%b2),abs(b2));
        else
            printf("y=%d/%dx-%d(%d/%d)",m1,abs(m2),abs(b1/b2),abs(b1%b2),abs(b2));
    }
}
