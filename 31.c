#include<stdio.h>
#include<stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(struct TYPE*);
typedef struct _TwoInputGate{
    GATEVALUE(_TwoInputGate);
    int A;
    int B;
}TwoInputGate;
typedef struct _OneInputGate{
    GATEVALUE(_OneInputGate);
    int A;
}OneInputGate;
int GateAndValue(TwoInputGate *obj){return obj->A & obj->B;}
int GateOrValue(TwoInputGate *obj){return obj->A | obj->B;}
int GateXorValue(TwoInputGate *obj){return obj->A ^ obj->B;}
int GateNotValue(OneInputGate *obj){return !obj->A;}
int GateEmptyValue(OneInputGate *obj){return obj->A;}
void CreateTwoInputGate(TwoInputGate *obj,int A,int B,char C){
    if(C=='A'){
        obj->GateValue = GateAndValue;
    }
    else if(C=='O'){
        obj->GateValue = GateOrValue;
    }
    else if(C=='X'){
        obj->GateValue = GateXorValue;
    }
    obj->A=A;
    obj->B=B;
}
void CreateOneInputGate(OneInputGate *obj,int A,char C){
    if(C=='N'){
        obj->GateValue = GateNotValue;
    }
    else if(C=='E'){
        obj->GateValue = GateEmptyValue;
    }
    obj->A=A;
}
int main(){
    int I1,I2,I3,I4;
    char A,B,C,D,E,F;
    TwoInputGate a,c,d,e,f;
    OneInputGate b;
    scanf(" %d,%d,%d,%d",&I1,&I2,&I3,&I4);
    scanf(" %c,%c,%c,%c,%c,%c",&A,&B,&C,&D,&E,&F);
    CreateTwoInputGate(&a,I1,I2,A);
    CreateOneInputGate(&b,a.GateValue(&a),B);
    CreateTwoInputGate(&c,a.GateValue(&a),I3,C);
    CreateTwoInputGate(&d,b.GateValue(&b),c.GateValue(&c),D);
    CreateTwoInputGate(&e,c.GateValue(&c),I4,E);
    CreateTwoInputGate(&f,d.GateValue(&d),e.GateValue(&e),F);
    printf("%d,%d,%d",b.GateValue(&b),d.GateValue(&d),f.GateValue(&f));
    return 0;
}
