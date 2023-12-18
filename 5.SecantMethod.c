#include<stdio.h>
#include<math.h>

float f(float x){
//    return (x*log10(x)-1.2);
//    return (x*x*x-5*x+1);
return (x*x*exp(-x/2)-1);
}

int main()
{
    float x0,x1,x,error; int itr=0;
    do{
        printf("Enter intervals, x0 and x1: ");
        scanf("%f %f",&x0,&x1);
        if(f(x0)*f(x1)<0){
            printf("Root lies between %f and %f: ",x0,x1);
            break;
        }
        else{
            printf("Wrong interval, try again.\n");
        }
    }while(1);
    printf("Enter allowed error: ");
    scanf("%f",&error);
    do{
        itr++;
        x=x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);
        printf("Iteration %d, value of f(%f) is %f.\n",itr,x,f(x));
        if(fabs(f(x))<error){
            printf("Root of equation is %f after %d iterations.\n",x,itr);
            break;
        }
        else if(f(x)*f(x0)<0) x1=x;
        else x0=x;
//        x0=x1;
//        x1=x;
    }while(1);
    return 0;
}