#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tarjeta {
protected:
    string numeroTarjeta;
    string nombreTitular;
    int codigoSeguridad;
    bool esPrincipal;

public:
    Tarjeta(string numero, string titular, int codigo, bool principal)
        : numeroTarjeta(numero), nombreTitular(titular), codigoSeguridad(codigo), esPrincipal(principal) {}

    void mostrarDetalles() const {
        cout << "Número de Tarjeta: " << numeroTarjeta << endl;
        cout << "Titular: " << nombreTitular << endl;
        cout << "Código de Seguridad: " << codigoSeguridad << endl;
        cout << "Es Principal: " << (esPrincipal ? "Sí" : "No") << endl;
    }
};

class TarjetaCredito : public Tarjeta {
private:
    string mesCaducidad;
    string anioCaducidad;

public:
    TarjetaCredito(string numero, string titular, int codigo, bool principal, string mes, string anio)
        : Tarjeta(numero, titular, codigo, principal), mesCaducidad(mes), anioCaducidad(anio) {}

    void mostrarDetalles() const {
        Tarjeta::mostrarDetalles();
        cout << "Fecha de Caducidad: " << mesCaducidad << "/" << anioCaducidad << endl;
    }
};

class Prestamo {
private:
    string fechaAprobacion;
    string fechaConsignacion;
    vector<string> fechasPago;

public:
    Prestamo(string aprobacion, string consignacion, const vector<string>& pagos)
        : fechaAprobacion(aprobacion), fechaConsignacion(consignacion), fechasPago(pagos) {}

    void mostrarDetalles() const {
        cout << "Fecha de Aprobación: " << fechaAprobacion << endl;
        cout << "Fecha de Consignación: " << fechaConsignacion << endl;
        cout << "Fechas de Pago: ";
        for (const string& pago : fechasPago) {
            cout << pago << " ";
        }
        cout << endl;
    }
};

class Cuenta {
private:
    string numeroCuenta;
    string descripcion;
    vector<Tarjeta> tarjetasDebito;
    vector<TarjetaCredito> tarjetasCredito;
    vector<Prestamo> prestamos;

public:
    Cuenta(string numero, string desc) : numeroCuenta(numero), descripcion(desc) {}

    void agregarTarjetaDebito(Tarjeta tarjeta) {
        tarjetasDebito.push_back(tarjeta);
    }

    void agregarTarjetaCredito(TarjetaCredito tarjeta) {
        tarjetasCredito.push_back(tarjeta);
    }

    void agregarPrestamo(Prestamo prestamo) {
        if (prestamos.size() < 3) {
            prestamos.push_back(prestamo);
        } else {
            cout << "No se pueden agregar más de 3 préstamos por cuenta." << endl;
        }
    }

    void mostrarDetalles() const {
        cout << "Número de Cuenta: " << numeroCuenta << endl;
        cout << "Descripción: " << descripcion << endl;

        cout << "Tarjetas de Débito:" << endl;
        for (const auto& tarjeta : tarjetasDebito) {
            tarjeta.mostrarDetalles();
        }

        cout << "Tarjetas de Crédito:" << endl;
        for (const auto& tarjeta : tarjetasCredito) {
            tarjeta.mostrarDetalles();
        }

        cout << "Préstamos:" << endl;
        for (const auto& prestamo : prestamos) {
            prestamo.mostrarDetalles();
        }
    }
};

class Cliente {
private:
    string codigo;
    string cedula;
    string nombres;
    string apellidos;
    string direccion;
    string email;
    string telefono;
    vector<Cuenta> cuentas;

public:
    Cliente(string cod, string id, string nombre, string apellido, string dir, string correo, string tel)
        : codigo(cod), cedula(id), nombres(nombre), apellidos(apellido), direccion(dir), email(correo), telefono(tel) {}

    void agregarCuenta(Cuenta cuenta) {
        cuentas.push_back(cuenta);
    }

    void mostrarDetalles() const {
        cout << "Código: " << codigo << endl;
        cout << "Cédula: " << cedula << endl;
        cout << "Nombre: " << nombres << " " << apellidos << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Email: " << email << endl;
        cout << "Teléfono: " << telefono << endl;

        cout << "Cuentas:" << endl;
        for (const auto& cuenta : cuentas) {
            cuenta.mostrarDetalles();
        }
    }
};

int main() {

    Cliente cliente("001", "1234567890", "Limber", "Tacuri", "Av. San Miguel 1", "limbertacuri2@gmail.com", "2222-1234");

    Cuenta cuenta("123-456-789", "Cuenta de Ahorros");

    Tarjeta tarjetaDebito("1111-2222-3333-4444", "Limber Tacuri", 123, true);
    TarjetaCredito tarjetaCredito("5555-6666-7777-8888", "Limber Tacuri", 456, true, "12", "2030");

    cuenta.agregarTarjetaDebito(tarjetaDebito);
    cuenta.agregarTarjetaCredito(tarjetaCredito);

    vector<string> fechasPago = {"2025-02-01", "2025-03-01", "2025-04-01"};
    Prestamo prestamo("2025-01-01", "2025-01-05", fechasPago);

    cuenta.agregarPrestamo(prestamo);

    cliente.agregarCuenta(cuenta);

    cliente.mostrarDetalles();

    return 0;
}
