#include <fstream>
#include <iostream>
using namespace std;

class Cliente {
    private:
        string nomeCliente;
        string cpfCliente;

    public:
        Cliente(){

        }
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
        int identConta;
        Cliente clienteConta;
        double saldoConta;

    public:
        ContaBancaria(int ident, Cliente cliente, double saldo = 0.0){
            setIdent(ident);
            setCliente(cliente);
            setSaldo(saldo);
        }

        void setIdent(int ident){
            this->identConta = ident;
        }
        void setCliente(Cliente cliente){
            this->clienteConta = cliente;
        }
        void setSaldo(double saldo){
            this->saldoConta = saldo;
        }

        void exibirSaldo(){
            cout << "Saldo atual da conta " << this->identConta << ": " << this->saldoConta << endl;
        }
        void exibirInformacoes(){
            cout << "Titular: "+clienteConta.getNome()+", CPF: "+clienteConta.getCpf() << endl;
            cout << "Numero da Conta: " << this->identConta << ", Saldo: R$ " << this->saldoConta << endl;
        }

        void depositar(double valor){
            this->saldoConta += valor;
        }
        void sacar(double valor){
            if(this->saldoConta < valor){
                cout << "Saldo insuficiente para saque" << endl;
                return;
            }
            this->saldoConta -= valor;
        }

        void transferir(double valor, ContaBancaria &destinatario){
            if(this->saldoConta < valor){
                cout << "Saldo insuficiente para transferencia" << endl;
                return;
            }

            this->saldoConta -= valor;
            destinatario.depositar(valor);

            cout << "Transferido: R$ " << valor << " da conta " << this->identConta << " para a conta " << destinatario.identConta << endl;

        }
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

int main() {

    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    conta1.exibirSaldo();

    conta1.transferir(200.0, conta2);

    conta1.transferir(300.0, conta2, conta3);

    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
