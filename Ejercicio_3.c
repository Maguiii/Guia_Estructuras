/*3) Utilice el ejercicio 1, modificándolo para que las notas del estudiante estén en un vector de
notas dentro de la estructura. Este vector de notas puede almacenar hasta 10 notas del alumno.
Los lugares no utilizados se escriben con un valor -1 para indicar que ese lugar está vacío.
De esta manera, un estudiante puede haber rendido 2 exámenes, otro 4 y otro 10, para citar algunos ejemplos.
Se pide conservar la funcionalidad del programa teniendo en cuenta esta nueva organización de la información.
Por lo tanto, para mostrar el promedio del estudiante, habrá que considerar las notas que tiene en este vector de notas,
teniendo cuidado en utilizar solamente las notas que existan y omitiendo los -1 que pueda haber.*/

#include <stdio.h>

struct estudiantes   
{
    int dni;
    int cantidad;      // Se utiliza una variable para indicar la cantidad de notas que posee el estudiante.
    float notas[10];  // Se declara un vector de notas dentro de la estructura "estudiantes".
};

int main()
{
    int i = 0;
    int j = 0;
    
    float acumulador = 0;
    float promedio = 0;
    
    struct estudiantes estudiante[5];   // Se declara el vector de estructuras.

    for(i=0; i<5; i++)
	{
        printf("Ingrese el dni del estudiante %d: ", i+1);  // Se realiza el ingreso de los dates del estudiante
        scanf("%d", &estudiante[i].dni);

        printf("Ingrese cantidad de notas: ");    // La variable cantidad puede o no ser distinta para cada estudiante, por eso forma parte de la estructura.
        scanf("%d", &estudiante[i].cantidad);

        printf("Ingrese notas del estudiante: ", i+1); 
        
        for(j=0; j<10; j++)    // Se utiliza la intruccion for para el cargar las notas del estudiante en el vector
		{
	        if(j < estudiante[i].cantidad)       // Se aplica cuando j es menor a la cantidad del estudiante, ya que j comienza en 0.    
			{
                scanf("%f", &estudiante[i].notas[j]);  // Todas las notas que el usuario ingrese seran guardadas en el vector notas de cada estudiante.
			}
            else
			{
                estudiante[i].notas[j] = -1;  // El resto de las posiciones del vector seran escritos con el valor -1.
            }
        }
    }


    for(i=0; i<5; i++)   // Se utiliza la instruccion for para manejarse dentro del vector estudiante.
	{
        for(j=0; j<estudiante[i].cantidad; j++)   // Se utiliza la instruccion for para manejarse dentro del vector de notas de cada estudiante.
		{
            acumulador += estudiante[i].notas[j];
        }
        
        if(estudiante[i].cantidad == 0) // Se tiene en cuenta que si el estudiante no tiene ninguna nota, su promedio sera de 0.
        {
            promedio = 0;
        }
        else
        {
            promedio = acumulador / estudiante[i].cantidad;
        }

        printf("D.N.I.: %d\tPromedio: %.2f\n", estudiante[i].dni, promedio); // Para cada estudiante se imprime su DNI junto con su promedio.
    }
    return 0;
}
