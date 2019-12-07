#include <stdio.h>
#include "LinkedList.h"
#include "Node.h"


int main(void){

	LinkedList *list = NULL;
	// printf("before:0x%p\n", list);
	LinkedListInit(&list);
	// printf("after:0x%p\n", list);

	for(int k = 0; k < 1;++k){
		for(int i = 0;i < 5;++i){
			Node *node;
			NodeInit(&node,i);
			LinkedListAppend(list,node);
			// printf(" list->head->data:%d\n", list->head->data);
			// printf(" list->tail->data:%d\n", list->tail->data);
		}
	}


	Node *tempNode = NULL;
	LinkedListOutPrint(list);
	for(int i = 0;i < 2;++i){
		
		NodeInit(&tempNode,i);
		LinkedListRemove(list,tempNode);
		NodeFree(&tempNode);
		
	}
	// LinkedListOutPrint(list);
	{
		NodeInit(&tempNode,3);
		// LinkedListRemove(list,tempNode);
		Node *res = LinkedListFindByData(list,tempNode);

		/* 用于检测使用的链表是否正确 */
		if(res != NULL){
			printf("res->last->data = %d\n", res->last->data);
		}else{
			OUTEMPTYWARN
		}
		NodeFree(&tempNode);
		// printf("tempNode:0x%p\n", tempNode);
	}

	// LinkedListOutPrintStandard(list,10,100);
	LinkedListOutPrint(list);
	LinkedListFree(&list);
	printf("list:0x%p\n", list);
	
	return 0;
}