/*-------------------------------------------------
Fecha:
Catedra:
NombredelPrograma:
Lenguaje de Programacion:
Programador:
Cedula:
Descripcion del Programa: (colocoa aqui el enumciado del ejercicio de la guia)


Comentarios:
*/


// LIBRERIAS o Directivas del preprocesador
//EJEMPLO
/*#include <stdlib.h>
#include <math.h>
#include <string>
//#include <windows.h>
#include <time.h>*/

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>


using namespace std;
/*======================================================
// VARIABLES GLOBALES
//======================================================*/

//======================================================
int cont1=0;
int numero=0;
int numero1=0;
int num=0;

/*=======================================================
// PROTOTIPOS //
//=======================================================*/
//------------------------------------------
//coloca aqui Los prototipos si colocas los prototipos las funciones deben ir despues de la funcion main

double NroAleatorio(int num);  //definicion de la funcion



/*=======================================================
// FUNCIONES //
//=======================================================*/


//------------------------------------------
//funcion coloca aqui tus funciones o Los prototipos si colocas los prototipos las funciones deben ir despues de la funcion main







//======================================================
// FUNCION PRINCIPAL
//======================================================

main()
{

    cout << "**********************************" << endl << endl;
    cout << "     Se Compilo sin Errores       " << endl << endl;
    cout << "**********************************" << endl;

    srand(time(NULL));// llama al generador de numero aleatorios el cual le entrega 1 valor a la vez.

    num=NroAleatorio(num); // llama a la funcion de numero aleatorios y 
				  //le pide un valor entre 1 y el valor de la variable Numero y guarda enla variable num;
				  
	cout << "Numero Aleatorio--> " << num << "\n"; // Muestra el valor de la variable num
	 //system("pause");

    return 0;
}
/*=======================================================
// FUNCIONES //
//=======================================================*/
//------------------------------------------
//funcion coloca aqui tus funciones si colocaste los prototipos las funciones deben ir despues de la funcion main

//----------------------------------
// Bloque de instrucciones
//----------------------------------
// funcion crea un numero aleatorio
double NroAleatorio(int num)   //definición de la función
{
// VARIABLES lOCALES
//------------------------------------------------------
//esta funcion genera numeros aleatorios entre 1 y 100
// si desea aumentar o disminuir el rango de numeros que se generan
//cambia la el valor de la variable numero
        cont1=0;
        // cambia en la linea siguiente el valor de la variable numero
        // ahora esta en 100 para aumentar el rango de numero aleatorios cambiala
        //consejo dejala asi por ahora.
        numero=100;
        numero=round(numero);
        numero1=round(numero+1);
        // Genera numero aleatorio entre 1 y numero
        num = 1 + rand() % (numero1 - 1);
        //cout << num << " " <<endl;
	return num;
}















