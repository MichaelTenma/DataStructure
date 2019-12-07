
#ifndef _ONEDIRECTNODE_H_
#define _ONEDIRECTNODE_H_

#include "BasicNode.h"

typedef struct _Node{
	// int nodeType;
	DataType data;
	struct _Node *next;
} Node;

#endif