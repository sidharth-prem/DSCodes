#include<stdio.h>
#include<stdlib.h>
void main()
{
	int DATA;
	struct node
	{
		int data;
		struct node *link;
	}*ptr=NULL,*start=NULL,*new=NULL,*temp=NULL;
	int ch;
	do
	{
		printf("\nSingly Linked List\n");
		printf("***MENU***\n");
		printf("1. Insert at beginning \n");
		printf("2. Insert at end \n");
		printf("3. Insert after an element S \n");
		printf("4. Delete from beginning \n");
		printf("5. Delete from end \n");
		printf("6. Delete a particular element \n");
		printf("7. Display \n");
		printf("8. Exit \n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		  case 1:
			new = (struct node*)malloc(sizeof(struct node));
			if(new == NULL)
			{
				printf("Can't allocate memory due to insufficient memory!");
				
			}
			else
			{
				printf("Enter the value: \n");
				scanf("%d",&new->data);
				new->link=start;
				start = new;
			}
				printf("\n");
				break;

		  case 2:
			new = (struct node*)malloc(sizeof(struct node));
			if(new == NULL)
			{
				printf("Can't allocate memory due to insufficient memory!");
				
			}
			else
			{
				printf("Enter the value: \n");
				scanf("%d",&new->data);
				if(start == NULL)
				{
				start = new;
				new->link=NULL;
				}
				else
				{	
				ptr = start;
				while(ptr->link!=NULL)
					ptr=ptr->link;
				ptr->link=new;
				new->link=NULL;
				}
			}
			printf("\n");
			break;
	  	 case 3:
			
			new = (struct node*)malloc(sizeof(struct node));
			if(new == NULL)
		{
			printf("Can't allocate memory due to insufficient memory!");
			
		}
		if(start==NULL)
		{
			printf("List is empty, element cannot be inserted in between.\n");
			
		}
		else
		{
			printf("Enter value to be entered: \n");
			scanf("%d",&new->data);
			printf("Enter the value after which the new element should be inserted: \n");
			scanf("%d",&DATA);
			ptr=start;
			while(ptr->data!=DATA)
				ptr=ptr->link;
			new->link=ptr->link;
			ptr->link=new;
		}
		printf("\n");
		break;
	
		case 4:
		if(start==NULL)
			printf("List empty!");
		else
		{
			ptr=start;
			start=start->link;
			free(ptr);
		}
		printf("\n");
		break;
		
		case 5:
		if(start==NULL)
			printf("List empty!");
		else
		{
			ptr=start;
			while(ptr->link!=NULL)
			{
				temp=ptr;
				ptr=ptr->link;
			}
			free(ptr);
			temp->link=NULL;
		}
		printf("\n");
		break;
		
		case 6:
		
		if(start==NULL)
		{
			printf("List is empty, element cannot be deleted!\n");
			
		}
		else
		{
		    printf("Enter the element that should be deleted in between:\n");
		    scanf("%d",&DATA);
			ptr=start;
			while(ptr->data!=DATA)
			{
				temp=ptr;
				ptr=ptr->link;
			}
			temp->link=ptr->link;
			free(ptr);
		}
		printf("\n");
		case 7:
		      
		    printf("\n");
		 
		    if(start==NULL)
		    {
		       printf("There are no elements!");
		    }
		    else
		    {
		       printf("ELEMENTS IN list are :");
		       temp=start;
		       while(temp->link!=NULL)
		       {
		          printf("%d  ",temp->data);
		          temp=temp->link;
		       }
		       printf("%d  ",temp->data);
		    }
		 break;
		case 8:
			printf("Exiting the Program!!!\n");
		 	exit(1);		 
		default : printf("Wrong choice! \n ");
		}
	}while(ch<9);
}


