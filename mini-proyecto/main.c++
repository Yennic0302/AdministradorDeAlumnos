/*-------------------------------------------------
Fecha: 26/01/2024
Catedra: Algoritmica y programacion
NombredelPrograma: 
Lenguaje de Programacion: C++
Programador: Juan Navas / Yender Rodriguez
Cedula:  / 28692795
Descripcion del Programa:
(coloco aqui el enumciado del ejercicio de la guia)


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
#include <algorithm>
#include <vector>


using namespace std;
/*======================================================
// VARIABLES GLOBALES
//======================================================*/

//======================================================

struct Estudiante {
  int codEst;
  int cedula;
  string nombreYAppellido;
  vector<int> codsMats;
};

struct PorcentajeDeEvaluacion{
  int Pnp1;
  int Pnp2;
  int Pnp3;
  int Pnp4;
};


struct Materia {
  int codMateria;
  string Materia;
  PorcentajeDeEvaluacion porcentajes;
};

struct NotasDeEvaluaciones{
  int Pn1;
  int Pn2;
  int Pn3;
  int Pn4;
};

struct Nota {
  int codMateria;
  int cedulaEstudiante;
  NotasDeEvaluaciones notas;
};

int codigoEstudiante = 0;
int codigoDeMateria = 0;
Materia materias[10];
Estudiante estudiantes[99];
vector<Nota> notas;



/*=======================================================
// PROTOTIPOS //
//=======================================================*/
//------------------------------------------
/*coloca aqui Los prototipos si colocas
 los prototipos las funciones deben
 ir despues de la funcion main

*/
void showMainMenu ();
void menuSwitch (int op);

PorcentajeDeEvaluacion establecerPorcentajes ();
void establecerMateria();

void consultarNotasYDatosDelAlumno (int cedula);

void cargarDatosDeAlumno();

void cargarNotasDeAlumno (int cedula);

void modificarDatosDeAlumno (int cedula);

void modificarNotasDeAlumno (int cedula);

void emisionDeActaDeNotas (int cedula);

/*=======================================================
// FUNCIONES //
//=======================================================*/



//------------------------------------------
//funcion coloca aqui tus funciones
//o Los prototipos si colocas los prototipos las funciones deben ir despues de la funcion main



//======================================================
// FUNCION PRINCIPAL
//======================================================



int main (){
int op;
  while (op != 8){
    showMainMenu();
    cin >> op;
    menuSwitch(op);
  };  
  
  return 0;
}
/*=======================================================
// FUNCIONES //
//=======================================================*/

void showMainMenu (){
  cout<< "=============================== MENU =================================\n";
  cout<< "    1. Establecer Materia                                             \n";
  cout<< "    2. Consultar notas y datos del alumno                             \n";
  cout<< "    3. Cargar datos de alumno                                         \n";
  cout<< "    4. Cargar notas parciales del alumno                              \n";
  cout<< "    5. Modificar datos del alumno                                     \n";
  cout<< "    6. Modificar notas parciales del alumno                           \n";
  cout<< "    7. Emision de Acta de Notas                                       \n";
  cout<< "    8. Salir                                                          \n";
  cout<< "                                                                      \n";
  cout<< "                      Seleccione una opcion:                          \n";
  cout<< "======================================================================\n";
}


void menuSwitch (int op) {
    int cedula;
    switch(op) {
        case 1:
            system("cls");
            establecerMateria();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "cedula del estudiante: "; 
            cin >> cedula ;
            consultarNotasYDatosDelAlumno(cedula);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cargarDatosDeAlumno();
            system("pause");
            system("cls");

            break;
        case 4:
            system("cls");
            cout << "cedula del estudiante: "; 
            cin >> cedula ;
            cargarNotasDeAlumno(cedula);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "cedula del estudiante: "; 
            cin >> cedula ;
            modificarDatosDeAlumno(cedula);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << "cedula del estudiante: "; 
            cin >> cedula ;
            modificarNotasDeAlumno(cedula);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            cout << "cedula del estudiante: "; 
            cin >> cedula ;
            emisionDeActaDeNotas(cedula);
            system("pause");
            system("cls");
        break;

        case 8:
            cout << "saliendo";
        break;
        default:
            cout << "Opción inválida, intente de nuevo." << endl;
            break;
    }
}


PorcentajeDeEvaluacion establecerPorcentajes (){
  PorcentajeDeEvaluacion newPorcentajes;
  cout << "Agregar porcentajes de cada evalucion      \n";
  cout << "Agregar un total de 100\% en 4 evaluaciones\n";
  cout << "\n";
  cout << "Ingrese porcentaje de primera evaluacion:  \n";
  cin >> newPorcentajes.Pnp1;
  cout << "Ingrese porcentaje de segunda evaluacion:  \n";
  cin >> newPorcentajes.Pnp2;
  cout << "Ingrese porcentaje de tercera evaluacion:  \n";
  cin >> newPorcentajes.Pnp3;
  cout << "Ingrese porcentaje de cuarta evaluacion:   \n";
  cin >> newPorcentajes.Pnp4;
  if(newPorcentajes.Pnp1+ newPorcentajes.Pnp2+newPorcentajes.Pnp3+newPorcentajes.Pnp4 != 100){
    system("cls");
    cout << "Ingrese los porcentajes  de manera correcta\n";
    return establecerPorcentajes();
  }else{
    return newPorcentajes;
  }
};

void establecerMateria(){
  Materia newMateria;
  string nombreMateria;
  newMateria.codMateria = codigoDeMateria; 
  cout << "Nombre de la materia: \n";
  cin >> newMateria.Materia;
  system("cls");
  newMateria.porcentajes = establecerPorcentajes();
  materias[codigoDeMateria] = newMateria;
  codigoDeMateria += 1;
  cout << "\n";
  cout << "Se ha agregado correctamente la materia.\n"<<endl;
  cout << "codMat: " ; cout << newMateria.codMateria; cout << " | "; cout << newMateria.Materia; cout << "\n";
  cout << " ==========================================================================\n";
  cout << "       Pnp1       |       Pnp2       |       Pnp3       |       pnp4       \n ";
  cout << "==========================================================================\n";
  cout << "        "; cout <<newMateria.porcentajes.Pnp1; cout << "        |";
  cout << "        "; cout <<newMateria.porcentajes.Pnp2; cout << "        |";
  cout << "        "; cout <<newMateria.porcentajes.Pnp3; cout << "        |";
  cout << "        "; cout <<newMateria.porcentajes.Pnp4; cout << "        ";
  cout << "\n";
}


void consultarNotasYDatosDelAlumno (int cedula){
  cout << "consultando notas" ;
}

// Juan Navas
void cargarDatosDeAlumno(){
  cout << "cargando Datos";
}

// Yender Rodriguez

void cargarNotasDeAlumno (int cedula){
  cout << "cargando notas";
}

// Juan Navas
void modificarDatosDeAlumno (int cedula){
  cout << "modificando datos";
}

// Yender Rodriguez

void modificarNotasDeAlumno (int cedula){
  cout << "modificando notas";
}

void emisionDeActaDeNotas (int cedula){
  cout << "emitiendo notas";
}


//------------------------------------------
//funcion coloca aqui tus funciones si colocaste los prototipos las funciones deben ir despues de la funcion main

//----------------------------------
// Bloque de instrucciones
//----------------------------------
// funcion crea un numero aleatorio
