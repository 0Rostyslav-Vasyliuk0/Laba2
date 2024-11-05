#include <stdio.h>
#include <math.h>

// стала e , використовуеться для обчислення експоненти 
#define E 2.718

// Функція для обчислення Y за заданим x, a, b.
double calculate_y(double x, double a, double b) {
    if (x < 1) 
    {
        return pow(fabs(a + b * x), 1.0 / 4.0);  // |a + b*x|^1/4
    } else if (x >= 1 && x < 2) 
    {
        return pow(log(b * b + x), 2);  // ln^2(b^2 + x)
    } else 
    {
        return exp(b + 3);  // e^(b + 3)
    }
}

double calculate_average(double sum, int count) //Обчислюе середнє арифметичне
{
    if (count == 0) 
    {
        return 0; // щоб неможливо було ділити на 0
    }
    return sum / count;
}

int main() // Основа функції 
{
    double a = 0.85, b = 0.56; //Константа
    double x_start = 0.5, x_end = 2.5, h = 0.5; // початкове і кінцеве значення X
    double sum = 0; 
    int count = 0; // змінні для накопичення суми всіх значень Y>1 і підрахунку кількості таких значень. 

    printf("x\t\ty\n"); /*Цикл для показу значень і обчислення*/
    for (double x = x_start; x <= x_end; x += h) // перебирає всі значення X
    {
        double y = calculate_y(x, a, b); // обчислюе значення Y
        printf("%.2f\t\t%.5f\n", x, y); //виводить на екран значення X і Y
        
        if (y > 1) 
        {
            sum += y; // додавання до суми значення обчисленого Y
            count++; //збільшення лічильника на 1
        }
    }
