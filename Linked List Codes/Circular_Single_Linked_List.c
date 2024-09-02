/* PROGRAM FOR SINGLY CIRCULAR LINED LIST */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct Node
{
	int data;
	struct Node *link;
};
//typedef struct Node * NODEPTR;
struct Node * start=NULL;

struct Node * GetNode()
{
	return ( (struct Node *) malloc(sizeof(struct Node)));
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

int main()
{
	int ch;
	do
	{
		//clrscr();
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
		//getch();
	}while(ch!=5);
	return 0;
}

void CreateList()
{
	struct Node * end=NULL,*I;
	char choice;
	if(start!=NULL)
	{
		printf("\n\nTHE LIST IS ALREADY CREATED !!");
		return;
	}
	do
	{
		I = GetNode();
		printf("\n\nENTER THE DATA TO BE INSERTED : \t");
		scanf("%d",&I->data);

		if(start == NULL)
		{
			start = I;
		}
		else
		{
			end -> link = I;
		}
		end = I;
		I -> link = start;
		printf("\nDO YOU WANT TO CONTINUE (Y/N) ... ");
		choice = getche();
	}while(choice == 'Y' || choice == 'y');
}
void Insert()
{
	int ch;
	// we can check here - if the list is existing
	do
	{
		//clrscr();

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
		//getch();
	}while(1);		//while(ch!=5);
}
void InsertBefore()
{
	int val;
	struct Node * ptrAtValue;
	struct Node * I;
	struct Node * ptrBeforeValue;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	printf("\n\nENTER THE DATA BEFORE WHICH NEW NODE TO BE INSERTED : \t");
	scanf("%d",&val);

	ptrAtValue = start;


    // search and set the pointer
	while( (ptrAtValue->data != val) && ptrAtValue->link!=start)
		ptrAtValue = ptrAtValue ->link;
	if(ptrAtValue->data != val)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	I = GetNode();
	printf("\n\nENTER THE DATA TO BE INSERTED : \t");
	scanf("%d",&I->data);

	ptrBeforeValue = start;
	while(ptrBeforeValue->link != ptrAtValue)
		ptrBeforeValue = ptrBeforeValue->link;
	ptrBeforeValue -> link = I;
	I->link = ptrAtValue;

	if(ptrAtValue == start) // INSERT BEFORE FIRST
	{
		start = I;
	}
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

	while( (ptrAtValue->data != val) && ptrAtValue->link!=start)
		ptrAtValue = ptrAtValue ->link;
	if(ptrAtValue->data != val)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	I = GetNode();
	printf("\n\nENTER THE DATA TO BE INSERTED : \t");
	scanf("%d",&I->data);
		// following code will work
		// for any node , even the last node
	I->link = ptrAtValue->link;
	ptrAtValue -> link = I;
}

void InsertAtPosition()
{
	int pos,nodeCount,i;
	struct Node * ptrBeforePos,*ptrAtPos;
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

	ptrAtPos = start;

	for(i=0;i<pos-1;i++)
		ptrAtPos = ptrAtPos ->link;

	ptrBeforePos = start;
	while(ptrBeforePos->link != ptrAtPos)
		ptrBeforePos = ptrBeforePos->link;


    I->link = ptrBeforePos->link;
	ptrBeforePos -> link = I;
	//I->link = ptrAtPos;

	if(pos == 1) // INSERT BEFORE FIRST
	{
		start = I;
	}
}
int CountNodes()
{
	struct Node * temp;
	int count = 1;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return 0;
	}
	temp = start ;
	while(temp->link != start)
	{
		temp = temp->link;
		count++;
	}
	return count;
}
void Delete()
{
	int ch;
	do
	{
		//clrscr();
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
		//getch();
	}while(1);		//while(ch!=4);

}
void DeleteByValue()
{
	int val;
	struct Node * ptrAtValue;
	struct Node * ptrBeforeValue;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	printf("\n\nENTER THE DATA OF NODE TO BE DELETED : \t");
	scanf("%d",&val);

	ptrAtValue = start;

	while( (ptrAtValue->data != val) && ptrAtValue->link!=start)
		ptrAtValue = ptrAtValue ->link;
	if(ptrAtValue->data != val)
	{
		printf("\n\nREQUIRED NODE NOT FOUND !!!");
		return;
	}

	ptrBeforeValue = start;
	while(ptrBeforeValue->link != ptrAtValue)
		ptrBeforeValue = ptrBeforeValue->link;
	if(ptrBeforeValue == ptrAtValue)
	{
		start = NULL;
	}
	else
	{
		ptrBeforeValue -> link = ptrAtValue->link;
		if(ptrAtValue == start)
			start = start -> link;
	}
	printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtValue->data);
	ptrAtValue->link = NULL;
	free(ptrAtValue);
}

void DeleteAtPosition()
{
	int pos,nodeCount,i;
	struct Node * ptrBeforePos,*ptrAtPos;
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
		ptrAtPos = ptrAtPos ->link;

	ptrBeforePos = start;
	while(ptrBeforePos->link != ptrAtPos)
		ptrBeforePos = ptrBeforePos->link;

	if(ptrBeforePos == ptrAtPos)
	{
		start = NULL;
	}
	else
	{
		ptrBeforePos -> link = ptrAtPos->link;
		if(ptrAtPos == start)
			start = start -> link;
	}
	printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtPos->data);
	ptrAtPos->link = NULL;
	free(ptrAtPos);
}

void Display()
{
	struct Node * temp;
	if(start == NULL)
	{
		printf("\n\nLIST IS EMPTY !!!");
		return;
	}
	temp = start;
	printf("\n");
	do
	{
		printf("%d",temp->data);
		if(temp ->link != start)
			printf(" -> ");
		temp = temp->link;
	}while(temp != start);
}

/*
Delete All
Merge
concatenate
Divide
	- divide after node
	- divide at position
copy
sorta
search
display reverse
create reverse
*/
