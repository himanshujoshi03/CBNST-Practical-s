#include<stdio.h>
#include<math.h>

float f(float x){
    return (cos(x)-x*exp(x));
}

int main()
{
    float x,x0,x1,error; int itr=0;
    do{
        printf("Enter values of x0 and x1: ");
        scanf("%f %f",&x0,&x1);
        if((f(x0)*f(x1))<0){
            printf("Root lies between %f and %f.\n",x0,x1);
            break;
        }
        else{
            printf("Wrong interval, please try again.\n");
        }
    }while(1);
    printf("Enter allowed error: ");
    scanf("%f",&error);
    do{
        itr++;
        x=x0-((x1-x0)/(f(x1)-f(x0)))*f(x0);
        printf("Iteration %d, value of f(%f) is %f.\n",itr,x,f(x));
        if(fabs(f(x))<error){
            printf("Root of equation is %f after %d iteration.\n",x,itr);
            break;
        }
        else if((f(x)*f(x0))<0){
            x1=x;
        }
        else{
            x0=x;
        }
    }while(1);
    return 0;
}
