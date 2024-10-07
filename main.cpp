#include <iostream>
#include "fuzzy_controller.h"


int main() {

    setlocale(LC_ALL, "Russian");

    FuzzyController f_controller;

    std::vector<float> ans;

    double temperature;
    double humidity;
    double brightness;

    std::cout << "������� �����������: ";
    std::cin >> temperature;
    std::cout << "������� ���������: ";
    std::cin >> humidity;
    std::cout << "������� �������: ";
    std::cin >> brightness;

    std::system("cls");
    
    f_controller.init_borders();

    ans = f_controller.climate_control(temperature, humidity, brightness);

    std::cout << "�������� �����������: " << ans[0] << "%" << std::endl;
    std::cout << "�������� ������������: " << ans[1] << "%" << std::endl;
    if (ans[2] == 1)
        std::cout << "����� �����" << std::endl;
    else
        std::cout << "����� �� �����" << std::endl;
    std::cout << "�������� ����: " << ans[3] << "%" << std::endl;

    return 0;
}

