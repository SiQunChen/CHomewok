#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pro(char iA[100],char iB[100],char fA[100],char fB[100],int f,int leniA,int leniB,int lenfA,int lenfB){
    int flag=0;
    char ans[300];
    for(int i=0;i<300;i++){
        ans[i]=0;
    }
    for(int i=0;i<99;i++){
        if(iA[i]>=48)iA[i]-=48;
        if(iB[i]>=48)iB[i]-=48;
        if(fA[i]>=48)fA[i]-=48;
        if(fB[i]>=48)fB[i]-=48;
    }
    if(f==3 || f==2)printf("-");
    for(int i=lenfB-1;i>=0;i--){
        for(int j=lenfA-1;j>=0;j--){
            ans[299-(lenfA-1)+j-(lenfB-1)+i]+=(fA[j]*fB[i]);
            if(ans[299-(lenfA-1)+j-(lenfB-1)+i]>9){
                ans[299-(lenfA-1)+j-(lenfB-1)+i-1]+=ans[299-(lenfA-1)+j-(lenfB-1)+i]/10;
                ans[299-(lenfA-1)+j-(lenfB-1)+i]%=10;
            }
        }
        for(int j=99;j>99-leniA;j--){
            ans[201+i+j-lenfB-lenfA]+=(iA[j]*fB[i]);
            if(ans[201+i+j-lenfB-lenfA]>9){
                ans[200+i+j-lenfB-lenfA]+=ans[201+i+j-lenfB-lenfA]/10;
                ans[201+i+j-lenfB-lenfA]%=10;
            }
        }
    }
    for(int i=99;i>99-leniB;i--){
        for(int j=lenfA-1;j>=0;j--){
            ans[201-lenfB-lenfA+j+i]+=(fA[j]*iB[i]);
            if(ans[201-lenfB-lenfA+j+i]>9){
                ans[200-lenfB-lenfA+j+i]+=ans[201-lenfB-lenfA+j+i]/10;
                ans[201-lenfB-lenfA+j+i]%=10;
            }
        }
        for(int j=99;j>99-leniA;j--){
            ans[101-lenfA-lenfB+j+i]+=(iA[j]*iB[i]);
            if(ans[101-lenfA-lenfB+j+i]>9){
                ans[100-lenfA-lenfB+j+i]+=ans[101-lenfA-lenfB+j+i]/10;
                ans[101-lenfA-lenfB+j+i]%=10;
            }
        }
    }
    for(int i=0;i<300-lenfA-lenfB;i++){
        if(ans[i]!=0)flag=1;
        if(flag==1)printf("%d",ans[i]);
    }
    printf(".");
    for(int i=299-lenfA-lenfB+1;i<300;i++){
        printf("%d",ans[i]);
    }
}
void sub(char iA[100],char iB[100],char fA[100],char fB[100],int f,int f1,int f2,int len){
    int flag=0,flaaag=0;
    char ians[100],fans[100];
    for(int i=0;i<100;i++){
        fans[i]=0;
        ians[i]=0;
    }
    if(f2<f1){
        if(f==1 || f==2)printf("-");
        for(int i=99;i>=0;i--){
            if(fA[i]>=48)fA[i]-=48;
            if(fB[i]>=48)fB[i]-=48;
            fans[i]+=(fA[i]-fB[i]);
            if(fans[i]<0){
                if(i==0){
                    ians[99]-=1;
                    fans[0]+=10;
                }
                else{
                    fans[i-1]-=1;
                    fans[i]+=10;
                }
            }
        }
        for(int i=99;i>=0;i--){
            if(iA[i]>=48)iA[i]-=48;
            if(iB[i]>=48)iB[i]-=48;
            ians[i]+=(iA[i]-iB[i]);
            if(ians[i]<0){
                ians[i-1]-=1;
                ians[i]+=10;
            }
        }
    }
    else if(f2>f1){
        if(f==0 || f==3)printf("-");
        for(int i=99;i>=0;i--){
            if(fA[i]>=48)fA[i]-=48;
            if(fB[i]>=48)fB[i]-=48;
            fans[i]+=(fB[i]-fA[i]);
            if(fans[i]<0){
                if(i==0){
                    ians[99]-=1;
                    fans[0]+=10;
                }
                else{
                    fans[i-1]-=1;
                    fans[i]+=10;
                }
            }
        }
        for(int i=99;i>=0;i--){
            if(iA[i]>=48)iA[i]-=48;
            if(iB[i]>=48)iB[i]-=48;
            ians[i]+=(iB[i]-iA[i]);
            if(ians[i]<0){
                ians[i-1]-=1;
                ians[i]+=10;
            }
        }
    }
    else{
        for(int i=0;i<100;i++){
            if(iA[i]>iB[i]){
                if(f==1 || f==2)printf("-");
                for(int i=99;i>=0;i--){
                    if(fA[i]>=48)fA[i]-=48;
                    if(fB[i]>=48)fB[i]-=48;
                    fans[i]+=(fA[i]-fB[i]);
                    if(fans[i]<0){
                        if(i==0){
                            ians[99]-=1;
                            fans[0]+=10;
                        }
                        else{
                            fans[i-1]-=1;
                            fans[i]+=10;
                        }
                    }
                }
                for(int i=99;i>=0;i--){
                    if(iA[i]>=48)iA[i]-=48;
                    if(iB[i]>=48)iB[i]-=48;
                    ians[i]+=(iA[i]-iB[i]);
                    if(ians[i]<0){
                        ians[i-1]-=1;
                        ians[i]+=10;
                    }
                }
                break;
            }
            else if(iA[i]<iB[i]){
                if(f==0 || f==3)printf("-");
                for(int i=99;i>=0;i--){
                    if(fA[i]>=48)fA[i]-=48;
                    if(fB[i]>=48)fB[i]-=48;
                    fans[i]+=(fB[i]-fA[i]);
                    if(fans[i]<0){
                        if(i==0){
                            ians[99]-=1;
                            fans[0]+=10;
                        }
                        else{
                            fans[i-1]-=1;
                            fans[i]+=10;
                        }
                    }
                }
                for(int i=99;i>=0;i--){
                    if(iA[i]>=48)iA[i]-=48;
                    if(iB[i]>=48)iB[i]-=48;
                    ians[i]+=(iB[i]-iA[i]);
                    if(ians[i]<0){
                        ians[i-1]-=1;
                        ians[i]+=10;
                    }
                }
                break;
            }
            else if(i==99){
                for(int i=0;i<100;i++){
                    if(fA[i]>fB[i]){
                        if(f==1 || f==2)printf("-");
                        for(int i=99;i>=0;i--){
                            if(fA[i]>=48)fA[i]-=48;
                            if(fB[i]>=48)fB[i]-=48;
                            fans[i]+=(fA[i]-fB[i]);
                            if(fans[i]<0){
                                if(i==0){
                                    ians[99]-=1;
                                    fans[0]+=10;
                                }
                                else{
                                    fans[i-1]-=1;
                                    fans[i]+=10;
                                }
                            }
                        }
                        for(int i=99;i>=0;i--){
                            if(iA[i]>=48)iA[i]-=48;
                            if(iB[i]>=48)iB[i]-=48;
                            ians[i]+=(iA[i]-iB[i]);
                            if(ians[i]<0){
                                ians[i-1]-=1;
                                ians[i]+=10;
                            }
                        }
                        break;
                    }
                    else if(fA[i]<fB[i]){
                        if(f==0 || f==3)printf("-");
                        for(int i=99;i>=0;i--){
                            if(fA[i]>=48)fA[i]-=48;
                            if(fB[i]>=48)fB[i]-=48;
                            fans[i]+=(fB[i]-fA[i]);
                            if(fans[i]<0){
                                if(i==0){
                                    ians[99]-=1;
                                    fans[0]+=10;
                                }
                                else{
                                    fans[i-1]-=1;
                                    fans[i]+=10;
                                }
                            }
                        }
                        for(int i=99;i>=0;i--){
                            if(iA[i]>=48)iA[i]-=48;
                            if(iB[i]>=48)iB[i]-=48;
                            ians[i]+=(iB[i]-iA[i]);
                            if(ians[i]<0){
                                ians[i-1]-=1;
                                ians[i]+=10;
                            }
                        }
                        break;
                    }
                    else if(i==99){
                        printf("0\n");
                        flaaag=1;
                        break;
                    }
                }
            }
        }
    }
    if(flaaag==0){
        for(int i=0;i<100;i++){
            if(ians[i]!=0)flag=1;
            if(flag==1)printf("%d",ians[i]);
        }
        printf(".");
        for(int i=0;i<len;i++){
            printf("%d",fans[i]);
        }
        printf("\n");
    }
}
void add(char iA[100],char iB[100],char fA[100],char fB[100],int f,int len){
    int flag=0;
    char ians[100],fans[100];
    for(int i=0;i<100;i++){
        fans[i]=0;
        ians[i]=0;
    }
    if(f==1 || f==2)printf("-");
    for(int i=len;i>=0;i--){
        if(fA[i]>=48)fA[i]-=48;
        if(fB[i]>=48)fB[i]-=48;
        fans[i]+=(fA[i]+fB[i]);
        if(fans[i]>9){
            if(i==0){
                ians[99]+=1;
                fans[0]-=10;
            }
            else{
                fans[i-1]+=1;
                fans[i]-=10;
            }
        }
    }
    for(int i=99;i>=0;i--){
        if(iA[i]>=48)iA[i]-=48;
        if(iB[i]>=48)iB[i]-=48;
        ians[i]+=(iA[i]+iB[i]);
        if(ians[i]>9){
            ians[i-1]+=1;
            ians[i]-=10;
        }
    }
    for(int i=0;i<100;i++){
        if(ians[i]!=0)flag=1;
        if(flag==1)printf("%d",ians[i]);
    }
    printf(".");
    for(int i=0;i<len;i++){
        printf("%d",fans[i]);
    }
    printf("\n");
}
int main(){
    int f1,f2,flag=0,lenfA=0,lenfB=0,len;
    char A[300],B[300];
    char iA[100],iB[100],fA[100],fB[100];
    for(int i=0;i<300;i++){
        A[i]=0;
        B[i]=0;
    }
    for(int i=0;i<100;i++){
        iA[i]=0;
        iB[i]=0;
        fA[i]=0;
        fB[i]=0;
    }
    gets(A);
    gets(B);
    for(int i=0;i<300;i++){
        if(A[i]=='.'){
            f1=i;
            break;
        }
    }
    for(int i=0;i<300;i++){
        if(B[i]=='.'){
            f2=i;
            break;
        }
    }
    for(int i=0;i<f1;i++){
        if(A[i]!='-')iA[i+100-f1]=A[i];
    }
    for(int i=0;i<f2;i++){
        if(B[i]!='-')iB[i+100-f2]=B[i];
    }
    for(int i=f1+1;i<300;i++){
        if(A[i]==0){
            lenfA=i-f1-1;
            break;
        }
        else fA[i-f1-1]=A[i];
    }
    for(int i=f2+1;i<300;i++){
        if(B[i]==0){
            lenfB=i-f2-1;
            break;
        }
        else fB[i-f2-1]=B[i];
    }
    if(lenfA>=lenfB)len=lenfA;
    else if(lenfA<lenfB)len=lenfB;
    if(A[0]=='-' && B[0]=='-'){
        flag=1;
        add(iA,iB,fA,fB,flag,len);
        sub(iA,iB,fA,fB,flag,f1-1,f2-1,len);
        pro(iA,iB,fA,fB,flag,f1,f2,lenfA,lenfB);
    }
    else if(A[0]=='-' && B[0]!='-'){
        flag=2;
        sub(iA,iB,fA,fB,flag,f1-1,f2,len);
        add(iA,iB,fA,fB,flag,len);
        pro(iA,iB,fA,fB,flag,f1,f2,lenfA,lenfB);
    }
    else if(A[0]!='-' && B[0]=='-'){
        flag=3;
        sub(iA,iB,fA,fB,flag,f1,f2-1,len);
        add(iA,iB,fA,fB,flag,len);
        pro(iA,iB,fA,fB,flag,f1,f2,lenfA,lenfB);
    }
    else{
        add(iA,iB,fA,fB,flag,len);
        sub(iA,iB,fA,fB,flag,f1,f2,len);
        pro(iA,iB,fA,fB,flag,f1,f2,lenfA,lenfB);
    }
}
