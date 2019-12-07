#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "TwoDirectNode.h"
#include "LinkedList.h"

/* TWODIRECT */
void NodeInit(Node **node,DataType data){
	*node = (Node*)malloc(sizeof(Node));
	// (*node)->nodeType = nodeType;
	(*node)->data = data;
	(*node)->last = NULL;
	(*node)->next = NULL;
}

bool equalsByData(const Node *a,const Node *b){
	bool res = false;
	if(a->data == b->data){
		res = true;
	}
	return res;
}
bool NodeRemove(LinkedList *list,Node *target){

	target->last->next = target->next;/* 将temp的上一个的下一个指向temp的下一个，即完成删除 */
	/* 该函数不会free掉target */
	return true;
}

void NodeAppend(LinkedList *list,Node *target){
	target->last = list->tail;
	list->tail->next = target;
}

bool NodeIsEmpty(Node *node){
	bool isEmpty = false;/* 表示空 */
	if(node != NULL){
		isEmpty = true;
	}
	return isEmpty;
}

Node NodePointToNode(Node *node){
	Node *res;
	NodeInit(&res,0);
	if(NodeIsEmpty(node)){
		/* 非空 */
		res->data = node->data;
		res->last = node->last;
		res->next = node->next;
		// printf("XXX:%d\n",res->data);
	}
	return *res;
}

void NodeGetLast(LinkedList *list,Node *node,Node **result){
	*result = node->last;
}

void NodeFree(Node **node){
	free(*node);
	*node = NULL;
}