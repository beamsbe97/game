#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <memory>
#include <algorithm>
#include "GameObject.h"

using namespace std;

class Geometry{
    public:
        Geometry(ActiveObject* gameObj)
        :xOrigin(obj->get_xPos()), yOrigin(obj->get_yPos()), gameObj(gameObj){}

        float getXorigin(){return xOrigin;}
        float getYorigin(){return yOrigin;}
        virtual bool collisionCheck(const Geometry* otherObject) const = 0;
        virtual vector<map<string,float>> calcAABB_boundaries();
        virtual void update() = 0;
    protected:
        float xOrigin;
        float yOrigin;
        vector<map<string,float>> aabbBoundaries;
        ActiveObject* gameObj;
};

class Polygon : public Geometry{
    public:
        Polygon(vector<vector<float>> vertices);
        bool collisionCheck(const Geometry* otherObject) const override;
        bool aabbCollision(const Geometry* otherObject) const;
        vector<float> calcAABB_boundaries();
        bool satCollision(const Geometry* otherObject) const;
        void update();
        

    private:
        vector<vector<float>> vertices;
        vector<vector<float>> edgeVecs;
        vector<vector<vector<float>>> edges; // list of (x1,y1), (x2,y2) vertices that form an edge 
        void getEdgeVecs();
        void getEdges();
        

}

class Circle:public Geometry{
    public:
        Circle(float xOrigin, float yOrigin, float radius);

        float getRadius(){return radius;}
        bool collisionCheck(const Geometry* otherObject) const override;
        vector<map<string,float>> calcAABB_boundaries();

    private:
        float radius;

}