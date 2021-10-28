/*
 * plasticos.c
 *
 *  Created on: 12 Oct 2021
 *      Author: Lauta
 */
#include "plasticos.h"
#include "funciones.h"
void InicializarListaPlasticos(ePlasticos listaPlasticos[], int tam){

	for(int i = 0;i < tam; i++)
	{
		listaPlasticos[i].altaDensidad = 0;
		listaPlasticos[i].bajaDensidad = 0;
		listaPlasticos[i].polipropileno = 0;
		listaPlasticos[i].basura = 0;
		listaPlasticos[i].estadoPlasticos = EMPTY;
	}

}
void AdministrarPlasticos(ePlasticos listaPlasticos[], float kgPedido,int index, int* pValidacion){


	int validacionHDPE;
	int validacionLDPE;
	int validacionPP;

	listaPlasticos[index].basura = kgPedido;
	listaPlasticos[index].altaDensidad = IngresarFlotante("Ingrese la cantidad de plasticos de alta densidad\n",9999, &validacionHDPE);
	listaPlasticos[index].bajaDensidad = IngresarFlotante("Ingrese la cantidad de plasticos de baja densidad\n",9999, &validacionLDPE);
	listaPlasticos[index].polipropileno = IngresarFlotante("Ingrese la cantidad de plasticos de propileno\n",9999, &validacionPP);


	if(validacionHDPE == 0 && validacionLDPE == 0 && validacionPP == 0){
		listaPlasticos[index].basura -= listaPlasticos[index].altaDensidad;
		listaPlasticos[index].basura -= listaPlasticos[index].bajaDensidad;
		listaPlasticos[index].basura -= listaPlasticos[index].polipropileno;
		*pValidacion = 0;
	}else{
		*pValidacion = -1;
	}
}

void MostrarPlasticos(ePlasticos lista[], int index){
	printf ("Id Pedido\tAlta densidad\tBaja Densidad\tPolipropileno\tBasura\n");
	printf("%d %16.2f %15.2f %15.2f %16.2f\n", lista[index].idPedido, lista[index].altaDensidad, lista[index].bajaDensidad, lista[index].polipropileno, lista[index].basura);
}

void CalcularPropilenoPromedio(ePlasticos listaPlasticos[], int totalClientes, int tam){
	float totalReciclados = 0;
	float promedio;
	for(int i = 0; i<tam; i++){
		totalReciclados +=  listaPlasticos[i].polipropileno;
	}
	promedio = totalReciclados / totalClientes;
	printf("El promedio de polipropileno reciclado es de %.2f\n", promedio);
}
int BuscarPrimerEspacioLibrePlasticos(ePlasticos* list, int tam, int* validation)
{
  int i;
  int index = -1;
  int foundSpace = -1;
  index = -1;

  for (i = 0; i < tam; i++)
  {

	if (list[i].estadoPlasticos != FILLED)
	{
			foundSpace = 0;
			index = i;
			break;
	}
  }
  if(foundSpace == -1 || tam != TAM2){
	  *validation = -1;
	  return index;
  }else{
	  *validation = 0;
	  return index;
  }

}


