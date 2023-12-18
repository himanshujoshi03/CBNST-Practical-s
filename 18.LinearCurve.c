#include<stdio.h>

void gaussJordon(int n,float table[10][10]){
    float ratio=0,X[10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j!=i){
                ratio=table[j][i]/table[i][i];
                for(int k=1;k<=n+1;k++){
                    table[j][k]-=(ratio*table[i][k]);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        X[i]=table[i][n+1]/table[i][i];
    }

    float a=X[1],b=X[2];

    printf("Equation: y = %.2fx + %.2f",b,a);
}

int main(){
    int n;
    printf("Enter no of points: ");
    scanf("%d",&n);

    float X[n],Y[n],table[10][10],xS=0,yS=0,x2S=0,xyS=0;

    printf("Enter data points X and Y respectively: ");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i]);
    }

    for(int i=0;i<n;i++){
        xS+=X[i];
        yS+=Y[i];
        x2S+=(X[i]*X[i]);
        xyS+=(X[i]*Y[i]);
    }

    table[1][1]=n,table[1][2]=xS,table[1][3]=yS;
    table[2][1]=xS,table[2][2]=x2S,table[2][3]=xyS;

    gaussJordon(2,table);
    return 0;
}
