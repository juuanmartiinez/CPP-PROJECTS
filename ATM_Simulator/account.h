#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    string nombre;
    string numeroCuenta;
    int pin;
    double saldo;

public:
    Account(const string& nombre,const string& numeroCuenta, int pin, double saldoInicial);

    string getNombre() const;
    bool validarPin(int pinIngresado) const;
    double getSaldo() const;
    string getNumeroCuenta() const;
    void depositar(double monto);
    bool retirar(double monto);
};

#endif
