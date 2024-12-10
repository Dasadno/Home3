#include <iostream>

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

void printArray(int** array, int rows, int cols) {
    std::cout << "��������� ������:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    int rows2, cols2;
    std::cout << "������� ���������� ����� ������� �������: ";
    std::cin >> rows2;
    std::cout << "������� ���������� �������� ��� ������� �������: ";
    std::cin >> cols2;

    int rows1, cols1;
    std::cout << "������� ���������� ����� ��� ������� �������: ";
    std::cin >> rows1;
    std::cout << "������� ���������� �������� ��� ������� �������: ";
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
    std::cout << "������� ����� ��������� ����� ��� ������� �������: ";
    std::cin >> startValue1;
    if (!std::isdigit(startValue1)) {std::cout << "Invalid input";}
  
    std::cout << "������� ����� ��������� ����� ��� ������� �������: ";
    std::cin >> startValue2;
    if (!std::isdigit(startValue2)){std::cout << "Invalid input";}

        fillArrayMultiplication(array1, rows1, cols1, startValue1);
        fillArrayIncrement(array2, rows2, cols2, startValue2);

    printArray(array2, rows2, cols2);

    printArray(array1, rows1, cols1);

    for (int i = 0; i < rows1; i++)
    {
        delete[] array1[i];
        delete[] array1;
    }
    for (int i = 0; i < rows2; i++)
    {
        delete[] array2[i];
        delete[] array2;
    }

    return 0;
}