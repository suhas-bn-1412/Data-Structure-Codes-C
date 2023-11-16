#include<stdio.h>

int main()
{
  int sum(int*,int);
  int sum1(int*,int,int);
  int min(int*,int,int);
  int result,m;
  int a[]={2,3,1,5,6};
  
  //result=sum(a,4);
   result = sum1(a,0,4);
  printf("\nSum = %d\n",result);
  m=min(a,0,4);
  printf("\nThe min = %d\n",m);
}
 
  int sum1(int* a, int l, int h)
  {
    //check if there is one element
    if(l==h)
      return a[l];
    //divide the array into two halves
    int m= (l+h)/2;
    int left=sum1(a,l,m);//find the sum of left half
     int right=sum1(a,m+1,h);//find the sum of right half
    return(left + right);
  }

  int min(int *a, int l, int h)
  {
    //check if there is one element
    if(l==h)
      return a[l];
    //divide the array into two halves
    int m= (l+h)/2;
    int left=min(a,l,m);//find the min of left half
     int right=min(a,m+1,h);//find the min of right half
     if(left <right)
       return left;
     return right;
  }



  int sum(int *a, int n)
  {
     int s=0;
    //check if one element
    if(n==0)
      return a[n];
    ///reduce the problem size by 1 and find the sum
    s=sum(a,n-1)+a[n];
    return s;
  }
  

 




