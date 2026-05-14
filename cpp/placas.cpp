#include "placas.h"
#include <cstdlib>
#include <sstream>
#include <iomanip>

std::string generarPlaca() {
    const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::stringstream placa;

    for (int i = 0; i < 3; i++) {
        placa << letras[rand() % 26];
    }
    placa << "-";
    placa << std::setw(3) << std::setfill('0') << (rand() % 999);

    return placa.str();
}

std::string horaActual() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
    return std::string(buffer);
}
