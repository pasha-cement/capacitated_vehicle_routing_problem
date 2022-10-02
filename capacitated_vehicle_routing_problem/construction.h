//
//  capacitated_vehicle_routing_problem
//
//  Created by Павел
//
#ifndef CONSTRUCTION_H_INCLUDED
#define CONSTRUCTION_H_INCLUDED
#include "solution.h"

class 
Construction{
public:
    void calculaCustoInsercao(Solution* s, int vehicle);
    void constructiveProcedure(Solution* s, const double alpha);
    
    struct InsertionInfo {
        int noInserido;
        int arestaRemovida;
        double custo ;
    };
    
    static bool compareByCost(const InsertionInfo &a, const InsertionInfo &b)
    {
        return a.custo < b.custo;
    }
    vector<int> CL;
    vector<InsertionInfo> custoInsercao; 
    
    friend ostream & operator << (ostream &out, const Construction &c);
};

#endif //CONSTRUCTION_H_INCLUDED
