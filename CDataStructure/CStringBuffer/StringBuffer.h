#ifndef _STRINGBUFFER_H_
#define _STRINGBUFFER_H_

#include "../CArrayList/ArrayList.h"

#define Datatype char
/* 用来初始化的data */
#define datatypeInitData '\0'

typedef struct _ArrayList StringBuffer;

/* 创建并且初始化一个StringBuffer */
extern void StringBufferInit(StringBuffer **list);

/* 向StringBuffer中添加一个data */
extern void StringBufferAppend(StringBuffer **list,Datatype data);

/* 通过index从StringBuffer中获取一个data */
extern bool StringBufferGet(const StringBuffer *list,int index,Datatype *result);

/* 通过index从StringBuffer中移除一个data */
extern void StringBufferRemove(StringBuffer **list,int index);

/* 返回第一个index */
extern void StringBufferFindIndex(const StringBuffer *list,int begin,int end,Datatype data,int *resultIndex);

/* 令StringBuffer增长 */
extern void StringBufferStandardGrow(StringBuffer **list,StringBuffer **resultList,int increase);
extern void StringBufferGrow(StringBuffer **list,StringBuffer **resultList);

/* 输出StringBuffer */
extern void StringBufferOutPrintStandard(const StringBuffer *list,int begin,int end,void (*outPrint)(const StringBuffer *list,int index));
extern void StringBufferOutPrint(const StringBuffer *list,void (*outPrint)(const StringBuffer *list,int index));

/* 进行StringBuffer的复制 */
extern void StringBufferCopy(StringBuffer **list,StringBuffer **resultList);

/* 释放StringBuffer的内存 */
extern void StringBufferFree(StringBuffer **list);

/* 判断StringBuffer是否为空 */
extern bool StringBufferIsEmpty(const StringBuffer *list);

/* 判断StringBuffer中的array是否有元素 */
extern bool StringBufferIsCouldBeGotten(const StringBuffer *list);

/* free掉StringBuffer->array */
extern void StringBufferFreeArray(StringBuffer **list);

/* StringBuffer to String */
extern void StringBufferToString(const StringBuffer *list,char **string,int *length);

extern void __STRINGBUFFER_OUTPRINT__FUNC__(const ArrayList *list,int index);

#endif