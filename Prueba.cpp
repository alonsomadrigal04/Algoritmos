#include <iostream>

int main() {
    int arr[5]; // No se inicializa explícitamente

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " "; // Los valores aquí son indeterminados
    }

    return 0;
}
