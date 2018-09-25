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

#ifndef IPHeuristic_hpp
#define IPHeuristic_hpp

#include <stdio.h>
#include "RPGBuilder.h"
#include <queue>
#include <set>
#include "IPModel.hpp"

#define EPSILON 0.0001

using namespace std;
using namespace Planner;

class IPHeuristic : public IPModel {
public:
    IPHeuristic(MinimalState & state, bool d = false);
    static vector<int> findNonDominatedActionsNumeric();
    vector<int> findNonDominatedActions(vector<int>& toFilter);
    ~IPHeuristic(){}
    
protected:
    
    virtual void initialiseVariables();
    virtual void buildConstraints();
    virtual void updateConstraints(MinimalState &state);
    static bool actionIsDominated(int i, int j);
    vector<int> actionsToUse;
    vector<int> actionsToFilter;
    //static vector<int> actionsToFilter;
    int maxUse;
    MinimalState &theState;
    virtual void extractSolution();
private:
    // index follow ripple note 231 (?)
    vector<int> up;
    vector<int> npmax;
    vector<int> npmin;
    vector<int> ua;
    vector<int> eap;
    vector<int> tp;
    vector<int> ta;
    vector<int> ip;
    vector<int> mac;
    vector<int> ma;
    vector<int> uc;
    vector<int> eac;
    vector<int> tc;
    vector<int> iv;
    // upperbound
    int B;
    vector<int> maxAction;
    vector<bool> isInGoal;
    // relevance analysis
    vector<set<int>> firstAchievers; //given a literal, return a set of action achiever
    //vector<set<int>> fAdd; // given an action, return set of first achievers added by the actions
    vector<bool> relevantActions; // given an action, return set of first achievers added by the actions
    vector<bool> relevantPropositions; // given an action, return set of first achievers added by the actions
    // inverse actions
    vector<bool> actionLandmarks;
    vector<bool> factLandmarks;
    vector<bool> actionEliminated;
    vector<bool> factEliminated;
    vector<vector<bool>> fAdd;
    vector<vector<bool>> pAdd;
    
    map<int,list<int>> inverseActions;
    // landmarks
    vector<set<int>> candidateLandmarks;
    vector<set<int>> candidateActionLandmarks;
    
    // constraints
    void objectiveValue();
    void goalState();
    void actionPreconditions();
    void firstAchiever();
    void actionEffects();
    void initialState();
    void propositionalLandmarks();
    void numericalLandmarks();
    void timeConstraintPreconditions();
    void timeConstraintEffects();
    void numericPreconditions();
    void numericGoalConditions();
    void numericActionPreconditions();
    void numericFirstAchiever();
    void numericActionCounter();
    void numericTimeConstraintActionPreconditions();
    void numericTimeConstraintEffects();
    void inverseAction();
    void propositionalSEQConstraints();
    void numericSEQGoalConstraints();
    void variablesBounds();
    void relevantActionsConstraints();
    // other methods
    map<int,list<int>> getInverseActions();
    static pair<list<pair<int,double>>,double> getExpression(RPGBuilder::RPGNumericPrecondition precondition);
    void calculateMaxActions(MinimalState &theState);
    
    virtual int extractSolutionLength();
};
#endif /* IPHeuristic_hpp */
