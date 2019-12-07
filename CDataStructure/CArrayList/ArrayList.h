#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <stdbool.h>

#define Datatype char
/* 用来初始化的data */
#define datatypeInitData '\0'
#define BASICLENGTH 5
#define initializeIndex -1

typedef struct _ArrayList{
	Datatype *array;/* 数组指针 */
	int length;/* 数组大小 */
	int index;/* 当前末位元素 */
	int block;/* 每次数组扩充的长度 */
} ArrayList;

/* 创建并且初始化一个ArrayList */
extern void ArrayListInit(ArrayList **list);

/* 向ArrayList中添加一个data */
extern void ArrayListAppend(ArrayList **list,Datatype data);

/* 通过index从ArrayList中获取一个data */
extern bool ArrayListGet(const ArrayList *list,int index,Datatype *result);

/* 通过index从ArrayList中移除一个data */
extern void ArrayListRemove(ArrayList **list,int index);

/* 返回第一个index */
extern void ArrayListFindIndex(const ArrayList *list,int begin,int end,Datatype data,int *resultIndex);

/* 令ArrayList增长 */
extern void ArrayListStandardGrow(ArrayList **list,ArrayList **resultList,int increase);
extern void ArrayListGrow(ArrayList **list,ArrayList **resultList);

/* 输出ArrayList */
extern void ArrayListOutPrintStandard(const ArrayList *list,int begin,int end,void (*outPrint)(const ArrayList *list,int index));
extern void ArrayListOutPrint(const ArrayList *list,void (*outPrint)(const ArrayList *list,int index));

/* 进行ArrayList的复制 */
extern void ArrayListCopy(ArrayList **list,ArrayList **resultList);

/* 释放ArrayList的内存 */
extern void ArrayListFree(ArrayList **list);

/* 判断ArrayList是否为空 */
extern bool ArrayListIsEmpty(const ArrayList *list);

/* 判断ArrayList中的array是否有元素 */
extern bool ArrayListIsCouldBeGotten(const ArrayList *list);

/* free掉ArrayList->array */
extern void ArrayListFreeArray(ArrayList **list);

extern void __OUTPRINT__FUNC__(const ArrayList *list,int index);

#endif