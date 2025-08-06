#include <iostream>
#include <vector>
#include <cmath>
#include "GameObject.h"
#include <memory>
#include <algorithm>

using namespace std;

Polygon::Polygon(vector<vector<float>> vertices){
    this->vertices = vertices;
    this->getEdges();
    this->getEdgeVecs();

}
void Polygon::getEdges(){
    for(int i=0; i<vertices.size(); i++){
        edges.push_back({vertices[i], (vertices[(i==(vertices.size()-1)) ? 0 : i+1])});
    }
}

void Polygon::getEdgeVecs(){
    for(vector<vector<float>> edge : edges){
        vector<float> vertix1 = edge[0];
        vector<float> vertix2 = edge[1];
        vector<float> edgeVec = {vertix2[0]-vertix1[0], vertix2[1]-vertix1[1]};
        this->edgeVecs.push_back(edgeVec);
    }
}

void Polygon::what(){
    cout<<this->edges.size()<<"\n";
}


bool Polygon::collisionCheck(Polygon& otherObject){
    for(int i=0; i<edgeVecs.size(); i++){ // loop through every edge on polygon A

        //Get Normal vector of the edge
        vector<float> normal = {-edgeVecs[i][1], edgeVecs[i][0]}; //swap x and y and make x negative
        cout << "("<<normal[0]<<","<<normal[1]<<")";

        //Normalise the normal vector = each component divided by magnitude of vector
        float magnitude = sqrt(pow(abs(edges[i][1][0]-edges[i][0][0]), 2)+ pow(edges[i][1][1]-edges[i][0][1],2));
        vector<float> unitVec = {normal[1]/magnitude, normal[0]/magnitude};

        //Calculate dot product of the unitVec and all the edges of the polygon
        vector<float> dotProducts;
        vector<float> dotProducts_otherObject;

        for(vector<float> vec : edgeVecs){
            if(vec == edgeVecs[i]){
                continue;
            }
            dotProducts.push_back(vec[0]*unitVec[0] + vec[1]*unitVec[1]);
        }

        for(vector<float> vec : otherObject.edgeVecs){
            dotProducts_otherObject.push_back(vec[0]*unitVec[0] + vec[1]*unitVec[1]);
        }
        float dotProducts_max = *max_element(dotProducts.begin(), dotProducts.end());
        float dotProducts_min = *min_element(dotProducts.begin(), dotProducts.end());
        float dotProducts_otherObject_max = *max_element(dotProducts_otherObject.begin(), dotProducts_otherObject.end());
        float dotProducts_otherObject_min = *min_element(dotProducts_otherObject.begin(), dotProducts_otherObject.end());

        if(dotProducts_max<=dotProducts_otherObject_max && 
            dotProducts_max>=dotProducts_otherObject_min){
            return true;
        }

        if(dotProducts_min>=dotProducts_otherObject_min && dotProducts_min<=dotProducts_otherObject_max){
            return true;
        }    

    } 
    return false;
}