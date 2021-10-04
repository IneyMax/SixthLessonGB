#pragma once
#include <fstream>

struct my_file
{
    std::string name; // Имя файла
    std::ofstream edit; // Создание/открытие
    std::ifstream read; // Чтение
};

// Создаём файл с запрошенным именем
my_file create_file();

// Заполняем файл случайными числами
void filling_file(my_file &cur_file);

//Создаём третий файл и помещаем в него первые два
my_file glue_file(my_file &first_file, my_file &second_file);







