/*
 * 		utn_input.c
 *      Author: Martin Delgado
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 1
#define TRUE 0



static int getInt(int* pArray);
static int getFloat(float* pArray);
static int getName(char* pArray);
static int getDescription(char* pArray);

static int isNumberInt(char* pString);
static int isNumberFloat(char* pString);
static int isName(char* pString);
static int isDescription(char* pString);

static int myGets(char* pString, int LEN);



int utn_getNumberInt(int* pArray, char* MSG, char* MSG_ERROR, int MIN, int MAX, int RETRY)
{
	int rtn = -1;
	int buffer;

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && MIN < MAX && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getInt(&buffer) && MIN <= buffer && buffer <= MAX) {
				*pArray = buffer;
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getInt(int* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isNumberInt(buffer)) {
			*pArray = atoi(buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isNumberInt(char* pString)
{
	int rtn = 1;
	int i = 0;

	if (pString != NULL && strlen(pString) > 0) {
		if (pString[0] == '-' || pString[0] == '+') {
			i = 1;
		}
		for (	; pString[i] != '\0'; i++) {
			if (pString[i] < '0' || '9' < pString[i]) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}


int utn_getNumberFloat(float* pArray, char* MSG, char* MSG_ERROR, float MIN, float MAX, int RETRY)
{
	int rtn = -1;
	float buffer;

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && MIN < MAX && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getFloat(&buffer) && MIN <= buffer && buffer <= MAX) {
				*pArray = buffer;
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getFloat(float* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isNumberFloat(buffer)) {
			*pArray = atof(buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isNumberFloat(char* pString)
{
	int rtn = 1;
	int i = 0;
	int stringLen = strlen(pString);
	int flagPoint = FALSE;

	if (pString != NULL && stringLen > 0) {

		/*
		 * CASOS:
		 * "." SOLO UNO Y NO AL FINAL = OK
		 * "ENTER"
		 * "-ENTER"
		 * "+ENTER"
		 * ".ENTER"
		 * "+.ENTER"
		 * "-.ENTER" = OK
		 * " " verificar espacio
		 * verificar la longitud i < stringLen - 1
		 */

		if (pString[0] == '-' || pString[0] == '+') {
			i = 1;
		}

		if (pString[0] == '\0') {
			rtn = 0;
		} else {
			for (	; pString[i] != '\0'; i++) {
				//	PREGUNTO POR FUERA DEL RANGO
				if (pString[i] < '0' || '9' < pString[i]) {
					if (pString[i] == '.' && i < stringLen - 1 && flagPoint == FALSE) {
						flagPoint = TRUE;
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}
	}
	return rtn;
}


int utn_getName(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getName(buffer)) {
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getName(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isName(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}


//static int isWord(char* pString)
//{
//	int rtn = 1;
//	int i;
//
//	if (pString != NULL && strlen(pString) > 0) {
//		for (i = 0; pString[i] != '\0'; i++) {
//			if ((pString[i] < 'a' || 'z' < pString[i]) && (pString[i] < 'A' || 'Z' < pString[i])) {
//				rtn = 0;
//				break;
//			}
//		}
//	}
//	return rtn;
//}



static int isName(char* pString)
{
	int rtn = 1;
	int i;

	if (pString != NULL && strlen(pString) > 0) {

		if (pString[0] < 'A' || 'Z' < pString[0] ) {
			return 0;
		}
		for (i = 1; pString[i] != '\0'; i++) {
			if (pString[i] < 'a' || 'z' < pString[i] ) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}



int utn_getDescription(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getDescription(buffer)){
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getDescription(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isDescription(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isDescription(char* pString)
{
	int rtn = 1;
	int i;

	if (pString != NULL && strlen(pString) > 0) {
		for (i = 0; pString[i] != '\0'; i++){
			if (	(pString[i] < 'a' || 'z' < pString[i])
				&& 	(pString[i] < 'A' || 'Z' < pString[i])
				&& 	(pString[i] < '1' || '9' < pString[i])
				&&	pString[i] != ' '
				&& 	pString[i] != '.'
				&& 	pString[i] != ','
				&& 	pString[i] != ';'
				&& 	pString[i] != '-' ) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}


static int myGets(char* pString, int LEN)
{
	int rtn = -1;
	char buffer[4096];

	fflush(stdin); //Windows
	//fpurge(stdin); //Mac
	//__fpurge(stdin); //Linux >> #include <stdio_ext.h>

	if (pString != NULL && LEN > 0 && fgets(buffer, LEN, stdin) != NULL) {
		if (buffer[strnlen(buffer, sizeof(buffer))-1] == '\n') {
			buffer[strnlen(buffer, sizeof(buffer))-1] = '\0';
		}
		if (strnlen(buffer, sizeof(buffer)) <= LEN) {
			strncpy(pString, buffer, LEN);
			rtn = 0;
		}
	}
	return rtn;
}







//int menuYesOrNot(char* MSG, char* MSG_ERROR, int RETRY)
//{
//	int rtn = -1;
//	char buffer[64];
//
//	if (MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
//		do {
//			printf("%s", MSG);
//
//			if (!getName(buffer)) {
//				buffer = toupper(buffer);
//
//				if (!strcmp("Y", buffer)) {
//					rtn = 1;
//					break;
//				}
//				if (!strcmp("N", buffer)) {
//					rtn = 0;
//					break;
//				}
//			}
//			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
//			RETRY--;
//
//		} while(RETRY >= 0);
//	}
//	return rtn;
//}












