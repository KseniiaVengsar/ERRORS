// ERRORS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//синтаксической, семантической и ошибке линковки
#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

int main()
{
    //Синтаксическая ошибка//(забыли один + у инкремента)



   /* static int Arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    for (int i = 0; i < size; i+) {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;*/




    //сематическая ошибка//задание:вычесть двойку из каждого второго элемента массива.Ошибка: мы прибавляем двойку.

   std::vector<int> numbers = { 1, 2, 3, 4, 5 };

   // Лямбда-функция для сложения каждого второго элемента + 2
   auto someFu = [](int& element) {
       static int count = 0;
       if (count % 2 == 1)
           // для того, чтоб это исправить, нужно заменить + на -(element -= 2)
           element += 2;
       count++;
   };
   std::for_each(numbers.begin(), numbers.end(), someFu);
   for (const auto& num : numbers) {
       std::cout << num << " ";
   }
   std::cout << std::endl;




  
   //ошибка линковки//Я прошу прочесть из файла при помощи std::fstream, но у меня не подключена библиотека #include <fstream>, или файла самого нет.
   //необходимо добавить библиотеку и файл

   std::ifstream fin("in.txt");

   if (fin.fail())
   {
       std::cout << "Error" << std::endl;
   }
   else if (fin.is_open())
   {
       std::cout << "info from in.txt:" << std::endl;
       int N;
       fin >> N;

       std::cout << N << std::endl;
   }
   fin.close();
   return 0;


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
