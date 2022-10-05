#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define e 0.0001
#define f(x) (x*x*x - 4*x +1 )
#define df(x) (3*x*x - 4)

int main(){
    float x0,x1,f0,f1,df0;
    int k=0;
    printf("Enter the value of x0 ");
    scanf("%f",&x0);

    do{
        k++;
        f0=f(x0);
        df0=df(x0);
        x1=x0-(f0/df0);
        f1=f(x1);
        x0=x1;

        printf("\n\n iteratoin %d   root= %f    value of function= %f\n\n",k,x1,f1);
    }while(fabs(f1)>e);
    printf(" Real Root = %f ", x1);
    return 0;
}

