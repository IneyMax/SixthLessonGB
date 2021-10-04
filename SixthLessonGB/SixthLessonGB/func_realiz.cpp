#include <iostream>
#include <random>

// ДЗ 6 п.1:
// Выделение памяти для массива (при необходимости сюда можно добавить проверки на наличие памяти для выделения)
int* create_dynamic_array(int array_size)
{
    if (array_size > 0)
    {
        return new int[array_size]; // Выделение памяти под одномерный массив
    }
    else
        return nullptr;
}

// Заполнение массива
void filling_dynamic_array(int *my_array, int array_size)
{
    int index {};
    while (index < array_size)
    {
        my_array[index] = static_cast<int>(pow(2,index));
        index ++;
    }
}

// Вывод массива
void print_dynamic_array(int *my_array, int array_size)
{
    int index {};
    while (index < array_size)
    {
        std::cout << my_array[index] << " ";
        index ++;
    }
    std::cout << "\n";
}

// Очищение памяти
void destroy_dynamic_array(int *my_array){
        delete[] my_array;
        my_array = nullptr;
    }

// ДЗ 6 п.2:
// Генератор случайных чисел
int get_random_number()
{
    std::random_device rd; 
    std::mt19937 gen(rd());  // Seed
    std::uniform_int_distribution<> dist(0,10); // Choose values in range
    return dist(gen);
}

// Выделяем двумерный массив для матрицы
int** create_matrix (int matrix_size)
{
    if (matrix_size > 0)
    {
        auto new_matrix = new int* [matrix_size];
        int index {};
        while (index < matrix_size)
        {
            // Особой необходимости нет, но тут использую функцию из ДЗ 6 п.1
            new_matrix[index] = create_dynamic_array(matrix_size);
            index++;
        }
        return new_matrix;
    }
    else
        return nullptr;
}

// Заполняем матрицу
void fill_matrix(int ** matrix, int matrix_size)
{
    int index {};
    while (index < matrix_size)
    {
        int * temple_array = matrix[index];
        int temple_index {};
        while (temple_index < matrix_size)
        {
            temple_array[temple_index] = get_random_number();
            temple_index++;
        }
        index ++;
    }
    
}

//Вывод матрицы
void print_matrix(int ** matrix, int matrix_size)
{
    int index {};
    while (index < matrix_size)
    {
        // Для удобства используем функцию для печати массива из ДЗ 6 п.1:
        print_dynamic_array(matrix[index], matrix_size);
        index ++;
    }
}

//Удаление матрицы
void delete_matrix(int ** matrix, int matrix_size)
{
    int index {};
    while (index < matrix_size)
    {
        // Для удобства используем функцию удаления массива из ДЗ 6 п.1:
        destroy_dynamic_array(matrix[index]);
        index ++;
    }
}



