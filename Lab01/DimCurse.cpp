#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>

// Función para generar n puntos aleatorios en la dimensión d
std::vector<std::vector<double>> generarPuntos(int d, int n) {
    std::random_device rd; // Inicializa una fuente de números aleatorios basada en hardware o software.
    std::mt19937 gen(rd()); // Generador de números aleatorios.
    std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribución uniforme en el rango [0.0, 1.0).

    std::vector<std::vector<double>> puntos(n, std::vector<double>(d)); // Crea un vector para almacenar los puntos generados.

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            puntos[i][j] = dis(gen); // Genera un valor aleatorio en el rango [0.0, 1.0) y lo asigna a la coordenada del punto.
        }
    }

    return puntos; // Devuelve el conjunto de puntos generados.
}

// Función para calcular la distancia Euclidiana entre dos puntos
double distanciaEuclidiana(const std::vector<double>& punto1, const std::vector<double>& punto2) {
    double distancia = 0.0;
    int d = punto1.size(); // Obtiene la dimensión de los puntos, que debe ser la misma para ambos.

    for (int i = 0; i < d; ++i) {
        double diff = punto1[i] - punto2[i]; // Calcula la diferencia entre las coordenadas correspondientes.
        distancia += diff * diff; // Acumula el cuadrado de las diferencias.
    }

    return std::sqrt(distancia); // Devuelve la raíz cuadrada de la suma de los cuadrados de las diferencias.
}

int main() {
    std::vector<int> dimensiones = {10, 50, 100, 500, 1000, 2000, 5000}; // Lista de dimensiones a considerar.

    for (int d : dimensiones) { // Recorre las dimensiones.
        int n = 100; // Número de puntos aleatorios a generar.
        std::vector<std::vector<double>> puntos = generarPuntos(d, n); // Genera puntos aleatorios en la dimensión d.

        std::vector<double> distancias; // Vector para almacenar las distancias entre pares de puntos.

        // Calcular la distancia entre todos los pares de puntos
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = distanciaEuclidiana(puntos[i], puntos[j]); // Calcula la distancia entre dos puntos.
                distancias.push_back(dist); // Agrega la distancia al vector de distancias.
            }
        }

        // Guardar los resultados en un archivo de texto
        std::string filename = std::to_string(d) + ".txt"; // Genera el nombre del archivo basado en la dimensión.
        std::ofstream outfile(filename); // Abre el archivo para escritura.

        for (double dist : distancias) {
            outfile << dist << "\n"; // Escribe cada distancia en una línea del archivo.
        }

        outfile.close(); // Cierra el archivo.
    }

    return 0;
}
