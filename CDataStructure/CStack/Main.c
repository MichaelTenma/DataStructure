
#include <stdio.h>
#include "Stack.h"

int main(void){
	Stack *stack;
	StackInit(&stack);
	for(int i = 0;i < 10;++i){
		Node *node;
		NodeInit(&node,i);
		StackPush(stack,node);
		printf("Push:%d\n", node->data);
	}

	int runTimes = 9;
	for(int i = 0;i < runTimes;++i){
		Node *result = NULL;
		// NodeInit(&result,0);
		bool isHad = StackPop(&stack,&result);
		
		if(!isHad){
			i = runTimes;
		}else{
			printf("Pop:%d\n", result->data);
			NodeFree(&result);
		}
		
	}
	printf("isEmpty:%d\n",StackIsEmpty(stack));
	StackOutPrint(stack);
	printf("stack:%p\n",stack);
	StackFree(&stack);
	printf("stack:%p\n",stack);
	

	return 0;
}