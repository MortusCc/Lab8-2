#include "Lab8-2.h"
NODE* Operation(NODE* head)
{
	int s = -1;
	do
	{
		printf("1.Add Data\n"
			"2.Delete Data\n"
			"3.Find Data\n"
			"4.Update Data\n"
			"5.Switch Node\n"
			"0.Exit\n");
		printf("Input your choose:\n");
		int k = scanf("%d", &s);
		if (k == EOF)
		{
			exit(1);
		}
		switch (s)
		{
		case 1:
			head = Add(head);
			PrintLinkList(head);
			break;
		case 2:
			head = Delete(head);
			PrintLinkList(head);
			break;
		case 3:
			head = Find(head);
			PrintLinkList(head);
			break;
		case 4:
			head = Update(head);
			PrintLinkList(head);
			break;
		case 5:
			head = Switch(head);
			PrintLinkList(head);
			break;
		case 0:
			printf("Program is Exited.");
			break;
		default:
			printf("Input Error!");
			break;
		}
	} while (s != 0);
	PutFile(head);
	return head;
}
NODE* Add(NODE* head)
{
	int a = -1;
	char str[LEN + 1] = "\0";
START:
	printf("Input data you want to add:\n");
	int s = scanf("%d %[^\n]", &a, str);
	if (s == EOF)
	{
		exit(1);
	}
	if (a < 0)
	{
		printf("Input Error!");
		goto START;
	}
	if (a <= ListLen(head))
	{
		InsertIndexNode(head, a, str);
	}
	else
	{
		InsertLast(head, str);
	}
	return head;
}
NODE* Delete(NODE* head)
{
	char str[LEN + 1] = "\0";
	printf("Input data you want to delete:\n");
	int s = scanf(" %[^\n]", str);
	if (s == EOF)
	{
		exit(1);
	}
	NODE* pt = NULL;
	pt = head;
	int a = 0,index = 1;
	while (pt != NULL)
	{
		if (strcmp(pt->data, str) == 0)
		{
			a = index;
			break;
		}
		pt = pt->next;
		index++;
	}
	if (a != 0)
	{
		head = DeleteIndexNode(head, a);
		printf("Data is deleted.\n");
	}
	else
	{
		printf("There is no such a data!\n");
	}
	return head;
}
NODE* Find(NODE* head)
{
	char str[LEN + 1] = "\0";
	printf("Input data you want to find:\n");
	int s = scanf(" %[^\n]", str);
	if (s == EOF)
	{
		exit(1);
	}
	NODE* pt = NULL;
	pt = head;
	int a = 0, index = 0;
	while (pt != NULL)
	{
		if (strcmp(pt->data, str) == 0)
		{
			a = index;
			break;
		}
		pt = pt->next;
		index++;
	}
	if (a != 0)
	{
		printf("The data you want to find is on %d in Linked List.\n", a);
	}
	else
	{
		printf("There is no such a data!\n");
	}
	return head;
}
NODE* Update(NODE* head)
{
	int a = -1;
	char str[LEN + 1] = "\0";
START:
	printf("Input data you want to update:\n");
	int s = scanf("%d %[^\n]", &a, str);
	if (s == EOF)
	{
		exit(1);
	}
	if (a < 0)
	{
		printf("Input Error!");
		goto START;
	}
	if (a <= ListLen(head))
	{
		head = UpdateIndexNode(head, a, str);
	}
	else
	{
		InsertLast(head, str);
	}
	return head;
}
NODE* Switch(NODE* head)
{
	NODE* temp = NULL;
	temp = head;
	while (temp->next != NULL && temp->next->next != NULL)
	{
		NODE* pt1 = NULL, * pt2 = NULL;
		pt1 = temp->next;
		pt2 = temp->next->next;
		temp->next = pt2;
		pt1->next = pt2->next;
		pt2->next = pt1;
		temp = pt1;
	}
	return head;
}