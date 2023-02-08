
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




#endif

//L07_MATRICESYTABLEROS_H


 