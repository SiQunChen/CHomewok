#include<stdio.h>
int main(){
    char que[5],ans[5];
    scanf(" %s",&que);
    for(int i=0;i<6;i++){
        int A=0,B=0;
        scanf(" %s",&ans);
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(que[j]==ans[k] && j==k){
                    A+=1;
                    break;
                }
                else if(que[j]==ans[k]){
                    B+=1;
                    break;
                }
            }
        }
        if(A==4){
            printf("win");
            break;
        }
        else{
            printf("%dA%dB\n",A,B);
        }
    }
}
