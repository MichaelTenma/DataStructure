#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "OneDirectNode.h"
#include "LinkedList.h"

/* ONEDIRECT */
void NodeInit(Node **node,DataType data){
	*node = (Node*)malloc(sizeof(Node));
	// (*node)->nodeType = nodeType;
	(*node)->data = data;
	// (*node)->last = NULL;
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
	int index  = LinkedListFindIndexByData(list,target);
	if(index != ERRORINDEX){
		Node *before = LinkedListFindByIndex(list,--index);
		Node *after = before->next->next;/* before 的下两个就是 index 的下一个 */
		before->next = after;
	}
	/* 该函数不会free掉target */
	return true;
}

void NodeAppend(LinkedList *list,Node *target){
	list->tail->next = target;
}


bool NodeIsEmpty(Node *node){
	bool isEmpty = false;/* 表示空 */
	if(node != NULL && node->next != NULL){
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
		res->next = node->next;
	}
	return *res;
}

void NodeGetLast(LinkedList *list,Node *node,Node **result){
	int index  = LinkedListFindIndexByData(list,node);
	if(index != ERRORINDEX){
		*result = LinkedListFindByIndex(list,--index);
	}
}

void NodeFree(Node **node){
	free(*node);
	*node = NULL;
}