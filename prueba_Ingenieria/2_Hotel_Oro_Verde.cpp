#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Reserva {
    int id;
    string nombreCliente;
    string fecha;
    int habitacion;
    string metodoPago;
    bool estado;
};

class SistemaReservas {
private:
    vector<Reserva> reservas;
    int contadorReservas;

public:
    SistemaReservas() : contadorReservas(0) {}

    void hacerReserva() {
        Reserva nuevaReserva;
        nuevaReserva.id = ++contadorReservas;

        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, nuevaReserva.nombreCliente);

        cout << "Ingrese la fecha (YYYY-MM-DD): ";
        cin >> nuevaReserva.fecha;

        cout << "Ingrese el número de habitación: ";
        cin >> nuevaReserva.habitacion;

        cout << "Seleccione el método de pago: " << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta de Crédito" << endl;
        cout << "3. Transferencia Bancaria" << endl;
        int opcionPago;
        cin >> opcionPago;

        switch (opcionPago) {
            case 1:
                nuevaReserva.metodoPago = "Efectivo";
                break;
            case 2:
                nuevaReserva.metodoPago = "Tarjeta de Crédito";
                break;
            case 3:
                nuevaReserva.metodoPago = "Transferencia Bancaria";
                break;
            default:
                cout << "Método de pago inválido. Se asignará 'Sin especificar'." << endl;
                nuevaReserva.metodoPago = "Sin especificar";
        }

        nuevaReserva.estado = true;
        reservas.push_back(nuevaReserva);

        cout << "Reserva creada con éxito. ID de reserva: " << nuevaReserva.id << endl;
    }

    void consultarDisponibilidad() {
        cout << "Habitaciones disponibles: ";
        for (int i = 1; i <= 30; ++i) {
            bool disponible = true;
            for (const auto& reserva : reservas) {
                if (reserva.habitacion == i && reserva.estado) {
                    disponible = false;
                    break;
                }
            }
            if (disponible) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void cancelarReserva() {
        int id;
        cout << "Ingrese el ID de la reserva a cancelar: ";
        cin >> id;

        for (auto& reserva : reservas) {
            if (reserva.id == id && reserva.estado) {
                reserva.estado = false;
                cout << "Reserva con ID " << id << " cancelada con éxito." << endl;
                return;
            }
        }

        cout << "Reserva no encontrada o ya está cancelada." << endl;
    }

    void generarReportes() {
        cout << "==== Reporte de Reservas ====" << endl;
        for (const auto& reserva : reservas) {
            cout << "ID: " << reserva.id
                 << ", Cliente: " << reserva.nombreCliente
                 << ", Fecha: " << reserva.fecha
                 << ", Habitación: " << reserva.habitacion
                 << ", Método de Pago: " << reserva.metodoPago
                 << ", Estado: " << (reserva.estado ? "Activa" : "Cancelada") << endl;
        }
        cout << "=============================" << endl;
    }
};

int main() {
    SistemaReservas sistema;
    int opcion;

    do {
        cout << "\n=== Sistema de Gestión de Reservas ===" << endl;
        cout << "1. Hacer una reserva" << endl;
        cout << "2. Consultar disponibilidad" << endl;
        cout << "3. Cancelar una reserva" << endl;
        cout << "4. Generar reportes" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.hacerReserva();
                break;
            case 2:
                sistema.consultarDisponibilidad();
                break;
            case 3:
                sistema.cancelarReserva();
                break;
            case 4:
                sistema.generarReportes();
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida, intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}