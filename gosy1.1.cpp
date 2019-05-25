
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Element {
	int id;
	char name[100];
	char country[100];
	int places;
	char fio[100];
	struct Element* prev;
	struct Element* next;
};

void readString(char *string)
{
	fgets(string, 99, stdin);
	string[strlen(string) - 1] = '\0';
}

Element* createElement()
{
	Element* element = (Element*)malloc(sizeof(Element));

	element->prev = NULL;
	element->next = NULL;
	
	printf("Print id:  ");
	scanf_s("%d", &(element->id));

	printf("Print name:  ");
	getchar();
	readString(element->name);
	
	/*printf("Print country:  ");
	readString(element->country);

	printf("Print places:  ");
	scanf_s("%d", &(element->places));

	printf("Print fio:  ");
	getchar();
	readString(element->fio);*/
	return element;
}

void addElement(Element** head)
{
	Element *element = createElement();

	// вставка хэд
	if (*head == NULL) {
		*head = element;
		return;
	}

	//замена хэд
	if (element->id <= (*head)->id) {
		
		element->next = (*head);
		(*head)->prev = element;
		*head = element;
		return;
	}

	// вставка добавляемого элемента в нужное место в списке
	Element* current = *head;
	while (current->next != NULL && element->id > current->next->id)
	{
		current = current->next;
	}
	if (current->next != NULL) {
		element->next = current->next;
	}
	element->prev = current;
	current->next = element;
}

void printList(Element *head)
{
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	Element *current = head;
	do 
	{
		printf("id = %d\n", current->id);
		printf("name = %s\n", current->name);
		/*printf("country = %s\n", current->country);
		printf("places  %d\n", current->places);
		printf("fio = %s\n", current->fio);*/
		printf("_______________________\n");
		current = current->next;
	} while (current != NULL);
}

int main() 
{

	Element* head = NULL;

	while (true) {
		
		printf("1: Add to sort list\n");
		printf("2: Show list\n");
		printf("Print menu number: ");
		int num = 0;
		scanf_s("%d", &num);
		switch (num) 
		{
			case 1: 
				addElement(&head);
				printf("Done\n");
				break;
			case 2: 
				printf("Elements:\n");
				printf("_______________________\n");
				printList(head);
				break;
			default:
				printf("%d don't found.  Please try again\n", num);
				break;
		}
		printf("\n");
	}
	return 0;
}