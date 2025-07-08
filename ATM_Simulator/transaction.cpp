#include "transaction.h"

using namespace std;

Transaccion::Transaccion(int id, TransaccionType tipo, double monto,
                        const string& fecha,
                        const string& cuentaOrigen,
                        const string& cuentaDestino)
        : id(id), tipo(tipo), monto(monto), fecha(fecha),
            cuentaOrigen(cuentaOrigen), cuentaDestino(cuentaDestino) {}

int Transaccion::getID() const {
    return id;
}

TransaccionType Transaccion::getTipo() const {
    return tipo;
}

double Transaccion::getMonto() const {
    return monto;
}

string Transaccion::getFecha() const {
    return fecha;
}

string Transaccion::getCuentaOrigen() const {
    return cuentaOrigen;
}

string Transaccion::getCuentaDestino() const {
    return cuentaDestino;
}

string Transaccion::getTipoString() const{
    switch(tipo){
        case TransaccionType::Deposito:     return "Deposito";
        case TransaccionType::Retiro:   return "Retiro";
        case TransaccionType::Transferencia:    return "Transferencia";
        default:
            return "Desconocido";
    }
}