#include<stdio.h>
#include<stdlib.h>

struct node
{
   int coef;
   int expo;
   struct node *link;
   
}*ptr1=NULL,*first1=NULL,*first2=NULL,*ptr2,*new,*temp,*ptr3,*first3=NULL;

int i,ch=1;

void main()
{
printf("Enter FIRST polynomial : ");

while(ch!=2)
{
   printf("\n1. Insert\n2. Exit\n");
   scanf("%d",&ch);
   
   if(ch==1)
   {
   
   new=(struct node*)malloc(sizeof(struct node));
   
   printf("Enter the Coefficient : ");
   scanf("%d",&new->coef);
    
   printf("Enter the power : ");
   scanf("%d",&new->expo);
   
   if(first1==NULL)
   {
      first1=new;
      first1->link=NULL;
   }
   
   else
   {
   ptr1=first1;
   
   while(ptr1->link!=NULL)
      {
         ptr1=ptr1->link;
      }
   ptr1->link=new;
   new->link=NULL;
}

}
      
}

printf("Enter SECOND polynomial : ");
ch=1;

while(ch!=2)
{
   printf("\n1. Insert\n2. Exit\n");
   scanf("%d",&ch);
   if(ch==1)
   {
   new=(struct node*)malloc(sizeof(struct node));
   
   printf("Enter the Coefficient : ");
   scanf("%d",&new->coef);
   
   printf("Enter the Power : ");
   scanf("%d",&new->expo);
   
   if(first2==NULL)
   {
      first2=new;
      first2->link=NULL;
   }
   else
   {
   ptr2=first2;
   while(ptr2->link!=NULL)
      {
         ptr2=ptr2->link;
      }

   ptr2->link=new;
   new->link=NULL;
}
     
}

}


//POLYNOMIAL ADDITION 

ptr1=first1;
ptr2=first2;
while(ptr1!=NULL && ptr2!=NULL)
   {
      new=(struct node*)malloc(sizeof(struct node));
      if(ptr1->expo > ptr2->expo)
      {
         new->coef = ptr1->coef;
         new->expo=ptr1->expo;
         ptr1=ptr1->link;
      }
      
      else if (ptr2->expo > ptr1->expo )
      {
         new->coef = ptr2->coef;
         new->expo = ptr2->expo;
         ptr1 = ptr1->link;  
      }
      
      else
      {
         new->coef = ptr1->coef + ptr2->coef;
         new->expo = ptr1->expo;
         ptr1 = ptr1->link;
         ptr2 = ptr2->link;
      }
      
      if(first3==NULL)
      {
         first3 = new;
         temp=new;
         new->link=NULL;
      }
      
      else
      {
      temp->link=new;
      temp=new;
      new->link=NULL;
      }
   }
   
while(ptr1!=NULL)
   {
      new=(struct node*)malloc(sizeof(struct node));
      new->coef=ptr1->coef;
      new->expo=ptr1->expo;
      ptr1=ptr1->link;
      temp->link=new;
      temp=new;
      new->link=NULL;
   }

while(ptr2!=NULL)
   {
      new=(struct node*)malloc(sizeof(struct node));
      new->coef=ptr2->coef;
      new->expo=ptr2->expo;
      ptr2=ptr2->link;
      temp->link=new;
      temp=new;
      new->link=NULL;
   }

//DISPLAYING THE OUTPUT
ptr3=first3;
while(ptr3!=NULL)
   {
      printf("+%dx^",ptr3->coef);
      printf("%d\t",ptr3->expo);
      ptr3=ptr3->link;
   }


}

