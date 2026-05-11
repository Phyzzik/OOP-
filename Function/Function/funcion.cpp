#include "Function.h"    
#include <iostream>      
#include <cmath>         
#include <iomanip>       

using namespace std;

// Вывод результата: берет название функции, точку x и вычисленное значение y
void Function::printResult(double x) const {
    cout << getName() << " в точке x = " << x << " равна " << calculate(x) << endl;
}

// Поиск экстремумов: «пробегает» по графику от a до b с маленьким шагом
void Function::findExtremes(double a, double b, double step) const {
    double minVal = calculate(a); // Изначально считаем, что первая точка и есть минимум
    double maxVal = calculate(a); // и максимум тоже
    for (double x = a; x <= b; x += step) { // Цикл 
        double val = calculate(x);          // Считаем значение y в текущей точке x
        if (val < minVal) minVal = val;     // Если нашли значение меньше текущего минимума — обновляем его
        if (val > maxVal) maxVal = val;     // Если нашли значение больше текущего максимума — обновляем его
    }
    cout << "На интервале [" << a << ", " << b << "]: Min = " << minVal << ", Max = " << maxVal << endl;
}

// Интеграл: считает площадь под графиком методом средних прямоугольников
double Function::integrate(double a, double b, int n) const {
    double h = (b - a) / n;  // Разбиваем интервал на n очень узких колонок (шаг)
    double sum = 0;          // Переменная для общей площади
    for (int i = 0; i < n; i++) {
        sum += calculate(a + h * (i + 0.5)); // Берем высоту функции посередине каждой колонки
    }
    return sum * h;          // Умножаем сумму высот на ширину шага
}

// Производная
double Function::differentiate(double x, double h) const {
    // Формула центральной разности: (f(x+h) - f(x-h)) / 2h
    return (calculate(x + h) - calculate(x - h)) / (2 * h);
}

// Класс Гипербола

// Конструктор: сохраняет коэффициенты k и b при создании объекта
Hiperbola::Hiperbola(double k, double b) : k(k), b(b) {}

// Расчет: подставляет x в формулу k/x + b
double Hiperbola::calculate(double x) const {
    if (x == 0) return 0; // Защита на ноль делить нельзя (просто возвращаем 0)
    return k / x + b;
}

// Имя: возвращает текст, который мы увидим в консоли
string Hiperbola::getName() const {
    return "Гипербола (k/x + b)";
}

// Класс Парабола 

// Конструктор: сохраняет коэффициенты a, b и c
Parabola::Parabola(double a, double b, double c) : a(a), b(b), c(c) {}

// Расчет: классическое квадратное уравнение ax^2 + bx + c
double Parabola::calculate(double x) const {
    return a * x * x + b * x + c;
}

string Parabola::getName() const {
    return "Парабола (ax^2 + bx + c)";
}

//Класс Экспонента 

// Конструктор: сохраняет базу a и степень b
Exponenta::Exponenta(double a, double b) : a(a), b(b) {}

// Расчет: формула a * e^(bx), 
double Exponenta::calculate(double x) const {
    return a * exp(b * x); // exp - стандартная функция 
}

string Exponenta::getName() const {
    return "Экспонента (a * e^(bx))";
}

// Класс Полином 

// Конструктор: принимает вектор (массив) коэффициентов
Polinom::Polinom(vector<double> c) : coeffs(c) {}

// Расчет: идет циклом по массиву коэффициентов и возводит x в нужную степень
double Polinom::calculate(double x) const {
    double result = 0;
    for (int i = 0; i < (int)coeffs.size(); i++) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

// Имя: динамически считает степень
string Polinom::getName() const {
    return "Полином " + to_string(coeffs.size() - 1) + "-й степени";
}