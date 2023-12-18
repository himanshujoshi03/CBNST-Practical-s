#include<stdio.h>

void calculateForwardTable(int n,float Y[][n]){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            Y[j][i]=Y[j+1][i-1]-Y[j][i-1];
        }
    }
}

int main(){
    int n;
    printf("Enter total data points: ");
    scanf("%d",&n);
    float X[n],Y[n][n],x,y,u,unew,fact=1;
    printf("Enter data points in form of x and y respectively: ");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i][0]);
    }

    printf("Forward Differennce Table\n");
    calculateForwardTable(n,Y);
    for(int i=0;i<n;i++){
        printf("%0.2f\t",X[i]);
        for(int j=0;j<n-i;j++){
            printf("%0.2f\t",Y[i][j]);
        }
        printf("\n");
    }
    printf("Enter value of x you want to calculate y: ");
    scanf("%f",&x);

    u=(x-X[0])/(X[1]-X[0]);
    y=Y[0][0];
    unew=u;

    for(int i=1;i<n;i++){
        y+=(unew*Y[0][i])/fact;
        fact=fact*(i+1);
        unew=unew*(u-i);
    }

    printf("Value of y at x = %f is %f.\n",x,y);
    return 0;
}