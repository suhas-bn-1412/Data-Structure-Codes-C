#include<stdio.h>
void push(int *, int *,int);
int pop(int*,int*);
int isoper(char);
int postfix_eval(char*);
int main()
{
 char postfix[100];
 printf("\nenter the postfix expression\n");
 scanf("%s",postfix);
 int result=postfix_eval(postfix);
 printf("\nthe result=%d\n",result);
}

  int postfix_eval(char *postfix)
  {
    int i,r;
    char ch;
    i=0;
    int s[10];//stack;
    int top=-1;
    while(postfix[i]!='\0')
    {
      ch=postfix[i];
      if(isoper(ch))//if ch is an operator
      {
        int op1=pop(s,&top);
        int op2=pop(s,&top);
        switch(ch)
        {
          case '+':r=op1+op2;
                   push(s,&top,r);
                   break;

          case '-':r=op2-op1;
                   push(s,&top,r);
                   break;

          case '*':r=op1*op2;
                   push(s,&top,r);
                   break;
          case '/':r=op2/op1;
                   push(s,&top,r);
                   break;
       }
     }
      else//if operand
       push(s,&top,ch-'0');
     i++;
    }//end while
   return(pop(s,&top));  
}





  void push(int *s,int *t,int x)
  {
   ++*t;//increment top
   s[*t]=x;
  }

  int pop(int *s, int *t)
  {
   int x;
    x=s[*t];
    --*t;//decrement top
    return x;
  }

  int isoper(char ch)
  {
    if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))
      return 1;
    return 0;
   }






