#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");
    int U[7];
    int D[7];
    int V[7];

    srand(time(0));

    
    for (int i = 0; i < 7; i++) {
        U[i] = rand() % 81 - 40; 
        D[i] = rand() % 81 - 40; 
        V[i] = rand() % 81 - 40; 
    }

    int* ptrU = U;
    int* ptrD = D;
    int* ptrV = V;

    for (int i = 0; i < 7; i++) {
        double avg_temp = (*ptrU + *ptrD + *ptrV) / 3.0;
        std::cout << "Средняя температура за день " << i + 1 << ": " << avg_temp << std::endl;
        ptrU++;
        ptrD++;
        ptrV++;
    }

    return 0;
}
