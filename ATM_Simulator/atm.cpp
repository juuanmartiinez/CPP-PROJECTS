#include "atm.h"
#include "account.h"
#include "transaction.h"
#include "utilities.h"

#include <iostream>

using namespace std;

ATM::ATM() {}

void ATM::AgregarCuenta(const Account& cuenta){
    cuentas.push_back(cuenta);
}

Account* ATM::buscarCuentaPorNumero(const string& numeroCuenta) {
    for (auto& cuenta : cuentas) {
        if (cuenta.getNumeroCuenta() == numeroCuenta) {
            return &cuenta;
        }
    }
    return nullptr;
}

bool ATM::login(const string& numeroCuenta, int pin){
    Account* cuenta = buscarCuentaPorNumero(numeroCuenta);
    if(cuenta && cuenta ->validarPin(pin)){
        cuentaActual = cuenta;
        cout << "Login Exitoso. Bienvenido " << cuentaActual->getNombre() << endl;
        return true;
    }else{
        cout << "Login Fallido." << endl;
        return false;
    }
}

void ATM::logout(){
    cuentaActual = nullptr;
    cout << "Sesion cerrada." << endl; 
}

void ATM::mostrarMenu() {
    if (!cuentaActual) {
        cout << "No has iniciado sesión.\n";
        return;
    }

    int opcion = 0;
    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Ver saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Transferir\n";
        cout << "5. Mostrar historial de transacciones\n";
        cout << "6. Cerrar sesión\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                verSaldo();
                break;
            case 2: {
                double monto;
                cout << "Monto a depositar: ";
                cin >> monto;
                depositar(monto);
                break;
            }
            case 3: {
                double monto;
                cout << "Monto a retirar: ";
                cin >> monto;
                if (!retirar(monto))
                    cout << "Fondos insuficientes.\n";
                break;
            }
            case 4: {
                string destino;
                double monto;
                cout << "Número de cuenta destino: ";
                cin >> destino;
                cout << "Monto a transferir: ";
                cin >> monto;
                if (!transferir(destino, monto))
                    cout << "Transferencia fallida.\n";
                break;
            }
            case 5:
                mostrarHistorial();
                break;
            case 6:
                logout();
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6 && cuentaActual != nullptr);
}

void ATM::verSaldo() const {

    cout << "Saldo actual " << cuentaActual->getSaldo() << endl;

}

void ATM::depositar(double monto){

    if(monto <= 0){
        cout << "Monto invalido. Deber ser mayor que 0." << endl;
        return;
    }
    cuentaActual->depositar(monto);
    transacciones.emplace_back(idSiguienteTransaccion++, TransaccionType::Deposito, monto,
        "FechaPlaceholder", cuentaActual->getNumeroCuenta());

    cout << "Depósito realizado con éxito.\n";

}

bool ATM::retirar(double monto){
    if(monto <= 0) {
        cout << "Monto inválido. Debe ser mayor que 0." << endl;
        return false;
    }
    if(cuentaActual->retirar(monto)){
        transacciones.emplace_back(idSiguienteTransaccion++, TransaccionType::Retiro, monto,
            "FechaPlaceholder", cuentaActual->getNumeroCuenta());
        cout << "Retiro realizado con éxito.\n";
        return true;
    }
    return false;
}

bool ATM::transferir(const string& numeroDestino, double monto){

    if(monto <= 0){
        cout << "Monto inválido." << endl;
        return false;
    }
    Account* cuentaDestino = buscarCuentaPorNumero(numeroDestino);
    if(!cuentaDestino){
        cout << "Cuenta destino no encontrada." << endl;
        return false;
    }

    if(!cuentaActual->retirar(monto)){
        cout << "Fondos insuficientes para la transferencia." << endl;
        return false;
    }
    cuentaDestino->depositar(monto);

    transacciones.emplace_back(idSiguienteTransaccion++, TransaccionType::Transferencia, monto,
        "FechaPlaceholder", cuentaActual->getNumeroCuenta());
    
    cout << "Transferencia realizada con éxito a " << cuentaDestino->getNombre() << endl;
    return true;
}

void ATM::mostrarHistorial() const{
    cout << "------ HISTORIAL DE TRANSACCIONES ------" << endl;
    for(const auto& t : transacciones){
        if(t.getCuentaOrigen() == cuentaActual->getNumeroCuenta() || 
           t.getCuentaDestino() == cuentaActual->getNumeroCuenta()){
            
            cout << "ID: " << t.getID() << "Tipo: " << t.getTipoString()
                    << " Monto: " << t.getMonto() 
                    << " Fecha: " << t.getFecha() 
                    << " Cuenta Origen: " << t.getCuentaOrigen();
            if(!t.getCuentaDestino().empty()){
                cout << " A: " << t.getCuentaDestino();
            }
            cout << endl;
        } 
    }
}