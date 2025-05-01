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

int main() {
    // Cria três clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Cria três contas bancárias (conta1 inicia com 1000.0, outras com 0.0)
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe saldo da conta1
    conta1.exibirSaldo();

    // Transfere 200 da conta1 para conta2
    conta1.transferir(200.0, conta2);

    // Transfere 300 da conta1, dividindo entre conta2 e conta3 (150 para cada)
    conta1.transferir(300.0, conta2, conta3);

    // Exibe informações de todas as contas
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}