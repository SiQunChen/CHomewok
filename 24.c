#include<stdio.h>
#include<string.h>
#include<math.h>
typedef enum scoreType_s{G,GPA,S} scoreType_t;
typedef enum grade_s{AP,A,AS,BP,B,BS,CP,C,CS,F} grade_t;
typedef enum range_s{NU,EU,ED,SEU,SEM,SED,SIU,SIM,SID,FAIL} range_t;
typedef union score_s{
    int GPA;
    grade_t grade;
    range_t range;
}score_t;
int average_score(score_t student[500],scoreType_t type[500],int M){
    float score=0;
    int list[10]={95,87,82,78,75,70,68,65,60,50};
    for(int j=0;j<M;j++){
        if(type[j]==0){
            score+=list[student[j].grade];
        }
        else if(type[j]==1){
            if(student[j].GPA==43)score+=95;
            else if(student[j].GPA==40)score+=87;
            else if(student[j].GPA==37)score+=82;
            else if(student[j].GPA==33)score+=78;
            else if(student[j].GPA==30)score+=75;
            else if(student[j].GPA==27)score+=70;
            else if(student[j].GPA==23)score+=68;
            else if(student[j].GPA==20)score+=65;
            else if(student[j].GPA==17)score+=60;
            else if(student[j].GPA==0)score+=50;
        }
        else{
            score+=list[student[j].range];
        }
    }
    return round(score/M);
}
void changeS(char temp[500],score_t student[500][500],int i,int j){
    if(strncmp(temp,"90-100",500)==0){
        student[i][j].range=NU;
    }
    else if(strncmp(temp,"85-89",500)==0){
        student[i][j].range=EU;
    }
    else if(strncmp(temp,"80-84",500)==0){
        student[i][j].range=ED;
    }
    else if(strncmp(temp,"77-79",500)==0){
        student[i][j].range=SEU;
    }
    else if(strncmp(temp,"73-76",500)==0){
        student[i][j].range=SEM;
    }
    else if(strncmp(temp,"70-72",500)==0){
        student[i][j].range=SED;
    }
    else if(strncmp(temp,"67-69",500)==0){
        student[i][j].range=SIU;
    }
    else if(strncmp(temp,"63-66",500)==0){
        student[i][j].range=SIM;
    }
    else if(strncmp(temp,"60-62",500)==0){
        student[i][j].range=SID;
    }
    else if(strncmp(temp,"0-59",500)==0){
        student[i][j].range=FAIL;
    }
}
void changeG(char temp[500],score_t student[500][500],int i,int j){
    if(strncmp(temp,"A+",500)==0){
        student[i][j].grade=AP;
    }
    else if(temp[0]=='A' && temp[1]==0){
        student[i][j].grade=A;
    }
    else if(strncmp(temp,"A-",500)==0){
        student[i][j].grade=AS;
    }
    else if(strncmp(temp,"B+",500)==0){
        student[i][j].grade=BP;
    }
    else if(temp[0]=='B' && temp[1]==0){
        student[i][j].grade=B;
    }
    else if(strncmp(temp,"B-",500)==0){
        student[i][j].grade=BS;
    }
    else if(strncmp(temp,"C+",500)==0){
        student[i][j].grade=CP;
    }
    else if(temp[0]=='C' && temp[1]==0){
        student[i][j].grade=C;
    }
    else if(strncmp(temp,"C-",500)==0){
        student[i][j].grade=CS;
    }
    else{
        student[i][j].grade=F;
    }
}
int main(){
    scoreType_t type[500];
    score_t student[500][500];
    int M,N,ans[500],time=0;
    float GPAAA;
    char temp[500],stu_num[500][500];
    scanf("%d",&M);
    getchar();
    for(int i=0;i<500;i++){
        type[i]==0;
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<500;j++){
            temp[j]=0;
        }
        gets(temp);
        if(temp[0]=='G' && temp[1]==0){
            type[i]=G;
        }
        else if(strncmp(temp,"GPA",500)==0){
            type[i]=GPA;
        }
        else{
            type[i]=S;
        }
    }
    scanf(" %d",&N);
    for(int i=0;i<N;i++){
        scanf(" %s",stu_num[i]);
        getchar();
        for(int j=0;j<M;j++){
            for(int k=0;k<500;k++){
                temp[k]==0;
            }
            if(type[j]==0){
                gets(temp);
                changeG(temp,student,i,j);
            }
            else if(type[j]==1){
                scanf(" %f",&GPAAA);
                getchar();
                student[i][j].GPA=GPAAA*10;
            }
            else{
                scanf(" %s",temp);
                getchar();
                changeS(temp,student,i,j);
            }
        }
    }
    for(int i=0;i<N;i++){
        ans[i]=average_score(student[i],type,M);
    }
    for(int i=100;i>=0;i--){
        for(int j=0;j<N;j++){
            if(ans[j]==i){
                printf("%s\n",stu_num[j]);
                printf("%d\n",ans[j]);
                time++;
            }
        }
        if(time==3)break;
    }
}
