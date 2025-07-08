#ifndef ATM_H
#define ATM_H

#include <string>
#include <vector>

#include "account.h"
#include "transaction.h"

using namespace std;

class ATM{
private:
    vector<Account> cuentas;
    vector<Transaccion> transacciones;
    Account* cuentaActual = nullptr;
    int idSiguienteTransaccion = 1;

    Account* buscarCuentaPorNumero(const string& numeroCuenta);

public:

    ATM();
    void AgregarCuenta(const Account& cuenta);

    bool login(const string& numeroCuenta, int pin);
    void logout();

    void mostrarMenu();
    void verSaldo() const;
    void depositar(double monto);
    bool retirar(double monto);
    bool transferir(const string& numeroDestino, double monto);

    void mostrarHistorial() const;
};

#endif