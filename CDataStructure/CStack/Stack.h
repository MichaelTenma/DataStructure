#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include "../ClinkedList/LinkedList.h"
#include "../ClinkedList/Node.h"

typedef struct _LinkedList Stack;/* 以LinkedList为骨架 */

extern void StackInit(Stack **list);

extern void StackFree(Stack **list);

extern void StackPush(Stack *list,Node *node);
extern bool StackPop(Stack **list,Node **node);

extern void StackOutPrintStandard(const Stack *list,int index,int last);
extern void StackOutPrint(const Stack *list);
extern bool StackIsEmpty(const Stack *list);

extern void StackRemove(Stack *list);

#endif