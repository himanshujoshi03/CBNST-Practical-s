#include<stdio.h>
#include<math.h>

float f(float x){
//    return (x*x-12);
    return (x*log10(x)-1.2);
}

float fd(float x){
//    return (2*x);
    return (log10(x)+0.43429);
}

int main()
{
    float a,b,x0,x,error; int itr=0;
    do{
        printf("Enter the value of a and b: ");
        scanf("%f %f",&a,&b);
        if((f(a)*f(b))<0){
            printf("Root lies between %f and %f.\n",a,b);
            break;
        }
        else{
            printf("Wrong interval, try again.\n");
        }
    }while(1);
    printf("Enter allowed error: ");
    scanf("%f",&error);
    x0=(a+b)/2;
    do{
        if(fd(x0)!=0){
            itr++;
            x=x0-f(x0)/fd(x0);
            printf("Iteration %d, value of f(%f) is %f.\n",itr,x,f(x));
            if(fabs(f(x))<error){
                printf("Root of equation is %f after %d iteration.\n",x,itr);
                break;
            }
            x0=x;
        }
//        else{
//            printf("Sorry please manually enter x0: ");
//            scanf("%f",&x0);
//            itr=0;
//        }
    }while(1);
    return 0;
}
