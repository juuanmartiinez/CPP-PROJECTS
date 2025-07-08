#include "account.h"

Account::Account(const string& nombre,const string& numeroCuenta, int pin, double saldoInicial)
    : nombre(nombre),numeroCuenta(numeroCuenta), pin(pin), saldo(saldoInicial) {}

string Account::getNombre() const {
    return nombre;
}

string Account::getNumeroCuenta() const {
    return numeroCuenta;
}

bool Account::validarPin(int pinIngresado) const {
    return pinIngresado == pin;
}

double Account::getSaldo() const {
    return saldo;
}

void Account::depositar(double monto) {
    if (monto > 0) saldo += monto;
}

bool Account::retirar(double monto) {
    if (monto > 0 && monto <= saldo) {
        saldo -= monto;
        return true;
    }
    return false;
}

