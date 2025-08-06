#pragma once
#include <vector>

using namespace std;

class Polygon{
    private:
        float xOrigin;
        float yOrigin;
        vector<vector<float>> vertices;
        vector<vector<float>> edgeVecs;
        vector<vector<vector<float>>> edges; // list of (x1,y1), (x2,y2) vertices that form an edge 
        void getEdgeVecs();
        void getEdges();

    public:
        Polygon(vector<vector<float>> vertices);
        bool collisionCheck(Polygon& otherObject);
        void what();
};
