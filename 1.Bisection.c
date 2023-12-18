#include<stdio.h>
#include<math.h>

float f(float x){
    return (exp(x) -3*x);
}

int main()
{
    float x,x0,x1,error; int itr=0;
    do{
        printf("Enter values of x0 and x1 respectively: ");
        scanf("%f %f",&x0,&x1);
        if((f(x0)*f(x1))<0){
            printf("Root lies between %f and %f: ",x0,x1);
            break;
        }
        else{
            printf("Wrong intervals, please try again.\n");
        }
    }while(1);
    printf("Enter allowed error: ");
    scanf("%f",&error);
    do{
        itr++;
        x=(x0+x1)/2;
        printf("Iteration %d value of f(%f) is %f.\n",itr,x,f(x));
        if(fabs(f(x))<error){
            printf("The root of equation is %f and is founded at %d iteration: ",x,itr);
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