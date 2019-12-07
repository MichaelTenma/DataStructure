#include <stdio.h>
#include "StringBuffer.h"

int main(void){
	StringBuffer *strBuf = NULL;
	StringBufferInit(&strBuf);

	// for(int i = '0';i <= 'z';++i){
	// 	StringBufferAppend(&strBuf,i);
	// }

	char tempChar = EOF;
	while ( (tempChar = getchar()) != EOF ){
		if(tempChar != '\n'){
			StringBufferAppend(&strBuf,tempChar);
		}else{
			break;
		}
	}

	// printf("StringBuffer:\n");
	// StringBufferOutPrint(strBuf,__STRINGBUFFER_OUTPRINT__FUNC__);
	// printf("\n");
	char *string = NULL;
	int length = 0;
	StringBufferToString(strBuf,&string,&length);
	// printf("\n0x%p\n",string);
	printf("String:\n%s\n", string);
	StringBufferFree(&strBuf);
	return 0;
}