#include <iostream>
#include "sistema.h" // Inclui o cabeçalho
using namespace std;

Cliente::Cliente(){ // Caso o método não tenha parâmetros usa-se o padrão
    nome = "sem nome";
    cpf = "000.000.000-00";
}

Cliente::Cliente(const std::string& name, const std::string& num){ // Caso use os parâmetros
    nome = name;
    cpf = num;
}

const std::string& Cliente::get_nome() const { // Retorna o nome
    return nome;
}

const std::string& Cliente::get_cpf() const { // Retorna o cpf
    return cpf;
}

ContaBancaria::ContaBancaria(int num, const Cliente& client){ // Caso não defina o saldo, usa-se o padrão(0.0)
    numero = num;
    saldo = 0.0;
    titular = client;
}

ContaBancaria::ContaBancaria(int num, const Cliente& client, double balance){ // Caso queira definir o saldo na inicialização
    numero = num;
    saldo = balance;
    titular = client;
}

int ContaBancaria::get_num() const { // Retorna o número da conta
    return numero;
}

void ContaBancaria::depositar(double valor) { // Atualiza o saldo após operação(garante que seja sempre positivo)
    if(valor > 0){
        saldo += valor;
    }
    
}

void ContaBancaria::sacar(double valor) { // Atualiza o saldo após operação(garante que há saldo suficiente)
    if (saldo - valor >= 0) {
        saldo -= valor;
    } else {
        cout << "Saldo insuficiente!" << endl; // Mensagem de erro caso não tenha saldo
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (saldo - valor >= 0) {
        saldo -= valor; // Atualiza o saldo após operação(garante que há saldo suficiente)
        destino.depositar(valor);   // Faz a operação devida
        cout << "Transferido: R$ " << valor
             << " da conta " << numero         // Confirma que a operação foi bem sucedida
             << " para a conta " << destino.get_num()
             << endl;
    } else {
        cout << "Saldo insuficiente para transferência!" << endl;   // Mensagem de erro caso não tenha saldo
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if (saldo - valor >= 0) {
        double half = valor / 2.0;  // Inicializa nova variável para guardar as metades de cada conta destino(destino1 e destino2)
        saldo -= valor;     // Atualiza o saldo após operação(garante que há saldo suficiente)
        destino1.depositar(half);   // Faz as operações devidas
        destino2.depositar(half);
        cout << "Transferido: R$ " << half
             << " para cada conta (" << destino1.get_num()
             << " e " << destino2.get_num()      // Confirma que a operação foi bem sucedida
             << ") da conta " << numero
             << endl;
    } else {
        cout << "Saldo insuficiente para transferência!" << endl;   // Mensagem de erro caso não tenha saldo
    }
}

void ContaBancaria::exibirSaldo() const {   // Exibe o saldo quando chamada(quase um getter)
    cout << "Saldo atual da conta " << numero
         << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes() const { // Exibe as informações dos clientes e suas contas(formatado no padrão do exemplo)
    cout << "Titular: " << titular.get_nome()
         << ", CPF: " << titular.get_cpf() << endl;
    cout << "Número da conta: " << numero
         << ", Saldo: R$ " << saldo << endl;
}
