#include<stdio.h>
#include<stdlib.h>
#define N 10
float *remontee(float A[N][N],float B[N],int n)
{ 
  float *X;
  X=malloc(sizeof(float)*n);
  X[n-1]=B[n-1]/A[n-1][n-1];
  for(int i=n-2;i>=0;i--)
  {
   float s=0;
   for(int j=i+1;j<n;j++)
   {
    s+=A[i][j]*X[j];
   }
   X[i]=(B[i]-s)/A[i][i];
  }
  return X;
}

int main()
{
 float A[N][N],B[N];
 float *X;
 int n;
 printf("Enter the size of the matrix:\n");
 scanf("%d",&n);
 printf("Filling the matrix A\n");
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   printf("A[%d][%d] = ",i,j);
   scanf("%f",&A[i][j]);
  }
 }
 printf("Filing the vector B\n");
 for(int i=0;i<n;i++)
 {
  printf("B[%d] = ",i);
  scanf("%f",&B[i]);
 }
 X=remontee(A,B,n);
 printf("\n The resulting vector :[");
 for(int i=0;i<n;i++)
  printf("%f%c\n",X[i],",]"[i==n-1]);
}
