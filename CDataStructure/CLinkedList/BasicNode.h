
#ifndef _BASICNODE_H_
#define _BASICNODE_H_

#include <stdbool.h>
#include "LinkedList.h"
#define DataType int

typedef struct _Node Node;
typedef struct _LinkedList LinkedList;/* 由于头文件冲突，这里应该再声明一次链表容器 */

/*-------------------------Node Action BEGIN--------------------------------------*/

extern void NodeInit(Node **node,DataType data);

extern bool equalsByData(const Node *a,const Node *b);

extern bool NodeRemove(LinkedList *list,Node *target);

extern void NodeAppend(LinkedList *list,Node *target);

extern Node NodePointToNode(Node *node);

extern void NodeGetLast(LinkedList *list,Node *node,Node **result);
extern bool NodeIsEmpty(Node *node);

extern void NodeFree(Node **node);

/*-------------------------Node Action BEGIN--------------------------------------*/


#endif