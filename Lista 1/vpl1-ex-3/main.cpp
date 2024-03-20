#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int n;
    cin >> n;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* p = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com os dados passados
    int tamanho;
    cin >> tamanho;
    int v[tamanho] = {};
    for (int i = 0; i < tamanho; i++) {
        int dado;
        cin >> dado;
        v[i] = dado;
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &n << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &p << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << v << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << v << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << v[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p = &n;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << (&n == p) << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *p = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 17) Atribua o VALOR da variável (3) à variável declarada em (2)
    p = v;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    p = v;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    int k;
    for (k = 0; k < tamanho; k++){
        *(p + k) = *(p + k) * 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (k = 0; k < tamanho; k++){
        if(k < tamanho - 1){
            cout << v[k] << " ";
        }
        else{
            cout << v[k];
        }
    }
    cout << endl;
    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (k = 0; k < tamanho; k++){
        if(k < tamanho - 1){
            cout << v[k] << " ";
        }
        else{
            cout << v[k];
        }
    }
    cout << endl;
    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (k = 0; k < tamanho; k++){
        if(k < tamanho - 1){
            cout << *(p + k) << " ";
        }
        else{
            cout << *(p + k);
        }
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    p = &v[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 30) Imprima o VALOR que é obtido quando acessamos o ENDEREÇO do ponteiro (2) decrementado de 4
    cout << *(p - 4) << endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **m = &p;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << m << endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << &m << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << *m << endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << **m << endl;
    
    return 0;
}