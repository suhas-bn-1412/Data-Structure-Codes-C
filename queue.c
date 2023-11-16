#include<stdlib.h>
#include<stdio.h>

int insert(int,int*,int*,int*,int);
 int remove1(int *,int *, int*);
 void display(int *,int,int);
main()
{
  
  int *q;
  int ch,k,x;
   int f,r, size;
  f=r=-1;
  printf("Enter the size of the queue..");
  scanf("%d",&size);

  q=(int*)malloc(sizeof(int)*size);
  while(1)
  {
    display(q,f,r);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=insert(x,q,&f,&r,size);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=remove1(q,&f,&r);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

    int remove1(int *q, int *f, int *r)
  {
     int x;
     if(*f==-1)//check for queue underflow
     {
      printf("Queue empty..\n");
      return -1;
     }
     x=q[*f];
     if(*f==*r)//only one element in queue
       *f=*r=-1;
     else
       ++*f;
     return x;
  }


    
  int insert(int x,int *q,int *f,int *r,int size)
  {
    //check for Queue overflow
    if(*r==size-1)
    {
     printf("Queue overflow..cannot insert");
     return -1;
    }
    (*r)++;//or ++*r//increment rear
    q[*r]=x;
    if(*f==-1)//if first element
      *f=0;
     return 1;
  }

  
   void display(int *q, int f, int r)
   {
      int i;
      if(f==-1)
        printf("Empty Queue..\n");
      else
       {
         for(i=f;i<=r;i++)
           printf("%d  ",q[i]);
       }
      printf("\n");
  } 








