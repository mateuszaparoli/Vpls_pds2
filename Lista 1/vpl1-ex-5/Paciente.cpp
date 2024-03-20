#include "Paciente.hpp"

int Paciente::getID(){
    return this->_senha;
}

int Paciente::getPrioridade(){
    return this->_prioridade;
}

int Paciente::getIdade(){
    return this->_idade;
}

std::string Paciente::getNome(){
    return this->_nome;
}

Paciente::Paciente(int prioridade, std::string nome, int idade, int senha){
    this->_prioridade = prioridade;
    this->_nome = nome;
    this->_idade = idade;
    this->_senha = senha;
}

int Paciente::tempo_reservado_atendimento(){
    int m = this->_prioridade;

    if(m == 0){
        return 20;
    }
    else if(m == 1){
        return 18;
    }
    else if(m == 2){
        return 12;
    }
    else if(m == 3){
        return 8;
    }
    else{
        return 6;
    }
}

void Paciente::imprimir_dados(){
    int m = this->_prioridade;
    std::string _p;
    if(m == 0){
        _p = "V";
    }
    else if(m == 1){
        _p = "L";
    }
    else if(m == 2){
        _p = "A";
    }
    else if(m == 3){
        _p = "D";
    }
    else{
        _p = "Z";
    }

    std::cout << _p << "\t" << _senha << "\t" << _nome << "\t" << _idade << std::endl;
}