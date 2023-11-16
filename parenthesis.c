#include<stdio.h>
void push(char *s,int*,char);
char pop(char* s, int*);
int isempty(int);
int match(char *);
int main()
{
  char expr[10];
  printf("Enter the expression\n");
  scanf("%s",expr);
  int result=match(expr);
  if(result)
   printf("Matching of praenthesis succeeds\n");
 else
   printf("matching fails\n");
}
 
  int match(char *expr)
  {
    char s[10],ch,x;
    int i,top=-1;
    i=0;
    while(expr[i]!='\0')
    {
      ch=expr[i];
      switch(ch)
      {
         case '(':
         case '{':
         case '[':push(s,&top,ch);
                  break;
         case ')':if(!isempty(top))  
                  {   
                    x=pop(s,&top);
                    if(x=='(')//match succeeds,read the next character
                       break;
                    else
                      return 0;//mismatch of parenthesis
                  }
                  return 0;//extra closing parenthesis
        case '}':if(!isempty(top))  
                  {   
                    x=pop(s,&top);
                    if(x=='{')//match succeeds,read the next character
                       break;
                    else
                      return 0;//mismatch of parenthesis
                  }
                  return 0;//extra closing parenthesis
      case ']':if(!isempty(top))  
                  {   
                    x=pop(s,&top);
                    if(x=='[')//match succeeds,read the next character
                       break;
                    else
                      return 0;//mismatch of parenthesis
                  }
                  return 0;//extra closing parenthesis

       }
       i++;
    }
     if(isempty(top))
        return 1;
     return 0;//extra opening parenthesis
  }


  void push(char *s,int *t,char x)
  {
   ++*t;//increment top
   s[*t]=x;
  }

  char pop(char *s, int *t)
  {
    char x;
    x=s[*t];
    --*t;//decrement top
    return x;
  }

 

  int isempty(int top)
  {
    if(top==-1)
      return 1;
     return 0;
  }










