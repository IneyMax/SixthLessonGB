#include <iostream>
#include <random>
#include <string>
#include "SixthLessonGB2.h"


int get_random_number()
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,100); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}

my_file create_file()
{
    my_file new_file;
    std::string file_name;
    std::cin >> file_name;
    file_name = file_name + ".txt";
    new_file.name = file_name;
    new_file.edit = std::ofstream(file_name);
    new_file.edit.close();
    return new_file;
}

void filling_file(my_file &cur_file)
{
    cur_file.edit.open(cur_file.name);
    int i = 0;
    while (i < 50)
    {
        cur_file.edit << " " << get_random_number() << " " << std::endl;
        i++;
    }
    cur_file.edit.close();
}

my_file glue_file(my_file &first_file, my_file &second_file)
{
    // Создаём 3й файл:
    my_file new_file = create_file();
    //Открываем все нужные файлы
    new_file.edit.open(new_file.name);
    first_file.read.open(first_file.name);
    second_file.read.open(second_file.name);
    if (new_file.edit.is_open() && first_file.read.is_open() && second_file.read.is_open()) // Если все файлы отурыты
     {
     while (!first_file.read.eof() || !second_file.read.eof()) // Читаем файлы до конца!
     {
         //Записываем строки в новый файл:
         std::string buffer;
         std::getline(first_file.read, buffer);
         new_file.edit << buffer << std::endl;
         std::getline(second_file.read, buffer);
         new_file.edit << buffer << std::endl;
     }
        // Закрываем файлы:
        new_file.edit.close();
        first_file.read.close();
        second_file.read.close();
     }
    return new_file;

}

void find_string_in_file(my_file &cur_file)
{
    cur_file.read.open(cur_file.name);
    std::string find_item;
    std::cin >> find_item;
    find_item = " " + find_item + " "; // Из-за того, что числа разделены
    std::string buffer;
    while (!cur_file.read.eof())
    {
        std::getline(cur_file.read, buffer);
        if (buffer == find_item)
        {
            std::cout << "Yes!";
            break;
        }
    }
}








