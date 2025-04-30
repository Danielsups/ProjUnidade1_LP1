//Exemplo de classes

#include <string>
#include <iostream>
using namespace std;

class ContaBancaria {
    private:
        int saldo;

    public:
        //uso de "this->" como ponteiro para acessar diretamente a propriedade da classe chamada, neste exemplo: contaJoao
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