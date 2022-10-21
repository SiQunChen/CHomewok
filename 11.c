#include<stdio.h>
#include <math.h>
int main(){
    int number,time=0,ans[500],z,total=0;
    while(1){
        int i = 0,sum=0,temp,a[11];
        scanf(" %d",&number);
        scanf(" %d",&z);
        if(number==0){
            for(int i=0;i<11;i++){
                ans[11*time+i]=0;
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
            for(int i=2;i<sum+1;i++){
                int j=i,count=0;
                while(j!=1){
                    if(j%2==1){
                        j=(j+1)/2;
                        count+=1;
                    }
                    else{
                        j=j/2;
                        count+=1;
                    }
                }
                total+=count;
            }
            for(int i=0;i<11;i++){
                a[10-i]=total&1;
                total=total>>1;
            }
            for(int i=0;i<11;i++){
                ans[11*time+i]=a[i];
            }
            time+=1;
        }
        if(z==-1)
            break;
    }
    for(int i=0;i<time*11;i++){
        if(i>0 && i%11==0){
            printf("\n");
            printf("%d",ans[i]);
        }
        else{
            printf("%d",ans[i]);
        }
    }
    }
