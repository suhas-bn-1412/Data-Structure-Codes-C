#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  int *p;
  int i;
  printf("Enter the size of the array\n");
  scanf("%d",&n);

   p=(int*)malloc(sizeof(int)*n);

  printf("\nEnter tye elements..\n");
  for(i=0;i<n;i++)
   scanf("%d",(p+i));

  printf("\nprinting the elements..\n");

  for(i=0;i<n;i++)
   printf("%d  ",*(p+i));
}

