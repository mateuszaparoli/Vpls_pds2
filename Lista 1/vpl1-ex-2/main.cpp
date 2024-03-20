#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main (){

    string letras, frase, correcao, aux, palavras, p;
    int count = 0, contagem = 0, a, g;

    
    cin >> letras;

    while(cin >> aux){
        a = aux.length();
        for(int k = 0; k < a; k++){
            if(aux[k] == '*'){
                count = 1; 
            }
        }
        if(count == 1){
            palavras += aux + ' ';
        }
        contagem += count;
        count = 0;
        frase += aux + ' ';
    }

    int n = letras.length();
    int m = frase.length();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(frase[j] == '*'){
                frase[j] = letras[i];
                break;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int l = 0; l < m; l++){
            if(palavras[l] == '*'){
                palavras[l] = letras[k];
                break;
            }
        }
    }

    g = palavras.length();

    cout << "Frase corrigida: " << frase << endl;
    cout << "Total de " << contagem << " palavra(s) com problema:" << endl;
    
    for(int d = 0; d < g; d++){
        if(palavras[d] == ' '){
            cout << endl;
        }
        else{
            cout << palavras[d];
        }
    }


    return 0;
}