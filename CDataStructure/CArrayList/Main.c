#include <stdio.h>
#include "ArrayList.h"

void __OUTPRINT__FUNC__(const ArrayList *list,int index){
	printf("%d\n", list->array[index]);
}

int main(void){
	ArrayList *list = NULL;
	ArrayListInit(&list);

	for(int i = 0;i < 5;++i){
		ArrayListAppend(&list,i);
	}
	
	// ArrayListRemove(&list,11);
	ArrayListOutPrint(list,__OUTPRINT__FUNC__);

	// int resultIndex = -1;
	// int data = -1;
	// bool isSuccess = ArrayListGet(list,100,&data);
	// if( isSuccess ){
	// 	printf("Data:%d\n", data);
	// }else{
	// 	printf("Coubl not find a data as %d\n", data);
	// }

	// ArrayListFindIndex(list,0,5,data,&resultIndex);
	// if(resultIndex != initializeIndex){
	// 	printf("%d in %d\n", data, resultIndex);
	// }else{
	// 	printf("Coubl not find a data as %d\n", data);
	// }
	
	printf("ArrayList:0x%p\n", list);
	// ArrayListFreeArray(&list);
	printf("array:0x%p\n", list->array);
	printf("length:%d\n", list->length);
	printf("index:%d\n", list->index);
	printf("block:%d\n", list->block);

	ArrayListFree(&list);
	printf("ArrayList:0x%p\n", list);
	return 0;
}