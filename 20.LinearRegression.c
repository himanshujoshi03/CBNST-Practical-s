#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter total data points: ");
    scanf("%d",&n);

    float X[n],Y[n],X2[n],XY[n],xS=0,yS=0,x2S=0,xyS=0;
    printf("Enter values of x and y respectively: ");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i]);
        xS+=X[i]; yS+=Y[i];
    }
    for(int i=0;i<n;i++){
        X2[i]=pow(X[i],2);
        XY[i]=X[i]*Y[i];
        x2S+=X2[i];
        xyS+=XY[i];
    }

    float a,b;
    b=(n*xyS-xS*yS)/(n*x2S-(pow(xS,2)));
    a=(yS-b*xS)/n;

    printf("Equation is y=%0.2fx + %0.2f.\n",b,a);
    return 0;
}