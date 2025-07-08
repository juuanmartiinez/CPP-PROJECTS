#include <iostream>

#include "atm.h"
#include "account.h"

using namespace std;

int main(){

    ATM cajero;

    // Agregar cuentas de ejemplo

    Account cuenta1 = Account("Alice", "1001" , 1234, 1000.0);
    Account cuenta2 = Account("Bob", "1002" , 5678, 500.0);
    Account cuenta3 = Account("Charlie", "1003", 9101, 750.0);
    Account cuenta4 = Account("David", "1004", 1121, 300.0);
    Account cuenta5 = Account("Eve", "1005", 3141, 1200.0);

    cajero.AgregarCuenta(cuenta1);
    cajero.AgregarCuenta(cuenta2);
    cajero.AgregarCuenta(cuenta3);
    cajero.AgregarCuenta(cuenta4);
    cajero.AgregarCuenta(cuenta5);

    string numeroCuenta;
    int pin;

    cout << " BIENVENIDO AL CAJERO AUTOMATICO" << endl;

    bool acceso = false;

    while(!acceso){
        cout << "Ingrese el numero de cuenta: ";
        cin >> numeroCuenta;

        cout << "Ingrese el PIN: ";
        cin >> pin;

        acceso = cajero.login(numeroCuenta, pin);

    }

    cajero.mostrarMenu();

    return 0;
}