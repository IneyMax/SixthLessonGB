#include "SixthLessonGB2.h"

/*
threed_file = first_file + second_file;
TODO Попробовать реализовать перегрузку оператора для файлов
*/

int main()
{
 //ДЗ 6 п.3:
 my_file first_file = create_file();
 my_file second_file = create_file();

 filling_file(first_file);
 filling_file(second_file);

 //ДЗ 6 п.4:
 my_file thrid_file = glue_file(first_file, second_file);

 //ДЗ 6 п.5:
 find_string_in_file(thrid_file);

 return 0;
}

