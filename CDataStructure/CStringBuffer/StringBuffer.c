#include <stdio.h>
#include <stdlib.h>
#include "StringBuffer.h"

void __STRINGBUFFER_OUTPRINT__FUNC__(const ArrayList *list,int index){
	printf("%c", list->array[index]);
}

/* 创建并且初始化一个StringBuffer */
void StringBufferInit(StringBuffer **list){
	ArrayListInit(list);
}

/* 向StringBuffer中添加一个data */
void StringBufferAppend(StringBuffer **list,Datatype data){
	ArrayListAppend(list,data);
}

/* 通过index从StringBuffer中获取一个data */
bool StringBufferGet(const StringBuffer *list,int index,Datatype *result){
	ArrayListGet(list,index,result);
}

/* 通过index从StringBuffer中移除一个data */
void StringBufferRemove(StringBuffer **list,int index){
	ArrayListRemove(list,index);
}

/* 返回第一个index */
void StringBufferFindIndex(const StringBuffer *list,int begin,int end,Datatype data,int *resultIndex){
	ArrayListFindIndex(list,begin,end,data,resultIndex);
}

/* 令StringBuffer增长 */
void StringBufferStandardGrow(StringBuffer **list,StringBuffer **resultList,int increase){
	ArrayListStandardGrow(list,resultList,increase);
}
void StringBufferGrow(StringBuffer **list,StringBuffer **resultList){
	StringBufferStandardGrow(list,resultList,(*list)->block);
}

/* 输出StringBuffer */
void StringBufferOutPrintStandard(const StringBuffer *list,int begin,int end,void (*outPrint)(const StringBuffer *list,int index)){
	ArrayListOutPrintStandard(list,begin,end,outPrint);
}
void StringBufferOutPrint(const StringBuffer *list,void (*outPrint)(const StringBuffer *list,int index)){
	StringBufferOutPrintStandard(list,0,list->index,__STRINGBUFFER_OUTPRINT__FUNC__);
}

/* 进行StringBuffer的复制 */
void StringBufferCopy(StringBuffer **list,StringBuffer **resultList){
	ArrayListCopy(list,resultList);
}

/* 释放StringBuffer的内存 */
void StringBufferFree(StringBuffer **list){
	ArrayListFree(list);
}

/* 判断StringBuffer是否为空 */
bool StringBufferIsEmpty(const StringBuffer *list){
	ArrayListIsEmpty(list);
}

/* 判断StringBuffer中的array是否有元素 */
bool StringBufferIsCouldBeGotten(const StringBuffer *list){
	ArrayListIsCouldBeGotten(list);
}

/* free掉StringBuffer->array */
void StringBufferFreeArray(StringBuffer **list){
	ArrayListFreeArray(list);
}

/* StringBuffer to String */
void StringBufferToString(const StringBuffer *list,char **string,int *length){
	if( StringBufferIsCouldBeGotten(list) ){
		// printf("\nIam\n");
		*length = list->index+1;
		(*string) = (char*)malloc(sizeof(char)*(*length));
		char *temp = *string;
		// printf("0x%p\n",*string);
		for(int i = 0; i < *length; ++i){
			*((*string)++) = list->array[i];
		}
		**string = '\0';/* 末位添加标准标识符 */
		*string = temp;
		// printf("0x%p\n",*string);
	}

}