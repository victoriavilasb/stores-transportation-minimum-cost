#ifndef store_hpp
#define store_hpp

class Store {
    public:
        int store_id, position_x, position_y;
        Store(int store_id, int position_x, int position_y);
        float calculate_distance(int store_position_x, int store_position_y);
};

#endif
