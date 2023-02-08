#include "lib/gtest-1.8.1/gtest.h"
#include "src/solucion.h"

int main(int argc, char **argv) {

    /*
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    */

    /* Ejercicio 1 */

    /*
    vector<vector<int>> m;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    m.push_back(v1);

    vector<int> v2;
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    m.push_back(v2);

    cout << "La matriz construida es " << endl;
    mostrarMatriz(m);
    */

    /* Ejercicio 2.a */

    /*
    vector<vector<int>> m;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    m.push_back(v1);

    vector<int> v2;
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    m.push_back(v2);

    cout << "El producto punto entre ";
    mostrarVector(v1);
    cout << " y ";
    mostrarVector(v2);
    int res = productoPunto(v1,v2);

    cout << " es igual a " << res << endl;
     */

    /* Ejercicio 2.b */

    /*
    vector<vector<int>> A;
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    A.push_back(v1);

    vector<int> v2;
    v2.push_back(8);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(3);
    A.push_back(v2);

    cout << "El producto de " << endl;
    mostrarMatriz(A);
    cout << " con su traspuesta es igual a " << endl;
    vector<vector<int>> res = productoConTraspuesta(A);
    mostrarMatriz(res);
     */

    /* Ejercicio 3 */

    /*
    vector<vector<int>> A;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    A.push_back(v1);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    A.push_back(v2);

    vector<int> v3;
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    A.push_back(v3);

    cout << "La matriz original es " << endl;
    mostrarMatriz(A);
    cout << " " << endl;
    vector<vector<int>> res = redimensionar(A,2,6);
    int filas = 2;
    int columnas = 6;
    cout << "Y la nueva matriz redimensionada con " << filas << " filas " << "y " << columnas << " columnas " << "es igual a " << endl;
    mostrarMatriz(res);
    */


    return 0;
}



