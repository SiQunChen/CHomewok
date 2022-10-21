#include<stdio.h>
int main(){
    int x,y,z,a;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    scanf("%d",&a);
    printf("%.1f\n",(x+y)*z-(a*0.05)-((x+y)*z*0.08));
    printf("%.1f\n",a*0.05);
    printf("%.1f",(x+y)*z*0.08);
}
