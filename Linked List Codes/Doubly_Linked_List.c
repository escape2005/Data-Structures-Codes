/*	PROGRAM FOR DOUBLY LINKED LIST 	*/
// plz set new nodes llink and rlink first,
// this way we will not lose any side's node's address

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	struct Node *llink;
	int data;
	struct Node *rlink;
};

struct Node * start=NULL,*ptr=NULL,*I=NULL;

struct Node * GetNode()
{
	return((struct Node *) malloc(sizeof(struct Node)));
}

void delNode(struct Node *temp)
{
	temp->llink = NULL;
	temp->rlink = NULL;
	free(temp);
}

void CreateList();
int CountNodes();
void Insert();
void InsertBefore();
void InsertAfter();
void InsertAtPosition();
void Delete();
void DeleteByValue();
void DeleteAtPosition();
void Display();



void CreateList()
{
	struct Node *end = NULL;
	if(start!=NULL)
	{
		printf("\nTHE LIST IS ALREADY CREATED !");
		return;
	}
	do
	{
		I=GetNode();
		/*if(I == NULL)
		{
			printf("\n\nOVERFLOW!!");
			return;
		}*/

		printf("\n\nENTER THE DATA ==>\t");
		scanf("%d",&I->data);
		I->rlink=NULL;
		I->llink = end;

		if(start==NULL)
		{
			start=I;
		}
		else
		{
			end -> rlink=I;
		}

		end = I;

		printf("\nDO YOU WANT TO ADD MORE NODES ...(y/n) :\t");
	}while(toupper(getche())=='Y');
}

void main()
{
	int ch;
	do
	{
		clrscr();
		printf("\n\n********** CHOICES *********");
		printf("\n\n1 : CREATE LIST");
		printf("\n2 : INSERT A NODE");
		printf("\n3 : DELETE A NODE");
		printf("\n4 : DISPLAY LIST");
		printf("\n5 : EXIT");
		printf("\n\nENTER YOUR CHOICE : \t");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: // create list
			{
				CreateList();
				printf("\n\nNODES PRESENT : %d",CountNodes());
			}
			break;

			case 2: // insert node
			{
				Insert();
			}
			break;

			case 3: // delete node
			{
				Delete();
			}
			break;

			case 4: // display list
			{
				Display();
			}
			break;

			case 5: // exit
			break;

			default :
				printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
		}
		getch();
	}while(ch!=5);
}
void Insert()
{
	int ch;
	// we can check here - if the list is existing
	do
	{
		clrscr();

		printf("\n\n******* INSERT OPTIONS *******");
		printf("\n\n1 : INSERT BEFORE A NODE");
		printf("\n2 : INSERT AFTER A NODE");
		printf("\n3 : INSERT AT A POSITION");
		printf("\n4 : DISPLAY");
		printf("\n5 : BACK TO MAIN MENU");
		printf("\n\nENTER YOUR CHOICE : \t");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: // INSERT BEFORE
			{
				InsertBefore();
			}
			break;

			case 2: // insert after a node
			{
				InsertAfter();
			}
			break;

			case 3: // insert at a position
			{
				InsertAtPosition();
			}
			break;

			case 4: // display list
			{
				Display();
			}
			break;

			case 5: // BACK TO MAIN MENU
			return;
			//break;

			default :
				printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
		}
		getch();
	}while(1);		//while(ch!=5);
}

void InsertBefore()
{
	int val;
	struct Node * ptrAtValue;
	struct Node * I;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	printf("\n\nENTER THE DATA BEFORE WHICH NEW NODE TO BE INSERTED : \t");
	scanf("%d",&val);

	ptrAtValue = start;

	while( (ptrAtValue->data != val) && ptrAtValue!=NULL)
		ptrAtValue = ptrAtValue ->rlink;
	if(ptrAtValue == NULL)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	I = GetNode();
	printf("\n\nENTER THE DATA TO BE INSERTED : \t");
	scanf("%d",&I->data);

	I->llink = ptrAtValue->llink;
	I->rlink = ptrAtValue;

	if(ptrAtValue == start) // INSERT BEFORE FIRST
	{
		//start -> llink = I;
		start = I;
	}
	else
	{
		I -> llink -> rlink = I;
		//ptrAtValue -> llink = I;
	}
	ptrAtValue -> llink = I;
	//I -> rlink -> llink = I;
}

void InsertAfter()
{
	int val;
	struct Node * ptrAtValue;
	struct Node * I;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}

	printf("\n\nENTER THE DATA AFTER WHICH NEW NODE TO BE INSERTED : \t");
	scanf("%d",&val);

	ptrAtValue = start;

	while( (ptrAtValue->data != val) && ptrAtValue!=NULL)
		ptrAtValue = ptrAtValue ->rlink;
	if(ptrAtValue == NULL)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	I = GetNode();
	printf("\n\nENTER THE DATA TO BE INSERTED : \t");
	scanf("%d",&I->data);

	I->rlink = ptrAtValue->rlink;
	I -> llink = ptrAtValue;
	ptrAtValue -> rlink = I;
	if(I->rlink != NULL) // i.e. it is not the last node
		I->rlink->llink = I;
}

void InsertAtPosition()
{
	int pos,nodeCount,i;
	struct Node * ptrBeforePos;
	struct Node * I;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	nodeCount = CountNodes();
	printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
	printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount+1);

	//while(1)
	//{
		printf("\n\nENTER POSITION AT WHICH NEW NODE TO BE INSERTED : \t");
		scanf("%d",&pos);
		if(pos<1 || pos>nodeCount+1)
		{
			printf("\n\nINVALID VALUE !");
			return;
			/*
			Display();
			printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
			printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount+1);
			continue;*/
		}
		//break;
	//}
	I = GetNode();
	printf("\n\nENTER THE DATA TO BE INSERTED : \t");
	scanf("%d",&I->data);

	if(pos == 1)
	{
		I->rlink = start;
		start -> llink = I;
		I->llink = NULL;
		start = I;
		return;
	}
	ptrBeforePos = start;

	for(int i=0;i<pos-2;i++)
		ptrBeforePos = ptrBeforePos ->rlink;

	I->rlink = ptrBeforePos->rlink;
	I -> llink = ptrBeforePos;
	ptrBeforePos -> rlink = I;

	if(I->rlink != NULL) // i.e. it is not the last node
		I->rlink->llink = I;


}

void Delete()
{
	int ch;
	do
	{
		clrscr();
		// we can check here - if list is existing
		printf("\n\n******* DELETE OPTIONS *******");
		printf("\n\n1 : DELETE NODE BY VALUE");
		printf("\n2 : DELETE NODE AT A POSITION");
		printf("\n3 : DISPLAY");
		printf("\n4 : BACK TO MAIN MENU");
		printf("\n\nENTER YOUR CHOICE : \t");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: // DELETE BY VALUE
			{
				DeleteByValue();
			}
			break;

			case 2: // delete node at a position
			{
				DeleteAtPosition();
			}
			break;

			case 3: //display
			{
				Display();
			}
			break;

			case 4: // BACK TO MAIN MENU
			return;
			//break;

			default :
				printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
		}
		getch();
	}while(1);		//while(ch!=4);

}

void DeleteByValue()
{
	int val;
	struct Node * ptrAtValue;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	printf("\n\nENTER THE DATA OF NODE TO BE DELETED : \t");
	scanf("%d",&val);

	ptrAtValue = start;

	while( (ptrAtValue->data != val) && ptrAtValue!=NULL)
		ptrAtValue = ptrAtValue ->rlink;

	if(ptrAtValue == NULL)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	if(ptrAtValue == start) // DELETE FIRST NODE
	{
		start = start->rlink;
		if(start != NULL)
		{
			//ptrAtValue -> rlink -> llink = ptrAtValue -> llink;
			start -> llink = NULL;
		}
	}
	else if(ptrAtValue->rlink == NULL) // DELETE LAST NODE
	{
		ptrAtValue -> llink -> rlink = NULL;
	}
	else // DELETE A NODE IN BETWEEN
	{
		//ptrAtValue -> rlink -> llink = ptrAtValue -> llink;
		//ptrAtValue -> llink -> rlink = ptrAtValue -> rlink;
		ptrAtValue -> rlink -> llink = ptrAtValue -> llink;
		ptrAtValue -> llink -> rlink = ptrAtValue -> rlink;
	}
	printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtValue->data);
	delNode(ptrAtValue);
}

void DeleteAtPosition()
{
	int pos,nodeCount,i;
	struct Node *ptrAtPos;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	nodeCount = CountNodes();
	printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
	printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount);

	//while(1)
	//{
		printf("\n\nENTER POSITION OF NODE TO BE DELETED : \t");
		scanf("%d",&pos);
		if(pos<1 || pos>nodeCount)
		{
			printf("\n\nINVALID VALUE !");
			return;
			/*
			Display();
			printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
			printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount+1);
			continue;*/
		}
		//break;
	//}


	ptrAtPos = start;
	for(i=0;i<pos-1;i++)
		ptrAtPos = ptrAtPos ->rlink;

	if(ptrAtPos == start) // DELETE FIRST NODE
	{
		start = start->rlink;
		if(start != NULL)
		{
			//ptrAtPos -> rlink -> llink = ptrAtPos -> llink;
			start -> llink = NULL;
		}
	}
	else if(ptrAtPos->rlink == NULL) // DELETE LAST NODE
	{
		ptrAtPos -> llink -> rlink = NULL;
	}
	else // DELETE A NODE IN BETWEEN
	{
		ptrAtPos -> rlink -> llink = ptrAtPos -> llink;
		ptrAtPos -> llink -> rlink = ptrAtPos -> rlink;
	}
	printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtPos->data);
	delNode(ptrAtPos);
}


int CountNodes()
{
	struct Node * temp = start;
	int count = 0;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return 0;
	}
	while(temp != NULL)
	{
		temp = temp->rlink;
		count++;
	}
	return count;
}

void Display()
{
	struct Node * temp = start;
	if(temp == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	printf("\n");
	while(temp != NULL)
	{
		printf("%d",temp->data);
		if(temp->rlink != NULL)
			printf(" <-> ");
		temp = temp->rlink;
	}
}
/*
Delete All
Merge
concatenate
Divide
	- divide after nodea
	- divide at position
copy
sort
search
display reverse
create reverse
*/
