#include <fstream>
#include <iostream>
using namespace std;

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