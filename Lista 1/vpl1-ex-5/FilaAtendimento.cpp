#include "FilaAtendimento.hpp"
#include "Paciente.hpp"

// Certifique-se de inicializar a senha sequencial no construtor de FilaAtendimento

int senha_sequencial = 1;

void FilaAtendimento::adicionar_paciente(int prioridade, std::string nome, int idade) {
    // Crie um novo paciente e atribua uma senha sequencial a ele
    Paciente novoPaciente(prioridade, nome, idade, senha_sequencial++);
    
    Node* novoNode = new Node;
    novoNode->paciente = novoPaciente;

    if (inicio == nullptr || prioridade < inicio->paciente.getPrioridade()) {
        // Inserir no início da fila
        novoNode->proximo = inicio;
        inicio = novoNode;
    } else {
        Node* atual = inicio;
        while (atual->proximo != nullptr && prioridade >= atual->proximo->paciente.getPrioridade()) {
            atual = atual->proximo;
        }
        // Inserir no meio ou no final da fila
        novoNode->proximo = atual->proximo;
        atual->proximo = novoNode;
    }
}


Paciente* FilaAtendimento::chamar_paciente_por_prioridade() {
    if (inicio == nullptr) {
        std::cout << "Nenhum paciente!" << std::endl;
        return nullptr;
    }

    // Obter o paciente de maior prioridade (primeiro da lista)
    Paciente* pacienteChamado = &(inicio->paciente);

    // Remover o paciente da lista
    Node* temp = inicio;
    inicio = inicio->proximo;
    delete temp;

    return pacienteChamado;
}

Paciente* FilaAtendimento::buscar_paciente_mais_velho() {
    if (inicio == nullptr) {
        std::cout << "Nenhum paciente!" << std::endl;
        return nullptr;
    }

    Node* atual = inicio;
    Node* pacienteMaisVelho = inicio;

    while (atual != nullptr) {
        if (atual->paciente.getIdade() > pacienteMaisVelho->paciente.getIdade()) {
            pacienteMaisVelho = atual;
        }
        atual = atual->proximo;
    }

    return &(pacienteMaisVelho->paciente);
}

Paciente* FilaAtendimento::chamar_paciente_por_idade() {
    Paciente* pacienteMaisVelho = buscar_paciente_mais_velho();

    if (pacienteMaisVelho == nullptr) {
        return nullptr; // Não há pacientes na fila
    }

    // Remover o paciente de maior idade da lista
    Node* anterior = nullptr;
    Node* atual = inicio;

    while (atual != nullptr && atual->paciente.getID() != pacienteMaisVelho->getID()) {
    anterior = atual;
    atual = atual->proximo;
    }

    if (anterior != nullptr) {
        anterior->proximo = atual->proximo;
    } else {
        inicio = atual->proximo;
    }

    // Armazenar o paciente em uma variável temporária
    Paciente* pacienteRemovido = &(atual->paciente);

    // Liberar a memória do nó removido
    delete atual;

    return pacienteRemovido;
}

void FilaAtendimento::estimativa_tempo_para_atendimento(int senha) {
    if (inicio == nullptr) {
        std::cout << "Nenhum paciente na fila!" << std::endl;
        return;
    }

    int n = 1; // Começamos com 1 porque o primeiro paciente já está na fila
    int r = 0;
    std::string m;

    Node* atual = inicio;

    while (n <= senha && atual != nullptr) {
        if (n == senha) {
            m = atual->paciente.getNome();
        }

        r += atual->paciente.tempo_reservado_atendimento();
        atual = atual->proximo;
        n++;
    }

    if (n <= senha) {
        std::cout << "Paciente nao esta na fila!" << std::endl;
    } else {
        std::cout << "Tempo estimado para atendimento de " << m << " (senha=" << senha << ") eh " << r << " minutos." << std::endl;
    }
}




void FilaAtendimento::imprimir_fila(){
    Node* atual = inicio;

    if (inicio == nullptr) {
        std::cout << "Nenhum paciente!" << std::endl;
        return;
    }

    while (atual != nullptr) {
        atual->paciente.imprimir_dados();
        atual = atual->proximo;
    }
}