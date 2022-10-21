#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f1(double x,double a){return sqrt(a-pow(x,2));}
double f2(double x,double a){return (a*pow(x,3) + 7.0L*x)/sqrt(a+x);}
double Area(double a,double p,double q,int err,int cho){
    int n=1;
    double area1=0,area2=0;
    double (*f)(double,double);
    if(cho==1)f=f1;
    else f=f2;
    while(1){
        n=n*2.0L;
        area1=area2;
        area2=0.0L;
        double x=(q-p)/n;
        double fy1=(*f)(p,a);
        double fy2=(*f)(p+x,a);
        for(int i=1;i<n+1;i++){
            area2+=(fabs(fy1)+fabs(fy2))*x/2.0L;
            fy1=fy2;
            fy2=(*f)(p+x*(i+1.0L),a);
        }
        if(fabs(area2-area1)<pow(10,(-err)))return area2;
    }
}
int main(){
    int choose,err;
    double a,p,q;
    while(1){
        scanf(" %d",&choose);
        if(choose==0)break;
        scanf(" %lf",&a);
        scanf(" %lf",&p);
        scanf(" %lf",&q);
        scanf(" %d",&err);
        printf("%.12lf\n",Area(a,p,q,err,choose));
    }
}
