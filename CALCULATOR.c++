#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Entrada de dimensiones para la primera matriz
    cout << "Introduce el número de filas y columnas para la primera matriz (A): ";
    cin >> rowsA >> colsA;

    // Entrada de dimensiones para la segunda matriz
    cout << "Introduce el número de filas y columnas para la segunda matriz (B): ";
    cin >> rowsB >> colsB;

    // Crear matrices dinámicamente
    int** A = new int*[rowsA];
    for (int i = 0; i < rowsA; i++) {
        A[i] = new int[colsA];
    }

    int** B = new int*[rowsB];
    for (int i = 0; i < rowsB; i++) {
        B[i] = new int[colsB];
    }

    // Entrada de elementos de la matriz A
    cout << "Introduce los elementos de la matriz A (" << rowsA << "x" << colsA << "):\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    // Entrada de elementos de la matriz B
    cout << "Introduce los elementos de la matriz B (" << rowsB << "x" << colsB << "):\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    // Comprobar si se pueden sumar y restar las matrices
    if (rowsA == rowsB && colsA == colsB) {
        cout << "Suma de las matrices:\n";
        do {
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsA; j++) {
                    cout << A[i][j] + B[i][j] << " ";
                }
                cout << endl;
            }
        } while (false);  // Usamos do-while para mostrar solo una vez

        cout << "Resta de las matrices:\n";
        do {
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsA; j++) {
                    cout << A[i][j] - B[i][j] << " ";
                }
                cout << endl;
            }
        } while (false);
    } else {
        cout << "La suma y resta no están permitidas ya que las matrices tienen dimensiones diferentes.\n";
    }

    // Comprobar si se pueden multiplicar las matrices
    if (colsA == rowsB) {
        int** result = new int*[rowsA];
        for (int i = 0; i < rowsA; i++) {
            result[i] = new int[colsB];
        }

        cout << "Multiplicación de las matrices:\n";
        do {
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    result[i][j] = 0;  // Inicializamos el valor de la celda
                    for (int k = 0; k < colsA; k++) {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        } while (false);

        // Liberar memoria de la matriz resultado
        for (int i = 0; i < rowsA; i++) {
            delete[] result[i];
        }
        delete[] result;
    } else {
        cout << "La multiplicación no está permitida: el número de columnas de A debe ser igual al número de filas de B.\n";
    }

    // Liberar memoria de las matrices A y B
    for (int i = 0; i < rowsA; i++) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < rowsB; i++) {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}
