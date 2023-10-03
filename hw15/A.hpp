//
//  A.hpp
//  hw15
//
//  Created by Дима on 03.10.23.
//

#ifndef A_hpp 
#define A_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

class A{
    int** array;
    int rows;
    int cols;
public:
    A();
    A(int r, int c);
    A(const A& obj);
    A operator=(int value);
    A operator=(A& obj);
    A operator+(const int number);
    A operator-(const int number);
    A operator*(const int number);
    A operator/(const int number);
    A operator+(const A& obj);
    A operator-(const A& obj);
    A operator*(const A& obj);
    A operator/(const A& obj);
    friend ostream& operator<<(ostream& os, A& b);
};

#endif /* A_hpp */
