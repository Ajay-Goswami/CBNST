#include<stdio.h>
int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10];
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    /* Now finding the elements of diagonal matrix */
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}





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
      for(count = 1; count <= limit; count++)
      {
            for(t = 1; t <= limit + 1; t++)
            {
                  printf("Matrix[%d][%d] = ", count, t);
                  scanf("%f", &matrix[count][t]);
            }
      }
      for(count = 1; count <= limit; count++)
      {
            y[count] = 0;
      }
      do
      {
            a = 0;
            for(count = 1; count <= limit; count++)
            {
                  sum = 0;
                  for(t = 1; t <= limit; t++)
                  {
                        if(t != count)
                        {
                              sum = sum + matrix[count][t] * y[t];
                        }
                  }
                  temp = (matrix[count][limit + 1] - sum) / matrix[count][count];
                  error = fabs(y[count] - temp);
                  if(error > a)
                  {
                        a = error;
                  }
                  y[count] = temp;
                  printf("\nY[%d]=\t%f", count, y[count]);
            }
            printf("\n");
      }
      while(a >= allowed_error);
      printf("\n\nSolution\n\n");
      for(count = 1; count <= limit; count++)
      {
            printf("\nY[%d]:\t%f", count, y[count]);
      }
      return 0;
}





#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
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

/* Main function */
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 clrscr();
 printf("Enter tolerable error:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

 getch();
 return 0;
}