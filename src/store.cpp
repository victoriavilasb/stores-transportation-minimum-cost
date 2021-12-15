#include "../include/store.hpp"
#include <iostream>
#include <cmath>

Store::Store(int store_id, int position_x, int position_y) {
    this->store_id = store_id;
    this->position_x = position_x;
    this->position_y = position_y;
}

float
Store::calculate_distance(int store_position_x, int store_position_y) {
    return sqrt(pow(this->position_x - store_position_x, 2) + pow(this->position_y - store_position_y, 2));
}