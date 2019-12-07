#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "Node.h"

void LinkedListInit(LinkedList **list){
	// printf("%d\n",sizeof(LinkedList));
	*list = (LinkedList*)malloc(sizeof(LinkedList));
	(*list)->length = 0;
	(*list)->head = NULL;
	(*list)->tail = NULL;
	// printf("inner:0x%p\n", *list);
}

void LinkedListAppend(LinkedList *list,Node *node){
	if(list->length <= 0){
		list->head = node;
		list->length = 1;
	}else{
		NodeAppend(list,node);
		++list->length;
	}
	list->tail = node;
}

void LinkedListRemove(LinkedList *list,Node *node){
	if(LinkedListIsEmpty(list)){

		Node *temp = LinkedListFindByData(list,node);
		if(temp != NULL){
			/* if the node is exist */
			if(equalsByData(list->head,node)){
				/* if head */
				if(list->length > 1){
					list->head = list->head->next;
				}else{
					list->head = NULL;
					list->tail = NULL;
				}
				
			}else{
				if(NodeRemove(list,temp)){
					NodeFree(&temp);/* 释放内存 */
				}
			}
			--(list->length);
		}

	}
}

void LinkedListFree(LinkedList **pList){

	if(LinkedListIsEmpty(*pList)){
		if((*pList)->length > 0){
			Node *node = (*pList)->head;
			Node *temp = NULL;
			for( ; node ; node = node->next){
				NodeFree(&temp);
				temp = node;
				// --list->length;/* 删除一个自减一次，方便错误的发现 */
			}
			NodeFree(&temp);/* free掉最后一个 */
			// (*pList)->length = 0; /* 减少计算量，debug的时候注意 */
			// (*pList)->head = NULL;/* 如果free掉，输出就会异常 */
		}
	}
	/* 无论如何都free一次 */
	free(*pList);/* 销毁链表容器 */
	(*pList) = NULL;/* 安全起见指向NULL */
	// printf("pList:0x%p\n", *pList);
}

Node* LinkedListFindByIndex(const LinkedList *list,int index){
	Node *res = NULL;
	if(LinkedListIsEmpty(list) && index <= list->length){
		Node *node = list->head;

		for(int i = 0 ; node ; node = node->next,++i){
			if(i == index){
				res = node;
				break;
			}
		}

	}else{
		OUTEMPTYWARN
	}
	return res;

}
Node* LinkedListFindByData(const LinkedList *list,Node *target){
	Node *res = NULL;
	if(LinkedListIsEmpty(list)){
		Node *node = list->head;

		for(; node ; node = node->next){
			if(equalsByData(target,node)){
				res = node;
				break;
			}
		}

	}else{
		OUTEMPTYWARN
	}
	return res;
}
int LinkedListFindIndexByData(const LinkedList *list,Node *target){
	int res = ERRORINDEX;
	if(LinkedListIsEmpty(list)){
		Node *node = list->head;

		for(int i = 0; node ; node = node->next,++i){
			if(equalsByData(target,node)){
				res = i;
				break;
			}
		}

	}else{
		OUTEMPTYWARN
	}
	return res;
}

void LinkedListOutPrintStandard(const LinkedList *list,int index,int last){
	
	if(LinkedListIsEmpty(list)){
		Node *node = list->head;
		printf("In painting,list Size:%d\n",list->length);

		for(int i = 0 ; node && index <= last; node = node->next,++i){
			if(i >= index && i <= last){
				printf("%d\n", node->data);
				++index;
			}
		}

	}else{
		OUTEMPTYWARN
	}

}

void LinkedListOutPrint(const LinkedList *list){
	LinkedListOutPrintStandard(list,0,list->length-1);
}

bool LinkedListIsEmpty(const LinkedList *list){
	// printf("There is checking isEmpty!\n");
	bool isEmpty = false;
	if(list != NULL){
		if(list->head != NULL){
			isEmpty = true;/* 非空 */
		}
	}
	return isEmpty;
}
