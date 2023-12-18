#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    return (y-x)/(y+x);
}

int main()
{
    float x0,y0,x,y=0,h;
    printf("Enter values of x0,y0 and h respectively: ");
    scanf("%f %f %f",&x0,&y0,&h);

    printf("Enter value of x you want to find y: ");
    scanf("%f",&x);

    while(x0+h<=x){
        y=y0+h*f(x0,y0);
        y0=y;
        x0=x0+h;
    }
    printf("Value of y at x = %f is %f.\n",x,y);
    return 0;
}