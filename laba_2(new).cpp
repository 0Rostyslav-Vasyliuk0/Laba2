#include <stdio.h>
#include <math.h>

// Функція для обчислення y в залежності від x, a та b
double calculate_y(double x, double a, double b) {
    if (x < 1) {
        return pow(fabs(a + b * x), 1.0 / 4); // Четвертий корінь
    } else if (x >= 1 && x < 2) {
        return pow(log(pow(b, 2) + x), 2); // Квадрат натурального логарифма
    } else { // x >= 2
        return exp(b + 3); // e^(b+3)
    }
}

// Функція обчислення середнього арифметичного
double calculate_average(double sum, int count) {
    return (count == 0) ? 0 : sum / count; // Уникайте ділення на 0
}

int main() {
    double a = 1.3, b = 0.56;  // Константи
    double x_start = 0.5, x_end = 3.0, h = 0.5;  // Діапазон x і розмір кроку
    double sum = 0;  // Сума значень y > 1
    int count = 0;  // Кількість значень y > 1

    printf("x\t\ty\n");
    for (double x = x_start; x <= x_end; x += h) {
        double y = calculate_y(x, a, b);
        printf("%.2f\t\t%.5f\n", x, y);

        if (y > 1) {
            sum += y;
            count++;
        }
    }

    double average = calculate_average(sum, count);
    printf("Average of y > 1: %.5f\n", average);

    return 0;
}
