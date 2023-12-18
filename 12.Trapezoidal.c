#include<stdio.h>
#include<math.h>

float f(float x){
    return (x/(pow(x,3)+10));
}

int main()
{
    float a,b,h,y=0; // h=step
    printf("Enter values of interval (a,b): ");
    scanf("%f %f",&a,&b);

    int n;
    printf("Enter number of sub-intervals: ");
    scanf("%d",&n);

    h=(b-a)/n;
    y=f(a)+f(b);

    for(int i=1;i<n;i++){
        y+=2*f(a+i*h);
    }

    y=(h/2)*y;
    printf("Value of integral is %f.\n",y);
    return 0;
}