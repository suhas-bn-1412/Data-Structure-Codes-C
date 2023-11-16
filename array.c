#include<stdio.h>
main()
{
  void display(int* a, int );
  int a[4]={1,2,3,4};
  display(a,3);

}

  void display(int *a, int n)
  {
    int i;

    for(i=0;i<=n;i++)
    {
      printf("\nAddress of the %d element = %p\n",i,a);
      printf("The value of %d element = %d\n",i,*a);
       a++;
    }
  }
 
