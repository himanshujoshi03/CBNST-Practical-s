#include<math.h>
#include<stdio.h>

float f(float x){
    return (cos(x)+1)/3;
}

float fd(float x){
    return (-sin(x)/3);
}

int main()
{
    float x0,x,error; int itr=0;
    do{
        printf("Enter value of x0: ");
        scanf("%f",&x0);
        if(fabs(fd(x0))<1){
            printf("Root can be found.\n");
            break;
        }
        else
        {
            printf("Wrong interval, try again.\n");
        }
    }while(1);
    printf("Enter allowed error: ");
    scanf("%f",&error);
    do{
        itr++;
        x=f(x0);
        printf("Iteration %d, value of x is %f.\n",itr,x);
        if(fabs(x0-x)<error){
            printf("Root of equation is %f after %d iterations.\n",x,itr);
            break;
        }
        x0=x;
    }while(1);
    return 0;
}
