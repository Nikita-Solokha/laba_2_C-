#include <iostream>
#include <vector>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;

    double* arr = new double[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> *(arr + i);
    }

    // Найти номер максимального по модулю элемента массива
    int max_abs_idx = 0;
    double max_abs_value = std::abs(*arr);
    double* ptr = arr;
    for (int i = 1; i < n; ++i) {
        if (std::abs(*(ptr + i)) > max_abs_value) {
            max_abs_value = std::abs(*(ptr + i));
            max_abs_idx = i;
        }
    }
    std::cout << "Индекс максимального элемента по модулю: " << max_abs_idx << std::endl;

    // Вычислить сумму элементов массива после первого положительного элемента
    double sum_after_positive = 0;
    bool found_positive = false;
    for (int i = 0; i < n; ++i) {
        if (found_positive) {
            sum_after_positive += *(ptr + i);
        }
        else if (*(ptr + i) > 0) {
            found_positive = true;
        }
    }
    std::cout << "Сумма элементов после первого положительного элемента: " << sum_after_positive << std::endl;

    // Преобразовать массив
    double a, b;
    std::cout << "Введите диапазон [a, b] для фильтрации целой части: ";
    std::cin >> a >> b;

    std::vector<double> filtered_arr;
    ptr = arr;
    for (int i = 0; i < n; ++i) {
        if (static_cast<int>(*(ptr + i)) >= a && static_cast<int>(*(ptr + i)) <= b) {
            filtered_arr.push_back(*(ptr + i));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (static_cast<int>(*(ptr + i)) < a || static_cast<int>(*(ptr + i)) > b) {
            filtered_arr.push_back(*(ptr + i));
        }
    }

    std::cout << "Преобразованный массив: ";
    for (double elem : filtered_arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    delete[] arr; // Освобождение памяти, выделенной для массива
    return 0;
}
