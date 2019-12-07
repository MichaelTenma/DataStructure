
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

/* 创建并且初始化一个ArrayList */
void ArrayListInit(ArrayList **list){
	*list = (ArrayList*)malloc(sizeof(ArrayList));
	(*list)->array = (Datatype*)malloc(sizeof(Datatype)*BASICLENGTH);
	(*list)->length = BASICLENGTH;

	(*list)->index = initializeIndex;
	(*list)->block = BASICLENGTH;
}

/* 向ArrayList中添加一个data */
void ArrayListAppend(ArrayList **list,Datatype data){
	if( ArrayListIsEmpty(*list) ){
		if((*list)->index == (*list)->length - 1){
			ArrayList *resultList = NULL;
			// printf("nowIndex:%d\n", (*list)->index);
			ArrayListGrow(list,&resultList);
			*list = resultList;
			// printf("afterGrowIndex:%d\n", (*list)->index);
		}
		(*list)->array[++((*list)->index)] = data;
	}
}

/* 通过index从ArrayList中获取一个data */
bool ArrayListGet(const ArrayList *list,int index,Datatype *result){
	bool isSuccess = false;
	if(ArrayListIsCouldBeGotten(list)){
		if( index >= 0 && index <= list->index){
			*result = list->array[index];
			isSuccess = true;
		}
	}
	return isSuccess;
}

/* 通过index从ArrayList中移除一个data */
void ArrayListRemove(ArrayList **list,int index){
	if( ArrayListIsCouldBeGotten(*list) ){
		if( index <= (*list)->index ){
			for(int i = index;i < (*list)->index;++i){
				(*list)->array[i] = (*list)->array[i+1];
			}
			--((*list)->index);
		}
	}
}

/* 返回第一个index */
void ArrayListFindIndex(const ArrayList *list,int begin,int end,Datatype data,int *resultIndex){
	if( ArrayListIsCouldBeGotten(list) ){
		if(begin >= 0 && end <= list->index){
			for(int i = begin;i <= end;++i){
				if(list->array[i] == data){
					*resultIndex = i;
					break;
				}
			}
		}

	}
}

/* 令ArrayList增长 */
void ArrayListStandardGrow(ArrayList **list,ArrayList **resultList,int increase){
	/* list必须与resultList的地址不一样,并且resultList为空 */
	if( ArrayListIsCouldBeGotten(*list) && list != resultList && !ArrayListIsEmpty(*resultList)){

		int capacity = (*list)->length + increase;

		ArrayListInit(resultList);
		(*resultList)->array = (Datatype*)malloc(sizeof(Datatype)*capacity);
		(*resultList)->length = capacity;

		ArrayListCopy(list,resultList);
		ArrayListFree(list);

	}else{
		printf("The resultList is ERROR!!!\n");
	}
}

void ArrayListGrow(ArrayList **list,ArrayList **resultList){
	ArrayListStandardGrow(list,resultList,(*list)->block);
}

/* 输出ArrayList */
void ArrayListOutPrintStandard(const ArrayList *list,int begin,int end,void (*outPrint)(const ArrayList *list,int index)){
	if( ArrayListIsCouldBeGotten(list) ){
		if(begin >= 0 && end <= list->index){
			printf("It is ready to print all elements in ArrayList,and the length is %d\n", end - begin + 1);
			for(int i = begin;i <= end;++i){
				outPrint(list,i);
				// printf("%c\n", list->array[i]);
			}
		}
	}
}

void ArrayListOutPrint(const ArrayList *list,void (*outPrint)(const ArrayList *list,int index)){
	if( ArrayListIsEmpty(list) ){
		ArrayListOutPrintStandard(list,0,list->index,outPrint);
	}
}

/* 进行ArrayList的复制 */
void ArrayListCopy(ArrayList **list,ArrayList **resultList){
	/* 单纯的复制，不会判断任何东西 */
	/* 使用前请自己脑补非空判断 */
	for(int i = 0;i <= (*list)->index;++i){
		(*resultList)->array[i] = (*list)->array[i];
	}
	(*resultList)->index = (*list)->index;

	/* 对后面的位进行初始化 */
	for(int i = (*resultList)->index + 1; i < (*resultList)->length ;++i){
		(*resultList)->array[i] = datatypeInitData;
	}

}

/* 释放ArrayList的内存 */
void ArrayListFree(ArrayList **list){
	if(ArrayListIsEmpty(*list)){
		if( ArrayListIsCouldBeGotten(*list) ){
			ArrayListFreeArray(list);
		}
		free(*list);
		*list = NULL;
	}
}

/* 判断ArrayList是否为空 */
bool ArrayListIsEmpty(const ArrayList *list){
	bool result = false;
	if(list != NULL){
		result = true;
	}
	return result;
}

/* 判断ArrayList中的array是否有元素 */
bool ArrayListIsCouldBeGotten(const ArrayList *list){
	bool result = false;
	if(ArrayListIsEmpty(list)){
		if(list->index != initializeIndex){
			result = true;
		}
	}
	return result;
}

/* free掉ArrayList->array */
void ArrayListFreeArray(ArrayList **list){
	if( ArrayListIsEmpty(*list) ){
		free((*list)->array);
		(*list)->array = NULL;
		(*list)->length = 0;
		(*list)->index = initializeIndex;
	}
}
