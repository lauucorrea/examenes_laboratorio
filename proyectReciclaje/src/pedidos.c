#include "pedidos.h"
#include "funciones.h"
/*
 * typedef struct{
	int idCliente;
	int idPedido;
	int kgCargamento;
	int estadoPedido;

}ePedido;
 */
//0 vacio
//1 cargado
//-1 pedido completado
ePedido IngresarUnPedido(ePedido lista[],int idPedido,int idCliente,float kgCargamento, int validacionId, int validacionKg, int* pValidacion){
	ePedido pedido;
	pedido.idCliente = idCliente;
	pedido.idPedido = idPedido;
	pedido.kgCargamento = kgCargamento;

	if(validacionId == 0 && validacionKg == 0){
		pedido.estadoPedido = 1;
		*pValidacion = 0;
	}else{
		pedido.estadoPedido = 0;
		*pValidacion = -1;
	}


	return pedido;
}

void InicializarListaPedidos(ePedido listaPedidos[], int tam){
	for(int i = 0;i < tam; i++)
	{
      listaPedidos[i].estadoPedido = 0;
    }
}

void MostrarPedido(ePedido unPedido){
	puts("-------------------------------------------");
	printf("%d %15d %20.2f\n", unPedido.idCliente, unPedido.idPedido,unPedido.kgCargamento);
}

int MostrarListadoPedidos(ePedido lista[], int tam)
{
	int flagListaVacia = -1;
	printf ("Id Cliente\tId Pedido\tKg Cargamento\n");
	for (int i = 0; i < tam; i++)
	{
		if(lista[i].estadoPedido == FILLED){
			MostrarPedido(lista[i]);
			flagListaVacia = 0;
		}

	}
	return flagListaVacia;
}

int BuscarPedidoPorId(ePedido* list, int len,int id){
	int index = -1;
		for(int i = 0; i < len; i++){
			if(list[i].idPedido == id){
				index = i;
				break;
			}
		}
	 return index;
}

int BuscarPedidoPorIdCliente(ePedido* list, int len,int id){
	int index = -1;
		for(int i = 0; i < len; i++){
			if(list[i].idCliente == id && list[i].estadoPedido == 1){
				index = i;
				break;
			}
		}
	 return index;
}
//busca el estadoABuscar en el estado del pedido. devuelve 0 si se encontro, y devuelve -1 si no se encontro en el cliente
void BuscarEstadoPedido(ePedido listaPedidos[],int indicePedidos, int indiceClientes, int estadoABuscar, int* pValidacion){
	if(listaPedidos[indicePedidos].estadoPedido == estadoABuscar){
		*pValidacion = 0;
	}else{
		*pValidacion = -1;
	}
}

int BuscarPrimerEspacioLibrePedidos(ePedido* list, int tam, int* validation)
{
  int i;
  int index = -1;
  int foundSpace = -1;
  index = -1;

  for (i = 0; i < tam; i++)
  {

	if (list[i].estadoPedido != FILLED)
	{
			foundSpace = 0;
			index = i;
			break;
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

void CalcularCantidadPedidos(ePedido lista[], int tam, int idCliente, int* cantidadCompletados, int* cantidadPendientes, int* cantidadTotal){

	int contadorCompletados =0;
	int contadorPendientes = 0;
	int totalPedidos = 0;

	for(int j=0; j<tam; j++){
		if(lista[j].idCliente == idCliente){
			if(lista[j].estadoPedido == -1){
				contadorCompletados++;
			}
			if(lista[j].estadoPedido == 1){
				contadorPendientes ++;
			}
		}
	}
	totalPedidos = contadorPendientes + contadorCompletados;

	if(contadorCompletados != 0){
		*cantidadCompletados = contadorCompletados;
	}
	if(contadorPendientes != 0){
		*cantidadPendientes = contadorPendientes;
	}
	if(totalPedidos != 0){
		*cantidadTotal = totalPedidos;
	}
}


