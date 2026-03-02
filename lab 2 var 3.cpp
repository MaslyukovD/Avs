#include <iostream>
#include <cfenv>


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Программа сложения двух чисел (float) с выбором режима округления IEEE 754\n";

    float a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    cout << "Выберите режим округления:\n";
    cout << "1 - к ближайшему (по умолчанию)\n";
    cout << "2 - к нулю\n";
    cout << "3 - к +бесконечности (вверх)\n";
    cout << "4 - к -бесконечности (вниз)\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: fesetround(FE_TONEAREST); break;
    case 2: fesetround(FE_TOWARDZERO); break;
    case 3: fesetround(FE_UPWARD); break;
    case 4: fesetround(FE_DOWNWARD); break;
    default:
        cout << "Неверный выбор, используется режим к ближайшему.\n";
        fesetround(FE_TONEAREST);
    }

    float sum = a + b;

    cout << "Результат сложения: " << sum << endl;

    return 0;
}