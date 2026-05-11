#pragma once

#include <iostream>                
#include <vector>                  
#include <string>                  
#include <cmath>                   

using namespace std;               

// Базовый класс
class Function {                   // Объявление класса «Функция»
public:                            // Секция доступных извне методов
    virtual ~Function() {}         // Виртуальный деструктор (нужен для корректного удаления объектов-наследников)

    // Виртуальные методы (Интерфейс)
    virtual double calculate(double x) const = 0; // Чисто виртуальная функция для вычисления f(x)
    virtual string getName() const = 0;           // Чисто виртуальная функция, возвращающая название функции

    // Обычные методы (Общая логика для всех функций)
    void printResult(double x) const;                            // Объявление метода для вывода значения в консоль
    void findExtremes(double a, double b, double step = 0.01) const; // Объявление метода поиска min/max на интервале
    double integrate(double a, double b, int n = 1000) const;    // Объявление метода для вычисления интеграла
    double differentiate(double x, double h = 1e-5) const;       // Объявление метода для вычисления производной
};

// Класс Гипербола
class Hiperbola : public Function { // Класс Гипербола наследует свойства класса Function
private:                            // Скрытые данные класса
    double k, b;                    // Коэффициенты гиперболы (k/x + b)
public:
    Hiperbola(double k, double b);           // Конструктор класса
    double calculate(double x) const override; // Уточнение (переопределение) расчета для гиперболы
    string getName() const override;          // Уточнение имени для гиперболы
};

// Класс Парабола
class Parabola : public Function {  // Наследование от Function
private:
    double a, b, c;                 
public:
    Parabola(double a, double b, double c);  // Конструктор
    double calculate(double x) const override; // Переопределение расчета
    string getName() const override;          // Переопределение имени
};

// Класс Экспонента
class Exponenta : public Function { // Наследование от Function
private:
    double a, b;                    
public:
    Exponenta(double a, double b);           // Конструктор
    double calculate(double x) const override; // Переопределение расчета
    string getName() const override;          // Переопределение имени
};

// Класс Полином n-й степени
class Polinom : public Function {   // Наследование от Function
private:
    vector<double> coeffs;          // Массив коэффициентов (от a0 до an)
public:
    Polinom(vector<double> c);               // Конструктор, принимающий список коэффициентов
    double calculate(double x) const override; // Переопределение расчета через цикл
    string getName() const override;          // Переопределение имени
};