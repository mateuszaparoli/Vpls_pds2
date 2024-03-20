#include "Carro.hpp"
#include "Pessoa.hpp"

Carro::Carro(double x, double y, double th){
    this->x = x;
    this->y = y;
    this->th = th;
}

double Carro::getX(){
    return this->x;
}

double Carro::getY(){
    return this->y;
}

double Carro::getTH(){
    return this->th;
}

void Carro::girar(double w, double t){
    this->th += w*t;
}

void Carro::mover(double v, double t){
    this->x+= v*t*(cos (this->th));
    this->y+= v*t*(sin (this->th));
}

double Carro::calcular_angulo_pessoa(Pessoa* pessoa){
    double h = pessoa->y - this->y;
    double s = pessoa->x - this->x;

    return (atan2(h,s) - this->th);
}

double Carro::calcular_distancia_pessoa(Pessoa* pessoa){
    double m = pow((this->x - pessoa->x), 2);
    double k = pow((this->y - pessoa->y), 2);

    return pow((m + k), 0.5);
}

bool Carro::movimentacao_permitida(Pessoa** pessoas, int n){
    int c = 0;
    for(int i = 0; i < n; i++){
        double m = calcular_angulo_pessoa(pessoas[i]) * 180/M_PI;
        double k =calcular_distancia_pessoa(pessoas[i]);
        if(((-(45)) <= m && m <= (45)) && ((-5) <= k && k <= 5)){
            c = 1;
            cout << "Alerta! " << i << "    " << m << " "<< k << endl;
        }
    }
    if(c == 1){
        return false;
    }
    else{
        return true;
    }
}

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t){
    if(movimentacao_permitida(pessoas, n)){
        girar(w, t);
        mover(v, t);
    }
}