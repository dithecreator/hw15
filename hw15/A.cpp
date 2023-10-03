//
//  A.cpp
//  hw15
//
//  Created by Дима on 03.10.23.
//

#include "A.hpp"
#include <iostream>
using namespace std;
A::A(){
    array = nullptr;
    rows = 0;
    cols = 0;
}


A::A(int r, int c){
    rows = r;
    cols = c;
    array = new int*[rows];
    for(int i = 0; i < rows; i++){
        array[i] = new int[cols];
    }

}


A::A(const A& obj){
    rows = obj.rows;
    cols = obj.cols;
    array = new int* [rows];
        for(int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            array[i][j] = obj.array[i][j];
        }
    }
}


A A:: operator=(int value){
    
for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
        array[i][j] = value;
    }
}
    return * this;
}

A A:: operator=(A& obj){
    rows = obj.rows;
    cols = obj.cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            array[i][j] = obj.array[i][j];
        }
    }
    return *this;
}





A A:: operator+(const int number){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] += number;
            }
        }
        return result;
    }

A A:: operator-(const int number){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] -= number;
            }
        }
        return result;
    }


A A:: operator*(const int number){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] *= number;
            }
        }
        return result;
    }


A A:: operator/(const int number){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] /= number;
            }
        }
        return result;
    }

A A:: operator+(const A& obj){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
    if(this -> rows && this -> cols == obj.rows && obj.cols){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] += obj.array[i][j];
            }
        }
    }
        return result;
    }

A A:: operator-(const A& obj){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
    if(this -> rows && this -> cols == obj.rows && obj.cols){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] -= obj.array[i][j];
            }
        }
    }
        return result;
    }


A A:: operator*(const A& obj){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
    if(this -> rows && this -> cols == obj.rows && obj.cols){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] *= obj.array[i][j];
            }
        }
    }
        return result;
    }


A A:: operator/(const A& obj){
        A result(rows, cols);
        result.array = new int* [rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
    if(this -> rows && this -> cols == obj.rows && obj.cols){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.array[i][j] /= obj.array[i][j];
            }
        }
    }
        return result;
    }


ostream& operator<<(ostream& os, A& b){
    for (int i = 0; i < b.rows; i++){
        for (int j = 0; j < b.cols; j++){
            os << b.array[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}
