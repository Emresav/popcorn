/************************************************************************
 * Copyright(C) 2018: C. Piacentini, M. P. Castro, A. A. Cire, J. C. Beck
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public license as
 * published by the Free Software Foundation; either of the license, or
 * (at your option) any later version.
 *
 * This planner is currently in BETA, and is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public license for more details.
 *
 * To contact the development team, email to
 * <chiarap@mie.utoronto.ca>
 *
 * This builds on LPRPG. The following is the original LPRPG license:
 *
 * Copyright 2008, 2009, Strathclyde Planning Group,
 * Department of Computer and Information Sciences,
 * University of Strathclyde, Glasgow, UK
 * http://planning.cis.strath.ac.uk/
 *
 * Maria Fox, Richard Howey and Derek Long - Code from VAL
 * Stephen Cresswell - PDDL Parser
 * Andrew Coles, Amanda Coles - Code for LPRPG
 *
 * This file is part of LPRPG.
 *
 * LPRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * LPRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LPRPG.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

#ifndef IPStateBasedUnified_hpp
#define IPStateBasedUnified_hpp

#include <stdio.h>
#include "IPStateBasedModel.hpp"
#include "RPGBuilder.h"
#include "VariableElimination.hpp"

#define EPS 0.0001
using namespace std;
using namespace Planner;

class IPStateBasedUnified : public IPStateBasedModel {
public:
    IPStateBasedUnified(MinimalState & state, int horizon, vector<bool> & aL, vector<bool> & fL, vector<bool> & aE, vector<bool> & fE, bool d = false) :  IPStateBasedModel(state,horizon, aL, fL, aE, fE, d), delta(1), infinity(10),  minMaxValues(0), minMaxSteps(0), simpleEffectActionsConstant(0), linearEffectActionEffectID(0), minEffect(0), variableActionLinear(0) {
        infinity = 100000;//
        //infinity = IloInfinity;
        
        FukunagaAnalysis::getActionsEffects(simpleEffectActionsConstant,linearEffectActionEffectID);
        variableActionLinear.assign(RPGBuilder::getPNECount(),vector<bool>(RPGBuilder::numberOfActions(),false));
        for (int iV = 0; iV < RPGBuilder::getPNECount();++iV){
            for (auto p : linearEffectActionEffectID[iV]){
                variableActionLinear[iV][p.first] = true;
            }
        }
        if(debug){
            for (int iV = 0; iV < RPGBuilder::getPNECount(); ++iV){
                cout << "variable " << iV << " has " << simpleEffectActionsConstant[iV].size() << " simple actions and " << linearEffectActionEffectID[iV].size() << " linear actions " << endl;
            }
        }
        
    }
    
    ~IPStateBasedUnified(){
        
    }
    virtual void addMIPStart(list<int> solution){ };
    virtual void incrementTimeHorizon(MinimalState & state, int increment = 0);
protected:
    double delta;
    double infinity;
    virtual void initialiseVariables();
    virtual void buildConstraints();
    void numericPreconditions(int tMin, int tMax);
    void numericEffects(int tMin, int tMax);
    void numericInitialStateConstraint();
    void numericGoalStateConstraint();
    void numericNoopConstraint(int tMin, int tMax);
    void numericNoopEffects(int tMin, int tMax);
    void numericMutex(int tMin, int tMax);
    void numericMutexEffects(int tMin, int tMax);
    void addVariables(int tMin, int tMax);
    void symmetryEnd(int tMin, int tMax);
    list<int> toErase2;
    //virtual void extractSolution();
    
    vector<vector<pair<double,double>>>  minMaxValues;
    vector<vector<pair<double,double>>>  minMaxSteps;
    vector<list<pair<int,double>>>       simpleEffectActionsConstant;
    vector<list<pair<int,int>>>          linearEffectActionEffectID;
    vector<vector<bool>>             variableActionLinear;
    vector<double>                       minEffect;
};

#endif /* IPStateBasedUnified_hpp */
