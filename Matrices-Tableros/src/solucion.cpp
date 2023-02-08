#include "solucion.h"

void mostrarVector(vector<int> &v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        if(i != v.size()-1){
            cout << v[i] << ",";
        } else {
            cout << v[i] << "]";
        }
    }
}

/* Ejercicio 1 */

void mostrarMatriz(vector<vector<int>> &m){
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            cout << m[fila][columna] << " ";
        }
        cout << " " << endl;
    }
}

/* Ejercicio 2.a */

int productoPunto(vector<int> v1, vector<int> v2){
    assert(v1.size() == v2.size());                 // PRE: La longitud de ambos vectores debe ser la misma

    int prod = 0;
    for(int i = 0; i < v1.size(); i++){
        prod = prod + v1[i] * v2[i];
    }
    return prod;
}

/* Ejercicio 2.b */

vector<vector<int>> productoConTraspuesta(vector<vector<int>> A){

    vector<vector<int>> prodConTraspuesta;
    int cantFilas = A.size();

    for(int fila = 0; fila < cantFilas; fila++){
        vector<int> filaResActual;                                       // Cuando se llena una fila, se vacia nuevamente el vector para colocar otra
        for(int filaActual = 0; filaActual < cantFilas; filaActual++){
            int valorPosicion = productoPunto(A[fila], A[filaActual]);
            filaResActual.push_back(valorPosicion);
        }
        prodConTraspuesta.push_back(filaResActual);
    }
    return prodConTraspuesta;
}

/* Dejo el siguiente ejemplo como guia para resolver el ejercicio
A            At             res
5 3 4 2       5 8           res00 = A[0] * TODA COLUMNA 0      res01 = A[0] * TODA COLUMNA 1
8 1 0 3       3 1           res10 = A[1] * TODA COLUMNA 0      res11 = A[1] * TODA COLUMNA 1
              4 0
 2x4          2 3

              4x2
*/

/* Ejercicio 3 */

/* La precondicion en el ejercicio 3 es que la cantidad total de elementos de la matriz tiene que ser divisible
por la cantidad de filas que se quiere redimensionar */

vector<int> transformarEnVector(vector<vector<int>> m){
    vector<int> vec;

    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            vec.push_back(m[fila][columna]);
        }
    }
    return vec;
}

vector<vector<int>> redimensionar(vector<vector<int>> m, int filas, int columnas){
    assert((m.size() > 0) && (m.size() * m[0].size() % filas == 0));                      // PRE: Mencionada al inicio del ejercicio

    vector<vector<int>> matrizRedimensionada;
    vector<int> vectorMatriz = transformarEnVector(m);
    int j = 0;
    int i = 0;

    while(i < vectorMatriz.size()){
        vector<int> filaActual;
        while(j < columnas){
            filaActual.push_back(vectorMatriz[i]);
            j++;
            i++;
        }
        matrizRedimensionada.push_back(filaActual);
        j = 0;
    }
    return matrizRedimensionada;
}






