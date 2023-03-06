//============================================================================
// Name        : Error_Code.h
// Author      : Abdurrahman Nurhakim
// Version     : 1.1.2
// Copyright   : Your copyright notice
// Description : Error Code with Flexible Input Parameter (LinkedList Based)
//============================================================================


#include <iostream>
#include <cstdio>
#include <sstream>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <bits/types.h>
#include "unit-test.h"

typedef unsigned short int	my_typedata_16_t; ///my type data 16 bit

typedef enum {
	NULL_BIT,
	FOUR_BIT = 4,
	EIGHT_BIT = 8,
	SIX_TEEN_BIT = 16,
	THIRTY_TWO_BIT = 32,
	SIXTY_FOUR_BIT = 64
};

struct ErrorCode {
	my_typedata_16_t hexValue;
	int isError;
        struct ErrorCode* next;
};

class ErrorCodeClass {
public:
	ErrorCodeClass();
	struct ErrorCode* createErrorCodeList(int parameters[]);
	void ReadErrorCode(struct ErrorCode* head, my_typedata_16_t *OutputValue);
	void deleteErrorCodeList(ErrorCode* head); ///it seems like free() in linkedlist
};


