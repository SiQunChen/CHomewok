#include<stdio.h>
#include <math.h>
int main(){
    int number,time=0,ans[200],z;
    while(1){
        int i = 0,sum=0,count=0,temp,a[4];
        scanf(" %d",&number);
        scanf(" %d",&z);
        if(number==0){
            for(int i=0;i<4;i++){
                ans[4*time+i]=0;
            }
            time+=1;
        }
        else{
            while (number!=0){
                temp = number%10;
                number /= 10;
                sum += temp*pow(2,i);
                ++i;
                }
            while(sum!=1){
                if(sum%2==1){
                    sum=(sum+1)/2;
                    count+=1;
                }
                else{
                    sum=sum/2;
                    count+=1;
                }
            }
            for(int i=0;i<4;i++){
                a[3-i]=count&1;
                count=count>>1;
            }
            for(int i=0;i<4;i++){
                ans[4*time+i]=a[i];
            }
            time+=1;
        }
        if(z==-1)
            break;
    }
    for(int i=0;i<time*4;i++){
        if(i>0 && i%4==0){
            printf("\n");
            printf("%d",ans[i]);
        }
        else{
            printf("%d",ans[i]);
        }
    }
    }
