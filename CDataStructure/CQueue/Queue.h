#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include "../ClinkedList/LinkedList.h"
#include "../ClinkedList/Node.h"

typedef struct _LinkedList Queue;/* 以LinkedList为骨架 */

extern void QueueInit(Queue **list);

extern void QueueFree(Queue **list);

extern void QueueAdd(Queue *list,Node *node);
extern bool QueueGet(Queue **list,Node **node);

extern void QueueOutPrintStandard(const Queue *list,int index,int last);
extern void QueueOutPrint(const Queue *list);
extern bool QueueIsEmpty(const Queue *list);

extern void QueueRemove(Queue *list);

#endif