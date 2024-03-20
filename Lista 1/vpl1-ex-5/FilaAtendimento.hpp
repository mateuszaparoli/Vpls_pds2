#ifndef FILAATENDIMENTO_HPP
#define FILAATENDIMENTO_HPP

#include <iostream>
#include "Paciente.hpp"

struct Node{
    Paciente paciente;
    Node* proximo;
};

struct FilaAtendimento
{

    Node* inicio = nullptr;

    void adicionar_paciente(int prioridade, std::string nome, int idade);

    Paciente* chamar_paciente_por_prioridade();

    Paciente* chamar_paciente_por_idade();

    Paciente* buscar_paciente_mais_velho();

    void estimativa_tempo_para_atendimento(int senha);

    void imprimir_fila();
};


#endif