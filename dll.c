#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
void insert_head(struct node**, int);
void insert_tail(struct node **, int);
void delete_node(struct node**, int);
void delete_first(struct node **);
void delete_last(struct node **);
void display(struct node*);
int main()
{
  struct node *first;
  first=NULL;
  int x,ch,pos;
  while(1)
  {
    display(first);
    printf("\n1..Insert Head..\n");
    printf("2..Insert Tail..\n");
    printf("3..Delete First..\n");
    printf("4..Delete Last..\n");
    printf("5..Delete node..\n");
    printf("6..Delete at position\n");
    printf("7..Insert at position\n");
    scanf("%d",&ch);

    switch(ch)
    {
       case 1: printf("Enter the value..\n");
               scanf("%d",&x);
               insert_head(&first,x);
               break;
        case 2: printf("Enter the value..\n");
               scanf("%d",&x);
               insert_tail(&first,x);
               break;
         case 3:delete_first(&first);
                break;
         case 4:delete_last(&first);
                break;
         case 5: printf("Enter the value..\n");
               scanf("%d",&x);
               delete_node(&first,x);
               break;
        /*case 6: printf("Enter the position..\n");
               scanf("%d",&x);
               delete_pos(&first,x);
               break;
        case 7: printf("Enter the value and position..\n");
               scanf("%d %d",&x,&pos);
               insert_pos(&first,x,pos);
               break;*/

    }

  }
}

   void delete_first(struct node **p)
   {
     struct node *q;
     q=*p;
 
     if((q->prev==NULL)&&(q->next==NULL))//only one node
        *p=NULL;
     else //more than one node in the list
       {
           *p=q->next;
           (*p)->prev=NULL;
       }
     free(q);
    }

   void delete_last(struct node **p)
   {
     struct node *q;
     q=*p;
 
     if((q->prev==NULL)&&(q->next==NULL))//only one node
        *p=NULL;
     else //more than one node in the list
       {
          while(q->next!=NULL)
            q=q->next;
   
       q->prev->next=NULL;
       }
     free(q);
   }



   void delete_node(struct node**p, int x)
   {
      struct node *q;

      q=*p;

      //move forward in the list until the node is found
      while((q!=NULL)&&(q->data!=x))
          q=q->next;
      if(q!=NULL)//node found..or if(q->data==x)
      {
         if((q->prev==NULL)&&(q->next==NULL))//only one node in list
            *p=NULL;//make first NULL
         else if(q->prev==NULL)//first node
          {
             *p=q->next;
             (*p)->prev=NULL;
          }
         else if(q->next==NULL)//last node
             q->prev->next=NULL;
          else//somewhere in the middle
            {
              q->prev->next=q->next;
              q->next->prev=q->prev;
            }
          free(q);
      }
     else
       printf("Node not found...\n");
   }

  void insert_head(struct node**p,int x)
  {
    struct node *temp;

    //create a node

    temp=(struct node*)malloc(sizeof(struct node));    
    temp->data=x;
    temp->prev=temp->next=NULL;

   
    //is this the first node?
     if (*p==NULL)//checking the value in first
       *p=temp;//copy address of temp in first
     else//link new node to the first node
       {
          temp->next=*p;
          (*p)->prev=temp;
          *p=temp;
        }
  }


  void display(struct node *p)
   {
      if(p==NULL)
         printf("\nEmpty List..\n");
      else
        {
          while(p!=NULL)
          {
            printf("%d<->",p->data);
            p=p->next;
          }
        }
   }


  void insert_tail(struct node**p,int x)
  {
    struct node *temp,*q;

    //create a node
    temp=(struct node*)malloc(sizeof(struct node));    
    temp->data=x;
    temp->prev=temp->next=NULL;

    //check if this is the first node

    if(*p==NULL)
       *p=temp;
    else
     {
        //go to the end of the list
      q=*p;      
      while(q->next!=NULL)
        q=q->next;

      q->next=temp;//link the new node to the last node
      temp->prev=q;
     }
  }



         



















































  




    









