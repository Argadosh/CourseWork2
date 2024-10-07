#include <iostream>
#include "fuzzy_controller.h"


int main() {

    setlocale(LC_ALL, "Russian");

    FuzzyController f_controller;

    std::vector<float> ans;

    double temperature;
    double humidity;
    double brightness;

    std::cout << "Введите температуру: ";
    std::cin >> temperature;
    std::cout << "Введите влажность: ";
    std::cin >> humidity;
    std::cout << "Введите яркость: ";
    std::cin >> brightness;

    std::system("cls");
    
    f_controller.init_borders();

    ans = f_controller.climate_control(temperature, humidity, brightness);

    std::cout << "Мощность вентилятора: " << ans[0] << "%" << std::endl;
    std::cout << "Мощность обогревателя: " << ans[1] << "%" << std::endl;
    if (ans[2] == 1)
        std::cout << "Полив нужен" << std::endl;
    else
        std::cout << "Полив не нужен" << std::endl;
    std::cout << "Мощность ламп: " << ans[3] << "%" << std::endl;

    return 0;
}

