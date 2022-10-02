//
//  capacitated_vehicle_routing_problem
//
//  Created by Павел
//
#ifndef NEIGHBORHOOD_H_INCLUDED
#define NEIGHBORHOOD_H_INCLUDED
#include "solution.h"

class Neighborhood{
public:
    Neighborhood(Input *input);
    vector<string> NeighborhoodList(){return NL;};
    void improve(Solution* s,string choosenNeighborhood);
    
    void bestSwap(Solution* s);
    double swapDeltaEvaluation(Solution* s,int vehicle, int i,int j);
    void swapMove(Solution* s,int vehicle, int i,int j, double delta);
    
    void swapVehicle(Solution* s);
    pair<double,double> swapVehicleDeltaEvaluation(Solution* s,int v1, int v2, int i,int j);
    void swapVehicleMove(Solution *s, int v1, int v2, int a, int b, pair<double,double> delta);
    
    void bestTwoOpt(Solution* s);
    double twoOptDeltaEvaluation(Solution* s,int vehicle, int arci,int arcj);
    void twoOptMove(Solution* s, int vehicle, int arci,int arcj, double delta);
    
    void bestReInsertion(Solution* s, int size = 1 );
    double reInsertionDeltaEvaluation(Solution* s, int vehicle, int arc, int size, int shift);
    void reInsertionMove(Solution* s, int vehicle, int arc, int size, int shift, double delta);
    
    Input* in;
    vector<string> NL;
    friend ostream & operator << (ostream &out, const Neighborhood &c);
    
};

#endif //NEIGHBORHOOD_H_INCLUDED
