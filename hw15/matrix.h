//
//  matrix.h
//  hw15
//
//  Created by Дима on 01.10.23.
//

#ifndef matrix_h
#define matrix_h
#include <iostream>
using namespace std;



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



template <class T>
class Matrix{
    T** array;
    int rows;
    int cols;
public:
    Matrix();
    Matrix(int c, int r);
    void input();
    void generate();
    void print();
    Matrix operator+(int number);
    Matrix operator-(int number);
    Matrix operator*(int number);
    Matrix operator/(int number);
    Matrix searchMax();
    Matrix searchMin();
    Matrix operator+(const Matrix<T>& obj);
    Matrix operator-(const Matrix<T>& obj);
    Matrix operator*(const Matrix<T>& obj);
    Matrix operator/(const Matrix<T>& obj);
    Matrix& operator=(const Matrix& obj);
    ~Matrix();
    const T* operator[](int index) const {
          if (index >= 0 && index < rows) {
              return array[index];
          }
          return nullptr;
      }

      // Оператор [] для доступа к строкам матрицы (для изменяемых объектов)
      T* operator[](int index) {
          if (index >= 0 && index < rows) {
              return array[index];
          }
          return nullptr;
      }
    
 
};


template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& obj) {
    if (rows > 0)
            {
                for (int i = 0; i < rows; i++)
                    delete[] array[i];
            }
            if (cols > 0)
            {
                delete[] array;
            }
    if (this == &obj) {
        return *this;
    }


    rows = obj.rows;
    cols = obj.cols;

    array = new T*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            array[i][j] = obj.array[i][j];
        }
    }

    return *this;
}

template <class T>
Matrix<T>:: Matrix(){
    cols = 0;
    rows = 0;
    array = nullptr;
}

template <class T>
Matrix<T>:: Matrix(int c, int r){
    cols = c;
    rows = r;
   array = new T*[rows];
    
    for(int i = 0; i < rows; i++){
        array[i] = new T[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            array[i][j] = 0;
        }
    }
}

template <class T>
void Matrix<T>::input(){
     
    array = new T*[rows];
    for(int i = 0; i < rows; i++){
        array[i] = new T[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "enter " << i << " element: ";
            cin >> array[i][j];
            
        }
    }
}


template <class T>
void Matrix<T>::generate(){
    array = new T*[rows];
    
    for(int i = 0; i < rows; i++){
        array[i] = new T[cols];
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            array[i][j] = 1 + rand() % (11 - 1);
            
        }
    }
}




template <class T>
void Matrix<T>:: print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << array[i][j] << " ";
            
        }
        cout << endl;
    }
}

template <class T>
Matrix<T> Matrix<T>:: operator+(int number){
    Matrix<T> result(cols, rows);
    result = *this;
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            result.array[i][j] += number;
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>:: operator-(int number){
    Matrix<T> result(cols, rows);
    result = *this;
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            result.array[i][j] -= number;
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>:: operator*(int number){
    Matrix<T> result(cols, rows);
    result = *this;
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            result.array[i][j] *= number;
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>:: operator/(int number){
    Matrix<T> result(cols, rows);
    result = *this;
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            result.array[i][j] /= number;
        }
    }
    return result;
}


template <class T>
Matrix<T> Matrix<T>:: searchMax(){
    T max = array[0][0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(array[i][j] > max){
                max = array[i][j];
            }
        }
    }
    return max;
}


template <class T>
Matrix<T> Matrix<T>:: searchMin(){
    T min = array[0][0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(array[i][j] < min){
                min = array[i][j];
            }
        }
    }
    return min;
}


template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj){
    if (cols != obj.cols || rows != obj.rows) {
        cout << "error!" << endl;
    }

    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.array[i][j] = array[i][j] + obj.array[i][j];
        }
    }
    return result;
}



template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj){
    if (cols != obj.cols || rows != obj.rows) {
        cout << "error!" << endl;
    }

    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.array[i][j] = array[i][j] - obj.array[i][j];
        }
    }
    return result;
}


template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj){
    if (cols != obj.cols || rows != obj.rows) {
        cout << "error!" << endl;
    }

    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.array[i][j] = array[i][j] * obj.array[i][j];
        }
    }
    return result;
}


template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& obj){
    if (cols != obj.cols || rows != obj.rows) {
        cout << "error!" << endl;
    }

    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.array[i][j] = array[i][j] / obj.array[i][j];
        }
    }
    return result;
}



template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    

}
#endif /* matrix_h */
