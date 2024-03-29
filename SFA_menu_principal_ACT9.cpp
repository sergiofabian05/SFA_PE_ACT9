//Sergio Fabian Aguiar   Matricula: 374317
//DESCRIP: Realiza programa en C el programa deberá tener menu.
//SFA_PE_ACT8
// Fecha 25/03/2024     Ultima modificacion:29/03/2024

#include "SFA_libfunciones_ACT9.h"

bool validarNumero(int numero, int min, int max) {
    return numero >= min && numero <= max;
}

int busquedaSecuencial(int arr[], int n, int clave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i;
        }
    }
    return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 15
#define C 4
#define M 4


int msges();
void menu();
void LlenarVector(int vect[], int m, int ri, int rf);
void LlenarVectorAleatorio(int vect[], int m, int ri, int rf);
void ImprimirVector(int vect[], int m, const char *nombre);
void LlenarMatriz(int matri[][M], int m, int n);
void ImprimirMatriz(int matri[][M], int m, int n);
void OrdenarVector(int vect[], int m);
int BuscarValorEnVector(int vect[], int m, int valor);

int main() {
    menu();
    return 0;
}

int msges() {
    int op;
    system("CLS");
    printf("\tMENU\n");
    printf("1. LLENAR VECTOR\n");
    printf("2. LLENAR MATRIZ\n");
    printf("3. IMPRIMIR VECTOR\n");
    printf("4. IMPRIMIR MATRIZ\n");
    printf("5. ORDENAR VECTOR\n");
    printf("6. BUSCAR VALOR EN VECTOR\n");
    printf("0. SALIR\n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu() {
    int vect1[N], matriz[C][M];
    int op;
    do {
        op = msges();
        switch (op) {
            case 1:
                LlenarVector(vect1, N, 100, 200);
                break;
            case 2:
                LlenarMatriz(matriz, C, M);
                break;
            case 3:
                ImprimirVector(vect1, N, "Vector1");
                break;
            case 4:
                ImprimirMatriz(matriz, C, M);
                break;
            case 5:
                OrdenarVector(vect1, N);
                printf("Vector1 ordenado:\n");
                ImprimirVector(vect1, N, "Vector1");
                break;
            case 6: {
                int valor;
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                int indice = BuscarValorEnVector(vect1, N, valor);
                if (indice != -1) {
                    printf("El valor %d se encuentra en la posición %d del Vector1.\n", valor, indice + 1);
                } else {
                    printf("El valor %d no se encuentra en el Vector1.\n", valor);
                }
                break;
            }
        }
    } while (op != 0);
}

void LlenarVector(int vect[], int m, int ri, int rf) {
    system("cls");
    printf("Llenar vector ingresando numeros enteros en el rango del %d al %d.\n", ri, rf);
    for (int i = 0; i < m; i++) {
        do {
            printf("%d ---> ", i + 1);
            scanf("%d", &vect[i]);
        } while (vect[i] < ri || vect[i] > rf);
    }
    system("pause");
}

void LlenarMatriz(int matri[][M], int m, int n) {
    system("cls");
    printf("Llenar matriz con numeros aleatorios en el rango de 1 al 16.\n");
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matri[i][j] = rand() % 16 + 1;
        }
    }
    system("pause");
}

void ImprimirVector(int vect[], int m, const char *nombre) {
    system("cls");
    printf("%s:\n", nombre);
    for (int i = 0; i < m; i++) {
        printf("%d ---> [%d]\n", i + 1, vect[i]);
    }
    system("pause");
}

void ImprimirMatriz(int matri[][M], int m, int n) {
    system("cls");
    printf("Matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf(" [%d] ", matri[i][j]);
        }
        printf("\n");
    }
    system("pause");
}

void OrdenarVector(int vect[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (vect[j] > vect[j + 1]) {
                int temp = vect[j];
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}

int BuscarValorEnVector(int vect[], int m, int valor) {
    for (int i = 0; i < m; i++) {
        if (vect[i] == valor) {
            return i;
        }
    }
    return -1;
}

