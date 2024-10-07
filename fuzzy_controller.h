#pragma once
#ifndef FUZZY_CONTROLLER
#define FUZZY_CONTROLLER

#include <iostream>
#include <vector>

class FuzzyController {
private:

    struct Border {
        double min;
        double max;
    };

    std::vector<float> controller;

    enum State { LOW, NORMAL, HIGH };

    State temp_state;
    State humid_state;
    State bright_state;

    Border t_low_border;
    Border t_normal_border;
    Border t_high_border;

    Border h_low_border;
    Border h_normal_border;
    Border h_high_border;

    Border b_low_border;
    Border b_normal_border;
    Border b_high_border;

    double calculate_temperature_low(double temperature);
    double calculate_temperature_normal(double temperature);
    double calculate_temperature_high(double temperature);
    void calculate_temperature_state(double temperature);

    double calculate_humidity_low(double humidity);
    double calculate_humidity_normal(double humidity);
    double calculate_humidity_high(double humidity);
    void calculate_humidity_state(double humidity);

    double calculate_brightness_low(double brightness);
    double calculate_brightness_normal(double brightness);
    double calculate_brightness_high(double brightness);
    void calculate_brightness_state(double brightness);

public:
    void init_borders();
    std::vector<float> climate_control(double temperature, double humidity, double brightness);
};

#endif // !FUZZY_CONTROLLER
