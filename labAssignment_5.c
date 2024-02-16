#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{	
	int strLength = 0;

	node* temp = head;
	while (temp != NULL) {
		strLength++;
		temp = temp->next;
	}

	return strLength;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	char* str = NULL;
	int i = 0;

	str = (char*)malloc((length(head) + 1) * (sizeof(char)));

	while (head != NULL) {
		str[i] = head->letter;
		head = head->next;
		i++;
	}
	str[i] = '\0';

	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = (node*)malloc(sizeof(node));
	node* temp2;
	temp->letter = c;
	temp->next = NULL;

	if (*pHead == NULL) {
		*pHead = temp;
		return;
	}

	temp2 = *pHead;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}

	temp2->next = temp;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* temp = *pHead;
    node* temp2;

    while (temp != NULL) {
        temp2 = temp->next; 
        free(temp); 
        temp = temp2; 
    }

    *pHead = NULL; 
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}