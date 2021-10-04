#include "SixthLessonGB.h"
#include <iostream>

int main()
{
    // ДЗ 6 п.1:
    int array_size;
    std::cout << "Enter size of your array: ";
    std::cin >> array_size;
    int * dynamic_array = create_dynamic_array(array_size);
    filling_dynamic_array(dynamic_array, array_size);
    print_dynamic_array(dynamic_array, array_size);
    destroy_dynamic_array(dynamic_array);

    // ДЗ 6 п.2:
    int matrix_size {4};
    int ** matrix = create_matrix(matrix_size);
    fill_matrix(matrix, matrix_size);
    print_matrix(matrix, matrix_size);
    delete_matrix(matrix, matrix_size);

    
    return 0;
}
