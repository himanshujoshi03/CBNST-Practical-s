#include<stdio.h>
#include<math.h>

void convertToUpperTriangular(int n,float A[][n+1]){
    float ratio=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                ratio=A[j][i]/A[i][i];
                for(int k=0;k<n+1;k++){
                    A[j][k]-=(ratio*A[i][k]);
                }
            }
        }
    }
}
void applyBackwardSubstitution(int n,float A[][n+1],float value[]){
    float sum=0;
    value[n-1]=A[n-1][n]/A[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        sum=0;
        for(int j=i+1;j<n;j++){
            sum+=A[i][j]*value[j];
        }
        value[i]=(A[i][n]-sum)/A[i][i];
    }
}

int main()
{
    int n;
    printf("Enter number of unknown variables: ");
    scanf("%d",&n);
    float A[n][n+1],value[n];
    printf("Enter elements in augmented matrix.\n");
    for(int i=0;i<n;i++){
        printf("Enter elements in %d row: ",i+1);
        for(int j=0;j<n+1;j++){
            scanf("%f",&A[i][j]);
        }
    }

    convertToUpperTriangular(n,A);
    printf("Upper triangular matrix.\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++)
        {
            printf("%0.4f\t",A[i][j]);
        }
        printf("\n");
    }

    applyBackwardSubstitution(n,A,value);
    printf("Unknown variables are: ");
    for(int i=0;i<n;i++){
        printf("%0.4f    ",value[i]);
    }
    return 0;
}