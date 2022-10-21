#include<stdio.h>
int main(){
    int x,x0,x1,x2=0,x3=0,y,y0,y1,y2=0,y3=0,z,z0,z1,z2=0,z3=0;
    scanf("%d",&x);
    scanf("%d",&x0);
    switch(x0){
    case 1:
        scanf("%d",&x1);
        break;
    case 2:
        scanf("%d",&x1);
        scanf("%d",&x2);
        break;
    case 3:
        scanf("%d",&x1);
        scanf("%d",&x2);
        scanf("%d",&x3);
        break;
    }
    scanf("%d",&y);
    scanf("%d",&y0);
    switch(y0){
    case 1:
        scanf("%d",&y1);
        break;
    case 2:
        scanf("%d",&y1);
        scanf("%d",&y2);
        break;
    case 3:
        scanf("%d",&y1);
        scanf("%d",&y2);
        scanf("%d",&y3);
        break;
    }
    scanf("%d",&z);
    scanf("%d",&z0);
    switch(z0){
    case 1:
        scanf("%d",&z1);
        break;
    case 2:
        scanf("%d",&z1);
        scanf("%d",&z2);
        break;
    case 3:
        scanf("%d",&z1);
        scanf("%d",&z2);
        scanf("%d",&z3);
        break;
    }
    if(x1==y1 | x1==y2 | x1==y3){
        printf("%d and %d conflict on %d",x,y,x1);
    }
    else if(x1==z1 | x1==z2 | x1==z3){
        printf("%d and %d conflict on %d",x,z,x1);
    }
    else if(x2==y1 | x2==y2 | x2==y3){
        printf("%d and %d conflict on %d",x,y,x2);
    }
    else if(x2==z1 | x2==z2 | x2==z3){
        printf("%d and %d conflict on %d",x,z,x2);
    }
    else if(x3==y1 | x3==y2 | x3==y3){
        printf("%d and %d conflict on %d",x,y,x3);
    }
    else if(x3==z1 | x3==z2 | x3==z3){
        printf("%d and %d conflict on %d",x,z,x3);
    }
    else if(y1==z1 | y1==z2 | y1==z3){
        printf("%d and %d conflict on %d",y,z,y1);
    }
    else if(y2==z1 | y2==z2 | y2==z3){
        printf("%d and %d conflict on %d",y,z,y2);
    }
    else if(y3==z1 | y3==z2 | y3==z3){
        printf("%d and %d conflict on %d",y,z,y3);
    }
}
