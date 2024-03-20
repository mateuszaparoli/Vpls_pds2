// NÃO ALTERE ESSA LINHA
//#include "avaliacao_basica_atendimento.hpp"

#include <iostream>
#include "Paciente.hpp"
#include "FilaAtendimento.hpp"

int main() {

    FilaAtendimento filaatendimento;
    Paciente paciente;
    char data;
    while (std::cin >> data) {   // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (data) {
            
            // Imprimindo o status de todas as pessoas da cena
            case 'a': {      
                std::string m;
                int a, b;     
                std::cin >> a >> m >> b;
                filaatendimento.adicionar_paciente(a, m, b); 
                break;
            }
            
            // Mover pessoa
            case 'p': {                 
                filaatendimento.imprimir_fila();     
                break;           
            }

            // Imprimindo o status do carro
            case 'r': {                
                filaatendimento.chamar_paciente_por_prioridade();
                break;
            }    

            // Girando o carro
            case 'i': {     
               filaatendimento.chamar_paciente_por_idade();
               break;
            }     

            // Mover o carro em frente
            case 'm': {     
                Paciente* paciente;
                paciente = filaatendimento.buscar_paciente_mais_velho();
                paciente->imprimir_dados();
                break;
            }    

            // Calculo o ângulo para uma certa pessoa
            case 'e': {
                int senha;     
                std::cin >> senha;          
                filaatendimento.estimativa_tempo_para_atendimento(senha);
                break;
            }  

            // Calculo da distância para uma certa pessoa
            //case 'b': {     
                //avaliacao_basica();
                //break;
            //}    
        
        }                                        
    }
    return 0;
}