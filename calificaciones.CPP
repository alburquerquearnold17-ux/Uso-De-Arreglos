#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAX_ESTUDIANTES = 20;       // Máximo permitido
    const int NUM_CALIFICACIONES = 4;     // Calificaciones por estudiante
    int n;                                // Cantidad de estudiantes
    float calificaciones[MAX_ESTUDIANTES * NUM_CALIFICACIONES]; // Arreglo unidimensional
    float promedios[MAX_ESTUDIANTES];     // Promedio por estudiante
    int aprobados = 0, reprobados = 0;
    float notaMax = 0, notaMin = 100, sumaGeneral = 0;

    // Solicitar cantidad de estudiantes
    do {
        cout << "Cantidad de estudiantes (max 20): ";
        cin >> n;
    } while (n < 1 || n > MAX_ESTUDIANTES);

    // Captura de calificaciones
    for (int i = 0; i < n; i++) {
        float suma = 0;
        cout << "\nEstudiante " << i+1 << ":\n";
        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            float nota;
            do {
                cout << "Calificacion " << j+1 << " (0-100): ";
                cin >> nota;
            } while (nota < 0 || nota > 100);

            calificaciones[i * NUM_CALIFICACIONES + j] = nota; // Guardar en arreglo
            suma += nota;

            if (nota > notaMax) notaMax = nota;
            if (nota < notaMin) notaMin = nota;
        }
        promedios[i] = suma / NUM_CALIFICACIONES;
        sumaGeneral += promedios[i];
        if (promedios[i] >= 70) aprobados++; else reprobados++;
    }

    // Mostrar resultados
    cout << "\n===== RESULTADOS =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i+1 << ": ";
        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            cout << calificaciones[i * NUM_CALIFICACIONES + j] << " ";
        }
        cout << " | Promedio: " << fixed << setprecision(2) << promedios[i];
    }

    cout << "\n\n===== RESUMEN GENERAL =====\n";
    cout << "Promedio general del grupo: " << fixed << setprecision(2) << sumaGeneral/n << "\n";
    cout << "Calificacion mas alta: " << notaMax << "\n";
    cout << "Calificacion mas baja: " << notaMin << "\n";
    cout << "Aprobados: " << aprobados << "\n";
    cout << "Reprobados: " << reprobados << "\n";

    return 0;
}