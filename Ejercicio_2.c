/* 2) Una aerolinea tiene vuelos, los cuales poseen un código alfanumérico (ejemplo: AR1500), una ciudad
de origen y una ciudad de destino. Ingrese 4 vuelos en un vector. Luego de ingresados los datos permita que el
 usuario escriba el nombre de una ciudad y muestre los vuelos que parten y los que arriban a esa ciudad.
Si no hubiera vuelos para la ciudad ingresada debe mostrarse un mensaje de error.*/

#include <stdio.h>
#include <string.h>  // Se utiliza la libreria string.h para porder trabajar con cadenas de texto.

struct vuelo           // Se declara la estructura vuelo donde se indica con que tipos de datos cuenta.
{
    char codigo[7];      // El codigo se de clara como variable char porque se trata de un codigo alfanumerico, por lo cual contiene numeros y letras.
    char origen[20];
    char destino[20];
};

int main()
{
    int i = 0;
    int vuelo_encontrado = 0;    // Se utiliza una flag para activar o no un mensaje de error que informe al usuario que no se encontro ningun vuelo.
    
    char ciudad[20];
      
    struct vuelo vuelos[4];    
  
     
    for(i=0; i<4; i++)                          // Ingreso de base de datos, de donde mas tarde se buscaran coincidencias.
	{
        printf("Ingrese el codigo del vuelo: ");
        scanf("%s", &vuelos[i].codigo);

        printf("Ingrese ciudad de origen: ");
        scanf("%s", &vuelos[i].origen);

        printf("Ingrese ciudad destino: ");
        scanf("%s", &vuelos[i].destino);
    }


    printf("Ingrese ciudad a buscar vuelos: ");  // Ingreso del usuario de la ciudad de la cual desea ver los vuelos que arriban y que parten.
    scanf("%s", ciudad);


    

    for(i=0; i<4; i++)
	{
		/* Se utiliza la funcion strcmp para comparar el nombre de la ciudad que ingreso 
		el usuario con las ciudades de origen de todas las posiciones del vector de estructura. */
		
        if(strcmp(ciudad, vuelos[i].origen) == 0)  // Si el resultado de la funcio es 0, significa que se hallo una coincidencia.
        {
        	printf("Vuelo que parte de %s: %s\n", ciudad, vuelos[i].codigo);
			
            vuelo_encontrado = 1;      // Al encotrar coincidencias el estado de la flag pasa a 1 desactivando el mensaje de error.
        }
    }

    
    for(i=0; i<4; i++)   //Se hace la misma comparacion que arriba, pero esta vez con los vuelos que arriban a la ciudad que ingreso el usuario.
	{
        if(strcmp(ciudad, vuelos[i].destino) == 0)
		{
			printf("Vuelo que arriba a %s: %s\n", ciudad, vuelos[i].codigo);

            vuelo_encontrado = 1;
        }
    }
    
    if(vuelo_encontrado == 0){ //Se pone en practica la utilizacion de la flag, mostrando el mensaje error si no se encontro ningun vuelo.
        printf("ERROR, no se encontro ningun vuelo que arribe o que parta de la ciudad solicitada");
    }
    return 0;
}
