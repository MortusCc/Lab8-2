#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
typedef char DATA;
typedef struct node
{
	DATA data[LEN + 1];
	struct node* next;
}NODE;
#define MAX 100
NODE* Build(NODE* head);
int ListLen(NODE* head);
NODE* FindLast(NODE* head);
NODE* FindIndexNode(NODE* head, int index);
NODE* InsertLast(NODE* head, DATA* a);
NODE* InsertIndexNode(NODE* head, int index, DATA* a);
NODE* DeleteIndexNode(NODE* head, int index);
NODE* UpdateIndexNode(NODE* head, int index, DATA* a);
void PrintLinkList(NODE* head);
void PutFile(NODE* head);
