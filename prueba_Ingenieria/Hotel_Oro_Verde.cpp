#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para representar una reserva
struct Reserva {
    int id;
    string nombreCliente;
    string fecha;
    int habitacion;
    bool estado; // true = activa, false = cancelada
};

// Clase principal del sistema
class SistemaReservas {
private:
    vector<Reserva> reservas;
    int contadorReservas;

public:
    SistemaReservas() : contadorReservas(0) {}

    // Hacer una nueva reserva
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

        nuevaReserva.estado = true;
        reservas.push_back(nuevaReserva);

        cout << "Reserva creada con éxito. ID de reserva: " << nuevaReserva.id << endl;
    }

    // Consultar disponibilidad (simulación)
    void consultarDisponibilidad() {
        cout << "Habitaciones disponibles: ";
        for (int i = 1; i <= 20; ++i) {
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

    // Cancelar una reserva
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

    // Generar reportes
    void generarReportes() {
        cout << "==== Reporte de Reservas ====" << endl;
        for (const auto& reserva : reservas) {
            cout << "ID: " << reserva.id
                 << ", Cliente: " << reserva.nombreCliente
                 << ", Fecha: " << reserva.fecha
                 << ", Habitación: " << reserva.habitacion
                 << ", Estado: " << (reserva.estado ? "Activa" : "Cancelada") << endl;
        }
        cout << "=============================" << endl;
    }
};

// Función principal
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
