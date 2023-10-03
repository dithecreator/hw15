//
//  main.cpp
//  hw15
//
//  Created by Дима on 01.10.23.
//


//Тема: шаблоны
//
//Задание
//
//Создайте шаблонный класс матрица.
//Необходимо реализовать динамическое выделение памяти, очистку памяти, заполнение матрицы с клавиатуры,
//заполнение случайными значениями, отображение матрицы, арифметические операции с помощью перегруженных
//операторов (+,-, *, /),
// поиск максимального и минимального элемента.
//
//Реализовать собственный класс А(с перегрузками ), и использовать в шаблоне класса.

#include <iostream>
#include "matrix.h"
#include "A.hpp"
using namespace std;


int main() {
    
    Matrix<int> a(3, 4);
    Matrix<int> b(3, 4);
    a.generate();
    b.generate();
    a.print();
    cout << endl;
    b.print();
    b = b + 10;
    cout << endl;
    b.print();
    b = b - 10;
    cout << endl;
    b.print();
    b = b * 10;
    cout << endl;
    b.print();
    b = b / 10;
    cout << endl;
    b.print();
    cout << endl;
    Matrix<int> c(3, 4);
    c = a + b;
    c.print();
}
