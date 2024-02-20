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
//#include <algorithm>
//#include <istream>
//#include <stdlib.h>
//#include <math.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <regex>
#include <cstring>
#define MAX_MATERIAS 10


using namespace std;
/*======================================================
// VARIABLES GLOBALES
//======================================================*/

//======================================================

struct Estudiante {
  int codEst;
  int cedula;
  char nombreYApellido[30];
  int codsMats[MAX_MATERIAS] = {0};
};

struct PorcentajeDeEvaluacion{
  int Pnp1;
  int Pnp2;
  int Pnp3;
  int Pnp4;
};


struct Materia {
  int codMateria;
  char Materia[30];
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

Materia materias[MAX_MATERIAS] = {};
Estudiante estudiantes[100] = {};
Nota notas[1000]= {{0,0,{0}}};



/*=======================================================
// PROTOTIPOS //
//=======================================================*/
//------------------------------------------
/*coloca aqui Los prototipos si colocas
 los prototipos las funciones deben
 ir despues de la funcion main

*/

void leerArchivoEstudiantes();
void leerArchivoMaterias();
void leerArchivoNotas();

void escribirEstudiantes();
void escribirMaterias();
void escribirNotas();

void clearScreen();
void pause();

bool tieneLetras(int numero);
void showMainMenu ();
void menuSwitch (int op);

int buscarEstudiante(int cedula);
int buscarMateria(int codigo);
int buscarNotaDelAlumno(int cedula, int codMat);

void mostrarMateriasAlumno (int codMats[10]);
void mostrarMaterias ();

bool inscritoAMateria (int codMats[10], int codMateria);
void mostrarNotasCargadas (Estudiante estudiante, Nota newNota);
void mostrarDatosAlumno (Estudiante estudiante);
void mostrarNotaAlumno (Nota newNota);

PorcentajeDeEvaluacion establecerPorcentajes ();
void mostrarMensajeDeMateria (Materia newMateria);
void establecerMateria();


void consultarNotasDatosAlumno (int cedula);

int* pedirMaterias(int* mats[10]);
void pedirNombreYApellido(char nombreYApellido[30]);
void cargarDatosDeAlumno(int cedula);

NotasDeEvaluaciones establecerNotas(); 
void cargarNotasDeAlumno (int cedula);

int nuevoCodigoDeMateria ( Estudiante estudiante);
void agregarOBorrarMateria (Estudiante estudiante);
void mostrarEstudianteModificado (Estudiante estudiante);
Estudiante menuEstudiante(Estudiante estudiante);
void modificarDatosAlumno (int cedula);

void mostrarNotasModificadas (Estudiante estudiante, Nota newNota);
Nota menuNotasSwitch( Nota notasNuevas,Estudiante estudiante);
void modificarNotasDeAlumno (int cedula);

void emitirActaNotas ();

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
  leerArchivoEstudiantes();
  leerArchivoMaterias();
  leerArchivoNotas();
  int op;
  while (op != 8){
    clearScreen();
    showMainMenu();
    cout<< "Seleccione una opcion: ";
    while (!(cin >> op) || op < 0 || tieneLetras(op)) {
      cin.clear();
      cin.ignore(256,'\n');
      clearScreen();
      cout << "Por favor ingrese un numero entero positivo \n";
      pause();
      clearScreen();
      showMainMenu();
      cout<< "Seleccione una opcion: ";
    }
    menuSwitch(op);
  };  
  
  return 0;
}
/*=======================================================
// FUNCIONES //
//=======================================================*/

void leerArchivoMaterias() {
  fstream archivo("materias.bin", ios::in | ios::binary);
  archivo.read((char*)&materias, sizeof(materias) );
  archivo.close( );

  for (int i = 0; i < size(materias) ; i++) {
    if(materias[i].codMateria != 0){
      codigoDeMateria++;
    }
  }
}

void leerArchivoEstudiantes() {
  fstream archivo("estudiantes.bin", ios::in | ios::binary);
  archivo.read((char*)&estudiantes, sizeof(estudiantes) );
  archivo.close( );

  for (int i = 0; i < size(estudiantes) ; i++) {
    if(estudiantes[i].cedula != 0){
      codigoEstudiante++;
    }
  }
}

void leerArchivoNotas() {
  fstream archivo("notas.bin", ios::in | ios::binary);
  archivo.read((char*)&notas, sizeof(notas) );
  archivo.close( );
}
void escribirEstudiantes(){
  fstream archivo("estudiantes.bin", ios::out | ios::binary);
  archivo.write((char*)&estudiantes, sizeof(estudiantes) );
  archivo.close( );
}

void escribirMaterias(){
  fstream archivo("materias.bin", ios::out | ios::binary);
  archivo.write((char*)&materias, sizeof(materias) );
  archivo.close( );
}

void escribirNotas(){
  fstream archivo("notas.bin", ios::out | ios::binary);
  archivo.write((char*)&notas, sizeof(notas) );
  archivo.close( );
}

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

void clearScreen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

void pause() {
#ifdef _WIN32
system("pause");
#else
system("read -p 'Press Enter to continue...' var");
#endif
}
bool tieneLetras(int numero) {
  string numeroString  = to_string(numero);
  regex regex("[a-zA-Z]");
  return regex_match(numeroString, regex);
}


void menuSwitch (int op) {
    int cedula;
    switch(op) {
        case 1:
            clearScreen();
            establecerMateria();
            escribirMaterias();
            pause();
            break;
        case 2:
            clearScreen();
            cout << "cedula del estudiante: "; 
            while (!(cin >> cedula) ||  cedula < 0) {
              cin.clear();
              cin.ignore(256,'\n');
              clearScreen();
              cout << "Por favor ingrese una cedula valida: ";
            }
            consultarNotasDatosAlumno(cedula);
            pause();
            break;
        case 3:
            clearScreen();
            cout << "cedula del estudiante: "; 
            while (!(cin >> cedula)|| cedula < 0 || tieneLetras(cedula)) {
              cin.clear();
              cin.ignore(256,'\n');
              clearScreen();
              cout << "Por favor ingrese una cedula valida: ";
            }
            cargarDatosDeAlumno(cedula);
            escribirEstudiantes();
            pause();
            break;
        case 4:
            clearScreen();
            cout << "cedula del estudiante: "; 
            while (!(cin >> cedula) || tieneLetras(cedula) || cedula < 0) {
              cin.clear();
              cin.ignore(256,'\n');
              clearScreen();
              cout << "Por favor ingrese una cedula valida: ";
            }
            cargarNotasDeAlumno(cedula);
            escribirNotas();
            pause();
            break;
        case 5:
            clearScreen();
            cout << "cedula del estudiante: "; 
            while (!(cin >> cedula) || tieneLetras(cedula) || cedula < 0) {
              cin.clear();
              cin.ignore(256,'\n');
              clearScreen();
              cout << "Por favor ingrese una cedula valida: ";
            }
            modificarDatosAlumno(cedula);
            escribirEstudiantes();
            escribirNotas();
            pause();
            break;
        case 6:
            clearScreen();
            cout << "cedula del estudiante: "; 
            while (!(cin >> cedula) || tieneLetras(cedula) || cedula < 0) {
              cin.clear();
              cin.ignore(256,'\n');
              clearScreen();
              cout << "Por favor ingrese una cedula valida: ";
            }
            modificarNotasDeAlumno(cedula);
            escribirNotas();
            pause();
            break;
        case 7:
            clearScreen();
            emitirActaNotas();
            pause();
            break;

        case 8:
            cout << "saliendo";
            break;
        default:
            clearScreen();
            cout << "Opcion invalida, intente de nuevo." << endl;
            pause();
            break;
    }
}




int buscarEstudiante(int cedula) {
  for (int i = 0; i < size( estudiantes); i++) {
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

int buscarNotaDelAlumno(int cedula, int codMat){
  for(int i = 0; i < size(notas); i++){
    if(notas[i].cedulaEstudiante == cedula && notas[i].codMateria == codMat){
      return i;
    }
  }
  return -1; 
}

void mostrarMateriasAlumno (int mats[10]){
  cout << "Materias inscritas:" << "\n";
  cout << "codMateria" << " | " <<  "Nombre de Materia" << "\n";
  cout << "==========================================="<< "\n";
  for (int i = 0; i < MAX_MATERIAS; i++)
    {
      if(mats[i] != 0){
        int indiceMateria = buscarMateria(mats[i]);
        cout << materias[indiceMateria].codMateria << "          | " <<  materias[indiceMateria].Materia << "\n";
      }
    }
  cout << "\n";

}

void mostrarMaterias (){
  cout << "codMateria" << " | " <<  "Nombre de Materia" << "\n";
  cout << "==========================================="<< "\n";
  for (int i = 0; i < size(materias); i++)
    {
      if(materias[i].codMateria != 0){
        cout << materias[i].codMateria << "          | " <<  materias[i].Materia << "\n";
      }
    }
  cout << "\n";
}

bool inscritoAMateria (int codMats[10], int codMateria) {
  bool estaInscrito = false;
  for (int i =0; i < MAX_MATERIAS;i++){
    if (codMats[i]==codMateria){
      estaInscrito=true;
      break;
    }
  }
  return estaInscrito;
}

void mostrarNotasCargadas (Estudiante estudiante, Nota newNota){
  int indiceMateria = buscarMateria(newNota.codMateria);
  cout << "codEst:"<< estudiante.codEst << " | " << "Cedula: "  << newNota.cedulaEstudiante  << " | " <<"Estudiante: " << estudiante.nombreYApellido << "\n";
  cout << "codMat: " << newNota.codMateria  << " | " << "Materia: " << materias[indiceMateria].Materia << "\n";
  cout << " ==========================================================================\n";
  cout << "        Pn1       |       Pn2        |       Pn3        |       Pn4       \n ";
  cout << "==========================================================================\n";
  cout << "        " <<newNota.notas.Pn1 << "        |";
  cout << "        " <<newNota.notas.Pn2 << "        |";
  cout << "        " <<newNota.notas.Pn3 << "        |";
  cout << "        " <<newNota.notas.Pn4 << "        ";
  cout << "\n";
}

void mostrarDatosAlumno (Estudiante estudiante){
    cout << "codEst:"<< estudiante.codEst << " | " << "Cedula: "  << estudiante.cedula  << " | " <<"Estudiante: " << estudiante.nombreYApellido << "\n";
    cout << "\n" << endl;
}

void mostrarNotaAlumno (Nota newNota){
  int indiceMateria = buscarMateria(newNota.codMateria);
  cout << "codMat: " << newNota.codMateria  << " | " << "Materia: " << materias[indiceMateria].Materia << "\n";
  cout << " ==========================================================================\n";
  cout << "        Pn1       |       Pn2        |       Pn3        |       Pn4       \n ";
  cout << "==========================================================================\n";
  cout << "        " <<newNota.notas.Pn1 << "        |";
  cout << "        " <<newNota.notas.Pn2 << "        |";
  cout << "        " <<newNota.notas.Pn3 << "        |";
  cout << "        " <<newNota.notas.Pn4 << "        ";
  cout << "\n";
}


PorcentajeDeEvaluacion establecerPorcentajes (){
  PorcentajeDeEvaluacion newPorcentajes;
  cout << "Agregar porcentajes de cada evalucion      \n";
  cout << "Agregar un total de 100\% en 4 evaluaciones\n";
  cout << "\n";
  cout << "Ingrese porcentaje de primera evaluacion: ";
  while (!(cin >> newPorcentajes.Pnp1) || tieneLetras(newPorcentajes.Pnp1)|| newPorcentajes.Pnp1  <= 0 || newPorcentajes.Pnp1 > 50 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 50: ";
  }
  cout << "Ingrese porcentaje de segunda evaluacion: ";
    while (!(cin >> newPorcentajes.Pnp2) || tieneLetras(newPorcentajes.Pnp2)|| newPorcentajes.Pnp2  <= 0 || newPorcentajes.Pnp2 > 50 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 50: ";
  }
  cout << "Ingrese porcentaje de tercera evaluacion: ";
    while (!(cin >> newPorcentajes.Pnp3) || tieneLetras(newPorcentajes.Pnp3)|| newPorcentajes.Pnp3 <= 0 || newPorcentajes.Pnp3 > 50 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 50: ";
  }
  cout << "Ingrese porcentaje de cuarta evaluacion: ";
  while (!(cin >> newPorcentajes.Pnp4) || tieneLetras(newPorcentajes.Pnp4)|| newPorcentajes.Pnp4  <= 0 || newPorcentajes.Pnp4 > 50 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 50: ";
  }

  if(newPorcentajes.Pnp1+ newPorcentajes.Pnp2+newPorcentajes.Pnp3+newPorcentajes.Pnp4 != 100){
    clearScreen();
    cout << "Ingrese los porcentajes  de manera correcta\n";
    return establecerPorcentajes();
  }else{
    return newPorcentajes;
  }
};


void mostrarMensajeDeMateria (Materia newMateria){
  clearScreen();
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
  cout << "\n";

}

void establecerMateria(){
  cin.get();
  if(codigoDeMateria == MAX_MATERIAS){
    cout << "no se puede agregar mas materias \n";
    return;
  }
  Materia newMateria;
  newMateria.codMateria = codigoDeMateria + 1 * 100; 
  cout << "Nombre de la materia: ";
  string nombreMateria;
  getline(cin, nombreMateria);
   while(nombreMateria == ""){
    cout << "El nombre de la materia puede estar vacio, ingrese nuevamente: ";
    getline(cin, nombreMateria);
  }
  strcpy(newMateria.Materia,nombreMateria.c_str());
  clearScreen();
  newMateria.porcentajes = establecerPorcentajes();
  materias[codigoDeMateria] = newMateria;
  codigoDeMateria += 1;
  mostrarMensajeDeMateria(newMateria);
}


void consultarNotasDatosAlumno(int cedula) {
  int indiceEstudiante = buscarEstudiante(cedula);
  if (indiceEstudiante == -1) {
    cout << "El estudiante con la identificacion " << cedula << " no esta registrado." << endl;
    return;
  }
  Estudiante estudiante = estudiantes[indiceEstudiante];
  mostrarDatosAlumno(estudiante);
  bool tieneMateriasInscritas = false;
  for(int i = 0; i <size(estudiante.codsMats); i++){
    if(estudiante.codsMats[i] != 0) tieneMateriasInscritas= true;
  }
  if(tieneMateriasInscritas){
    for(int i = 0; i < size(estudiante.codsMats); i++){
      if(estudiante.codsMats[i] != 0){
        int indiceNota = buscarNotaDelAlumno(cedula,estudiante.codsMats[i]);
        if(indiceNota != -1){
          Nota nota = notas[indiceNota];
          mostrarNotaAlumno(nota);
        }else{
          int indiceMateria = buscarMateria(estudiante.codsMats[i]);
          cout << "No se encuentra notas cargadas para " << materias[indiceMateria].Materia << endl;
        }
      }
    }
  }
}


void pedirNombreYApellido(char nombreYApellido[30]){
  string nombre_c;
  cout << "Ingrese el nombre y apellido del estudiante: ";
  getline(cin,nombre_c);
  while(nombre_c == ""){
    cout << "El nombre y apellido no puede estar vacio, ingrese nuevamente: ";
    getline(cin,nombre_c);
  }
  strcpy(nombreYApellido,nombre_c.c_str());
}

void pedirMaterias(int mats[10]){
  string agregarOtra;
  mostrarMaterias();
  cout << "Que materia desea inscribir?, agrega codigo de materia:";
  int codMat;
  while (!(cin >> codMat) ||codMat < 0 || tieneLetras(codMat)) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo: ";
    }
  bool materiaRegistrada =false;
  for(int  i=0 ; i < MAX_MATERIAS ; i++){
    if(mats[i]==codMat){
      materiaRegistrada = true;
      break;
    }
  }

  if(!materiaRegistrada){
    if(buscarMateria(codMat) != -1){
      for(int i = 0; i <10;i++){
        if(mats[i] ==0 ){
          mats[i]= codMat;
          break;
        }
      }
    }else{
      cout << "La materia ingresada no se encuentra registrada \n";
    }
  }else{
    cout << "Esta materia ya esta inscrita"<<endl;
  }
  cin.get();
  cout << "Desea incribir otra materia? (s/n): "<<endl;
  string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
  if(resp == "s" || resp == "S"){
    clearScreen();
    pedirMaterias(mats);
  }
}
void cargarDatosDeAlumno(int cedula) {
  cin.get();
  int indiceEstudiante = buscarEstudiante(cedula);
  if(indiceEstudiante == -1 ){
    Estudiante newEstudiante;
    newEstudiante.codEst = codigoEstudiante;
    newEstudiante.cedula = cedula;
    pedirNombreYApellido(newEstudiante.nombreYApellido);
    clearScreen();
    cout << "Desea registrar materia? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
    if(resp == "s" || resp == "S"){
      bool algunaMateriaRegistrada = false;
      for(int  i=0 ; i < MAX_MATERIAS ; i++){
        if(materias[i].codMateria != 0){
          algunaMateriaRegistrada = true;
          break;
      }
      }
      if(algunaMateriaRegistrada){
        pedirMaterias(newEstudiante.codsMats);
      }else{
        cout << "no se encuentran  materias registradas, puedes inscribir materias una vez se hallan registrado materias"<< endl;
        pause();
      }
    }
    estudiantes[codigoEstudiante]= newEstudiante;
    codigoEstudiante += 1;
    clearScreen();
    cout << "Estudiante registrado correctamente." << endl;
    cout << "\n" << endl;
    mostrarDatosAlumno(newEstudiante);
    bool algunaMateriaInscrita =false;
    for(int  i=0 ; i < MAX_MATERIAS ; i++){
      if(newEstudiante.codsMats[i]!=0){
        algunaMateriaInscrita = true;
        break;
      }
    }
    if(algunaMateriaInscrita){
      mostrarMateriasAlumno(newEstudiante.codsMats);
    }
  } else{
    cout << "El estudiante con la identificacion " << cedula<< " ya esta registrado." << endl;
  }
}
NotasDeEvaluaciones establecerNotas (){ 
  NotasDeEvaluaciones nota;
  clearScreen();
  cout << "Ingrese notas del 1 al 20 \n";
  cout << "\n";
  cout << "primera evaluacion: ";
  while (!(cin >> nota.Pn1) || tieneLetras(nota.Pn1) || nota.Pn1 < 0 || nota.Pn1 > 20) {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
  }
  cout << "segunda evaluacion: ";
    while (!(cin >> nota.Pn2) || tieneLetras(nota.Pn1) || nota.Pn1 < 0 || nota.Pn1 > 20) {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
  }
  cout << "tercera evaluacion: ";
    while (!(cin >> nota.Pn3) || tieneLetras(nota.Pn3) || nota.Pn3 < 0 || nota.Pn3 > 20) {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
  }
  cout << "cuarta evaluacion: ";
    while (!(cin >> nota.Pn4) || tieneLetras(nota.Pn4) || nota.Pn4 < 0 || nota.Pn4 > 20) {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
  }
  return nota;
};


void cargarNotasDeAlumno (int cedula){
  int indiceEstudiante = buscarEstudiante(cedula);
  Estudiante estudiante = estudiantes[indiceEstudiante];
  if(indiceEstudiante != -1){
    bool algunaMateriaRegistrada = false;
    for(int  i=0 ; i < MAX_MATERIAS ; i++){
      if(estudiante.codsMats[i] != 0){
        algunaMateriaRegistrada = true;
        break;
      }
    }
    if(!algunaMateriaRegistrada){
      cout << "Alumno no tiene materias inscritas para cargar notas."<< endl;
      return;
    }
    Nota newNota;
    newNota.cedulaEstudiante  = cedula;
    mostrarMateriasAlumno(estudiante.codsMats);
    cout << "Ingrese codigo de la Materia: ";
    while (!(cin >> newNota.codMateria) || tieneLetras(newNota.codMateria) || newNota.codMateria < 0) {
      cin.clear();
      cin.ignore(256,'\n');
      clearScreen();
      cout << "Por favor ingrese un numero entero positivo";
    }
    bool estaInscrito = inscritoAMateria(estudiante.codsMats,newNota.codMateria);
    if(!estaInscrito){
      cout << "Alumno no inscrito a la materia\n";
      cargarNotasDeAlumno(cedula);
    }
    int indiceNota = buscarNotaDelAlumno(cedula,newNota.codMateria);
    if(indiceNota != -1){
      cout << "Estudiante ya tiene notas cargadas para esta materia \n";
      return;
    }
    int indiceMateria = buscarMateria(newNota.codMateria);
    if(indiceMateria != -1 ){
      newNota.notas = establecerNotas();
      for (int i = 0; i < size(notas); i++)
      {
        if(notas[i].cedulaEstudiante == 0){
          notas[i]=newNota;
          break;
        }
      }
      clearScreen();
      cout << "Se ha agregado correctamente la nota\n"<<endl;
      mostrarNotasCargadas(estudiante,  newNota);
    }else{
      clearScreen();
      cout << "Ingrese codigo de materia correctamente \n";
      cargarNotasDeAlumno(cedula);
    }
  }else {
      cout << "No se a encontrado estudiante con esta Cedula." << endl;
      return;
  };
}

int nuevoCodigoDeMateria (int codMats[10]){
  cout << "Materias disponibles en sistema: \n"; 
  mostrarMaterias();
  int codMat;
  cout << "Ingrese codigo de materia que desea inscribir: ";
  while (!(cin >> codMat) || tieneLetras(codMat) || codMat < 0 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Agregue correctamente el codigo de materia: ejempl = 0";
  }
  bool estaInscritoAMateria = inscritoAMateria(codMats,codMat);
  if(estaInscritoAMateria){
    cout << "Estudiante ya se encuentra inscrito a la materia \n" <<endl;
    return -1;
  }else{
    return codMat;
  }
}

void agregarOBorrarMateria (int codMats[10]){
  clearScreen();
  cin.get();
  bool tieneMaterias = false;
  for(int i =0; i < MAX_MATERIAS ; i++){
    if(codMats[i] != 0) tieneMaterias = true;
  }
  if(!tieneMaterias){
    cout << "alumno no tiene materias incritas para borrar,pero puedes ingresar una nueva materia.\n" << endl;
  }else{
    mostrarMateriasAlumno(codMats);
  }
  int accion;
  cout << "Desea agregar o borrar materia?: (1: agregar, 0: borrar) ";
  while (!(cin >> accion) || tieneLetras(accion) || accion < 0 ){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Agregue correctamente el codigo de materia: ejempl = 0";
  }
  if(accion == 1){
    clearScreen();
    int codigoNuevoMat =nuevoCodigoDeMateria(codMats);
    if(codigoNuevoMat !=-1){
      for(int i = 0; i < 10; i++){
        if(codMats[i] == 0){
          codMats[i] = codigoNuevoMat;
          break;
        }
      }
    }
  }
  else if(accion == 0){
    if(tieneMaterias){
      cout << "Ingrese el codigo de materia que desea borrar: ";
      int codigoMatABorrar;
      while (!(cin >> codigoMatABorrar) || tieneLetras(codigoMatABorrar)||codigoMatABorrar < 0){
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Agregue correctamente el codigo de materia: ejempl = 0";
      }
      for(int i = 0; i  < MAX_MATERIAS ;i++){
        if(codMats[i]== codigoMatABorrar){
          codMats[i]=0;
          break;
        }
      }
    }else{
      cout << "No tiene materias inscritas para eliminar."<< endl;
    }
  }else{
    cout<<"Opcion no valida\n";
    agregarOBorrarMateria(codMats);
  };
}


void mostrarEstudianteModificado (Estudiante estudiante){
  clearScreen();
  cout << "Seleccione el dato que desea modificar mediante su numero correspondiente: " << "\n";
  cout << "1. Cedula: " <<estudiante.cedula << "\n";
  cout << "2. Nombre y Apellido: " << estudiante.nombreYApellido<< "\n";
  cout << "3. Materias " << "\n";
  cout << "\n";
  bool tieneMaterias = false;
  for(int i =0; i < MAX_MATERIAS ; i++){
    if(estudiante.codsMats[i] != 0) tieneMaterias = true;
  }
  if(tieneMaterias){
    mostrarMateriasAlumno(estudiante.codsMats);
  }else{
    cout <<  "Alumno no esta registrado a alguna materia, puede inscribirlo desde la opcion 3\n" <<endl;
  }
}

Estudiante menuEstudiante(Estudiante estudiante){
  int op;
  clearScreen();
  mostrarEstudianteModificado(estudiante);
  cout << "Ingrese el dato que desea cambiar:  ";
  while (!(cin >> op) || tieneLetras(op)||op < 0){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Agregue un numero entero positivo: ";
  }
  switch (op) {
  case 1:{
    cout << "Ingrese nueva cedula: ";
    while (!(cin >> estudiante.cedula) || tieneLetras(estudiante.cedula)||estudiante.cedula < 0|| buscarEstudiante(estudiante.cedula) != -1){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Agregue una cedula valida y disponible: ";
    }

    cout << "Desea cambiar otro dato? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n";
    }
    if(resp == "s" || resp == "S"){
      return menuEstudiante(estudiante);
      break;
    }else {
      return estudiante;
    }
    break;
  }
  case 2:{
    cin.get();
    cout << "Ingrese nuevo nombre y apellido: ";
    string nombre_c;
    getline(cin,nombre_c);
    while(nombre_c == ""){
      cout << "El nombre y apellido no puede estar vacio, ingrese nuevamente: ";
    getline(cin,nombre_c);
  }
    strcpy(estudiante.nombreYApellido,nombre_c.c_str());
    cout << "Desea cambiar otro dato? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n";
    }
    if(resp == "s" || resp == "S"){
      return menuEstudiante(estudiante);
      break;
    }else {
      return estudiante;
    }
    break;
  }
  case 3:{
    bool algunaMateriaRegistrada = false;
    for(int  i=0 ; i < MAX_MATERIAS ; i++){
      if(materias[i].codMateria != 0){
        algunaMateriaRegistrada = true;
        break;
      }
    }

    if(algunaMateriaRegistrada){
      agregarOBorrarMateria(estudiante.codsMats);
    }else{
      cout << "no se encuentran  materias registradas, puedes inscribir materias una vez se hallan registrado materias"<< endl;
    }

    cout << "Desea cambiar otro dato? (s/n):  ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n";
    }
    if(resp == "s" || resp == "S"){
      return menuEstudiante(estudiante);
      break;
    }else {
      return estudiante;
      break;
    }
    break;
  }
  default:{
    cout << "no existe la nota especificada";
    return estudiante;
    break;
  }
  }
}

void modificarDatosAlumno(int cedula) {
  int indiceEstudiante = buscarEstudiante(cedula);
  if(indiceEstudiante == -1){
    cout << "No se encuentra estudiante con la cedula indicada" <<endl;
    return;
  };
  Estudiante estudiante =  estudiantes[indiceEstudiante];
  int cedulaAntigua = estudiante.cedula;
  Estudiante estudianteModificado = menuEstudiante(estudiante);
  mostrarEstudianteModificado(estudianteModificado);
  cout << "Desea guardar modificaciones? (s/n): ";
  string resp;
  while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "ingrese  una respuesta valida s/n";
    }
  if(resp == "s" || resp == "S"){
    int codigosModificados[10] ={0};
    int contadorMateria= 0;
    for (int i = 0; i < size(estudiante.codsMats); i++)
    {
      int encontrado = false;
      for (int j = 0; j < size(estudianteModificado.codsMats); j++)
      {
        if(estudiante.codsMats[i] == estudianteModificado.codsMats[j])
          encontrado = true;
      }
      if(!encontrado){
        codigosModificados[contadorMateria] = estudiante.codsMats[i];
        contadorMateria++;
      }
    }

    if(codigosModificados[0] !=0){
      int indicesNotas[10] ={-1};
      int contadorIndices = 0;
      for(int i =0; i <  contadorMateria ; i++){
        int indiceNota = buscarNotaDelAlumno(estudiante.cedula,codigosModificados[i]);
        if (indiceNota != -1){
          indicesNotas[contadorIndices] = indiceNota;
          contadorIndices++;
        }
      }
      if(indicesNotas[0] !=-1){
        string op;
        cout << "Se encuentran notas registradas en materias eliminadas\n";
        cout << "Desea proceder con la eliminacion y modificacion? (s/n): ";
        while (!(cin >>op) || (op != "s" &&  op != "n" && op !=  "S" && op != "N")){
          cin.clear();
          cin.ignore(256,'\n');
          cout << "ingrese  una respuesta valida s/n";
        }
        if (op=="s"||op=="S"){
          for(int k = 0; k< contadorIndices;k++){
            notas[indicesNotas[k]] = {0,0,{0}};
          }
          if(cedulaAntigua != estudianteModificado.cedula){
            for(int i = 0; i < size(notas); i++){
              for (int j = 0; j < size(estudianteModificado.codsMats); j++)
              {
                int indiceNota = buscarNotaDelAlumno(cedulaAntigua,estudianteModificado.codsMats[j]);
                if(indiceNota != -1) notas[indiceNota].cedulaEstudiante = estudianteModificado.cedula;
              }
            }
          }

        estudiantes[indiceEstudiante] = estudianteModificado;
        }else{
          return;
        }
      }else{
        if(cedulaAntigua != estudianteModificado.cedula){
        for(int i = 0; i < size(notas); i++){
          for (int j = 0; j < size(estudianteModificado.codsMats); j++)
          {
            int indiceNota = buscarNotaDelAlumno(cedulaAntigua,estudianteModificado.codsMats[j]);
            if(indiceNota != -1) notas[indiceNota].cedulaEstudiante = estudianteModificado.cedula;
          }
        }
        }
      estudiantes[indiceEstudiante] = estudianteModificado;
      return;
      } 
    }else{
      if(cedulaAntigua != estudianteModificado.cedula){
        for(int i = 0; i < size(notas); i++){
          for (int j = 0; j < size(estudianteModificado.codsMats); j++)
          {
            int indiceNota = buscarNotaDelAlumno(cedulaAntigua,estudianteModificado.codsMats[j]);
            if(indiceNota != -1) notas[indiceNota].cedulaEstudiante = estudianteModificado.cedula;
          }
        }
      }
      estudiantes[indiceEstudiante] = estudianteModificado;
      return;
    }
  }else if (resp == "n" || resp == "N"){
    return ;
  }
}

void mostrarNotasModificadas (Estudiante estudiante, Nota newNota){
  clearScreen();
  cout << "codEst:"<< estudiante.codEst << " | " <<"Estudiante: " << estudiante.nombreYApellido << "\n";
  cout << "codMat: " << newNota.codMateria  << " | " << "Cedula: "  << newNota.cedulaEstudiante  << "\n";
  cout << "1. Pn1: " <<newNota.notas.Pn1 << "\n";
  cout << "2. Pn2: " <<newNota.notas.Pn2<< "\n";
  cout << "3. Pn3: " <<newNota.notas.Pn3 << "\n";
  cout << "4. Pn4: " <<newNota.notas.Pn4 << "\n";
}

Nota menuNotasSwitch( Nota notasNuevas,Estudiante estudiante){
  int op;
  clearScreen();
  mostrarNotasModificadas(estudiante, notasNuevas);
  cout << "Ingrese la evaluacion que desea cambiar:  ";
  while (!(cin >> op) || tieneLetras(op)||op < 0){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Agregue un numero entero positivo: ";
  }
  switch (op) {
  case 1:{
    cout << "Ingrese nueva nota: ";
    while (!(cin >> notasNuevas.notas.Pn1) || tieneLetras(notasNuevas.notas.Pn1) || notasNuevas.notas.Pn1 < 0 || notasNuevas.notas.Pn1 > 20) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
    }
    cout << "Desea cambiar otra nota? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
    if(resp == "s" || resp == "S"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else {
      return notasNuevas;
    }
    break;
  }
  case 2:{
    cout << "Ingrese nueva nota: ";
    while (!(cin >> notasNuevas.notas.Pn2) || tieneLetras(notasNuevas.notas.Pn2) || notasNuevas.notas.Pn2 < 0 || notasNuevas.notas.Pn2 > 20) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
    }
    cout << "Desea cambiar otra nota? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
    if(resp == "s" || resp == "S"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else{
      return notasNuevas;
      break;
    }
    break;
  }
  case 3:{
    cout << "Ingrese nueva nota: ";
    while (!(cin >> notasNuevas.notas.Pn3) || tieneLetras(notasNuevas.notas.Pn3) || notasNuevas.notas.Pn3 < 0 || notasNuevas.notas.Pn3 > 20) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
    }
    cout << "Desea cambiar otra nota? (s/n): ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
    if(resp == "s" || resp == "S"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else {
      return notasNuevas;
      break;
    }
    break;
  }
  case 4:{
    cout << "Ingrese nueva nota: ";
    while (!(cin >> notasNuevas.notas.Pn4) || tieneLetras(notasNuevas.notas.Pn4) || notasNuevas.notas.Pn4 < 0 || notasNuevas.notas.Pn4 > 20) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo entre 0 y 20: ";
    }
    cout << "Desea cambiar otra nota? (s/n) : ";
    string resp;
    while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
      cin.clear();
      cin.ignore(256,'\n');
      cout << "ingrese  una respuesta valida s/n: ";
    }
    if(resp == "s" || resp == "S"){
      return menuNotasSwitch( notasNuevas,estudiante);
      break;
    }else {
      return notasNuevas;
      break;
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
  bool tieneMaterias = false;
  for(int i =0; i < MAX_MATERIAS ; i++){
    if(estudiante.codsMats[i] != 0) tieneMaterias = true;
  }
  if(!tieneMaterias){
    cout << "El alumno no tiene materias registradas" << "\n";
    return;
  }else{
    mostrarMateriasAlumno(estudiante.codsMats);
  }
  int codMat;
  cout << "Ingrese el codigo de la materia  que desea Modificar: ";
    while (!(cin >> codMat) || tieneLetras(codMat) || codMat < 0) {
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Por favor ingrese un numero entero positivo: ";
  }
  bool inscritoEnMateria = inscritoAMateria(estudiante.codsMats,codMat);
  if(!inscritoAMateria){
    cout << "El estudiante no se encuentra inscrito a la materia";
    return;
  }
  int indexNota  = buscarNotaDelAlumno(cedula, codMat);
  if(indexNota == -1){
    cout << "Alumno no tiene notas cargadas para la materia " << materias[0].Materia << endl;
    return;
  }
  Nota notasAnteriores = notas[indexNota];
  Nota notaNueva = menuNotasSwitch(notasAnteriores,estudiante);
  mostrarNotasModificadas(estudiante, notaNueva);
  cout << "Desea guardar modificacion? (s/n): ";
  string resp;
  while (!(cin >>resp) || (resp != "s" &&  resp!= "n" && resp !=  "S" && resp != "N")){
    cin.clear();
    cin.ignore(256,'\n');
    cout << "ingrese  una respuesta valida s/n: ";
  }
  if(resp == "s" || resp == "S"){
    notas[indexNota] = notaNueva;
  }else if (resp == "n" || resp == "N"){
    return ;
  }

}

void emitirActaNotas() {
  clearScreen();
  mostrarMaterias();
  int codMateria;
  
  cout << "Ingrese el codigo de la materia: ";
  while (!(cin >> codMateria) || tieneLetras(codMateria) || codMateria < 0 ) {
      cin.clear();
      cin.ignore(256,'\n');
      cout << "Por favor ingrese un numero entero positivo: ";
    }
  clearScreen();
  
  int indiceMateria = buscarMateria(codMateria);
  
  if (codMateria != -1) {

    Materia materia = materias[indiceMateria];
    cout << "Universidad Experimental de la Gran Caracas" << endl;
    cout << "Sede: La Floresta" << endl;
    cout << "Carrera: Ing. Informatica" << endl;
    cout << "Catedra: "<<materia.Materia << endl;
    cout << endl;

    cout << setw(63) << materia.porcentajes.Pnp1<<"%" << setw(8) << materia.porcentajes.Pnp2 <<"%" 
    << setw(8)<< materia.porcentajes.Pnp3<<"%" << setw(8)  << materia.porcentajes.Pnp4<<"%"  <<endl;

    cout << setw(10) << "Cod.Est" << setw(15) << "Cedula" << setw(30) << "Nombre y Apellido" 
    << setw(10) << "Np1" << setw(10) << "NP2" << setw(10) << "NP3" << setw(10) << "NP4" 
    << setw(15) << "Nota Final" << setw(15) << "Status"  << endl;
    cout << "===============================================================================================================================" <<"\n" << endl;


    for(int i = 0; i < size(estudiantes); i++){
      for (int j = 0; j < size(estudiantes[i].codsMats); j++)
      {
        if(codMateria == estudiantes[i].codsMats[j]){
          int indiceNota = buscarNotaDelAlumno(estudiantes[i].cedula, estudiantes[i].codsMats[j]);
          Nota notaEstudiante =  notas[indiceNota];

        if(indiceNota != -1){
        float pnpf1,pnpf2,pnpf3,pnpf4,nf;
        pnpf1 =  materia.porcentajes.Pnp1 *  notaEstudiante.notas.Pn1 / 100  ;
        pnpf2 =  materia.porcentajes.Pnp2 *  notaEstudiante.notas.Pn2 / 100  ;
        pnpf3 =  materia.porcentajes.Pnp3 *  notaEstudiante.notas.Pn3 / 100  ;
        pnpf4 =  materia.porcentajes.Pnp4 *  notaEstudiante.notas.Pn4 / 100  ;
 
        nf = pnpf1+pnpf2+pnpf3+pnpf4; 

        string status;
        if (nf < 12) {
            status = "Reprobado";
        } else if (nf < 16) {
            status = "Recuperativo";
        } else {
            status = "Aprobado";
        }


        cout << setw(10) << estudiantes[i].codEst << setw(15) << estudiantes[i].cedula << setw(30) << estudiantes[i].nombreYApellido 
             << setw(10) << notaEstudiante.notas.Pn1 << setw(10) << notaEstudiante.notas.Pn2<< setw(10) << notaEstudiante.notas.Pn3 << setw(10) << notaEstudiante.notas.Pn4
             << setw(15) << nf << setw(15) << status << "\n" << endl;
        }else{


          cout << setw(10) << estudiantes[i].codEst << setw(15) << estudiantes[i].cedula << setw(30) << estudiantes[i].nombreYApellido 
          << setw(10) << "N/C" << setw(10) << "N/C" << setw(10) << "N/C"<< setw(10) << "N/C"<< setw(15) << "N/C" << setw(15) << "Reprobado" <<"\n" << endl;
        }

        }

      }
    }

    cout << "Acta de notas generada correctamente." << endl;
  } else {
    cout << "La materia no está registrada." << endl;
  }
}

//------------------------------------------
//funcion coloca aqui tus funciones si colocaste los prototipos las funciones deben ir despues de la funcion main

//----------------------------------
// Bloque de instrucciones
//----------------------------------
// funcion crea un numero aleatorio
