#include <iostream>

// Функція для циклічного зсуву рядків
void shiftRow(int** matrix, int rowCount, int colCount, int shiftCount, bool shiftRight) {
    // Зменшуємо кількість зсувів до мінімальної кількості, що необхідна (менше, ніж N)
    shiftCount %= colCount;

    // Якщо зсув уліво, перетворюємо на еквівалентний зсув управо
    if (!shiftRight) shiftCount = colCount - shiftCount;

    for (int row = 0; row < rowCount; ++row) {
        // Створюємо тимчасовий масив для збереження зсунутого рядка
        int* tempRow = new int[colCount];

        // Циклічно зсуваємо елементи рядка і зберігаємо їх у tempRow
        for (int col = 0; col < colCount; ++col) {
            tempRow[(col + shiftCount) % colCount] = matrix[row][col];
        }

        // Копіюємо зсунуті елементи з tempRow назад у матрицю
        for (int col = 0; col < colCount; ++col) {
            matrix[row][col] = tempRow[col];
        }

        // Звільняємо тимчасовий масив після обробки рядка
        delete[] tempRow;
    }
}

// Функція для циклічного зсуву стовпців
void shiftColumn(int** matrix, int rowCount, int colCount, int shiftCount, bool shiftDown) {
    // Зменшуємо кількість зсувів до мінімальної кількості (менше, ніж M)
    shiftCount %= rowCount;

    // Якщо зсув вгору, перетворюємо на еквівалентний зсув вниз
    if (!shiftDown) shiftCount = rowCount - shiftCount;

    // Створюємо тимчасовий двовимірний масив для збереження зсунутої матриці
    int** tempMatrix = new int*[rowCount];
    for (int row = 0; row < rowCount; ++row) {
        tempMatrix[row] = new int[colCount];
    }

    // Виконуємо циклічний зсув стовпців
    for (int col = 0; col < colCount; ++col) {
        for (int row = 0; row < rowCount; ++row) {
            // Розміщуємо зсунуті значення в тимчасовий масив
            tempMatrix[(row + shiftCount) % rowCount][col] = matrix[row][col];
        }
    }

    // Копіюємо зсунуті елементи з tempMatrix назад у matrix
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            matrix[row][col] = tempMatrix[row][col];
        }
    }

    // Звільняємо пам'ять, виділену для тимчасового масиву
    for (int row = 0; row < rowCount; ++row) {
        delete[] tempMatrix[row];
    }
    delete[] tempMatrix;
}

int main() {
    int rowCount = 3, colCount = 4;

    // Створюємо динамічний двовимірний масив розміром MxN
    int** matrix = new int*[rowCount];
    for (int row = 0; row < rowCount; ++row) {
        matrix[row] = new int[colCount];
    }

    // Заповнюємо матрицю початковими значеннями
    int value = 1;
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            matrix[row][col] = value++;
        }
    }

    int rowShifts = 1; // Кількість зсувів для рядків
    int colShifts = 2; // Кількість зсувів для стовпців
    bool rowToRight = true; // Напрямок зсуву для рядків
    bool colToDown = false; // Напрямок зсуву для стовпців

    //Якщо rowToRight = true, то зсув відбувається вправо, інакше вліво
    //Якщо colToDown = true, то зсув відбувається вниз, інакше вверх
    //Якщо rowShifts або colShifts від'ємні, то зсув відбувається в інший бік

    // Виконуємо зсув рядків та стовпців відповідно до заданих параметрів
    shiftRow(matrix, rowCount, colCount, rowShifts, rowToRight);
    shiftColumn(matrix, rowCount, colCount, colShifts, colToDown);

    // Виводимо результуючу матрицю
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    // Звільняємо пам'ять, виділену для основної матриці
    for (int row = 0; row < rowCount; ++row) {
        delete[] matrix[row];
    }
    delete[] matrix;

    return 0;
}