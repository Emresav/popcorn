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

#ifndef IPStateBasedModelModel_hpp
#define IPStateBasedModelModel_hpp

#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include "RPGBuilder.h"
#include "IPModel.hpp"

using namespace std;
using namespace Planner;

class IPStateBasedModel : public IPModel {
public:
    IPStateBasedModel(MinimalState & state, int horizon, vector<bool> & aL, vector<bool> & fL, vector<bool> & aE, vector<bool> & fE, bool d = false);
    ~IPStateBasedModel(){

    }
    virtual void addMIPStart(list<int> solution);
    virtual void incrementTimeHorizon(MinimalState & state, int increment = 0);
    
protected:
    virtual void initialiseVariables();
    virtual void buildConstraints();
    virtual void updateConstraints(MinimalState &state);
    virtual void extractSolution();
    
    void addVariables(int tMin, int tMax);
    
    map <pair<Literal*,int>, int> indexLiteral;
    map <pair<instantiatedOp*,int>, int> indexAction;
    map <pair<Literal*,int>, int> indexActionNoop;
    map <pair<PNE*,int>, int> indexPNE;
    map <pair<PNE*,int>, int> indexPNENoop;
    map <pair<pair<instantiatedOp*,int>,int>, int> indexCP;
   // min and max values of variables
    vector<double> maxPossible;
    vector<double> minPossible;
    map <pair<int,int>,int> uc;
    
    //constraints
    void initialStateConstraint();
    void goalStateConstraint();
    void objectiveFunction(int tMin, int tMax);
    void actionPreconditions(int tMin, int tMax);
    void actionsEffects(int tMin, int tMax);
    void mutexRelations(int tMin, int tMax);
    void noopPreconditions(int tMin, int tMax);
    void noopMutex(int tMin, int tMax);
    void noopMutexAdd(int tMin, int tMax); //reduntant
    void noopForcedIfNoActionsAdd(int tMin, int tMax); //reduntant
    void forcePropositionsNotSelected(int tMin, int tMax); //reduntant
    void lastLayer(int tMax);
    void numericActionPreconditions(int tMin, int tMax);
    void numericPreconditions(int tMin, int tMax);
    void numericGoalConditions();
    void numericMutex(int tMin, int tMax);
    void numericMutexPrecondition(int tMin, int tMax);
    void addLandmarksConstraints(int tMin, int tMax);
    void addNumericLandmarksConstraints(int tMin, int tMax);
    void addRelevanceConstraints(int tMin, int tMax);
    void addNumericRelevanceConstraints(int tMin, int tMax);
    void variablesBounds(int tMin, int tMax);
    void sequentialActions(int tMin, int tMax);
    void firstActions(int tMin, int tMax);
    int mT;
    int maxUse;
    int B;
    MinimalState &theState;
    vector<bool> actionLandmarks;
    vector<bool> factLandmarks;
    vector<bool> eliminatedActions;
    vector<bool> eliminatedFacts;
    list<int> toErase;
    vector<vector<pair<double,double>>>  minMaxValues;
    vector<vector<pair<double,double>>>  minMaxSteps;

};

#endif /* IPStateBasedModelModel_hpp */
