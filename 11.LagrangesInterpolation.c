#include<stdio.h>

int main()
{
    int n;
    printf("Enter total data points: ");
    scanf("%d",&n);

    float X[n],Y[n],x,y=0,nr,dr;
    printf("Enter data points X and Y respectively\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i]);
    }

    printf("Enter value of x you want to calculate y: ");
    scanf("%f",&x);

    for(int i=0;i<n;i++){
        nr=dr=1;
        for(int j=0;j<n;j++){
            if(j!=i){
                nr*=(x-X[j]);
                dr*=(X[i]-X[j]);
            }
        }
        y+=(nr/dr)*Y[i];
    }

    printf("Value of y at x = %f is %f.\n",x,y);
    return 0;
}