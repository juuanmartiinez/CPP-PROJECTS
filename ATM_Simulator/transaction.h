#ifndef TRANSACCTION_H
#define TRANSACCTION_H

#include <string>
using namespace std;

enum class TransaccionType {
    Deposito,
    Retiro,
    Transferencia
};

class Transaccion{
private:
    int id;
    TransaccionType tipo;
    double monto;
    string fecha;
    string cuentaOrigen;
    string cuentaDestino;
public:
    Transaccion(int id, TransaccionType tipo, double monto, 
                const string & fecha,
                const string& cuentaOrinen,
                const string& cuentaDestino = "");
    int getID() const;
    TransaccionType getTipo() const;
    double getMonto() const;
    string getFecha() const;
    string getCuentaOrigen() const;
    string getCuentaDestino() const;

    string getTipoString() const;
};

#endif
