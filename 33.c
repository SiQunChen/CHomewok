#include<stdio.h>
#include<stdlib.h>
#define TransportationText(TYPE)\
    char name[20];\
    double speed;\
    double distance;\
    int (*price)(struct TYPE*);\
    double (*time)(struct TYPE*);
typedef struct car_s {
    int oilPrice;
    int parkPrice;
    int tolls;
    TransportationText(car_s);
} car_t;
typedef struct bike_s {
    int rentPrice;
    TransportationText(bike_s);
} bike_t;
typedef struct bus_s {
    int fixedPrice;
    int Add;
    TransportationText(bus_s);
} bus_t;
typedef struct moto_s {
    int oilPrice;
    TransportationText(moto_s);
} moto_t;

int CarPrice(car_t* obj){
    int temp;
    temp=obj->distance/100;
    if(obj->distance/100!=temp)temp++;
    return obj->oilPrice*10*temp+obj->parkPrice+obj->tolls*temp;
}
int BikePrice(bike_t* obj){
    return obj->rentPrice;
}
int BusPrice(bus_t* obj){
    int temp=0;
    if(obj->distance>100){
        temp=(obj->distance-100)/50;
        temp++;
    }
    return obj->fixedPrice+obj->Add*temp;
}
int MotoPrice(moto_t* obj){
    int temp;
    if(obj->distance>100){
        temp=(obj->distance-100)/100;
        temp++;
    }
    else temp=1;
    return obj->oilPrice*4*temp;
}

double CarTime(car_t* obj){
    return obj->distance/obj->speed;
}
double BikeTime(bike_t* obj){
    return obj->distance/obj->speed;
}
double BusTime(bus_t* obj){
    return obj->distance/obj->speed;
}
double MotoTime(moto_t* obj){
    return obj->distance/obj->speed;
}

void CarCreate(car_t *obj,double target){
    strcpy(obj->name, "Car");
    obj->speed = 100;
    obj->distance = target;
    obj->price = CarPrice;
    obj->time = CarTime;
}
void BikeCreate(bike_t *obj,double target){
    strcpy(obj->name, "Bike");
    obj->speed = 20;
    obj->distance = target;
    obj->price = BikePrice;
    obj->time = BikeTime;
}
void BusCreate(bus_t *obj,double target){
    strcpy(obj->name, "Intercity Bus");
    obj->speed = 75;
    obj->distance = target;
    obj->price = BusPrice;
    obj->time = BusTime;
}
void MotoCreate(moto_t *obj,double target){
    strcpy(obj->name, "Scooter");
    obj->speed = 50;
    obj->distance = target;
    obj->price = MotoPrice;
    obj->time = MotoTime;
}
void compare(car_t *c,bike_t *bi,bus_t *b,moto_t *m,int money){
    for(int i=1;i<100;i++){
        if(c->time(c)<i && c->price(c)<=money){
            printf("%s\n",c->name);
            printf("%d\n",c->price(c));
            printf("%.2f\n",c->time(c));
            break;
        }
        else if(bi->time(bi)<i && bi->price(bi)<=money){
            printf("%s\n",bi->name);
            printf("%d\n",bi->price(bi));
            printf("%.2f\n",bi->time(bi));
            break;
        }
        else if(b->time(b)<i && b->price(b)<=money){
            printf("%s\n",b->name);
            printf("%d\n",b->price(b));
            printf("%.2f\n",b->time(b));
            break;
        }
        else if(m->time(m)<i && m->price(m)<=money){
            printf("%s\n",m->name);
            printf("%d\n",m->price(m));
            printf("%.2f\n",m->time(m));
            break;
        }
        else if(i==99)printf("No Transportation");
    }
}
int main(){
    int money;
    double target;
    car_t c;
    bike_t bi;
    bus_t b;
    moto_t m;
    scanf(" %lf %d",&target,&money);
    scanf(" %d %d %d",&c.oilPrice,&c.parkPrice,&c.tolls);
    scanf(" %d",&bi.rentPrice);
    scanf(" %d %d",&b.fixedPrice,&b.Add);
    scanf(" %d",&m.oilPrice);
    CarCreate(&c,target);
    BikeCreate(&bi,target);
    BusCreate(&b,target);
    MotoCreate(&m,target);
    compare(&c,&bi,&b,&m,money);
}
