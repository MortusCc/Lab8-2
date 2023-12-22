#include "MyLinkedList.h"
NODE* Build(NODE* head)
{
	FILE* fp = fopen("Input.txt", "r");
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	NODE* node, * tail;
	tail = head;
	DATA temp[LEN + 1] = "\0";
	for (int i = 0; i < MAX; i++)
	{
		fscanf(fp, " %[^\n]", temp);
		if (feof(fp))
		{
			goto END;
		}
		node = (NODE*)malloc(sizeof(NODE));
		strcpy(node->data, temp);
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
END:
	fclose(fp);
	return head;
}
int ListLen(NODE* head)
{
	int x = 0;
	NODE* pt = NULL;
	pt = head->next;
	while (pt != NULL)
	{
		x++;
		pt = pt->next;
	}
	return x;
}
NODE* FindLast(NODE* head)
{
	NODE* pt = NULL;
	pt = head;
	while (pt->next != NULL)
	{
		pt = pt->next;
	}
	return pt;
}
NODE* FindIndexNode(NODE* head, int index)
{
	NODE* pt = NULL;
	pt = head;
	int i = 1;
	while (i < index && pt != NULL)
	{
		pt = pt->next;
		i++;
	}
	return pt;
}
NODE* InsertLast(NODE* head, DATA* a)
{
	NODE* prePt = NULL, * pt = NULL;
	pt = (NODE*)malloc(sizeof(NODE));
	if (pt == NULL)
	{
		exit(1);
	}
	strcpy(pt->data, a);
	prePt = FindLast(head);
	prePt->next = pt;
	pt->next = NULL;
	return head;
}
NODE* InsertIndexNode(NODE* head, int index, DATA* a)
{
	NODE* prePt = NULL, * pt = NULL;
	pt = (NODE*)malloc(sizeof(NODE));
	if (pt == NULL)
	{
		exit(1);
	}
	strcpy(pt->data, a);
	prePt = FindIndexNode(head, index);
	if (prePt != NULL)
	{
		pt->next = prePt->next;
		prePt->next = pt;
	}
	else
	{
		printf("There is no such a node!\n");
	}
	return head;
}
NODE* DeleteIndexNode(NODE* head, int index)
{
	NODE* prePt = NULL, * pt = NULL;
	prePt = FindIndexNode(head, index - 1);
	pt = FindIndexNode(head, index + 1);
	if (prePt != NULL)
	{
		prePt->next = pt;
	}
	else
	{
		printf("There is no such a node!\n");
	}
	return head;
}
NODE* UpdateIndexNode(NODE* head, int index, DATA* a)
{
	NODE* pt = NULL;
	pt = FindIndexNode(head, index);
	pt = pt->next;
	strcpy(pt->data, a);
	return head;
}
void PrintLinkList(NODE* head)
{
	printf("Now Linked list: ");
	NODE* pt = NULL;
	pt = head->next;
	while (pt->next != NULL)
	{
		printf("%s -> ", pt->data);
		pt = pt->next;
	}
	printf("%s\n", pt->data);
}
void PutFile(NODE* head)
{
	FILE* fp = fopen("Output.txt", "w");
	if (fp == NULL)
	{
		printf("Can't open this file!\n");
		exit(1);
	}
	NODE* max = head->next;
	NODE* pt = NULL;
	pt = head->next;
	while (pt != NULL)
	{
		fputs(pt->data, fp);
		fputc('\n', fp);
		pt = pt->next;
	}
	fclose(fp);
}