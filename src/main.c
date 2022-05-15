/*
 ============================================================================
 Name        : Trabajo Practico 02.c
 Author      : Martin Delgado
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"
#include "utn_input.h"
#include "utn_operations.h"



int main(void) {
	setbuf(stdout, NULL); //Windows

//	system("title ADMINISTRACION DE PASAJEROS"); //Windows Console
//	system("mode 95,30"); //Windows Console


	Passenger arrayPassenger[QTY_PASSENGER];

	int option;
	int indice;
	int id;
	int contPassenger = 0;
	float priceTotal = -1;
	int cantPasajerosPromedio;



	//	INICIALIZO
	if (!pass_initArray(arrayPassenger, QTY_PASSENGER)) {
		pass_loadForced(arrayPassenger, QTY_PASSENGER);	//	DEBUG CARGA FORZADA
		contPassenger = 6;
	} else printf("\nERROR - CONTACTE CON SOPORTE");



	//	MENU
	do {
		//REINTENTO SETEO EN 0 PORQUE EL DO-WHILE YA ME DA ESTE SERVICIO
		//SI NO VALIDO OPCION Y NO LA INICIALIZE PUEDE VENIR CARGADA CON BASURA
		if (!utn_getNumberInt(&option, "\n\n---MENU--- "
								"\n1. ALTA"
								"\n2. MODIFICAR"
								"\n3. BAJA"
								"\n4. INFORMAR"
								"\n5. SALIR\n", " >>ERROR OPCION INVALIDA", 1, 5, 0)) {

			switch (option)	{


				case 1: // ALTA
					indice = pass_getEmptyIndex(arrayPassenger, QTY_PASSENGER);
					if (indice >= 0) {

						if (!pass_createArray(arrayPassenger, QTY_PASSENGER, indice)) {
							printf("\n>>SE DIO DE ALTA\n");
							contPassenger++;
						} else {
							printf("\n>>NO SE DIO DE ALTA\n");
						}
					} else {
						printf("\n\n>>NO HAY ESPACIO");
					}
					break;


				case 2: // MODIFICAR
					if (contPassenger > 0) {
						if(!utn_getNumberInt(&id, "\nIngrese ID: ", "ERROR", 1000, ID_LEN, 2)) {

							if (!pass_updateArray(arrayPassenger, QTY_PASSENGER, pass_searchId(arrayPassenger, QTY_PASSENGER, id))) {
								printf("\n>>SE GUARDO LA MODIFICACION\n");
							} else printf("\n>>NO SE PUDO MODIFICAR - ID INVALIDO");
						} else printf("\n>>NO SE PUDO MODIFICAR - ID INVALIDO");
					} else printf("\n>>ESTA VACIA LA LISTA");
					break;


				case 3: // BAJA
					if (contPassenger > 0) {
						if(!utn_getNumberInt(&id, "\nIngrese ID: ", "ERROR", 1000, ID_LEN, 2)) {

							if (!pass_deleteArray(arrayPassenger, QTY_PASSENGER, pass_searchId(arrayPassenger, QTY_PASSENGER, id))) {
								printf("\n>>SE BORRO EL PASAJERO\n");
								contPassenger--;
							} else printf("\n>>NO SE PUDO BORRAR - ID INVALIDO");
						} else printf("\n>>NO SE PUDO BORRAR - ID INVALIDO");
					} else printf("\n>>ESTA VACIA LA LISTA");
					break;


				case 4: // INFORMAR
					if (contPassenger > 0) {

						if (!utn_getNumberInt(&option, "\n\n---INFORME--- "
														"\n1. LISTADO DE PASAJEROS [APELLIDO - TIPO]"
														"\n2. TOTAL Y PROMEDIO"
														"\n3. LISTADO DE PASAJEROS [FLYCODE - STATUS]\n", " >>ERROR OP INVALIDA", 1, 6, 0)) {

							switch (option) {


								case 1:	//	LISTADO DE PASAJEROS [APELLIDO - TIPO]
									if (!pass_arrayBubbleShortTwoField(arrayPassenger, QTY_PASSENGER, '>')) {
										pass_printArray(arrayPassenger, QTY_PASSENGER);
									} else printf("\n>>NO SE PUDO LISTAR");
								break;


								case 2:	//	TOTAL Y PROMEDIO - CANTIDAD DE PASAJEROS QUE SUPUERAN EL PROMEDIO
									priceTotal = pass_priceTotal(arrayPassenger, QTY_PASSENGER);
									if (priceTotal >= 0) {

										cantPasajerosPromedio = pass_contPromedioPassenger(arrayPassenger, QTY_PASSENGER, priceTotal/contPassenger);
										printf("\nPRECIO TOTAL: $%.2f - PROMEDIO: $%.2f"
												"\n%d PASAJEROS SUPERAN EL PROMEDIO", priceTotal, priceTotal/contPassenger,cantPasajerosPromedio);
									}
								break;


								case 3:	//	LISTADO DE PASAJEROS [FLYCODE - STATUS]
									if (!pass_arrayBubbleShortTwoFieldFlight(arrayPassenger, QTY_PASSENGER, '>')) {
										pass_printArray(arrayPassenger, QTY_PASSENGER);
									} else printf("\n>>NO SE PUDO LISTAR");

								break;
							}
						}
					} else printf("\n>>ESTA VACIA LA LISTA");
					break;
			}
		}
	} while (option != 5);

	system("cls"); //Windows Console

	printf("\nEND PROGRAM - SYSTEM E-CORP");


	return EXIT_SUCCESS;
}




