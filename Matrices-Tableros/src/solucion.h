
#ifndef L07_MATRICESYTABLEROS_H
#define L07_MATRICESYTABLEROS_H

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <tuple>

using namespace std;

void mostrarMatriz(vector <vector <int > > m);

int productoPunto(vector<int> v1, vector<int> v2);

vector<int> transformarEnVector(vector <vector <int > > m);
vector <vector <int > > redimensionar(vector <vector <int > > m, int filas, int columnas);

void trasponer(vector <vector <int > >& m);

int contarPicos(vector <vector <int > > m);
bool esPico(vector <vector <int > > m, int f, int c);

tuple<tuple<int, int>, vector<tuple<int, int, int>>> aTriplas(vector<vector<int> > m);

#endif 

//L07_MATRICESYTABLEROS_H


 