#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (x*x*x - 5*x -7 )
// float f(float x);

int main(){
    float x0,x1,x2;
    int k=0;
    float e=0.0001;
    printf("Enter the value of x0, x1 ");
    scanf("%f%f",&x0,&x1);

    if(f(x0)*f(x1)>0){
        printf("Value of x0 and x1 is wrong");
        printf("f(x0) = %f  , f(x1) = %f,   f(x0)*f(x1) = %f ",f(x0),f(x1),f(x1)*f(x0));
        return 0;
    }

    do{
        k++;
        x2=(x1+x0)/2;
        if(f(x2) == 0)
            break;
        else if(f(x2)<0)
            x0=x2;
        else if(f(x2)>0)
            x1=x2;
        printf("\n\n x%d = %f   f(x%d) = %f\n\n",k,x2,k,fabs(f(x2)));
    }while(fabs(f(x2))>e && k<12);
    printf("Root = %f and number of iteration = %d", x2,k);
    return 0;
}

// float f(float x)
// {
//    return (x*x*x -x -1 );
// }
