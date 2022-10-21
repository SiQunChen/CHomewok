#include<stdio.h>
int main(){
    float A_score=0,B_score=0,number;
    char card[2];
    for(int i=0;i<3;i++){
        scanf(" %s",&card);
        if (card[0]=='A')
            A_score+=1;
        else if (card[0]=='J' | card[0]=='Q' | card[0]=='K')
            A_score+=0.5;
        else if (card[1]=='0')
            A_score+=10;
        else{
            number=card[0];
            A_score+=(number-48);
        }
    }
    if(A_score>10.5)
        A_score=0;
    for(int i=0;i<3;i++){
        scanf(" %s",&card);
        if (card[0]=='A')
            B_score+=1;
        else if (card[0]=='J' | card[0]=='Q' | card[0]=='K')
            B_score+=0.5;
        else if (card[1]=='0')
            B_score+=10;
        else{
            number=card[0];
            B_score+=(number-48);
        }
    }
    if(B_score>10.5)
        B_score=0;
    printf("%.1f\n%.1f\n",A_score,B_score);
    if(A_score>B_score)
        printf("A wins.");
    else if(A_score<B_score)
        printf("B wins.");
    else
        printf("It's a tie.");
    return 0;
}
