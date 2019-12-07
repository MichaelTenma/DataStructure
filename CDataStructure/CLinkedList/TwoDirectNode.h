
#ifndef _TWODIRECTNODE_H_
#define _TWODIRECTNODE_H_

#include "BasicNode.h"

typedef struct _Node{
	// int nodeType;
	DataType data;
	struct _Node *last;
	struct _Node *next;
} Node;

#endif