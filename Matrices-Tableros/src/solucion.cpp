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

/* Ejercicio 4 */

vector<vector<int>> trasponer(vector<vector<int>> &m){
    vector<vector<int>> traspuesta;

    for(int columna = 0; columna < m[0].size(); columna++){
        vector<int> filaActualDeTraspuesta;
        for(int fila = 0; fila < m.size(); fila++){
            filaActualDeTraspuesta.push_back(m[fila][columna]);
        }
        traspuesta.push_back(filaActualDeTraspuesta);
    }
    return traspuesta;
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

bool esPico(vector<vector<int>> m, int f, int c){
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

tuple<tuple<int,int>, vector<tuple<int,int,int>>> aTriplas(vector<vector<int>> m){

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

int encontrarMinPosicion(vector<tuple<int,int,int>> &vt, int desde, int hasta){
    int min = desde;
    for(int i = desde+1; i < hasta; i++){
        if(get<1>(vt[i]) < get<1>(vt[min])){
            min = i;
        }
    }
    return min;
}

void intercambiar(vector<tuple<int,int,int>> &vt, int indice, int minimo){
    tuple<int,int,int> tmp = vt[indice];
    vt[indice] = vt[minimo];
    vt[minimo] = tmp;
}

void ordenarPorColumna(vector<tuple<int,int,int>> &vt){
    for(int i = 0; i < vt.size(); i++){
        int minPos = encontrarMinPosicion(vt, i, vt.size());
        intercambiar(vt, i, minPos);
    }
}

vector<vector<int>> aMatriz(vector<tuple<int,int,int>> m, tuple<int,int> dim){
    vector<vector<int>> matriz;
    int filasMatriz = get<0>(dim);
    int columnasMatriz = get<1>(dim);

    vector<vector<tuple<int,int,int>>> filasDeLaMatriz;

    /* Se cargan los elementos de  acuerdo a su respectiva fila */
    for(int fila = 0; fila < filasMatriz; fila++){
        vector<tuple<int,int,int>> filaActual;
        for(int i = 0; i < m.size(); i++){
            if(get<0>(m[i]) == fila){
                filaActual.push_back(m[i]);
            }
        }
        filasDeLaMatriz.push_back(filaActual);
    }

    /* Ahora, se ordena cada fila de acuerdo a la columna */
    for(int k = 0; k < filasDeLaMatriz.size(); k++){
        ordenarPorColumna(filasDeLaMatriz[k]);
    }

    /* Finalmente, se colocan las filas ordenadas en la matriz */
    for(int h = 0; h < filasDeLaMatriz.size(); h++){
        vector<int> filaActualOrdenada;
        for(int s = 0; s < filasDeLaMatriz[h].size(); s++){
            int elementoActual = get<0>(filasDeLaMatriz[h][s]);
            filaActualOrdenada.push_back(elementoActual);
        }
        matriz.push_back(filaActualOrdenada);
    }
    return matriz;
}

/* Ejercicio 6.c */

int buscarMaxValorFila(vector<tuple<int,int,int>> m){
    int indiceMaxFila = 0;
    for(int i = 1; i < m.size(); i++){
        int valorFilaActual = get<0>(m[i]);
        if(valorFilaActual > get<0>(m[indiceMaxFila])){
            indiceMaxFila = i;
        }
    }
    int valorMaxFila = get<0>(m[indiceMaxFila]);
    return valorMaxFila;
}

int buscarMaxValorColumna(vector<tuple<int,int,int>> m){
    int indiceMaxColumna = 0;
    for(int i = 1; i < m.size(); i++){
        int valorColumnaActual = get<1>(m[i]);
        if(valorColumnaActual > get<1>(m[indiceMaxColumna])){
            indiceMaxColumna = i;
        }
    }
    int valorMaxColumna = get<1>(m[indiceMaxColumna]);
    return valorMaxColumna;
}

vector<vector<int>> transponerDispersa(vector<tuple<int,int,int>> m){
    int cantFilas = buscarMaxValorFila(m);
    int cantColumnas = buscarMaxValorColumna(m);
    tuple<int,int> dimensiones = make_tuple(cantFilas,cantColumnas);

    /* Armo la matriz como un vector de vector de enteros */
    vector<vector<int>> matriz = aMatriz(m,dimensiones);

    /* Finalmente, se traspone la matriz */
    vector<vector<int>> matrizTraspuesta = trasponer(matriz);
    return matrizTraspuesta;

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

/* Ejercicio 8.b */

bool sobresalen(vector<vector<int>> terreno, int n, int mts){
    bool puedoModificar = false;
    elevar(terreno, mts);

    /* Una vez elevado el terreno, se chequea si la cantidad de celdas subacuaticas es igual a n */
    int cantCeldasSubacuaticas = 0;
    for(int fila = 0; fila < terreno.size(); fila++){
        for(int columna = 0; columna < terreno[fila].size(); columna++){
            if(terreno[fila][columna] < 0){
                cantCeldasSubacuaticas++;
            }
        }
    }

    if(cantCeldasSubacuaticas == n){
        puedoModificar = true;
    }
    return puedoModificar;
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
    int celdasVecinas = 0;
    if(f == 0 || f == t.size() - 1){
        if(c == 0 || c == t[f].size() - 1){
            celdasVecinas = 2;
        }
    } else if(c == 0 || c == t[f].size() -1){
        celdasVecinas = 3;
    } else {
        celdasVecinas = 4;
    }
    return celdasVecinas;
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

bool caracteresValidos(vector<vector<char>> tablero){
    bool tableroValido = true;

    for(int fila = 0; fila < tablero.size(); fila++){
        for(int columna = 0; tablero[fila].size(); columna++){
            if(!((tablero[fila][columna] == 'X') || (tablero[fila][columna] == 'O') || (tablero[fila][columna] == ' '))){
                tableroValido = false;
            }
        }
    }
    return tableroValido;
}

vector<char> armarLineaNorte(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaN;
    for(int i = fila; i >= 0; i--){
        lineaN.push_back(tablero[i][columna]);
    }
    return lineaN;
}

vector<char> armarLineaSur(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaS;
    for(int i = fila; i < 3; i++){
        lineaS.push_back(tablero[i][columna]);
    }
    return lineaS;
}

vector<char> armarLineaEste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaE;
    for(int j = columna; j < 3; j++){
        lineaE.push_back(tablero[fila][j]);
    }
    return lineaE;
}

vector<char> armarLineaOeste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaO;
    for(int j = columna; j >= 0; j--){
        lineaO.push_back(tablero[fila][j]);
    }
    return lineaO;
}

vector<char> armarLineaNoreste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaNE;
    lineaNE.push_back(tablero[fila][columna]);
    lineaNE.push_back(tablero[1][1]);
    lineaNE.push_back(tablero[0][2]);
    return lineaNE;
}

vector<char> armarLineaNoroeste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaNO;
    lineaNO.push_back(tablero[fila][columna]);
    lineaNO.push_back(tablero[1][1]);
    lineaNO.push_back(tablero[0][0]);
    return lineaNO;
}

vector<char> armarLineaSureste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaSE;
    lineaSE.push_back(tablero[fila][columna]);
    lineaSE.push_back(tablero[1][1]);
    lineaSE.push_back(tablero[2][2]);
    return lineaSE;
}

vector<char> armarLineaSuroeste(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaSO;
    lineaSO.push_back(tablero[fila][columna]);
    lineaSO.push_back(tablero[1][1]);
    lineaSO.push_back(tablero[2][0]);
    return lineaSO;
}

vector<char> armarLineaRecta(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaR;
    for(int j = columna-1; j < 3; j++){
        lineaR.push_back(tablero[fila][j]);
    }
    return lineaR;
}

vector<char> armarLineaVertical(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaV;
    for(int i = fila-1; i < 3; i++){
        lineaV.push_back(tablero[i][columna]);
    }
    return lineaV;
}

vector<char> armarLineaDiagonalDerecha(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaDD;
    lineaDD.push_back(tablero[0][0]);
    lineaDD.push_back(tablero[fila][columna]);
    lineaDD.push_back(tablero[2][2]);

    return lineaDD;
}

vector<char> armarLineaDiagonalIzquierda(vector<vector<char>> tablero, int fila, int columna){
    vector<char> lineaDI;
    lineaDI.push_back(tablero[0][0]);
    lineaDI.push_back(tablero[fila][columna]);
    lineaDI.push_back(tablero[2][0]);

    return lineaDI;
}

// XOX
// XXO
// OXO

bool todosIgualesA(vector<char> palabra, char letra){
    bool iguales = false;
    int i = 0;
    while((i < palabra.size()) && (int(palabra[i]) == int(letra))){
        /* Mientras los caracteres son iguales no hacemos nada. Solo avanzo el indice i */
        i++;
    }
    /* Se interrumpio el ciclo */
    if(i == palabra.size()){
        iguales = true;
    }
    return iguales;
}

bool hayLineaEnCualquierDireccion(vector<vector<char>> t, int f, int c, char caracter){
    bool hayLinea = false;

    vector<vector<char>> todasLineasPosibles;
    vector<char> lineaNorte;
    vector<char> lineaSur;
    vector<char> lineaEste;
    vector<char> lineaOeste;
    vector<char> lineaDiagonalNoreste;
    vector<char> lineaDiagonalNoroeste;
    vector<char> lineaDiagonalSureste;
    vector<char> lineaDiagonalSuroeste;
    vector<char> lineaRecta;
    vector<char> lineaVertical;
    vector<char> lineaDiagonalDerecha;
    vector<char> lineaDiagonalIzquierda;

    if(f == 0){
        if(c == 0){
            // Caso Fila 0, columna 0
            lineaEste = armarLineaEste(t,f,c);
            lineaSur = armarLineaSur(t,f,c);
            lineaDiagonalSureste = armarLineaSureste(t,f,c);
            todasLineasPosibles.push_back(lineaEste);
            todasLineasPosibles.push_back(lineaSur);
            todasLineasPosibles.push_back(lineaDiagonalSureste);
        } else if(c == 1){
            // Caso Fila 0, columna 1
            lineaRecta = armarLineaRecta(t,f,c);
            lineaSur = armarLineaSur(t,f,c);
            todasLineasPosibles.push_back(lineaRecta);
            todasLineasPosibles.push_back(lineaSur);
        } else {
            // Caso Fila 0, columna 2
            lineaOeste = armarLineaOeste(t,f,c);
            lineaSur = armarLineaSur(t,f,c);
            lineaDiagonalSuroeste = armarLineaSuroeste(t,f,c);
            todasLineasPosibles.push_back(lineaOeste);
            todasLineasPosibles.push_back(lineaSur);
            todasLineasPosibles.push_back(lineaDiagonalSuroeste);
        }
    } else if(f == 1){
        if(c == 0){
            // Caso Fila 1, columna 0
            lineaEste = armarLineaEste(t,f,c);
            lineaVertical = armarLineaVertical(t,f,c);
            todasLineasPosibles.push_back(lineaEste);
            todasLineasPosibles.push_back(lineaVertical);
        } else if(c == 1){
            // Caso Fila 1, columna 1
            lineaRecta = armarLineaRecta(t,f,c);
            lineaVertical = armarLineaVertical(t,f,c);
            lineaDiagonalDerecha = armarLineaDiagonalDerecha(t,f,c);
            lineaDiagonalIzquierda = armarLineaDiagonalDerecha(t,f,c);
            todasLineasPosibles.push_back(lineaRecta);
            todasLineasPosibles.push_back(lineaVertical);
            todasLineasPosibles.push_back(lineaDiagonalDerecha);
            todasLineasPosibles.push_back(lineaDiagonalIzquierda);
        } else {
            // Caso Fila 1, columna 2
            lineaOeste = armarLineaOeste(t,f,c);
            lineaVertical = armarLineaVertical(t,f,c);
            todasLineasPosibles.push_back(lineaOeste);
            todasLineasPosibles.push_back(lineaVertical);
        }
    } else if(c == 0){
        // Fila 2, columna 0
        lineaNorte = armarLineaNorte(t,f,c);
        lineaEste = armarLineaEste(t,f,c);
        lineaDiagonalNoreste = armarLineaNoreste(t,f,c);
        todasLineasPosibles.push_back(lineaNorte);
        todasLineasPosibles.push_back(lineaEste);
        todasLineasPosibles.push_back(lineaDiagonalNoreste);
    } else if(c == 1){
        // Fila 2, columna 1
        lineaRecta = armarLineaRecta(t,f,c);
        lineaNorte = armarLineaNorte(t,f,c);
        todasLineasPosibles.push_back(lineaRecta);
        todasLineasPosibles.push_back(lineaNorte);
    } else {
        // Fila 2, columna 2
        lineaOeste = armarLineaOeste(t,f,c);
        lineaNorte = armarLineaNorte(t,f,c);
        lineaDiagonalNoroeste = armarLineaNoroeste(t,f,c);
        todasLineasPosibles.push_back(lineaEste);
        todasLineasPosibles.push_back(lineaNorte);
        todasLineasPosibles.push_back(lineaDiagonalNoroeste);
    }

    for(int j = 0; j < todasLineasPosibles.size(); j++){
        if(todosIgualesA(todasLineasPosibles[j],caracter)){
            hayLinea = true;
            break;
        }
    }
    return hayLinea;
}

string partidaTaTeTi(vector<vector<char>> tablero){
    string estadoPartida;
    if(!(tablero.size() == 3 && tablero[0].size() == 3 && tablero[1].size() == 3 && tablero[2].size() == 3 && caracteresValidos(tablero))){
        // Tablero invalido
        estadoPartida = "invalido";
    } else {
        // Tablero valido
        estadoPartida = "in progress";
        /* Se chequea para cada posicion del tablero si tiene 3 celdas con el mismo caracter en cualquier direccion posible */
        for(int fila = 0; fila < tablero.size(); fila++){
            for(int columna = 0; columna < tablero[fila].size(); columna++){
                if(hayLineaEnCualquierDireccion(tablero,fila,columna,tablero[fila][columna])){
                    if(tablero[fila][columna] == 'X'){
                        estadoPartida = "cruz";
                    } else if(tablero[fila][columna] == 'O'){
                        estadoPartida = "circulo";
                    }
                }
            }
        }
    }
    return estadoPartida;
}

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








































