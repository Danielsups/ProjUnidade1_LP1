#include "main.h"
#include <fstream>
#include <iostream>
using namespace std;

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