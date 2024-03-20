#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

using namespace std;

struct Pessoa {

    double x;
    double y;

    Pessoa (double x = 0, double y = 0);
    
    double getX();
    double getY();

    void mover(double dx, double dy);

};


#endif