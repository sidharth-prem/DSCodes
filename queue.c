#include<stdio.h>
void main()
{
 int Q[10],R=-1,F=-1,i,n,ch,x,y;
 printf("enter size of array:");
 scanf("%d",&n);
 for(i=0;i<10;i++)
 Q[i]=0;
 do
 {
  printf("1.Insert\n");
  printf("2.Delete\n");
  printf("3.Display\n");
  printf("4.Exit\n");
  printf("Enter your choice:\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:if(R==n-1)
          {
          printf("Queue Overflow!");
          break;
          }
          else
          {
            printf("Enter elements:\n");
          R++;
           scanf("%d",&x);
          Q[R]=x;
           if(F==-1)
           {
           F=0;
           }
          }
          break;
   case 2:if(F==-1)
          {
          printf("Queue Underflow!");
          break;
          }
          else 
          {
           y=Q[F];
           printf("Deleted element is: %d",y);
           if(F==R)
           {
            F=-1;
            R=-1;
           }
           else
           {
            F++;
           }
          }
          break;
   case 3:if(F==-1)
          printf("Queue is Empty!");
          else
          {
            printf("Available elements are:\n");
           for(i=F;i<=R;i++)
           {
                printf("%d\n",Q[i]);
           }
          }
   case 4:break;
   default:printf("Invalid choice\n");
   }
  }while(ch!=4);
 }
