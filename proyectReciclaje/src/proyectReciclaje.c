/*
 ============================================================================
 Name        : proyectReciclaje.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "plasticos.h"
#include "funciones.h"
#include "localidad.h"
#define TAM 200
#define TAM2 400
#define TAM3 3

int main(void) {
	eCliente listaClientes[TAM]= {{201,"Chacabuco",20052,"Direccion",1,1},{202,"Chacabuco",20052,"Direccion",2,1},{203,"Chacabuco",20052,"Direccion",1,1},{204,"Chacabuco",20052,"Direccion",3,1},{205,"Chacabuco",20052,"Direccion",2,1}};
	eLocalidad listaLocalidades[TAM3] = {{1, "Lomas", 0},{2, "Avellaneda", 0},{3, "Tigre", 0}};
	ePedido listaPedidos[TAM2];
	ePlasticos listaPlasticos[TAM2];

	setbuf(stdout, NULL);
	int estadoComparacion;
	int pValidaciones = -1; // 0 sin errores / vacio
						   // 1 cargado / procesado
						   // -1 error
	int validacionIdABM = -1;
	int validacionLocalidadABM = -1;
	int validacionDireccionABM = -1;
	int validacionKgIngresados = -1;
	int isListadoVacio;
	int hayPedidosPendientes = -1;
	//int flagClienteIngresado = 1;
	int opcion = 0;
	int flagCiclo = -1;
	int flagMaximos = -1;
	int idCliente = 200;
	int idPedidos = 400;

	int cantidadDeClientes = 0;

	int idClienteMaxPendientes = -1;
	int cantidadPedidosPendientes = 0;
	int auxPendientesMAX;

	int idClienteMaxCompletados = -1;
	int cantidadPedidosCompletados = 0;
	int auxCompletadosMAX;

	int idClienteMaxPedidos = -1;
	int cantidadPedidosTotal = 0;
	int auxPedidosMAX;

	float kgIngresados;
	float totalKgPedidos = 0;





	int busquedaIndex;
	int busquedaPedido;
	int busquedaPlasticos;
	int busquedaLocalidad;

	char direccionABM[50];
	int idABM;
	int localidadABM;


	do{
		MostrarMenu();
		puts("-------------------------------------------");
		opcion = IngresarEntero("Elija una opcion\n",11, &pValidaciones);
	/*	if(pValidaciones != 0 || (opcion != 1 && flagClienteIngresado != 0 )){
			puts("Primero ingresa al menos un empleado");
			continue;
		}*/
		//Cliclo para inicializar las listas solo una vez

		if(flagCiclo == -1){
			InicializarListaPedidos(listaPedidos,TAM2); //tamaño de 400. estipulando 2 pedidos por cliente
			//InicializarListaClientes(listaClientes, TAM); // tamaño de 200 clientes
			InicializarListaPlasticos(listaPlasticos, TAM2); //contador de plasticos por pedido de cliente
			flagCiclo = 0;
		}



	switch(opcion){
		case 1:
			//busco el primer espacio libre
			busquedaIndex = BuscarPrimerEspacioLibreClientes(listaClientes, TAM, &pValidaciones);

			//corroboro que las validaciones no sean las erroneas
			if(pValidaciones != -1 && busquedaIndex != -1){
				//contador de clientes para el promedio
				cantidadDeClientes++;
				// sumo 1 al contador de id de cliente inicializado en 200
				idCliente ++;
				//cargo el cliente
				listaClientes[busquedaIndex] = IngresarUnCliente(listaClientes, idCliente,&pValidaciones);
				puts("-------------------------------------------");
				printf("Ingresado correctamente. El id del cliente es %d\n", idCliente);
				//valido que al menos se haya ingresado un usuario
				//flagClienteIngresado = 0;
				//corta si esta todo ok. para evitar el mensaje de error que se muestra debajo
				break;
			}

			puts("-------------------------------------------");
			puts("El cliente no se pudo ingresar. Intentelo nuevamente");
		break;
		case 2:
			puts("-------------------------------------------");
			MostrarListadoClientes(listaClientes, TAM);
			idABM = IngresarEntero("Ingrese el id del cliente a modificar\n", 400, &validacionIdABM);
			busquedaIndex = BuscarClientePorId(listaClientes, TAM, idABM);

			if(busquedaIndex != -1 && validacionIdABM != -1){
				puts("-------------------------------------------");
				printf("Cliente encontrado. El id correspondiente es: %d\n", listaClientes[busquedaIndex].idCliente);
				puts("-------------------------------------------");
				getString(direccionABM, "Ingrese la nueva direccion del cliente\n", 50, &validacionDireccionABM);
				puts("-------------------------------------------");
				localidadABM = IngresarEntero("Ingrese una localidad 1.Lomas 2.Avellaneda 3.Tigre\n", 3, &validacionLocalidadABM);

				if(validacionDireccionABM != -1 && validacionLocalidadABM != -1 && validacionIdABM != -1){

					//CargarCambios(direccionABM,localidadABM, listaClientes, busquedaIndex);
					busquedaLocalidad = BuscarLocalidadPorId(listaLocalidades, 3, localidadABM);
					idABM = listaLocalidades[busquedaLocalidad].idLocalidad;
					if(busquedaLocalidad != -1 && localidadABM > 0){
						listaClientes[busquedaIndex].isEmpty = 1;
						listaClientes[busquedaIndex].localidad = idABM;
						strcpy(listaClientes[busquedaIndex].direccion,direccionABM);
						puts("-------------------------------------------");
						puts("El usuario se modifico correctamente");
					}else{
						puts("-------------------------------------------");
						puts("No encontramos la localidad  que ingreso");
						break;
					}
				}else{
					puts("-------------------------------------------");
					puts("No encontramos el id del usuario que ingreso");
					break;
				}
			}
		break;
		case 3:
			flagCiclo = -1;
			puts("-------------------------------------------");
			MostrarListadoClientes(listaClientes, TAM);
			puts("-------------------------------------------");
			idABM = IngresarEntero("Ingrese el id del usuario a eliminar\n",400, &validacionIdABM);
			busquedaIndex = BuscarClientePorId(listaClientes, TAM, idABM);



			if(busquedaIndex != -1 && validacionIdABM != -1){
				listaClientes[busquedaIndex].isEmpty = -1;
				//todos los pedidos que encuentre en el array de pedidos, son seteados en 0.
				do{
					busquedaPedido = BuscarPedidoPorIdCliente(listaPedidos, TAM2, idABM);

					if(busquedaPedido != -1){
						listaPedidos[busquedaPedido].estadoPedido = 0;
						flagCiclo = 0;
					}

				}while(busquedaPedido != -1);


				puts("-------------------------------------------");
				puts("Lista de clientes actualizada:");
				printf ("Id\tEmpresa Cuit\tDireccion\tLocalidad\n");
				MostrarListadoClientes(listaClientes, TAM);
				pValidaciones = 0;
			}

			if(pValidaciones != -1){
				puts("-------------------------------------------");
				puts("El usuario se elimino correctamente\n");
			}else{
				puts("-------------------------------------------");
				puts("No encontramos el id del usuario que ingreso");
			}
		break;
		case 4:
			//muestro el listado y pido los datos
			MostrarListadoClientes(listaClientes, TAM);
			puts("-------------------------------------------");
			idABM = IngresarEntero("Ingrese el id del usuario a cargar el pedido \n",400, &validacionIdABM);
			puts("-------------------------------------------");
			kgIngresados = IngresarEntero("Ingrese la cantidad de kg a transportar\n",9999, &validacionKgIngresados);
			//busco que el cliente exista
			busquedaIndex = BuscarClientePorId(listaClientes, TAM, idABM);

			if(validacionIdABM != -1 && validacionKgIngresados != -1 && busquedaIndex != -1){
				idPedidos ++;
				//busco el espacio libre disponible
				busquedaPedido = BuscarPrimerEspacioLibrePedidos(listaPedidos, TAM, &pValidaciones);

				if(busquedaPedido != -1 && pValidaciones != -1){
					//cargo el pedido en el espacio libre encontrado
					listaPedidos[busquedaPedido] =IngresarUnPedido(listaPedidos, idPedidos, idABM, kgIngresados, validacionIdABM, validacionKgIngresados, &pValidaciones);
					//busco la posicion de la localidad segun el id que esta guardado en el cliente
					busquedaLocalidad = BuscarLocalidadPorId(listaLocalidades, TAM, listaClientes[busquedaIndex].localidad);
					//en la posicion encontrada sumo 1 a la cantidad de pedidos total por cada localidad
					listaLocalidades[busquedaLocalidad].cantidadPedidos ++;

					if(pValidaciones != 0){
						puts("-------------------------------------------");
						puts("No pudimos registrar el pedido");
						break;
					}

					puts("-------------------------------------------");
					printf("Ingresado correctamente. El pesaje del pedido del cliente es de %.2f\n", kgIngresados);
					totalKgPedidos += kgIngresados;
					break;
				}else{
					puts("-------------------------------------------");
					puts("No se encontraron espacios libres para el pedido");
					break;
				}

			}else{
				puts("No se encontro el cliente ingresado");
			}

		break;
		case 5:
			isListadoVacio = MostrarListadoPedidos(listaPedidos, TAM2);
			idABM = IngresarEntero("Ingrese el id del pedido a procesar\n", 800, &validacionIdABM);
			if(validacionIdABM != -1 && isListadoVacio != -1){
				busquedaPedido = BuscarPedidoPorId(listaPedidos, TAM2, idABM);

				if(busquedaPedido != -1){
					busquedaIndex = BuscarClientePorId(listaClientes, TAM, listaPedidos[busquedaPedido].idCliente);
					busquedaPlasticos = BuscarPrimerEspacioLibrePlasticos(listaPlasticos, TAM2, &pValidaciones);

					if(busquedaPlasticos != -1){
						listaPlasticos[busquedaPlasticos].idPedido = listaPedidos[busquedaPedido].idPedido;
						MostrarPedido(listaPedidos[busquedaPedido]);
						puts("-------------------------------------------");
						printf("El cuit del cliente es: %d\n", listaClientes[busquedaIndex].cuit);
						printf("La direccion del cliente es: %s\n", listaClientes[busquedaIndex].direccion);
						puts("Estado del pedido: PENDIENTE\n");
						AdministrarPlasticos(listaPlasticos, listaPedidos[busquedaPedido].kgCargamento, busquedaPlasticos, &pValidaciones);

						listaPedidos[busquedaPedido].estadoPedido = -1;
						MostrarPlasticos(listaPlasticos, busquedaPlasticos);
						puts("-------------------------------------------");
						puts("Pedido procesado exitosamente");

					}else{
						puts("-------------------------------------------");
						puts("No se encontraron espacios libres\n");
					}
				}
			}else{
				puts("-------------------------------------------");
				puts("No encontramos el id ingresado");
			}

		break;
		case 6:
			isListadoVacio = MostrarListadoClientes(listaClientes, TAM);

			if(isListadoVacio != -1){
				for(int i=0; i < TAM; i++){
					for(int j=0; j<TAM2; j++){
						estadoComparacion = CompararIdCliente(listaClientes[i].idCliente, listaPedidos[j].idCliente);
						if(listaPedidos[j].estadoPedido == 1 && estadoComparacion != -1 ){
							cantidadPedidosPendientes++;
							busquedaLocalidad = BuscarLocalidadPorId(listaLocalidades, TAM3, listaClientes[i].localidad);
							listaLocalidades[busquedaLocalidad].cantidadPedidos ++;
						}
					}
					if(cantidadPedidosPendientes > 0  && listaClientes[i].isEmpty != 0){
						puts("-------------------------------------------");
						MostrarCliente(listaClientes[i], cantidadPedidosPendientes);
						cantidadPedidosPendientes = 0;

					}else if(listaClientes[i].isEmpty != 0){
						puts("-------------------------------------------");
						printf ("Id\tEmpresa Cuit\tDireccion\tLocalidad\n");
						MostrarCliente(listaClientes[i],0);
						puts("no se encontraron pedidos pendientes para este cliente\n");

					}
				}
			}else{
				puts("Listado de clientes vacio\n");
			}
		break;
		case 7:
				for(int i=0; i<TAM2; i++){
					if(listaPedidos[i].estadoPedido == 1){
						busquedaIndex = BuscarClientePorId(listaClientes, TAM, listaPedidos[i].idCliente);
						puts("-------------------------------------------");
						printf ("Id Cliente\tId Pedido\tKg Cargamento\n");
						MostrarPedido(listaPedidos[i]);
						puts("-------------------------------------------");
						printf("Cuit del cliente: %d \n", listaClientes[busquedaIndex].cuit);
						printf("Direccion del cliente: %s\n", listaClientes[busquedaIndex].direccion);

						ImprimirLocalidad(listaClientes[busquedaIndex].localidad);

						printf("Cantidad de kg a recolectar: %.2f \n", listaPedidos[i].kgCargamento);
						hayPedidosPendientes = 0;
				}
			}
		if(hayPedidosPendientes != 0){
			puts("-------------------------------------------");
			puts("No se encontraron pedidos pendientes\n");
			hayPedidosPendientes = 0;
		}

		break;
		case 8:
			for(int i=0; i<TAM2; i++){
				if(listaPedidos[i].estadoPedido == -1){
					busquedaIndex = BuscarClientePorId(listaClientes, TAM, listaPedidos[i].idCliente);
					puts("-------------------------------------------");
					printf ("Id Cliente\tId Pedido\tKg Cargamento\n");
					MostrarPedido(listaPedidos[i]);
					puts("-------------------------------------------");
					printf("Cuit del cliente: %d \n", listaClientes[busquedaIndex].cuit);
					printf("Direccion del cliente: %s\n", listaClientes[busquedaIndex].direccion);

					ImprimirLocalidad(listaClientes[busquedaIndex].localidad);

					printf("Cantidad de kg a recolectar: %.2f \n", listaPedidos[i].kgCargamento);
					hayPedidosPendientes = 0;
			}
		}
		if(hayPedidosPendientes != 0){
			puts("-------------------------------------------");
			puts("No se encontraron pedidos pendientes\n");
			hayPedidosPendientes = 0;
		}
		break;
		case 9:
			puts("-------------------------------------------");
			localidadABM = IngresarEntero("Ingrese una localidad 1.Lomas 2.Avellaneda 3.Tigre\n", 3, &pValidaciones);/**/
			if(pValidaciones != -1){
				busquedaLocalidad = BuscarLocalidadPorId(listaLocalidades, TAM, localidadABM);
				if(busquedaLocalidad == -1 || listaLocalidades[busquedaLocalidad].cantidadPedidos <= 0){
					puts("-------------------------------------------");
					puts("No se encontraron pedidos pendientes para esta localidad");
					break;
				}
				puts("-------------------------------------------");
				printf("La cantidad de pedidos pendientes para esta localidad es de: %d\n", listaLocalidades[busquedaLocalidad].cantidadPedidos);
			}
		break;
		case 10:
			CalcularPropilenoPromedio(listaPlasticos, cantidadDeClientes,TAM2);
		break;
		case 11:

			for(int i=0; i<TAM; i++){
				if(listaClientes[i].isEmpty == 1){
					CalcularCantidadPedidos(listaPedidos, TAM2, listaClientes[i].idCliente, &auxCompletadosMAX, &auxPendientesMAX, &auxPedidosMAX);

					if(flagMaximos == -1){
						cantidadPedidosCompletados = auxCompletadosMAX;
						cantidadPedidosPendientes = auxPendientesMAX;
						cantidadPedidosTotal = auxPedidosMAX;
						flagMaximos = 0;
					}else{
						if(auxPendientesMAX > cantidadPedidosPendientes){
							cantidadPedidosPendientes = auxPendientesMAX;
							idClienteMaxPendientes = listaClientes[i].idCliente;
							printf("INFO pendientes: %d \n", auxPendientesMAX);
							auxPendientesMAX = 0;
						}
						if(auxCompletadosMAX > cantidadPedidosCompletados){
							cantidadPedidosCompletados = auxCompletadosMAX;
							idClienteMaxCompletados = listaClientes[i].idCliente;
							printf("INFO completados: %d \n", auxCompletadosMAX);
							auxCompletadosMAX = 0;
						}
						if(auxPedidosMAX > cantidadPedidosTotal){
							cantidadPedidosTotal = auxPedidosMAX;
							idClienteMaxPedidos = listaClientes[i].idCliente;
							printf("INFO total: %d \n", auxPedidosMAX);
							auxPedidosMAX = 0;
						}
					}
				}
			}

			if(idClienteMaxPendientes != -1){
				puts("-------------------------------------------");
				puts("El cliente con mas cantidad de pedidos pendientes es:");
				puts ("Id\tEmpresa\t\tCuit\tDireccion\tLocalidad");
				busquedaIndex = BuscarClientePorId(listaClientes, TAM, idClienteMaxPendientes);
				MostrarCliente(listaClientes[busquedaIndex], 0);
				cantidadPedidosPendientes = 0;
			}
			if(idClienteMaxCompletados != -1){
				puts("-------------------------------------------");
				puts("El cliente con mas cantidad de pedidos completados es:");
				puts ("Id\tEmpresa\t\tCuit\tDireccion\tLocalidad");
				busquedaIndex = BuscarClientePorId(listaClientes, TAM, idClienteMaxCompletados);
				MostrarCliente(listaClientes[busquedaIndex], 0);
				cantidadPedidosCompletados = 0;
			}
			if(idClienteMaxPedidos != -1){
				puts("-------------------------------------------");
				puts("El cliente con mas cantidad de pedidos total es:");
				puts ("Id\tEmpresa\t\tCuit\tDireccion\tLocalidad");
				busquedaIndex = BuscarClientePorId(listaClientes, TAM, idClienteMaxPedidos);
				MostrarCliente(listaClientes[busquedaIndex], 0);
				cantidadPedidosTotal = 0;
			}
			flagMaximos = -1;

		break;
		}
	}while(opcion > 0 && opcion < 12);
	puts("Gracias por utilizar nuestro sistema");
}
