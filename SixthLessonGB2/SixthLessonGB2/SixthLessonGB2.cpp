#include "SixthLessonGB2.h"

/*
threed_file = first_file + second_file;
TODO Попробовать реализовать перегрузку оператора для файлов
*/

int main()
{
 my_file first_file = create_file();
 my_file second_file = create_file();

 filling_file(first_file);
 filling_file(second_file);

 my_file thrid_file = glue_file(first_file, second_file);
 
 return 0;
}

