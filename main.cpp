#include <fstream>
#include <iostream>
using namespace std;

class Cliente {
    private:
        string nomeCliente;
        string cpfCliente;

    public:
        Cliente(string nome, string cpf){
            setNome(nome);
            setCpf(cpf);
        }
        void setNome(string nome){
            this->nomeCliente = nome;
        }
        void setCpf(string cpf){
            this->cpfCliente = cpf;
        }
        string getNome(){
            return this->nomeCliente;
        }
        string getCpf(){
            return this->cpfCliente;
        }
};

class ContaBancaria {
    private:
        int saldo;

    public:
        ContaBancaria(){
            this->saldo = 0;
            cout << "Conta iniciada" << endl;
        }
        int getSaldo() {return this->saldo;}
        void depositar(int valor) {
            if (valor < 0) {    
                return;
            }
            this->saldo += valor;
        }
        void sacar(int valor) {
            if (this->saldo < valor) {
                return;
            }
            this->saldo -= valor;
        }

};

int main() {

    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    //ContaBancaria conta1("1001", cliente1, 1000.0);
    //ContaBancaria conta2("1002", cliente2);
    //ContaBancaria conta3("1003", cliente3);

    //conta1.exibirSaldo();

    //conta1.transferir(200.0, conta2);

    //conta1.transferir(300.0, conta2, conta3);

    //cout << endl;
    //conta1.exibirInformacoes();
    //conta2.exibirInformacoes();
    //conta3.exibirInformacoes();

    ContaBancaria contaJoao;

    contaJoao.depositar(25);
    contaJoao.sacar(10);
    cout << contaJoao.getSaldo() << endl;
    contaJoao.sacar(100);
    cout << contaJoao.getSaldo() << endl;
    contaJoao.depositar(-10);
    cout << contaJoao.getSaldo() << endl;

    return 0;
}

/*
Saldo atual da conta 1001: R$ 1000
Transferido: R$ 200 da conta 1001 para a conta 1002
Transferido: R$ 150 para cada conta (1002 e 1003) da conta 1001

Titular: Ana, CPF: 111.111.111-11
Número da Conta: 1001, Saldo: R$ 500
Titular: Bruno, CPF: 222.222.222-22
Número da Conta: 1002, Saldo: R$ 350
Titular: Carla, CPF: 333.333.333-33
Número da Conta: 1003, Saldo: R$ 150
*/