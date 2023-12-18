#include<stdio.h>
#include<math.h>

void convertToDiagonal(int n,float A[][n+1]){
    float ratio=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                ratio=A[j][i]/A[i][i];
                for(int k=0;k<n+1;k++){
                    A[j][k]-=(ratio*A[i][k]);
                }
            }
        }
    }
}

void valueArray(int n,float A[][n+1],float value[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i){
                value[i]=(A[i][n]/A[i][j]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter total number of unknowns: ");
    scanf("%d",&n);

    float A[n][n+1],value[n];
    printf("Enter element in augmented matrix.\n");
    for(int i=0;i<n;i++){
        printf("Enter element in %d row",i+1);
        for(int j=0;j<n+1;j++){
            scanf("%f",&A[i][j]);
        }
    }

    printf("Diagonal Matrix.\n");
    convertToDiagonal(n,A);
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("%0.2f\t",A[i][j]);
        }
        printf("\n");
    }

    valueArray(n,A,value);
    printf("Value of unknowns are: ");
    for(int i=0;i<n;i++){
        printf("%0.3f  ",value[i]);
    }
    return 0;
}