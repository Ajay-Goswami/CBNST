#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (x*x*x - 5*x -7 )

int main(){
    float x0,x1,x;
    int k=0;

    do{
        printf("Enter the range ");
        scanf("%f%f",&x0,&x1);
    }while(f(x0)*f(x1)>0);

    do{
        k++;
        x=x0-((f(x0)/ (f(x1)-f(x0)))*(x1-x0));
        if(f(x)<0)
            x0=x;
        else if(f(x)>0)
            x1=x;
        printf("\n\n x%d = %f   f(x%d) = %f\n\n",k,x,k,fabs(f(x)));
    }while(fabs(f(x))>0.0001 && k<12);
    printf("Root = %f and number of iteration = %d", x,k);
    return 0;
}
