/*
 * clientes.c
 *
 *  Created on: 8 Oct 2021
 *      Author: Lauta
 */

#include "clientes.h"
#include "funciones.h"

void InicializarListaClientes(eCliente listaClientes[], int tam){
	for(int i = 0;i < tam; i++)
	{
	listaClientes[i].isEmpty = EMPTY;
	}
}
//estadoIngreso =
// 1 Ingresado correctamente
// 0 No se Ingreso en ningun momento
//-1 si hubo algun error (a implementar)

eCliente IngresarUnCliente(eCliente lista[],int idCliente,int* validacion){
	eCliente cliente;
	int validacionCuit;
	int validacionDireccion;
	int validacionEmpresa;
	int validacionLocalidad;

	char empresa[50];
	int cuit;
	char direccion[50];
	int localidadEmpresa;

	getString(empresa,"Ingresar nombre de la empresa\n",50, &validacionEmpresa);
	cuit = IngresarEntero("Ingresa tu numero de cuit\n",999999999, &validacionCuit);
	getString(direccion,"Ingresar la direccion de su domicilio\n",50, &validacionDireccion);
	//getString(cliente.localidad,"Ingresar la localidad de su domicilio\n",50, &validacionLocalidad);
	localidadEmpresa = IngresarEntero("Ingrese una localidad 1.Lomas 2.Avellaneda 3.Tigre", 3, &validacionLocalidad);

	if(validacionEmpresa == 0 && validacionDireccion == 0 && validacionCuit == 0 && validacionLocalidad == 0){
		cliente.isEmpty = 1;
		cliente.idCliente = idCliente;
		cliente.localidad = localidadEmpresa;
		cliente.cuit = cuit;
		strcpy(cliente.direccion, direccion);
		strcpy(cliente.empresa, empresa);
		*validacion = 0;
	}else{
		cliente.isEmpty = 0;
		*validacion = -1;
	}
	return cliente;
}
void BorrarCliente(eCliente lista[], int tam, int *pValidacion)
{
  int i;
  int validacion;
  int idABM;
  char respuesta;
  MostrarListadoClientes(lista, tam);
  idABM = IngresarEntero("Ingrese el id del cliente a eliminar\n", 400, &validacion);
  if(validacion == 0){
	  for (i = 0; i < tam; i++)
	  {
		  if (lista[i].isEmpty != 0 && lista[i].idCliente == idABM)
		  {
			  do{
				  printf("Esta seguro que desea eliminar a %s?\n", lista[i].empresa);
				  fflush(stdin);
				  scanf("%c", &respuesta);
				  validacion = isalpha(respuesta);

			  }while(validacion != 0 || (respuesta != 'n' && respuesta != 's'));

			  if(respuesta == 's'){
				  lista[i].isEmpty = 0;
				  *pValidacion = 0;
				  break;
			  }else{
				  *pValidacion = -1;
				  break;
			  }
		  }
	  }
  }
}


int MostrarListadoClientes(eCliente lista[], int tam)
{
	int flagListaVacia = -1;
	printf ("Id\tEmpresa Cuit\tDireccion\tLocalidad\n");
	for (int i = 0; i < tam; i++)
	{
		if(lista[i].isEmpty == FILLED){
			MostrarCliente(lista[i],0);
			flagListaVacia = 0;
		}
	}
	return flagListaVacia;
}
//returns 0 = found empty position
//returns -1 = there's any free space in the list
int BuscarPrimerEspacioLibreClientes(eCliente* list, int tam, int* validation)
{
  int i;
  int index = 0;
  int foundSpace = -1;
  index = -1;

  for (i = 0; i < tam; i++)
  {

	if (list[i].isEmpty != FILLED)
	{
		if(foundSpace != 0){
			foundSpace = 0;
			index = i;
			break;
		}
	}
  }
  if(foundSpace == -1 || tam != TAM){
	  *validation = -1;
	  index = -1;
	  return index;
  }else{
	  *validation = 0;
	  return index;
  }

}

int BuscarClientePorLocalidad(eCliente lista[], int localidad, int len){
	int index = - 1;
	for(int i=0; i < len; i++){
		if(localidad == lista[i].localidad && lista[i].isEmpty != 0){
			index = i;
			break;
		}
	}
	return index;
}

void MostrarCliente(eCliente unCliente, int cantidadPedidos)
{
	int localidad;
	char nombreLocalidad[50];
	localidad = unCliente.localidad;

	switch(localidad){
		case 1: strncpy(nombreLocalidad , "Lomas", sizeof(nombreLocalidad));
		break;

		case 2: strncpy(nombreLocalidad , "Avellaneda", sizeof(nombreLocalidad));
		break;

		case 3: strncpy(nombreLocalidad , "Tigre", sizeof(nombreLocalidad));
		break;
	}

	if(cantidadPedidos != 0){
		printf ("Id\tEmpresa\t\tCuit\tDireccion\tLocalidad\tPedidos\n");
		printf("%d %10s %16d %8s %15s %10d\n", unCliente.idCliente, unCliente.empresa,
		unCliente.cuit, unCliente.direccion, nombreLocalidad, cantidadPedidos);
	}else{
		printf("%d %10s %5d %10s %15s\n", unCliente.idCliente, unCliente.empresa,
		unCliente.cuit, unCliente.direccion, nombreLocalidad);
	}

}
void CargarCambios(char direccion[], eCliente listaClientes[],int posicion){
	for(int i=0; i<=strlen(direccion); i++){
		listaClientes[posicion].direccion[i] = direccion[i];
	}
}


int CompararIdCliente(int idCliente, int IdPedido){
	if(idCliente == IdPedido){
		return 0;
	}else{
		return -1;
	}
}
int BuscarClientePorId(eCliente* list, int len,int id)
{
	int index = -1;
	for(int i = 0; i < len; i++){
		if(list[i].idCliente == id){
			index = i;
			break;
		}
	}
 return index;
}



