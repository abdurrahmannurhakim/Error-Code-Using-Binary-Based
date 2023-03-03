//============================================================================
// Name        : Error_Code.cpp
// Author      : Abdurrahman Nurhakim
// Version     : 1.1.2
// Copyright   : Your copyright notice
// Description : Error Code with Flexible Input Parameter (LinkedList Based)
//============================================================================

#include "Error_Code.h"

ErrorCodeClass::ErrorCodeClass() {
}

ErrorCode* ErrorCodeClass::createErrorCodeList(int parameters[]) {
	ErrorCode *head = NULL;
	ErrorCode *curr = NULL;
	my_typedata_16_t Value_16_bit;

	for (int i = 0; i < SIX_TEEN_BIT; i++) {
		Value_16_bit |= (parameters[i] << i);
		ErrorCode *node = new ErrorCode { Value_16_bit, parameters[i], NULL };
		if (head == NULL) {
			head = node;
			curr = node;
		} else {
			curr->next = node;
			curr = node;
		}
	}
	return head;
}

void ErrorCodeClass::ReadErrorCode(ErrorCode *head,
		my_typedata_16_t *OutputHEXValue) {
	ErrorCode *curr = head;
	while (curr != NULL) {
		*OutputHEXValue = curr->hexValue;
		curr = curr->next;
	}
}

void ErrorCodeClass::deleteErrorCodeList(ErrorCode *head) {
	ErrorCode *curr = head;

	while (curr != NULL) {
		ErrorCode *temp = curr;
		curr = curr->next;
		delete temp;
	}
}

/**
 example testing:
 **/

/**

 uint8_t readDEcimal;
 int parameters[] = {1, 1, 1, 0, 0, 1, 0, 0};
 ErrorCodeClass ErrorCode;
 int main() {

 struct ErrorCode* head = createErrorCodeList(parameters);
 ErrorCode.ReadErrorCode(head, &readDEcimal);
 ErrorCode.deleteErrorCodeList(head); //free
 printf("%d", readDEcimal);
 return 0;
 }

 **/
