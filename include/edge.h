#ifndef edge_hpp
#define edge_hpp

class Edge {
    public:
        int x, y;
        double weight;
        Edge(int x, int y, double weight);
        bool operator<(Edge const& other) {
            return weight < other.weight;
        }
};

#endif
