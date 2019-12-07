
#include <stdio.h>
#include "Queue.h"

int main(void){
	Queue *queue;
	QueueInit(&queue);
	for(int i = 0;i < 10;++i){
		Node *node;
		NodeInit(&node,i);
		QueueAdd(queue,node);
		printf("Add:%d\n", node->data);
	}

	{
		/* 测试模块 */
		for(int i = 0;i < 2;++i){
			// QueueOutPrint(queue);
			Node *res = NULL;
			bool isHad = QueueGet(&queue,&res);
			// printf("isHad:%d\n", isHad);
			if(isHad){
				// printf("res->data = %d\n",res->data);
				NodeFree(&res);
			}
		}
	}

	QueueOutPrint(queue);
	printf("Queue:0x%p\n",queue);
	QueueFree(&queue);
	printf("Queue:0x%p\n",queue);
	return 0;
}