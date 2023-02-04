#include "solucion.h"

/* Ejercicio 1 */

void mostrarMatriz(vector <vector <int > > m){
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            cout << m[fila][columna] << " ";
        }
        cout << " d " << endl;
    }
}

/* Ejercicio 2.a */

int productoPunto(vector<int> v1, vector<int> v2){
    assert(v1.size() == v2.size());                 // PRE: La longitud de ambos vectores debe ser la misma

    int prod = 0;
    for(int i = 0; i < v1.size(); i++){
        prod = prod + v1[i] * v2[i];
    }
}

/* Ejercicio 2.b */

vector <vector <int > > productoConTraspuesta(vector <vector <int > > A){
    
    vector <vector <int > > prodConTraspuesta;
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
8 1 0 3       3 1           res10 =  res11   
              4 0         
 2x4          2 3
              
              4x2

*/

/* Ejercicio 3 */

 /* La precondicion en el ejercicio 3 es que la cantidad total de elementos de la matriz tiene que ser divisible
por la cantidad de filas que se quiere redimensionar */

vector<int> transformarEnVector(vector <vector <int > > m){
    vector<int> vec;

    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            vec.push_back(m[fila][columna]);
        }
    }
    return vec;
} 

vector <vector <int > > redimensionar(vector <vector <int > > m, int filas, int columnas){
    assert((m.size() > 0) && (m.size() * m[0].size() % filas == 0));                      // PRE: Mencionada al inicio del ejercicio
    
    vector <vector <int > > matrizRedimensionada;
    vector<int> vectorMatriz = transformarEnVector(m);
    int j = 0;
    vector<int> filaActual;
    
    for(int i = 0; i < vectorMatriz.size(); i++){
        if(j < columnas){
            filaActual.push_back(vectorMatriz[i]);
            j++;
        } else {
            j = 0;
            matrizRedimensionada.push_back(filaActual);
            vector<int> filaActual;
        }
    }
    return matrizRedimensionada;
}

/* Ejercicio 4 */

void trasponer(vector <vector <int > >& m){
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            m[fila][columna] = m[columna][fila];
        }
    }
}

/* Ejercicio 5 */

int contarPicos(vector <vector <int > > m){
    int cantPicos = 0;
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            if(esPico(m,fila,columna)){
                cantPicos++;
            }
        }
    }
    return cantPicos;
}

bool esPico(vector <vector <int > > m, int f, int c){
    bool pico = true;
    if(f == 0){
        /* Caso 1. Primer fila de la matriz */
        if(c == 0){
            /* Caso 1.a. Primer fila y primer columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else if(c == m.size()-1){
            /* Caso 1.b Primer fila y ultima columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else {
            /* Caso 1.c Primer fila y columnas del "medio" */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        }
    } else if(f == m.size()-1){
        /* Caso 2 Ultima fila de la matriz */
        if(c == 0){ 
            /* Caso 2.a Ultima fila y primer columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else if(c == m.size() - 1){
            /* Caso 2.b Ultima fila y ultima columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        } else {
            /* Caso 2.c Ultima fila y columnas del "medio" */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
        }
    /* Casos de filas del medio */
    } else if(c == 0){
        /* Caso 3.a Cualquier fila del medio y primera columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
    } else if (c == m.size()-1){
        /* Caso 3.b Cualquier fila del medio y ultima columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] > m[f][c]){
                        pico = false;
                        break;
                    }
                }
            }
    } else {
        /* Caso 4 Cualquier otro valor que no se encuentra en los bordes de la matriz */
        for(int fila = f-1; fila <= f+1 ; fila++){
            for(int columna = c-1; columna <= c+1; columna++){
                if(m[fila][columna] > m[f][c]){
                    pico = false;
                    break;
                }
            }

        }
    }
    return pico;
}
/* Ejemplo de matriz para resolver el ejercicio */

// 1 2 3  
// 4 5 6 
// 7 8 9  

// i = 1
// j = 2

// a = 0 -> b = 1,2
// a = 1 -> b = 1,2
// a = 2 -> b = 1,2

/* Ejercicio 6.a */

tuple<tuple<int, int>, vector<tuple<int, int, int>>> aTriplas(vector<vector<int> > m){

    /* Creacion de la tupla con la cantidad de filas y columnas de la matriz */
    int filasMatriz = m.size();
    int columnasMatriz = m[0].size();
    tuple<int, int> filasYColumnas = make_tuple(filasMatriz, columnasMatriz);

    /* A continuacion, se arma el vector con los elementos distintos de cero detallando sus coordenadas */
    vector<tuple<int, int, int>> distintosCero;
    for(int fila = 0; fila < m.size(); fila++){
        for(int columna = 0; columna < m[fila].size(); columna++){
            if(m[fila][columna] != 0){
                tuple<int, int, int> elemYCoordenadas = make_tuple(m[fila][columna], fila, columna);
                distintosCero.push_back(elemYCoordenadas);
            }
        }
    }

    /* Finalmente, se arma la tupla con ambos resultados */
    tuple<tuple<int, int>, vector<tuple<int, int, int>>> resultado = make_tuple(filasYColumnas, distintosCero);
    return resultado;
}

/* Ejercicio 6.b */

vector<int> triplasAVector(vector<tuple<int, int, int>> m){
    vector<int> vec;
    for(int t = 0; t < m.size(); t++){
        tuple<int, int, int> triplaActual = m[t];
        int elem1 = get<0>(triplaActual);
        int elem2 = get<1>(triplaActual);
        int elem3 = get<2>(triplaActual); 
        vec.push_back(elem1);    
        vec.push_back(elem2);
        vec.push_back(elem3);
    }
    return vec;
}

vector <vector<int > > aMatriz(vector<tuple<int, int, int>> m, tuple<int, int> dim){
    int filasMatriz = get<0>(dim);
    int columnasMatriz = get<1>(dim);
    vector<int> v = triplasAVector(m);
    int indice = 0;
    vector<vector<int> > matriz;
    
    for(int fila = 0; fila < filasMatriz; fila++){
        vector<int> filaActual;
        for(int columna = 0; columna < columnasMatriz; columna++){
            filaActual.push_back(v[indice]);
            indice++;
        }
        matriz.push_back(filaActual);
    }
    return matriz;
}

void transponerDispersa(vector<tuple<int, int, int>>& m){
    for(int i = 0; i < m.size(); i++){
        // int tmp = get<0>(m[i]);
        // (m[i])  = get<1>(m[i]);
        // (m[i]).snd() = tmp;
    }
}

/* Ejercicios opcionales */

/* Ejercicio 7 */

/* Ejercicio 8.a */

void elevar(vector<vector<int>> &terreno, int x){
    for(int fila = 0; fila < terreno.size(); fila++){
        for(int columna = 0; columna < (terreno[fila]).size(); columna++){
            terreno[fila][columna] = terreno[fila][columna] + x; 
        }
    }
}

/* Ejercicio 8.a */

bool sobresalen(vector<vector<int>> terreno, int n, int &mts){

}

/* Ejercicio 8.c */

int contarCeldasSubacuaticas(vector<vector<int>> m, int f, int c){
    int celdaSubacuaticas = 0;

    if(f == 0){
        /* Caso 1. Primer fila de la matriz */
        if(c == 0){
            /* Caso 1.a. Primer fila y primer columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        } else if(c == m.size()-1){
            /* Caso 1.b Primer fila y ultima columna */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        } else {
            /* Caso 1.c Primer fila y columnas del "medio" */
            for(int fila = f; fila <= f+1 ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        }
    } else if(f == m.size()-1){
        /* Caso 2 Ultima fila de la matriz */
        if(c == 0){ 
            /* Caso 2.a Ultima fila y primer columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        } else if(c == m.size() - 1){
            /* Caso 2.b Ultima fila y ultima columna */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        } else {
            /* Caso 2.c Ultima fila y columnas del "medio" */
            for(int fila = f-1; fila <= f ; fila++){
                for(int columna = c-1; columna <= c+1; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
        }
    /* Casos de filas del medio */
    } else if(c == 0){
        /* Caso 3.a Cualquier fila del medio y primera columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
                for(int columna = c; columna <= c+1; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
    } else if (c == m.size()-1){
        /* Caso 3.b Cualquier fila del medio y ultima columna */
        for(int fila = f-1; fila+1 <= f ; fila++){
                for(int columna = c-1; columna <= c; columna++){
                    if(m[fila][columna] < 0){
                        celdaSubacuaticas++;
                    }
                }
            }
    } else {
        /* Caso 4 Cualquier otro valor que no se encuentra en los bordes de la matriz */
        for(int fila = f-1; fila <= f+1 ; fila++){
            for(int columna = c-1; columna <= c+1; columna++){
                if(m[fila][columna] < 0){
                    celdaSubacuaticas++;
                }
            }
        }
    }
    return celdaSubacuaticas;
}

int cantCeldasVecinas(vector<vector<int>> t, int f, int c){
    if(f == 0 || f == t.size() - 1){
        if(c == 0 || c == t[f].size() - 1){
            return 2;
        }
    } else if(c == 0 || c == t[f].size() -1){
        return 3;

    } else {
        return 4;
    }
}

int islas(vector<vector<int>> terreno){
    int cantIslas = 0;

    for(int fila = 0; fila < terreno.size(); fila++){
        for(int columna = 0; columna < terreno[fila].size(); columna++){
            int celdasSubacuaticas = contarCeldasSubacuaticas(terreno, fila, columna);
            if(celdasSubacuaticas == cantCeldasVecinas(terreno, fila, columna)){
                cantIslas++;
            }
        }
    }
    return cantIslas;
}

/* Ejemplo de matriz para la resolucion del ejercicio 

1235
4565
7895
7890
*/

 /* Ejercicio 9 */

tuple<int, int> buscarValleDesde(vector< vector<int>> m, int fila, int columna){
    tuple<int, int> coordenadasValle;
    for(int f = fila; f < m.size(); f++){
        for(int c = columna; columna < m[f].size(); columna++){
            if(todosVecinosAdyacentesMenores(m,f,c)){
                coordenadasValle = make_tuple(f,c); 
            }

        }
    }
    return coordenadasValle;
}

bool todosVecinosAdyacentesMenores(vector< vector<int>> m, int fila, int columna){
    bool todosMenores = true;
    if(fila == 0){
        if(columna == 0){
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        } else if(columna == m[fila].size() - 1){
            /* Ultima columna de la matriz */
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna-1; j <= columna; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        } else {
            /* Cualquier otra columna */
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        }
    } else if(fila == m.size()-1){
        /* Casos ultima fila */
        if(columna == 0){
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        } else if(columna == m[fila].size()-1){
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        } else {
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
        }
    } else {
        /* Casos cualquier otra fila */
        for(int i = fila-1; i <= fila+1; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(m[i][j] < m[fila][columna]){
                        todosMenores = false;
                        break;
                    }
                }
            }
    }
    return todosMenores;
}

// 1234
// 5678
// 9870
// 3456

/* Ejercicio 10 */

/* Ejercicio 11.a */

bool estaAmenazada(vector<vector<char> > t, int fila, int columna){
    bool hayAmenaza = false;

    if(fila == 0){
        if(columna == 0){
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        } else if(columna == t[fila].size() - 1){
            /* Ultima columna de la matriz */
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna-1; j <= columna; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        } else {
            /* Cualquier otra columna */
            for(int i = fila; i <= fila+1; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        }
    } else if(fila == t.size()-1){
        /* Casos ultima fila */
        if(columna == 0){
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        } else if(columna == t[fila].size()-1){
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        } else {
            for(int i = fila-1; i <= fila; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
        }
    } else {
        /* Casos cualquier otra fila */
        for(int i = fila-1; i <= fila+1; i++){
                for(int j = columna-1; j <= columna+1; j++){
                    if(t[i][j] == 'r'){
                        hayAmenaza = true;
                        break;
                    }
                }
            }
    }
    return hayAmenaza;
}

bool reinasEnAmenaza(vector<vector<char> > tablero, tuple<int, int> dimensiones){
    assert(get<0>(dimensiones) == get<1>(dimensiones));                     // PRE: Tablero cuadrado 

    bool amenazadas = false;
    int cantFilas = get<0>(dimensiones);
    int cantColumnas = get<1>(dimensiones);

    for(int fila = 0; fila < cantFilas; fila++){
        for(int columna = 0; columna < cantColumnas; columna++){
            if(estaAmenazada(tablero, fila, columna)){
                amenazadas = true;
                break;
            }
        }
    }
    return amenazadas;
}








































