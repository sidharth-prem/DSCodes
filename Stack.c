#include<stdio.h>
void main(){
    int s[10],top=-1,n,i,ch,x,y;
 printf("enter size of array:");
 scanf("%d",&n);
 do
 {
  
  printf("1.Push\n");
  printf("2.Pop\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  printf("Enter your choice:\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: if(top==n-1)
          printf("Stack Overflow\n");
          else
          {
            printf("Enter element:");
           top++;
           scanf("%d",&x);
           s[top]=x;
          }
          break;
   case 2: if(top==-1)
          printf("Stack Underflow");
          else
          {
           y=s[top];
           printf("Element Popped is %d\n",y);
          }
          top--;
          break;
   case 3: if(top==-1)
           printf("Stack is empty");
            printf("Elements available are:\n");
            for(i=top;i>=0;i--)
            {
                printf("%d\n",s[i]);
          }
          
          break;
   case 4: break;
   default: printf("Invalid Choice\n");
   }
  }while(ch!=4);
 }                          
  
