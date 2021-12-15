#include <iostream>
#include "../include/store.hpp"

using namespace std;

int main() {
    int km_motorcycle_limit, available_drones, km_motorcycle_cost, km_truck_cost;
    int store_id, position_x, position_y, stores_number;
    float distance;

    cin >> stores_number >> km_motorcycle_limit >> available_drones >> km_motorcycle_cost >> km_truck_cost;
  
    Store * stores_position[stores_number];
    float stores_weight_graph[stores_number][stores_number];
    
    // Initialize all stores and store it in an array
    for(int i = 0; i < stores_number; i++) {
        cin >> position_x >> position_y;
        stores_position[i] = new Store(i, position_x, position_y);
    }

    //  Set array to 0
    for(int i = 0; i < stores_number; i++) {
        for (int j = 0; j < stores_number; j++) {
            stores_weight_graph[i][j] = 0;
        }
    }
    
    // For each stores calculates the distance from the others
    for(int i = 0; i < stores_number; i++) {
        for (int j = 0; j < stores_number; j++) {
            distance = stores_position[i]->calculate_distance(stores_position[j]->position_x, stores_position[j]->position_y);
            stores_weight_graph[i][j] = distance;
        }
    }

    // // TEST: Print graph to validate weights
    // for(int i = 0; i < stores_number; i++) {
    //     for (int j = 0; j < stores_number; j++) {
    //         cout << stores_weight_graph[i][j] << " ";
    //     }

    //     cout << endl;
    // }   

    return 0;
}