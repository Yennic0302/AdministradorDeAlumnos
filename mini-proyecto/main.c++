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
#include <iomanip>


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
Estudiante newEstudiante ;
newEstudiante.cedula = 28692795;
newEstudiante.nombreYAppellido = "Yender Rodriguez";
newEstudiante.codEst = 0;
newEstudiante.codsMats.push_back(0);
estudiantes[0] = newEstudiante;
  while (op != 8){
    showMainMenu();
    cout<< "Seleccione una opcion: ";
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


void mostrarMensajeDeMateria (Materia newMateria){
  system("cls");
  cout << "Se ha agregado correctamente la materia.\n"<<endl;
  cout << "codMat: "  << newMateria.codMateria << " | "<<"Nombre: " << newMateria.Materia << "\n";
  cout << " ==========================================================================\n";
  cout << "       Pnp1       |       Pnp2       |       Pnp3       |       Pnp4       \n ";
  cout << "==========================================================================\n";
  cout << "        " <<newMateria.porcentajes.Pnp1 << "        |";
  cout << "        " <<newMateria.porcentajes.Pnp2 << "        |";
  cout << "        " <<newMateria.porcentajes.Pnp3 << "        |";
  cout << "        " <<newMateria.porcentajes.Pnp4 << "        ";
  cout << "\n";
}

void establecerMateria(){
  if(codigoDeMateria == 9){
    cout << "no se puede agregar mas materias \n";
    return;
  }
  Materia newMateria;
  string nombreMateria;
  newMateria.codMateria = codigoDeMateria; 
  cout << "Nombre de la materia: ";
  cin >> newMateria.Materia;
  system("cls");
  newMateria.porcentajes = establecerPorcentajes();
  materias[codigoDeMateria] = newMateria;
  codigoDeMateria += 1;
  mostrarMensajeDeMateria(newMateria);
}


void consultarNotasYDatosDelAlumno (int cedula){
  cout << "consultando notas" ;
}

// Juan Navas
void cargarDatosDeAlumno(){
  cout << "cargando Datos";
}

// Yender Rodriguez
// FUNCIONES NO UTILIZADAS
// int digitosDeNumero (int n){
//   int digitos = floor(log10(n)+1);
//   return digitos;
// }

// void agregarCeros (int n){
//   cout << setfill('0') << setw(3) << n ;
// }

// int eliminarCeros (int n){
//   string cadena = to_string(n);
//   int i = 0; 
//   while (cadena[i] == '0') { 
//     i++; 
//   }
//   cadena.erase(0, i); 

//   return stoi(cadena);
// }


int buscarEstudiante(int cedula) {
  for (int i = 0; i < size(estudiantes); i++) {
    if (estudiantes[i].cedula == cedula) {
      return i;
    }
  }
  return -1;
}

int buscarMateria(int codigo) {
  for (int i = 0; i < size(materias); i++) {
    if (materias[i].codMateria == codigo) {
      return i;
    }
  }
  return -1;
}

void mostrarMaterias (vector<int> materiasDeAlumno){
  cout << "codMateria" << " | " <<  "Nombre de Materia" << "\n";
  cout << "==========================================="<< "\n";
  for (int i = 0; i < size(materiasDeAlumno); i++)
    {
      cout << materias[materiasDeAlumno[i]].codMateria << "          | " <<  materias[materiasDeAlumno[i]].Materia << "\n";
    }
  cout << "\n";
}

bool inscritoAMateria (Estudiante estudiante, int codMateria) {
  bool estaInscrito = false;
  for (int i =0; i < size(estudiante.codsMats);i++){
    if (estudiante.codsMats[i]==codMateria){
      estaInscrito=true;
      break;
    }
  }
  return estaInscrito;
}

NotasDeEvaluaciones establecerNotas (){
  NotasDeEvaluaciones nota;
  system("cls");
  cout << "Ingrese notas del 1 al 20 \n";
  cout << "\n";
  cout << "primera evaluacion:  \n";
  cin >> nota.Pn1;
  cout << "segunda evaluacion:  \n";
  cin >> nota.Pn2 ;
  cout << "tercera evaluacion:  \n";
  cin >> nota.Pn3;
  cout << "cuarta evaluacion:   \n";
  cin >> nota.Pn4 ;
  return nota;
};
void mostrarNotasCargadas (Estudiante estudiante, Nota newNota){
  system("cls");
  cout << "Se ha agregado correctamente la nota\n"<<endl;
  cout << "codEst:"<< estudiante.codEst << " | " <<"Estudiante: " << estudiante.nombreYAppellido << "\n";
  cout << "codMat: " << newNota.codMateria  << " | " << "Cedula: "  << newNota.cedulaEstudiante  << "\n";
  cout << " ==========================================================================\n";
  cout << "        Pn1       |       Pn2        |       Pn3        |       Pn4       \n ";
  cout << "==========================================================================\n";
  cout << "        " <<newNota.notas.Pn1 << "        |";
  cout << "        " <<newNota.notas.Pn2 << "        |";
  cout << "        " <<newNota.notas.Pn3 << "        |";
  cout << "        " <<newNota.notas.Pn4 << "        ";
  cout << "\n";
}

void cargarNotasDeAlumno (int cedula){
  int indiceEstudiante = buscarEstudiante(cedula);
  Estudiante estudiante = estudiantes[indiceEstudiante];
  if(indiceEstudiante != -1){
    system("cls");
    Nota newNota;
    newNota.cedulaEstudiante  = cedula;
    mostrarMaterias(estudiante.codsMats);
    cout << "Ingrese codigo de la Materia: ";
    cin >> newNota.codMateria;
    bool estaInscrito = inscritoAMateria(estudiante,newNota.codMateria);
    if(!estaInscrito){
      cout << "Alumno no inscrito a la materia\n";
      cargarNotasDeAlumno(cedula);
    }
    int indiceMateria = buscarMateria(newNota.codMateria);
    if(indiceMateria != -1){
      newNota.notas = establecerNotas();
      notas.push_back(newNota);
      mostrarNotasCargadas(estudiante,  newNota);
    }else{
      cout << "Ingrese codigo de materia correctamente\n";
      cargarNotasDeAlumno(cedula);
    }
  }else {
      cout << "No se a encontrado estudiante con esta Cedula." << endl;
      return;
  };
}

// Juan Navas
void modificarDatosDeAlumno (int cedula){
  cout  << "Modificando Datos del Alumno" << endl;
}

// Yender Rodriguez

int buscarNotaDelAlumno(int cedula, int codMat){
  for(int i = 0; i < notas.size(); i++){
    if(notas[i].cedulaEstudiante == cedula && notas[i].codMateria == codMat){
      return i;
    }
  }
  return -1; 
}
void mostrarNotasModificadas (Estudiante estudiante, Nota newNota){
  system("cls");
  cout << "codEst:"<< estudiante.codEst << " | " <<"Estudiante: " << estudiante.nombreYAppellido << "\n";
  cout << "codMat: " << newNota.codMateria  << " | " << "Cedula: "  << newNota.cedulaEstudiante  << "\n";
  cout << "1. Pn1: " <<newNota.notas.Pn1 << "\n";
  cout << "2. Pn2: " <<newNota.notas.Pn2<< "\n";
  cout << "3. Pn3: " <<newNota.notas.Pn3 << "\n";
  cout << "4. Pn4: " <<newNota.notas.Pn4 << "\n";
}

Nota menuNotasSwitch( Nota notasNuevas,Estudiante estudiante){
  int op;
  system("cls");
  mostrarNotasModificadas(estudiante, notasNuevas);
  cout << "Ingrese la evaluacion que desea cambiar:  ";
  cin >> op;
  switch (op) {
  case 1:{
    cout << "Ingrese nueva nota: ";
    cin >> notasNuevas.notas.Pn1;
    cout << "Desea cambiar otra nota (si/no)? ";
    string resp;
    cin >> resp;
    if(resp == "si"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else{
      return notasNuevas;
    }
    break;
  }
  case 2:{
    cout << "Ingrese nueva nota: ";
    cin >> notasNuevas.notas.Pn2;
    cout << "Desea cambiar otra nota (si/no)? ";
    string resp;
    cin >> resp;
    if(resp == "si"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else{
      return notasNuevas;
    }
    break;
  }
  case 3:{
    cout << "Ingrese nueva nota :";
    cin >> notasNuevas.notas.Pn3;
    cout << "Desea cambiar otra nota (si/no)? ";
    string resp;
    cin >> resp;
    if(resp == "si"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else{
      return notasNuevas;
    }
    break;
  }
  case 4:{
    cout << "Ingrese nueva nota :";
    cin >> notasNuevas.notas.Pn4;
    cout << "Desea cambiar otra nota (si/no)? ";
    string resp;
    cin >> resp;
    if(resp == "si"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else{
      return notasNuevas;
    }
    break;
  }
  default:{
    cout << "no existe la nota especificada";
    return notasNuevas;
    break;
  }
  }
}



void modificarNotasDeAlumno (int cedula){
  int indiceEstudiante = buscarEstudiante(cedula);
  if(indiceEstudiante == -1){
    cout << "No se encuentra estudiante con la cedula indicada";
    return;
  };
  Estudiante estudiante =  estudiantes[indiceEstudiante];
  mostrarMaterias(estudiante.codsMats);
  int codMat;
  cout << "Ingrese el codigo de la materia  que desea Modificar: ";
  cin >> codMat;
  bool inscritoEnMateria = inscritoAMateria(estudiante,codMat);
  if(!inscritoAMateria){
    cout << "No se encuentra estudiante con la cedula indicada";
    return;
  }
  int indexNota  = buscarNotaDelAlumno(cedula, codMat);
  Nota notasAnteriores = notas[indexNota];
  Nota notaNueva = menuNotasSwitch(notasAnteriores,estudiante);
  mostrarNotasModificadas(estudiante, notaNueva);
  cout << "Desea guardar modificaciones? (si/no): ";
  string op;
  cin >> op;
  if(op == "si"){
    notas[indexNota] = notaNueva;
  }else{
    return ;
  }

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
