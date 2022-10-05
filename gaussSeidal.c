#include<stdio.h>
#include<math.h>
 
int main()
{
      int count, t, limit;
      float temp, error, a, sum = 0; 
      float matrix[10][10], y[10], allowed_error;
      printf("\nEnter the Total Number of Equations:\t");
      scanf("%d", &limit);
      printf("Enter Allowed Error:\t");
      scanf("%f", &allowed_error);
      printf("\nEnter the Co-Efficients\n");
      for(count = 1; count <= limit; count++){
            for(t = 1; t <= limit + 1; t++){
                  printf("Matrix[%d][%d] = ", count, t);
                  scanf("%f", &matrix[count][t]);
            }
      }
      for(count = 1; count <= limit; count++){
            y[count] = 0;
      }
      do{
            a = 0;
            for(count = 1; count <= limit; count++){
                  sum = 0;
                  for(t = 1; t <= limit; t++){
                        if(t != count){
                              sum = sum + matrix[count][t] * y[t];
                        }
                  }
                  temp = (matrix[count][limit + 1] - sum) / matrix[count][count];
                  error = fabs(y[count] - temp);
                  if(error > a){
                        a = error;
                  }
                  y[count] = temp;
                  printf("\nY[%d]=\t%f", count, y[count]);
            }
            printf("\n");
      }
      while(a >= allowed_error);
      printf("\n\nSolution\n\n");
      for(count = 1; count <= limit; count++){
            printf("\nY[%d]:\t%f", count, y[count]);
      }
      return 0;
}




#include<stdio.h>
#include<math.h>

/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function */
#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 clrscr();
 printf("Enter tolerable error:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do{
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

 return 0;
}