//
//  capacitated_vehicle_routing_problem
//
//  Created by Павел
//
#include "neighborhood.h"
#include "localsearch.h"
#include "solution.h"
#include "construction.h"
#include "perturbation.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm> 
using namespace std;

LocalSearch::LocalSearch( Input* input)
{
    this->in = input;
    s =  new Solution(in);
    s_star =  new Solution(in);
    s_line =  new Solution(in);
    s_rvnd =  new Solution(in);
    c = new Construction();
    p = new Perturbation();
    n = new Neighborhood(in);
}

Solution LocalSearch::GILSRVND(int Imax, int Iils, vector<double> &R){
    
    for(int i = 1; i <= Imax; i++){
        alpha = randomValue(R);        
        c->constructiveProcedure(s,alpha);
        (*s_line) = (*s);
        iterILS = 0;
        while(iterILS < Iils){
            RVND(s);
            if(f(s) < f(s_line)){
                (*s_line) = (*s);
                iterILS = 0;
            }
            (*s) = (*s_line);
            p->bridgePerturbation(s,4);
            iterILS = iterILS + 1;
        }
        if(f(s_line) < f(s_star)){
            (*s_star) = (*s_line);
        }
    }
    return (*s_star);
}

double LocalSearch::f(Solution* s){
    
    return s->totalDistance();
    
}

double LocalSearch::randomValue(vector<double> R){
    return R[rand()%R.size()];
}

string LocalSearch::randomNeighborhood(){
    return NL[rand()%NL.size()];
}

void LocalSearch::deleteNeighborhood(string choosenNeighborhood){
    auto it = find(NL.begin(), NL.end(), choosenNeighborhood);
    if(it != NL.end())
        NL.erase(it);
}

void LocalSearch::RVND(Solution* s){
    (*s_rvnd) = (*s);
    NL = n->NeighborhoodList();
    string choosenNeighborhood;
    while(NL.size() != 0){
        choosenNeighborhood = randomNeighborhood();
        n->improve(s_rvnd,choosenNeighborhood);
        if(f(s_rvnd) < f(s)){
            (*s) = (*s_rvnd);
        }
        else
            deleteNeighborhood(choosenNeighborhood);
    }
}
