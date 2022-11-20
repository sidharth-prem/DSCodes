#include <stdio.h>
void main()
{
int i,n,ch,c,Q[10],F=-1,R=-1,X,Y;
printf("Enter the size of the queue \n");
scanf("%d",&n);
do
{
  printf("MENU:\n");
  printf("1-INPUT RESTRICTED DEQUE\n");
  printf("2-OUTPUT RESTRICTED DEQUE\n");
  printf("3-EXIT\n");
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: do
            {
              printf("****OPERATION MENU****\n");
              printf("1-INSERTION THROUGH REAR\n");
              printf("2-DELETION THROUGH REAR\n");
              printf("3-DELETION THROUGH FRONT\n");
              printf("4-DISPLAY\n");
              printf("5-EXIT\n");
              printf("ENTER YOUR CHOICE: ");
              scanf("%d",&c);
              switch(c)
              {
                case 1: if ((R==n-1 && F==0)||(F==R+1))
                        {
                          printf("QUEUE OVERFLOW.\n");
                          break;
                        }
                        else if(R==n-1)
                        {
                          R=0;
                        }
                        else
                        {
                          R++;
                        }
                        printf("Enter element to INSERT: ");
                        scanf("%d",&X);
                        Q[R]=X;
                        if(F==-1)
                        {
                          F=0;
                        }    
                    break;
                case 2:if (F==-1)
                        {
                          printf("QUEUE UNDERFLOW.\n");
                        }
                        else
                        {
                          Y=Q[R];
                          printf("Element DELETED is: %d\n",Y);
                        }
                        if(F==R)
                        { 
                          F=-1;
                          R=-1;
                        }
                        else
                        {
                          if(R==0)
                          {
                            R=n-1;
                          }
                          else
                          {
                            R=R-1;
                          }    
                        }
                    break;
                  case 3: if(F==-1)
                          {
                            printf("OUEUE UNDERFLOW.\n");
                          } 
                          else
                          {
                            Y=Q[F];
                            printf("Element DELETED is: %d\n",Y);
                            if(F==R)
                            {
                              F=-1;
                              R=-1;
                            }
                            else
                            {
                              if(F==n-1)
                                F=0;
                              else
                                F++;
                            }
                          }
                      break;
                  case 4: if(F==-1)
                          {
                            printf("QUEUE UNDERFLOW.");
                          }
                          else if(F<R)
                          {
                            for(i=F; i<=R; i++)
                                printf("%d ",Q[i]);
                          }
                          else(F>R)
                          ;{ 
                             for(i=F; i<n; i++)
                                printf("%d ",Q[i]);
                          }
                          printf("\n");
                      break;
                  case 5: printf("Exitted.\n");
                      break;
                  default: printf("INVALID CHOICE.\n");
              }
            }while(c!=5);
        break;
    case 2: do
            {
              printf("****OPERATION MENU****\n");
              printf("1-INSERTION THROUGH REAR\n");
              printf("2-INSERTION THROUGH FRONT\n");
              printf("3-DELETION THROUGH FRONT\n");
              printf("4-DISPLAY\n");
              printf("5-EXIT\n");
              printf("ENTER YOUR CHOICE: ");
              scanf("%d",&c);
              switch(c)
              {
                case 1:if ((R==n-1 && F==0)||(F==R+1))
                        {
                          printf("QUEUE OVERFLOW.\n");
                        } 
                        else
                        {
                          if (R==n-1)
                              R=0;
                          else
                              R++;
                          printf("Enter element to INSERT: ");
                          scanf("%d",&X);
                          Q[R]=X;
                        }
                        if(F==-1)
                          F=0;
                    break;
                case 2: if ((R==n-1 && F==0)||(F==R+1))
                            printf("QUEUE OVERFLOW.\n");
                        else
                        {
                          if((F==-1)||(F==0))
                              F=n-1;
                          else
                          {
                              F--;
                              printf("Enter element to INSERT: ");
                              scanf("%d",&X);
                              Q[F]=X;
                          }
                          if(R==-1)
                              R=n-1;
                        }
                    break;
                case 3: if(F==-1)
                            printf("QUEUE UNDERFLOW.\n");
                        else
                        {
                            Y=Q[F];
                            printf("Element DELETED is: %d\n",Y);
                            if(F==R)
                            {
                              F=-1;
                              R=-1;
                            }
                            else
                            {
                              if(F==n-1)
                                F=0;
                              else
                                F++;
                            }
                        }
                    break;
                case 4: if(F==-1)
                            printf("QUEUE UNDERFLOW.\n");
                        else
                        {
                          if(F<R)
                          { 
                            for(i=F; i<=R; i++)
                                printf("%d ",Q[i]);
                          } 
                          else if(F>R)
                          { 
                            for(i=F; i<n; i++)
                                printf("%d ",Q[i]);
                            for (i=0; i<=R; i++)
                                printf("%d ",Q[i]);
                            printf("\n");  
                          }
                        }
                    break;
                case 5: printf("Exiting\n");
                        break;
                default: printf("INVALID CHOICE.\n");
              }
            }while(c!=5);
        break;
    case 3: printf("Exiting the program!\n");
            break;
    default: printf("INVALID CHOICE.\n");
  }  
}while(ch!=3);
}





            
            
            
            
            
            
                
