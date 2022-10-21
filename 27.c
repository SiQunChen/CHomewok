#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct person {
    int time;
    int wait[10];
    int delay;
} person_t;

void judge(person_t p[200], int t)
{
    int max=0,temp[200]={0},i,j,a,k,dd;
    memset(temp,0,200);
    for(i=0;i<t;i++)
    {
        j=0;
        a=p[i].wait[j];
        while(a!=0)
        {
            dd=p[i].time;
            if(temp[i]>0) dd+=temp[i];
            if(temp[a-1]<dd){
                temp[a-1]=dd;
            }
            j++;
            a=p[i].wait[j];
        }
    }
    for(i=0;i<t;i++)
    {
        k=p[i].time;
        k+=temp[i];
        if(max<k) max=k;
    }
    printf("%d\n",max);
}

int main() {
    int panel,project,times=0,i,k,temp,wa;
    person_t p[200];
    scanf(" %d",&panel);
    while(times<panel)
    {
        for(i=0;i<200;i++)
        {
            p[i].time=0;
            p[i].delay=0;
            for(k=0 ; k<10 ; k++) p[i].wait[k]=0;
        }
        scanf(" %d",&project);
        for(k=0;k<project;k++)
        {
            scanf(" %d", &p[k].time);
            scanf(" %d", p[k].wait);
            temp=p[k].wait[0];
            for(i=0;i<temp;i++){
                scanf(" %d",&wa);
                p[k].wait[i]=wa;}
        }
        judge(p,project);
        times++;
    }
}
