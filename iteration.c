#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define   f(x)   cos(x)-3*x+1
#define   g(x)   (1+cos(x))/3

int main(){
    float x0,x1;
    int k=1;
    float e=0.0001;
    printf("Enter the initial guess x0 ");
    scanf("%f",&x0);

    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do{
        x1=g(x0);
        printf("%d\t%f\t%f\t%f\t%f\n",k, x0, f(x0), x1, f(x1));

        if(k>12){
		   printf("Not Convergent.");
		   exit(0);
		}

        x0=x1;
        k++;
    }while(fabs(f(x1))>e);
    printf("Root = %f and number of iteration = %d and value of function is f(x0)=%f", x1,k,f(x0));
    return 0;
}

