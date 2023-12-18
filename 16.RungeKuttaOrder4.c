#include<stdio.h>

float f(float x,float y){
    return y-x;
}

int main(){
    float x,y,h,xn,k1,k2,k3,k4,dy;
    printf("Enter values of x, y and h: ");
    scanf("%f %f %f",&x,&y,&h);
    printf("Enter value of xn: ");
    scanf("%f",&xn);
    while(1){
        if(x==xn) break;
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/2,y+k2/2);
        k4=h*f(x+h,y+k3);
        dy=(k1+2*(k2+k3)+k4)/6;
        y=y+dy; x=x+h;
    }
    printf("Value of y at x = %f is %f.\n",x,y);
}