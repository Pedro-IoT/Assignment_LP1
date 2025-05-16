#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>

class Cliente {
private:
    std::string nome;
    std::string cpf;

public:
    Cliente(); // Método construtor sem atributos
    Cliente(const std::string& name, const std::string& num); // Método construtor com atributos
    const std::string& get_nome() const; // Método getter
    const std::string& get_cpf() const; // Método getter
};

class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    ContaBancaria(int num, const Cliente& client); // Método construtor sem saldo definido
    ContaBancaria(int num, const Cliente& client, double bal); // Método construtor com saldo
    int get_num() const; // Método getter para o número da conta
    void depositar(double valor);
    void sacar(double valor);
    void transferir(double valor, ContaBancaria &destino);  // Método que transfere para uma única conta
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2); // Sobrecarga do método para transferir para duas contas
    void exibirSaldo() const;
    void exibirInformacoes() const;
};

#endif
