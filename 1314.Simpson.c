#include<stdio.h>
#include<math.h>

float f(float x){
    return (1/(pow(x,2)+1));
}

void simpson13(float a,float b,int n,float h,float y){
    int cnt=1;
    for(int i=1;i<n;i++){
        y+=(cnt%2==0)?(2*f(a+i*h)):(4*f(a+i*h));
        cnt++;
    }
    y=(h/3)*y;
    printf("Value of integral is %f.\n",y);
}

void simpson38(float a,float b,int n,float h,float y){
    int cnt=1;
    for(int i=1;i<n;i++){
        y+=(cnt%3==0)?(2*f(a+i*h)):(3*f(a+i*h));
        cnt++;
    }
    y=(3*h/8)*y;
    printf("Value of integral is %f.\n",y);
}

int main(){
    float a,b,h,y=0; //h=step
    printf("Enter intervals (a,b): ");
    scanf("%f %f",&a,&b);
    int n,ch;
    printf("Enter number of sub-intervals not points: ");
    scanf("%d",&n);

    h=(b-a)/n;
    y=f(a)+f(b);

    do{
        printf("Enter 1 for simpson 13, 2 for simpson38: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                simpson13(a,b,n,h,y);
                break;
            case 2:
                simpson38(a,b,n,h,y);
                break;
            default:printf("Wrong input try again.\n");
        }
        if(ch==1 || ch==2) break;
    }while(1);
    return 0;
}
