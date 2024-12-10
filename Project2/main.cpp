#include <iostream>
#include <Windows.h>

void fillArrayIncrement(int** array, int rows, int cols, int startValue);
void fillArrayMultiplication(int** array, int rows, int cols, int startValue);

void deleteArray(int** array, int rows);
void printArray(int** array, int rows, int cols);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows2, cols2;
    std::cout << "¬ведите количество строк первого массива: ";
    std::cin >> rows2;
    std::cout << "¬ведите количество столбцов дл€ первого массива: ";
    std::cin >> cols2;

    int rows1, cols1;
    std::cout << "¬ведите количество строк дл€ второго массива: ";
    std::cin >> rows1;
    std::cout << "¬ведите количество столбцов дл€ второго массива: ";
    std::cin >> cols1;

    int** array1 = new int* [rows1];
    for (int i = 0; i < rows2; i++) {
        array1[i] = new int[cols1];
    }
    int** array2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        array2[i] = new int[cols2];
    }

    int startValue1;
    int startValue2;
    std::cout << "¬ведите число начальное число дл€ первого массива: ";
    std::cin >> startValue1;
  
    std::cout << "¬ведите число начальное число дл€ второго массива: ";
    std::cin >> startValue2;
  
        fillArrayMultiplication(array1, rows1, cols1, startValue1);
        fillArrayIncrement(array2, rows2, cols2, startValue2);

    printArray(array2, rows2, cols2);

    printArray(array1, rows1, cols1);

    deleteArray(array2, rows2);
    deleteArray(array1, rows1);

    return 0;
}

void fillArrayMultiplication(int** array, int rows, int cols, int startValue) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) {
                array[i][j] = startValue;
            }
            else if (j == 0) {
                array[i][j] = array[i - 1][0] * 2;
            }
            else {
                array[i][j] = array[i][j - 1] * 2;
            }
        }
    }
}

void fillArrayIncrement(int** array, int rows, int cols, int startValue) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) {
                array[i][j] = startValue;
            }
            else if (j == 0) {
                array[i][j] = array[i - 1][0] + 1;
            }
            else {
                array[i][j] = array[i][j - 1] + 1;
            }
        }
    }
}

void deleteArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void printArray(int** array, int rows, int cols) {
    std::cout << "—озданный массив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}