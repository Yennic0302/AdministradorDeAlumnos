/*-------------------------------------------------
Fecha:
Catedra:
NombredelPrograma:
Lenguaje de Programacion:
Programador:
Cedula:
Descripcion del Programa:
(coloco aqui el enumciado del ejercicio de la guia)


Comentarios:
*/

// LIBRERIAS o Directivas del preprocesador
// EJEMPLO
/*#include <stdlib.h>
#include <math.h>
#include <string>
//#include <windows.h>
#include <time.h>*/

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>


using namespace std;
/*======================================================
// VARIABLES GLOBALES
//======================================================*/

//======================================================
int cont1 = 0;
int numero = 0;
int numero1 = 0;
int num = 0;

struct Estudiante
{
    int id;
    string nombre;
    Materia materias[MAX_MATERIAS];
};

struct Materia
{
    string nombre;
    vector<Evaluacion> evaluaciones; // Modificado para usar evaluaciones
                                     // int notas[4];  // Removido
                                     // int total;    // Removido
};

struct Evaluacion
{
    string nombre;
    int porcentaje;
    float puntuacion;
};

/*=======================================================
// PROTOTIPOS //
//=======================================================*/
//------------------------------------------
/*coloca aqui Los prototipos si colocas
 los prototipos las funciones deben
 ir despues de la funcion main




*/
/*=======================================================
// FUNCIONES //
//=======================================================*/

//------------------------------------------
// funcion coloca aqui tus funciones
// o Los prototipos si colocas los prototipos las funciones deben ir despues de la funcion main

//======================================================
// FUNCION PRINCIPAL
//======================================================

int main()
{
    cout << "**********************************" << endl
         << endl;
    cout << "  Se compilo sin errores" << endl
         << endl;
    cout << "**********************************\n";
    return 0;
}




void establecerMateria() {
  int codigo;
  
  cout << "Ingrese el código de la materia: ";
  cin >> codigo;
  
  materiaActual = buscarMateria(codigo);
  
  if (materiaActual == -1) {
    cout << "Materia no encontrada." << endl;
  } else {
    cout << "Materia seleccionada: " << materias[materiaActual].nombre << endl;
  }
}

void consultarNotasDatosAlumno() {
  int id;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar el estudiante en el sistema
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante existe, mostrar sus datos y notas
  if (indiceEstudiante != -1) {
    cout << "Nombre: " << estudiantes[indiceEstudiante].nombre << endl;
    cout << "ID: " << estudiantes[indiceEstudiante].id << endl;
    for (int i = 0; i < MAX_MATERIAS; i++) {
      cout << "Materia: " << estudiantes[indiceEstudiante].materias[i].nombre << endl;
      for (int j = 0; j < 4; j++) {
        cout << "  - Nota " << j + 1 << ": " << estudiantes[indiceEstudiante].materias[i].notas[j] << endl;
      }
    }
  } else {
    cout << "El estudiante con la identificación " << id << " no está registrado." << endl;
  }
}

void cargarDatosAlumno() {
  int id;
  string nombre;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar si el estudiante ya está registrado
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante no está registrado, registrarlo
  if (indiceEstudiante == -1) {
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    
    estudiantes[numEstudiantes].id = id;
    estudiantes[numEstudiantes].nombre = nombre;
    
    numEstudiantes++;
    
    cout << "Estudiante registrado correctamente." << endl;
  } else {
    cout << "El estudiante con la identificación " << id << " ya está registrado." << endl;
  }
}

void cargarNotasParcialesAlumno() {
  int id;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar el estudiante en el sistema
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante existe, cargar las notas
  if (indiceEstudiante != -1) {
    for (int j = 0; j < MAX_MATERIAS; j++) {
      for (int k = 0; k < 4; k++) {
        cout << "Ingrese la nota " << k + 1 << " del estudiante " << estudiantes[indiceEstudiante].id << " en " << estudiantes[indiceEstudiante].materias[j].nombre << ": ";
        cin >> estudiantes[indiceEstudiante].materias[j].notas[k];
        estudiantes[indiceEstudiante].materias[j].total += estudiantes[indiceEstudiante].materias[j].notas[k];
      }
    }
    cout << "Notas cargadas correctamente." << endl;
  } else {
    cout << "El estudiante con la identificación " << id << " no está registrado." << endl;
  }
}

void modificarDatosAlumno() {
  int id;
  string nombre;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar el estudiante en el sistema
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante existe, modificar sus datos
  if (indiceEstudiante != -1) {
    cout << "Ingrese el nuevo nombre del estudiante: ";
    cin >> nombre;
    
    estudiantes[indiceEstudiante].nombre = nombre;
    
    cout << "Datos del estudiante modificados correctamente." << endl;
  } else {
    cout << "El estudiante con la identificación " << id << " no está registrado." << endl;
  }
}

void modificarNotasParcialesAlumno() {
  int id;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar el estudiante en el sistema
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante existe, modificar las notas
  if (indiceEstudiante != -1) {
    for (int j = 0; j < MAX_MATERIAS; j++) {
      for (int k = 0; k < 4; k++) {
        cout << "Ingrese la nueva nota " << k + 1 << " del estudiante " << estudiantes[indiceEstudiante].id << " en " << estudiantes[indiceEstudiante].materias[j].nombre << ": ";
        cin >> estudiantes[indiceEstudiante].materias[j].notas[k];
        estudiantes[indiceEstudiante].materias[j].total = 0;
        for (int l = 0; l < 4; l++) {
          estudiantes[indiceEstudiante].materias[j].total += estudiantes[indiceEstudiante].materias[j].notas[l];
        }
      }
    }
    cout << "Notas modificadas correctamente." << endl;
  } else {
    cout << "El estudiante con la identificación " << id << " no está registrado." << endl;
  }
}

void emitirActaNotas() {
  int id;
  
  cout << "Ingrese el número de identificación del estudiante: ";
  cin >> id;
  
  // Buscar el estudiante en el sistema
  int indiceEstudiante = buscarEstudiante(id);
  
  // Si el estudiante existe, generar el acta de notas
  if (indiceEstudiante != -1) {
    // Generar el acta de notas en formato PDF o HTML
    // ...
    
    cout << "Acta de notas generada correctamente." << endl;
  } else {
    cout << "El estudiante con la identificación " << id << " no está registrado." << endl;
  }
}

float calcularNotaFinal(Estudiante estudiante, int materia) {
  float total = 0.0f;
  for (int i = 0; i < 4; i++) {
    total += estudiante.materias[materia].notas[i];
  }
  return total / 4.0f;
}

void mostrarVisualizacionNota(Estudiante estudiante, int materia) {
  float notaFinal = calcularNotaFinal(estudiante, materia);
  
  cout << "**Materia:** " << estudiante.materias[materia].nombre << endl;
  for (int i = 0; i < 4; i++) {
    cout << "  - Nota " << i + 1 << ": " << estudiante.materias[materia].notas[i] << endl;
  }
  cout << "**Nota final:** " << notaFinal << endl;
}

int buscarEstudiante(int id) {
  for (int i = 0; i < numEstudiantes; i++) {
    if (estudiantes[i].id == id) {
      return i;
    }
  }
  return -1;
}

int buscarMateria(int codigo) {
  for (int i = 0; i < numMaterias; i++) {
    if (materias[i].codigo == codigo) {
      return i;
    }
  }
  return -1;
}



/*=======================================================
// FUNCIONES //
//=======================================================*/
//------------------------------------------
// funcion coloca aqui tus funciones si colocaste los prototipos las funciones deben ir despues de la funcion main

//----------------------------------
// Bloque de instrucciones
//----------------------------------
// funcion crea un numero aleatorio
