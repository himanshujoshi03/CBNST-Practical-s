#include<stdio.h>

void calculateBackwardTable(int n,float Y[][n]){
    for(int i=1;i<n;i++){
        for(int j=n-1;j>i-1;j--){
            Y[j][i]=Y[j][i-1]-Y[j-1][i-1];
        }
    }
}

int main()
{
    int n;
    printf("Enter total data points: ");
    scanf("%d",&n);

    float X[n],Y[n][n],x,y,u,unew,fact=1;
    printf("Enter values of X and Y respectively\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i][0]);
    }

    printf("Newton Backward Table.\n");
    calculateBackwardTable(n,Y);
    for(int i=0;i<n;i++){
        printf("%0.2f\t",X[i]);
        for(int j=0;j<=i;j++){
            printf("%0.2f\t",Y[i][j]);
        }
        printf("\n");
    }

    printf("Enter value of x for which you want to calculate y: ");
    scanf("%f",&x);
    u=(x-X[n-1])/(X[1]-X[0]);
    y=Y[n-1][0];
    unew=u;

    for(int i=1;i<n;i++){
        y+=(unew*Y[n-1][i])/fact;
        fact=fact*(i+1);
        unew=unew*(u+i);
    }
    printf("Value of y at x = %f is %f.\n",x,y);
    return 0;
}