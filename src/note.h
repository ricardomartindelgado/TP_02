/*
 * 		note.h
 *      Author: Smaythink
 */

#ifndef NOTE_H_
#define NOTE_H_



#endif /* NOTE_H_ */

/*

	TODO DEBUG TP02 FLYCODE EXPLOTA, no puedo restringir la cantidad de caractares
	no esta funcionando el myGet F*CK!!

		if (strnlen(buffer, sizeof(buffer)) <= LEN) {
			strncpy(pString, buffer, LEN);
			rtn = 0;


 	TODO prod_createArray DEBERIA TENER ADENTRO EL INDEX?
 	 https://youtu.be/VcU6cl1zqNU?t=4269

 	TODO prod_print
 	- PODRIA AGREGAR EL CAMPO IS EMPTY COMO PARAMETRO DE CRITERIO A FILTRAR
 	- PREGUNTAR SI ESTA SEGURO DE CARGAR LOS DATOS, PRINTEAR ANTES?

	TODO funcion validar email

	TODO isName validar primer elemento sea mayuscula OK
	TODO FALTAN DESARROLLAR
 	TODO CARGAR ARRAY
	TODO INICIALIZAR ARRAY EN UN VALOR
	TODO GENERAR UN SUBCONJUNTO DE ASCII CON EL RANGO QUE LE PASO
 	TODO FUNCION GET
	TODO FUNCION VALIDAR NUMERO FLOAT

	TODO FUNCION BURBUJEO CHECK CONTINUE
	TODO FUNCIONES VALIDAR CUIT, SOLO LETRAS
	TODO CONTAR PALABRAS
	TODO INGRESO EL RANGO Y ME DEVUELVE UN ARRAY CARGADO CON LOS ELEMENTOS




-------------------------------------------------------------------------

	REFACTORIZAR / REFACTORY

	SHORCUT: CTRL+SHIFT+R refactor rename>open rename dialog


	IMPORTANTE: siempre hacer refactor con un codigo que compile antes

	//	PASO 1
	copiar proyecto abierto con el main
	pegar proyecto
	cambiar nombre
	cerrar proyecto anterior
	buildear proyecto nuevo corrrer

	//	PASO 2
	cambiar nombre de entidad.h
	cambiar nombre de entidad.c

	//	PASO 3
	dentro de Cliente.h

	IMPORTANTE:
	verificar el preview que no cambie algo de la otra biblioteca

	renombrar la estructura
	cambiar campos
	cambiar el prefijo de la funcion una por una
	int cli_printArray(Cliente* cli, int LEN);

	cambiar nombre de los argumentos una por una
	ej arrayCliente por arrayProducto

	cambiar el nombre de la documentacion de la funcion
	es preferible usar reemplazar crtl+f


	//	PASO 5
	verificar el main
	cambiar nombre las variables, define



	//	OBSERVACIONES
	Name        : Clase11-Publicidades.c

	#include "Cliente.h"

	int cli_printArray(Cliente* cli, int LEN)
	int cli_initArray(Cliente* arrayClientes, int LEN)
	Cliente buffer;


-------------------------------------------------------------------------




 	FUNCION VALIDAR NUMERO FLOAT
	FOMATOS VALIDOS
	VALIDAR: -3.14; +3.14; .14;
 	NO VALIDAR: 3.1.3; ..2; 3a3; 314.


	'+'	PREGUNTO POR LA POSICION
	'.'	PREGUNTO POR LA CANTIDAD DE OCURRENCIAS



	utn_getTelefono
	utn_getDNI
	utn_getCUIT
	utn_getEmail
	utn_getTexto (letras y numeros)
	utn_getTexto (letras > nombre)


	isEmpty = 1;
	esta vacio? = verdadero


	ABM ALTA BAJA MDODIFICACION = (CRUD) create, read, update, and delete

 * ++VARIABLES
 * numero number num
 * acumulador accumulator acc
 * contador counter count
 * retorno return rtn
 * filtro filter
 * reintentos retry rtr
 * resultado output
 * cadena string str
 * inicializar initialize*
 * criterio criterion*
 * rango range
 * ordenar sort
 * regla de tres rule of three
 * campo field
 *
 *
 * ++FUNCIONES
 * Validate_OnlyNumberint()
 * Validate_OnlyAlphabet()
 * isDigit()
 * isNumber()
 * isChar()
 *
 * ++DEFINE
 * tamaño de buffer SIZE_BUFFER
 * largo lenght LEN
 * mensaje message MSG
 * mensaje de error error MSG_ERROR
 * cantidad quantity QTY



//#################################################################################



usuario
getNumerica numero razonble
{
getInt reemplaza el scanf
}


esNumerica valida numero
// llevan como nombre una pregunta devuelven verdadero o falso, no me indica error

getInt int valida
myGets string












//#################################################################################


//	NOTA MENTAL: CONSIDERAR SI TIENE SENTIDO
//	NO VALIDO NADA Y PUEDO HACER ESTO DIRECTAMENTE EN EL MAIN
//	DEBERIA VALIDAR QUE EL INGRESO Y EL RESULTADO DE LAS
//	OPERACIONES NO DESBORDE MI VARIABLE
//	int utn_sumarInt(int operador1, int operador2)
//	{
//		return operador1+operador2;
//	}
//
//	int utn_restarInt(int operador1, int operador2)
//	{
//		return operador1-operador2;
//	}
//
//	int utn_multiplicarInt(int operador1, int operador2)
//	{
//		return operador1*operador2;
//	}
 *
 *
 *


int utn_getInt(	int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);

			if(minimo <= bufferInt && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(minimo <= bufferFloat && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin); //Windows
			//fpurge(stdin); //Mac
			//__fpurge(stdin); //Linux >> #include <stdio_ext.h>
			scanf("%c", &bufferChar);

			if(minimo <= bufferChar && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}





//#################################################################################
//	DEBUG

void utn_arrayCharPrint(char* pArray, int len, char* nameArray);
void utn_arrayCharInicializarUnValor(char* pArray, int len, char valor);
void utn_arrayIntPrint(int* pArray, int len, char* nameArray);
void utn_arrayIntInicializarUnValor(int* pArray, int len, int valor);
void utn_arrayIntInicializarUnValorAscendente(int* pArray, int len);
void utn_arrayFloatInicializarUnValor(float* pArray, int len, int valor);
void utn_arrayFloatInicializarUnValorAscendente(float* pArray, int len);





void utn_arrayCharPrint(char* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %c", nameArray, i, pArray[i]);
	}
	printf("\n");
}

void utn_arrayCharInicializarUnValor(char* pArray, int len, char valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayIntPrint(int* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %d", nameArray, i, pArray[i]);
	}
	printf("\n");
}


void utn_arrayFloatPrint(float* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %f", nameArray, i, pArray[i]);
	}
	printf("\n");
}


void utn_arrayIntInicializarUnValor(int* pArray, int len, int valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayIntInicializarUnValorAscendente(int* pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = i;
	}
}

void utn_arrayFloatInicializarUnValor(float* pArray, int len, int valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayFloatInicializarUnValorAscendente(float* pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = i;
	}
}































*/
