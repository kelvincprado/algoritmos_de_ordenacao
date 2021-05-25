#include <iostream>
using namespace std;

void trocar(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int esquerda, int direita){
    int pivo = v[direita];
    int i = esquerda - 1;
    for (int j = esquerda; j < direita; j++){
        if (v[j] <= pivo){
            i++;
            trocar(v, i, j);
        }
    }
    trocar (v, i+1, direita);
    return i+1;
}

void quick(int v[], int esquerda, int direita){
    if (esquerda < direita){
        int q = particao(v, esquerda, direita);
        quick(v, esquerda, q-1);
        quick(v, q+1, direita);
    }
}

void mostrar(int v[], int tam){
    for (int i=0; i<tam; i++){
        cout << "Pos: " << i << " = " << v[i] << endl;
    }
    cout << endl;
}

int main(){
    int entrada[] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
    int tamanho = sizeof(entrada)/sizeof(entrada[0]);

    mostrar(entrada, tamanho);
    quick(entrada, 0, tamanho);
    mostrar(entrada, tamanho);

    return 0;
}
