#pragma once
#include <fstream>
#include <iostream>
using namespace std;

// Classe que representa um cliente
class Cliente {
    private:
        string nomeCliente;   // Nome do cliente
        string cpfCliente;    // CPF do cliente

    public:
        // Construtor padrão (sem parâmetros)
        Cliente(){

        }
        // Construtor com parâmetros para nome e CPF
        Cliente(string nome, string cpf){
            setNome(nome);
            setCpf(cpf);
        }

        // Métodos setters (para definir valores)
        void setNome(string nome){
            this->nomeCliente = nome;
        }
        void setCpf(string cpf){
            this->cpfCliente = cpf;
        }

        // Métodos getters (para obter valores)
        string getNome(){
            return this->nomeCliente;
        }
        string getCpf(){
            return this->cpfCliente;
        }
};

// Classe que representa uma conta bancária
class ContaBancaria {
    private:
        int identConta;         // Número de identificação da conta
        Cliente clienteConta;   // Cliente titular da conta
        double saldoConta;      // Saldo atual da conta

    public:
        // Construtor com parâmetros (saldo tem valor padrão 0.0)
        ContaBancaria(int ident, Cliente cliente, double saldo = 0.0){
            setIdent(ident);
            setCliente(cliente);
            setSaldo(saldo);
        }

        // Métodos setters
        void setIdent(int ident){
            this->identConta = ident;
        }
        void setCliente(Cliente cliente){
            this->clienteConta = cliente;
        }
        void setSaldo(double saldo){
            this->saldoConta = saldo;
        }

        // Exibe o saldo atual da conta
        void exibirSaldo(){
            cout << "Saldo atual da conta " << this->identConta << ": " << this->saldoConta << endl;
        }
        
        // Exibe todas as informações da conta
        void exibirInformacoes(){
            cout << "Titular: "+clienteConta.getNome()+", CPF: "+clienteConta.getCpf() << endl;
            cout << "Numero da Conta: " << this->identConta << ", Saldo: R$ " << this->saldoConta << endl;
        }

        // Realiza um depósito na conta
        void depositar(double valor){
            if (valor <= 0)
            {
                cout << "Valor invalido para deposito" << endl;
                return;
            }
            
            this->saldoConta += valor;
        }
        
        // Realiza um saque na conta (verifica saldo primeiro)
        void sacar(double valor){
            if(this->saldoConta < valor){
                cout << "Saldo insuficiente para saque" << endl;
                return;
            }
            
            this->saldoConta -= valor;
        }

        // Transfere valor para uma única conta de destino
        void transferir(double valor, ContaBancaria &destinatario){
            if(this->saldoConta < valor){
                cout << "Saldo insuficiente para transferencia" << endl;
                return;
            }

            this->saldoConta -= valor;
            destinatario.depositar(valor);

            cout << "Transferido: R$ " << valor << " da conta " << this->identConta << " para a conta " << destinatario.identConta << endl;
        }
        
        // Sobrecarga do método transferir: transfere para duas contas (divide o valor igualmente)
        void transferir(double valor, ContaBancaria &destinatario1, ContaBancaria &destinatario2){
            if(this->saldoConta < valor){
                cout << "Saldo insuficiente para transferencia" << endl;
                return;
            }
            
            this->saldoConta -= valor;
            destinatario1.depositar(valor/2);
            destinatario2.depositar(valor/2);

            cout << "Transferido: R$ " << valor << " para cada conta (" << destinatario1.identConta << " e " << destinatario2.identConta << ") da conta " << this->identConta << endl;
        }
};