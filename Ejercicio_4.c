/*4) Una ferretería tiene un listado de facturas emitidas en cierto año, con estos datos: 
número de factura, fecha de emisión (día y mes), nombre del cliente y monto total. Dado
un vector de 10 facturas, se necesita mostrar en pantalla cuál fue el mejor mes 
(o sea, el de mayor dinero facturado). Los datos se pueden ingresar por teclado o dejarlos fijos 
en el programa para no perder tiempo en tipear datos.*/
 
#include <stdio.h>

struct fecha_t{          // Se declara la estructura fecha para utilizar luego en la estructura facturas.
	int dia;
	int mes;
};

struct facturas_t{
	int num_factura;
	struct fecha_t fecha;
	char nombre[40];
	float monto;
};

int main(){
    
    float monto_mes[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Vector en el cual se va a guardar los montos en la posicion del mes correspondiente.
	struct facturas_t facturas[10];   
    int i;
	int mejor = 0;
	
	for (i=0 ; i<10 ; i++)        // Se hace el ingreso de datos.
	{       
		printf ("Ingrese el numero de factura: ");
		scanf ("%d",&facturas[i].num_factura);
		
		printf ("Ingrese el dia de la factura: ");
		scanf ("%d",&facturas[i].fecha.dia);
		
		printf ("Ingrese el mes de la factura: ");
		scanf ("%d",&facturas[i].fecha.mes);
		
		printf ("Ingrese el nombre del facturado: ");
		scanf("%s",&facturas[i].nombre);
		
		printf ("Ingrese el monto de la factura: ");
		scanf ("%f",&facturas[i].monto);
	}
	
	for (i=0 ; i<10 ; i++)  // En cada posicion del vector monto_mes se guarda el monto de la factura correspondiente a ese mes.
	{                     // En el caso que haya mas de una factura para un mismo mes,los montos se suman y se guardan en la posicion correspondiente al mes en el vector monto_mes.
	    monto_mes[--facturas[i].fecha.mes] += facturas[i].monto;		
	}
		
	for (i=0 ; i<12 ; i++)
	{
		if (monto_mes[i] > monto_mes[i+1]) // Se comparan los distintos meses para saber cual es el mayor, la posicion del mayor se guarda en "mejor".
		{                                  
			mejor = i;			          // En el caso que mas de un mes tenga el mismo monto, se tomara como mejor el primer mes.
		}
	}
	
	printf("El mejor mes fue el %d\n",++mejor);

	return 0;
}
