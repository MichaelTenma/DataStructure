#include <stdio.h>
#include "Queue.h"

void QueueInit(Queue **list){
	LinkedListInit(list);
}

void QueueFree(Queue **list){
	LinkedListFree(list);
}

void QueueAdd(Queue *list,Node *node){
	LinkedListAppend(list,node);
}
bool QueueGet(Queue **list,Node **node){
	bool result = false;
	if(QueueIsEmpty(*list) && (*list)->length > 0){
		/* 非空 */
		/* 只能从头开始取 */
		*node = (*list)->head;
		(*list)->head = (*list)->head->next;
		/* 注意head会被指向NULL，从而导致无法free */
		--(*list)->length;
		result = true;
	}
	return result;
}

void QueueOutPrintStandard(const Queue *list,int index,int last){
	LinkedListOutPrintStandard(list,index,last);
}
void QueueOutPrint(const Queue *list){
	QueueOutPrintStandard(list,0,list->length-1);
}
bool QueueIsEmpty(const Queue *list){
	return LinkedListIsEmpty(list);
}

void QueueRemove(Queue *list){
	if(QueueIsEmpty(list)){
		LinkedListRemove(list,list->tail);
		/* 自带free特效 */
	}
}