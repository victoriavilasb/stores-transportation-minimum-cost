#include <iostream>
#include <iomanip> 
#include <store.h>
#include <edge.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<double>
kruskal(int vertices_size, vector<int> tree_ids, vector<Edge> edges) {
    vector<double> result;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_ids[e.x] != tree_ids[e.y]) {
            result.push_back(e.weight);

            int old_id = tree_ids[e.x], new_id = tree_ids[e.y];
            for (int i = 0; i < vertices_size; i++) {
                if (tree_ids[i] == old_id) {
                    tree_ids[i] = new_id;
                }
            }
        
        }
    }

    return result;
}

int main() {
    int km_motorcycle_limit, available_drones, km_motorcycle_cost, km_truck_cost;
    int store_id, position_x, position_y, stores_number, remaining_stores;
    double distance;
    vector<Edge> edges;
    vector<double> mst;
    vector<int> stores_ids;
    double total_moto, total_truck;

    cin >> stores_number >> km_motorcycle_limit >> available_drones >> km_motorcycle_cost >> km_truck_cost;
  
    vector<Store *> stores(stores_number);

    // Initialize all stores and store it in an array
    for(int i = 0; i < stores_number; i++) {
        cin >> position_x >> position_y;
        stores[i] = new Store(i, position_x, position_y);
        stores_ids.push_back(i);
    }

    // For each stores calculates the distance from the others
    for(int i = 0; i < stores_number; i++) {
        for (int j = i; j < stores_number; j++) {
            distance = stores[i]->calculate_distance(stores[j]->position_x, stores[j]->position_y);
            if (distance > 0) {
                edges.push_back(Edge(stores[i]->store_id, stores[j]->store_id, distance));
            }
        }

    }

    mst = kruskal(stores_number, stores_ids, edges);

    remaining_stores = stores_number - available_drones;
    for (int i = 0; i < remaining_stores; i++) {
        if (mst[i] <= km_motorcycle_limit) {
            total_moto += mst[i] * km_motorcycle_cost;
        } else {
            total_truck += mst[i] * km_truck_cost;
        }
    }

    cout << std::fixed;
    cout << std::setprecision(3);
    cout << total_moto << " " << total_truck << endl;

    return 0;
}
