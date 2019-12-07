
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void StackInit(Stack **list){
	LinkedListInit(list);
}

void StackFree(Stack **list){
	LinkedListFree(list);
}

void StackPush(Stack *list,Node *node){
	LinkedListAppend(list,node);
}

bool StackPop(Stack **list,Node **node){
	/* get tail */
	bool result = false;
	if(StackIsEmpty(*list) && (*list)->length > 0){
		*node = (*list)->tail;
		NodeGetLast(*list,(*list)->tail,&((*list)->tail));/* 别乱改，到时候怎么死都不知道 */
		// (&((*list)->tail))->next = NULL;
		--((*list)->length);
		result = true;
		/* 不free，将tail指向当前tail的上一个 */
	}else{
		printf("It is NULL\n");
	}
	return result;
}

void StackOutPrintStandard(const Stack *list,int index,int last){
	LinkedListOutPrintStandard(list,index,last);
}
void StackOutPrint(const Stack *list){
	StackOutPrintStandard(list,0,list->length-1);
}

bool StackIsEmpty(const Stack *list){
	return LinkedListIsEmpty(list);
}

void StackRemove(Stack *list){
	/* 只能删除最后一个 */
	if(StackIsEmpty(list)){
		LinkedListRemove(list,list->tail);
		/* 自带free特效 */
	}
	
}