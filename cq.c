#include<stdio.h>
void main()
{
    int Q[10],R=-1,F=-1,i,n,ch,x,y;
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i=0;i<10;i++)
        Q[i]=0;
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if((R==n-1 && F==0)||(F==R+1))
                    {
                        printf("Queue Overflow!\n");
                        break;
                    }
                    if(R==n-1)
                        R=0;
                    else
                    {
                        printf("Enter elements:\n");
                        R++;
                        scanf("%d", &x);
                        Q[R]=x;
                        if(F==-1)
                        {
                            F=0;
                        }
                        
                    }
                    break;
            case 2: if(F==-1)
                    {
                            printf("Queue Underflow!\n");
                            
                    }
                    else
                    {
                        y=Q[F];
                        printf("Deleted element is: %d\n", y);
                        
                        if(F==R)
                        {
                            F=-1;
                            R=-1;
                        }
                        else if(F==n-1)
                        {
                            F=0;
                        }
                        else
                            F++;
                        }
                        break;
                        
            case 3: if(F==-1)
                    {
                        printf("Empty Queue!\n");
                        break;
                    }
                    else
                    {
                        printf("Display elements:\n");
                        for(i=F;i<=R;i++)
                        {
                            printf("%d \n",Q[i]);
                        }
                        
                    }
                    break;
            case 4: 
                    printf("Exiting the program!\n");
                    break;
            default: printf("Invalid choice!\n");
        }
    }while(ch!=4);
}
