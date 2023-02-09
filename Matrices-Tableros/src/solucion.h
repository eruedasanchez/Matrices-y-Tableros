#ifndef L07_MATRICESYTABLEROS_H
#define L07_MATRICESYTABLEROS_H

#include <iostream>
#include <vector>
#include <string.h>
#include <assert.h>
#include <tuple>

using namespace std;

void mostrarVector(vector<int> &v);

/* Ejercicio 1 */
void mostrarMatriz(vector<vector<int>> &m);

/* Ejercicio 2.a */
int productoPunto(vector<int> v1, vector<int> v2);

/* Ejercicio 2.b */
vector<vector<int>> productoConTraspuesta(vector<vector<int>> A);

/* Ejercicio 3 */
vector<int> transformarEnVector(vector<vector<int>> m);
vector<vector<int>> redimensionar(vector<vector<int>> m, int filas, int columnas);

/* Ejercicio 4 */
vector<vector<int>> trasponer(vector<vector<int>> &m);

/* Ejercicio 5 */
int contarPicos(vector <vector <int > > m);
bool esPico(vector <vector <int > > m, int f, int c);

/* Ejercicio 6.a */
tuple<tuple<int,int>, vector<tuple<int,int,int>>> aTriplas(vector<vector<int>> m);

/* Ejercicio 6.b */
int encontrarMinPosicion(vector<tuple<int,int,int>> &vt, int desde, int hasta);
void intercambiar(vector<tuple<int,int,int>> &vt, int indice, int minimo);
void ordenarPorColumna(vector<tuple<int,int,int>> &vt);
vector <vector<int>> aMatriz(vector<tuple<int,int,int>> m, tuple<int,int> dim);


/* Ejercicio 6.c */
int buscarMaxValorFila(vector<tuple<int,int,int>> m);
int buscarMaxValorColumna(vector<tuple<int,int,int>> m);
vector<vector<int>> transponerDispersa(vector<tuple<int,int,int>> m);

/* Ejercicio 7 */

void elevar(vector<vector<int>> &terreno, int x);

bool sobresalen(vector<vector<int>> terreno, int n, int &mts);

int contarCeldasSubacuaticas(vector<vector<int>> m, int f, int c);
int cantCeldasVecinas(vector<vector<int>> t, int f, int c);
int islas(vector<vector<int>> terreno);

tuple<int, int> buscarValleDesde(vector< vector<int>> m, int fila, int columna);
bool todosVecinosAdyacentesMenores(vector< vector<int>> m, int fila, int columna);

bool reinasEnAmenaza(vector< vector<char>> tablero, tuple<int, int> dimensiones);
bool estaAmenazada(vector< vector<char>> t, int fila, int columna);





#endif 

//L07_MATRICESYTABLEROS_H


 