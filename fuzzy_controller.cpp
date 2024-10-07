#include "fuzzy_controller.h"

double FuzzyController::calculate_temperature_low(double temperature){
    if (temperature <= t_normal_border.min) {
        return 1.0;
    }
    else if (temperature <= t_low_border.max) {
        return ((t_low_border.max - temperature) / (t_low_border.max - t_normal_border.min));
    }
    else {
        return 0.0;
    }
}

double FuzzyController::calculate_temperature_normal(double temperature){
    if (temperature <= t_normal_border.min) {
        return 0.0;
    }
    else if (temperature <= t_normal_border.max) {
        if (temperature > t_normal_border.min && temperature < t_low_border.max)
            return 2 - ((t_normal_border.max - temperature) / (t_low_border.max - t_normal_border.min));
        else if (temperature >= t_low_border.max && temperature <= t_high_border.min)
            return 1.0;
        else
            return (t_normal_border.max - temperature) / (t_normal_border.max - t_high_border.min);
    }
    else {
        return 0.0;
    }
}

double FuzzyController::calculate_temperature_high(double temperature){
    if (temperature <= t_high_border.min) {
        return 0.0;
    }
    else if (temperature <= t_high_border.max) {
        return (temperature - t_high_border.min) / (t_normal_border.max - t_high_border.min);
    }
    else {
        return 1.0;
    }
}

void FuzzyController::calculate_temperature_state(double temperature){
    double state_cold = calculate_temperature_low(temperature);
    double state_normal = calculate_temperature_normal(temperature);
    double state_hot = calculate_temperature_high(temperature);

    if (state_normal <= state_cold && state_cold != 0) {
        temp_state = LOW;
    }
    else if (state_normal <= state_hot && state_hot != 0) {
        temp_state = HIGH;
    }
    else {
        temp_state = NORMAL;
    }
}

double FuzzyController::calculate_humidity_low(double humidity){
    if (humidity <= h_normal_border.min) {
        return 1.0;
    }
    else if (humidity <= h_low_border.max) {
        return (h_low_border.max - humidity) / (h_low_border.max - h_normal_border.min);
    }
    else {
        return 0.0;
    }
}

double FuzzyController::calculate_humidity_normal(double humidity){
    if (humidity <= h_normal_border.min)
        return 0.0;
    else if (humidity <= h_normal_border.max) {
        if (humidity > h_normal_border.min && humidity < h_low_border.max)
            return 1 - ((h_low_border.max - humidity) / (h_low_border.max - h_normal_border.min));
        else if (humidity >= h_low_border.max && humidity <= h_high_border.min)
            return 1.0;
        else
            return ((h_normal_border.max - humidity) / (h_normal_border.max - h_high_border.min));
    }
    else
        return 0.0;
}

double FuzzyController::calculate_humidity_high(double humidity){
    if (humidity <= h_high_border.min)
        return 0.0;
    else if (humidity > h_high_border.min && humidity < h_normal_border.max)
        return 1 - ((h_normal_border.max - humidity) / (h_normal_border.max - h_high_border.min));
    else
        return 1.0;
}

void FuzzyController::calculate_humidity_state(double humidity){
    double state_low = calculate_humidity_low(humidity);
    double state_normal = calculate_humidity_normal(humidity);
    double state_high = calculate_humidity_high(humidity);

    if (state_normal <= state_low && state_low != 0) {
        humid_state = LOW;
    }
    else if (state_normal <= state_high && state_high != 0) {
        humid_state = HIGH;
    }
    else {
        humid_state = NORMAL;
    }
}

double FuzzyController::calculate_brightness_low(double brightness){
    if (brightness <= b_normal_border.min) {
        return 1.0;
    }
    else if (brightness <= b_low_border.max) {
        return ((b_low_border.max - brightness) / (b_low_border.max - b_normal_border.min));
    }
    else {
        return 0.0;
    }
}

double FuzzyController::calculate_brightness_normal(double brightness){
    if (brightness <= b_normal_border.min)
        return 0.0;
    else if (brightness <= b_normal_border.max) {
        if (brightness > b_normal_border.min && brightness < b_low_border.max)
            return 1 - ((b_low_border.max - brightness) / (b_low_border.max - b_normal_border.min));
        else if (brightness >= b_low_border.max && brightness <= b_high_border.min)
            return 1.0;
        else
            return ((b_normal_border.max - brightness) / (b_normal_border.max - b_high_border.min));
    }
    else
        return 0.0;
}

double FuzzyController::calculate_brightness_high(double brightness){
    if (brightness <= b_high_border.min)
        return 0.0;
    else if (brightness > b_high_border.min && brightness < b_normal_border.max)
        return 1 - ((b_normal_border.max - brightness) / (b_normal_border.max - b_high_border.min));
    else
        return 1.0;
}

void FuzzyController::calculate_brightness_state(double brightness){
    double state_weak = calculate_brightness_low(brightness);
    double state_normal = calculate_brightness_normal(brightness);
    double state_strong = calculate_brightness_high(brightness);

    if (state_normal <= state_weak && state_weak != 0) {
        bright_state = LOW;
    }
    else if (state_normal <= state_strong && state_strong != 0) {
        bright_state = HIGH;
    }
    else {
        bright_state = NORMAL;
    }
}

void FuzzyController::init_borders(){

    std::cout << "Введите границы для категории <Температура> для состояния <Холодная> (минимум максимум)" << std::endl;
    std::cin >> t_low_border.min >> t_low_border.max;
    std::cout << "Введите границы для категории <Температура> для состояния <Нормальная> (минимум максимум)" << std::endl;
    std::cin >> t_normal_border.min >> t_normal_border.max;
    std::cout << "Введите границы для категории <Температура> для состояния <Горячая> (минимум максимум)" << std::endl;
    std::cin >> t_high_border.min >> t_high_border.max;

    std::system("cls");

    std::cout << "Введите границы для категории <Влажность> для состояния <Низкая> (минимум максимум)" << std::endl;
    std::cin >> h_low_border.min >> h_low_border.max;
    std::cout << "Введите границы для категории <Влажность> для состояния <Нормальная> (минимум максимум)" << std::endl;
    std::cin >> h_normal_border.min >> h_normal_border.max;
    std::cout << "Введите границы для категории <Влажность> для состояния <Высокая> (минимум максимум)" << std::endl;
    std::cin >> h_high_border.min >> h_high_border.max;

    std::system("cls");

    std::cout << "Введите границы для категории <Яркость> для состояния <Слабая> (минимум максимум)" << std::endl;
    std::cin >> b_low_border.min >> b_low_border.max;
    std::cout << "Введите границы для категории <Яркость> для состояния <Нормальная> (минимум максимум)" << std::endl;
    std::cin >> b_normal_border.min >> b_normal_border.max;
    std::cout << "Введите границы для категории <Яркость> для состояния <Сильная> (минимум максимум)" << std::endl;
    std::cin >> b_high_border.min >> b_high_border.max;

    std::system("cls");
}

std::vector<float> FuzzyController::climate_control(double temperature, double humidity, double brightness){

    calculate_temperature_state(temperature);
    calculate_humidity_state(humidity);
    calculate_brightness_state(brightness);

    float fan_speed = 0.0f;
    float pow_rad = 0.0f;
    float watering = 0.0f;
    float power_lamp = 0.0f;

    switch (temp_state){
    case FuzzyController::LOW:
        switch (humid_state){
        case FuzzyController::LOW:
            fan_speed = 0.0f;
            pow_rad = 100.0f;
            watering = 1.0f;
            break;
        case FuzzyController::NORMAL:
            fan_speed = 0.0f;
            pow_rad = 50.0f;
            watering = 0.0f;
            break;
        case FuzzyController::HIGH:
            fan_speed = 0.0f;
            pow_rad = 50.0f;
            watering = 0.0f;
            break;
        default:
            break;
        }
        break;
    case FuzzyController::NORMAL:
        switch (humid_state){
        case FuzzyController::LOW:
            fan_speed = 0.0f;
            pow_rad = 50.0f;
            watering = 1.0f;
            break;
        case FuzzyController::NORMAL:
            fan_speed = 50.0f;
            pow_rad = 0.0f;
            watering = 0.0f;
            break;
        case FuzzyController::HIGH:
            fan_speed = 100.0f;
            pow_rad = 0.0f;
            watering = 0.0f;
            break;
        default:
            break;
        }
        break;
    case FuzzyController::HIGH:
        switch (humid_state){
        case FuzzyController::LOW:
            fan_speed = 50.0f;
            pow_rad = 0.0f;
            watering = 1.0f;
            break;
        case FuzzyController::NORMAL:
            fan_speed = 100.0f;
            pow_rad = 0.0f;
            watering = 1.0f;
            break;
        case FuzzyController::HIGH:
            fan_speed = 100.0f;
            pow_rad = 0.0f;
            watering = 0.0f;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    switch (bright_state){
    case FuzzyController::LOW:
        power_lamp = 100.0f;
        break;
    case FuzzyController::NORMAL:
        power_lamp = 50.0f;
        break;
    case FuzzyController::HIGH:
        power_lamp = 0.0f;
        break;
    default:
        break;
    }
    
    controller.push_back(fan_speed);
    controller.push_back(pow_rad);
    controller.push_back(watering);
    controller.push_back(power_lamp);

    return controller;
}
