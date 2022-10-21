#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14
#define ShapeText(TYPE)\
    char name[10];\
    double (*perimeter)(struct TYPE*);\
    double (*area)(struct TYPE*);
typedef struct _Shape{
    ShapeText(_Shape);
}Shape;
typedef struct _Circle{
    ShapeText(_Circle);
    double radius;
}Circle;
typedef struct _Rectangle{
    ShapeText(_Rectangle);
    double length;
    double width;
}Rectangle;
typedef struct _Square{
    ShapeText(_Square);
    double edge;
}Square;
typedef struct _Triangle{
    ShapeText(_Triangle);
    double edge1;
    double edge2;
    double edge3;
}Triangle;
double ShapePerimeter(Shape *obj) { return 0; }
double ShapeArea(Shape *obj) { return 0; }
void ShapeNew(Shape *obj) {
    scanf(" %c",obj->name);
    obj->perimeter=ShapePerimeter;
    obj->area=ShapeArea;
}
double CirclePerimeter(Circle *obj) { return obj->radius*2*PI; }
double CircleArea(Circle *obj) { return obj->radius*obj->radius*PI; }
void CircleNew(Circle *obj) {
    strcpy(obj->name,"circle");
    obj->perimeter=CirclePerimeter;
    obj->area=CircleArea;
}
double RectanglePerimeter(Rectangle *obj) { return obj->length*2+obj->width*2; }
double RectangleArea(Rectangle *obj) { return obj->length*obj->width; }
void RectangleNew(Rectangle *obj) {
    strcpy(obj->name,"rectangle");
    obj->perimeter=RectanglePerimeter;
    obj->area=RectangleArea;
}
double SquarePerimeter(Square *obj) { return obj->edge*4; }
double SquareArea(Square *obj) { return obj->edge*obj->edge; }
void SquareNew(Square *obj) {
    strcpy(obj->name,"square");
    obj->perimeter=SquarePerimeter;
    obj->area=SquareArea;
}
double TrianglePerimeter(Triangle *obj) { return obj->edge1+obj->edge2+obj->edge3; }
double TriangleArea(Triangle *obj){
    double s;
    s=(obj->edge1+obj->edge2+obj->edge3)/2;
    return sqrt(s*(s-obj->edge1)*(s-obj->edge2)*(s-obj->edge3));
}
void TriangleNew(Triangle *obj) {
    strcpy(obj->name,"triangle");
    obj->perimeter=TrianglePerimeter;
    obj->area=TriangleArea;
}
int main(){
    int number;
    double all_perimeter=0,all_area=0;
    scanf(" %d",&number);
    for(int i=0;i<number;i++){
        Shape s;
        ShapeNew(&s);
        if(strncmp(s.name,"C",1)==0){
            Circle c;
            scanf(" %lf",&c.radius);
            CircleNew(&c);
            printf("%.2f %.2f\n",c.perimeter(&c),c.area(&c));
            all_perimeter+=c.perimeter(&c);
            all_area+=c.area(&c);
        }
        else if(strncmp(s.name,"R",1)==0){
            Rectangle r;
            scanf(" %lf %lf",&r.length,&r.width);
            RectangleNew(&r);
            printf("%.2f %.2f\n",r.perimeter(&r),r.area(&r));
            all_perimeter+=r.perimeter(&r);
            all_area+=r.area(&r);
        }
        else if(strncmp(s.name,"S",1)==0){
            Square s;
            scanf(" %lf",&s.edge);
            SquareNew(&s);
            printf("%.2f %.2f\n",s.perimeter(&s),s.area(&s));
            all_perimeter+=s.perimeter(&s);
            all_area+=s.area(&s);
        }
        else if(strncmp(s.name,"T",1)==0){
            Triangle t;
            scanf(" %lf %lf %lf",&t.edge1,&t.edge2,&t.edge3);
            TriangleNew(&t);
            printf("%.2f %.2f\n",t.perimeter(&t),t.area(&t));
            all_perimeter+=t.perimeter(&t);
            all_area+=t.area(&t);
        }
    }
    printf("%.2f %.2f",all_perimeter,all_area);
}
