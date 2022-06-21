/* 1) Declare una estructura para almacenar datos de estudiantes (DNI y dos notas correspondientes a los dos cuatrimestres del anio).
Haga un programa que permita ingresar los datos de 5 estudiantes en un vector de estas estructuras.
Luego de ingresar los datos se deben mostrar los DNI de cada estudiante y el promedio que tiene en sus examenes. */

#include <stdio.h>

struct estudiantes{      //Se declara la estructura estudiante y se indica que datos van a estar incluidos en esta          
    int dni;                                                  
    float nota1;
    float nota2;
    };

int main(){
    int i = 0;
    float promedio;   
    struct estudiantes estudiante[5];   //Se crea un vector de estructuras (una posicion por cada estudiante)
		

    for(i=0; i<5; i++){                                //La utilizacion de un vector de estructuras agiliza el ingreso de datos            
        printf("Ingrese el dni del estudiante %d: ", i+1);
        scanf("%d", &estudiante[i].dni);

        printf("Ingrese la primer nota del estudiante %d: ", i+1); 
        scanf("%f", &estudiante[i].nota1);                         
                                                                   
        printf("Ingrese la segunda nota del estudiante %d: ", i+1);
        scanf("%f", &estudiante[i].nota2);
        
   		/* Se utiliza la expresion i+1 para mostar el numero de estudiante que se esta ingresando 
   		Se usa i+1 porque si se utilizara solo la i la primera posicion seria para el estudiante 0; 
   		y eso seria confuso para el usuario.*/
           
    }

    for(i=0; i<5; i++){        //Se calcula el promedio de cada estudiante y se muestra en pantalla

        promedio = (estudiante[i].nota1 + estudiante[i].nota2)/2;    //La variable promedio no es parte de la estructura estudiante, sino que cambia su valor en cada estudiante.         

        printf("D.N.I.: %d\tPromedio: %.2f\n", estudiante[i].dni, promedio);
    }
}

