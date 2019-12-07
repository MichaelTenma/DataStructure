
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdbool.h>
#include "Node.h"

#ifndef OUTEMPTYWARN
#define OUTEMPTYWARN printf("It is empty!\n");
#endif

#ifndef ERRORINDEX
#define ERRORINDEX -1
#endif

typedef struct _LinkedList{
	int length;
	Node *head;
	Node *tail;
} LinkedList;

/*-------------------------LinkedList Action BEGIN--------------------------------------*/

extern void LinkedListInit(LinkedList **list);

extern void LinkedListAppend(LinkedList *list,Node *node);
extern void LinkedListRemove(LinkedList *list,Node *node);

extern void LinkedListFree(LinkedList **list);

extern Node* LinkedListFindByIndex(const LinkedList *list,int index);
extern Node* LinkedListFindByData(const LinkedList *list,Node *target);
extern int LinkedListFindIndexByData(const LinkedList *list,Node *target);

extern Node* LinkedListGetNodeLast(const LinkedList *list,Node *target);/* 取得目标node的上一个,to do */

extern void LinkedListOutPrintStandard(const LinkedList *list,int index,int last);
extern void LinkedListOutPrint(const LinkedList *list);
extern bool LinkedListIsEmpty(const LinkedList *list);

/*-------------------------LinkedList Action END----------------------------------------*/

#endif