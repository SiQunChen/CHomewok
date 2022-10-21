#include<stdio.h>
int main() {
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("%.1f\n", ((-b)+sqrt(b*b-4*a*c))/(2*a));
    printf("%.1f", ((-b)-sqrt(b*b-4*a*c))/(2*a));
    return 0;
}
