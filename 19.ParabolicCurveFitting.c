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

    float a=X[1],b=X[2],c=X[3];

    printf("Equation: y=%.2f + %.2fx + %0.2fx^2",a,b,c);
}

int main(){
    int n;
    printf("Enter total data points: ");
    scanf("%d",&n);
    float X[n],Y[n],table[10][10],xS=0,yS=0,x2S=0,x3S=0,x4S=0,xyS=0,x2yS=0;
    printf("Enter data points X and Y respectively\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&X[i],&Y[i]);
    }

    for(int i=0;i<n;i++){
        xS+=X[i]; yS+=Y[i]; x2S+=(X[i]*X[i]); x3S+=(X[i]*X[i]*X[i]);
        x4S+=(X[i]*X[i]*X[i]*X[i]); xyS+=(X[i]*Y[i]);
        x2yS+=(X[i]*X[i]*Y[i]);
    }

    table[1][1]=n, table[1][2]=xS, table[1][3]=x2S, table[1][4]=yS;
    table[2][1]=xS, table[2][2]=x2S, table[2][3]=x3S, table[2][4]=xyS;
    table[3][1]=x2S, table[3][2]=x3S, table[3][3]=x4S, table[3][4]=x2yS;

    gaussJordon(3,table);
    return 0;
}