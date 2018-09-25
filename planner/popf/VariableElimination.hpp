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


#ifndef VariableElimination_hpp
#define VariableElimination_hpp

#include <stdio.h>
#include <set>
#include <vector>
#include <queue>
#include "RPGBuilder.h"
#include <unordered_set>

using namespace std;
using namespace Planner;
namespace FukunagaAnalysis {
    
    //bool debug = true;
    void performLandmarkAnalysis(set<int> & actions, MinimalState &state, bool includeNumeric, vector<vector<bool>> & factLandmarks, bool debug = true);
    // landmarks extraction
    /**
     Returns action and fact landmarks
     
     @param state: planning state
     @param factLandmarks: container where fact landmarks are added
     @param actionLandmarks: container where action landmarks are added
     @param debug: verbose
     @return null.
     */
    void extractLandmarkActionsAndFacts(MinimalState &state, vector<vector<bool>> & factLandmarksTable, vector<bool> & factLandmarks, vector<bool> & actionLandmarks, bool includeNumeric, bool debug);

    void extractLandmarkAndOrGraph(MinimalState &state, vector<vector<bool>> & factLandmarksTable, vector<bool> & factLandmarks, vector<bool> & actionLandmarks, bool includeNumeric, bool debug);
    
    void performRelevanceAnalysis(vector<vector<bool>>& factLandmarks, vector<vector<bool>> & factLandmarksForActions,vector<bool> &dominatedActions, vector<bool> &dominatedFacts, vector<vector<bool>> &fAdd, MinimalState &state, vector<bool>& relevantActions, vector<bool>& relevantPropositions, bool debug);
    
    void calculateLandmarksIntersections(vector<int> & intersection, int & max, vector<vector<bool>> & currentLandmarks, int action, int p);
    // calculate fachievers
    void calculateFirstAchieversAndFactLandmarksForAction(vector<vector<bool>>& factLandmarks, vector<vector<bool>> &firstAchievers,vector<vector<bool>> &fAdd, vector<vector<bool>> &factLandmarksForActions);
    void calculateFAdd();
    //
    bool dominatedActionElimination(MinimalState &theState, vector<vector<bool>> &fAdd, vector<vector<bool>> &factLandmarksForActions,  vector<bool> & dominatedFacts, vector<bool> & dominatedActions, vector<bool>& relevantActions, bool debug);
    void iterativeVariableElimination(MinimalState &state, vector<bool> &actionLandmarks, vector<bool> &factLandmarks, vector<bool> &eliminatedActions, vector<bool> &eliminatedFacts,  vector<vector<bool>> & fAdd, bool debug = true);
  
    //    // landmarks
    struct LandmarkState{
        set<int> propositions;
        vector<double>  minV;
        vector<double>  maxV;
        void printState(){
            cout << "proposition :";
            for(auto p : propositions){
                cout << p << " ";
            }
            cout << "\nnumeric : ";
            for (int i = 0; i< minV.size(); ++i){
                cout << "[" << minV[i] << "," << maxV[i] << "] ";
            }
            cout << endl;
        }
    };
    pair<list<pair<int,double>>,double> getExpression(RPGBuilder::RPGNumericPrecondition precondition);
    bool checkSatisfied(int condition, LandmarkState &state);
    bool checkSatisfied(int condition, set<int> &prop, vector<double> &minV, vector<double> &maxV);
    bool checkActionSatisfied(int action, LandmarkState &state);
    bool checkActionSatisfied(int action, set<int> &prop, vector<double> &minV, vector<double> &maxV);
    bool isSubsetOfI(list<Literal *>& toCheck, set<int>& superSet);
    bool isSubsetOfI(const list<Literal *>& toCheck, list<Literal *>& superSet);
    bool isSubsetOfI(list<int>& toCheck, set<int>& superSet);
    bool isSubsetOfI(set<int>& toCheck, set<int>& superSet);
    bool isSubsetOfI(const list<Literal *>& addEff, list<int> & numericAdd, vector<bool>& toCheck, vector<bool>& superSet);
    void updateState(int p, LandmarkState & s, bool isNumeric);
    void addConditionLandmark(int p, int a, LandmarkState &s, vector<vector<bool>>& currentLandmarks, queue<int> & actions, vector<bool>& visited, bool isNumeric, list<int>& addConditions, set<int>& actionsSet);
    bool updateCandidate(int p, int a,  LandmarkState & s, vector<vector<bool>>& currentLandmarks, list<int> &addedNumericCondition);
    void calculateNumericX(int p, int a, LandmarkState & s, vector<vector<bool>>& currentLandmarks, list<int> &addedNumericCondition, vector<bool>& X);
    void calculateNumericXIntersection(int p, int a, LandmarkState & s, vector<vector<bool>>& currentLandmarks, list<int> &addedNumericCondition, vector<bool>& X);
    // adder = false gives list of action that can achieve a precondition p
    // adder = true gives the list of condition that action p can achieve
    void getNumericAchievers(int p, list<int> & numericAchievers, bool adder = false);
    void calculateNumericAchievers(vector<list<int>>& numericAchieversTable, vector<list<int>> & numericAdders);
    
    void calculateNumericIncreasers(vector<list<double>> &increasers, vector<list<double>> &decreasers);
    
    // relevance analysis
    bool emptyIntersection(list<Literal *> &goals,  set<int> &fadd);
    bool emptyIntersection(list<Literal *> &goals,  vector<bool> &fadd);
    bool emptyIntersection(list<pair<int, int> > &goals,  vector<bool> &fadd);
    bool emptyIntersection(const list<int> &goals,  vector<bool> &fadd);
    bool dominatedNumericEffects(int i, int j);
    // return if something new happened
    bool getRelevantActions(vector<bool>& relevantActions, vector<bool>&actionLandmarks, vector<vector<bool>> & fAdd, bool debug);
    bool getRelevantPropositions(vector<bool>& relevantPropositions, vector<bool>& relevantActions, MinimalState &theState, bool debug);
    void getInverseActions(map<int,list<int>>& inverseActions);
    vector<list<int>> & getPrecondition();
    vector<set<int>> & getPreconditionSet();
    vector<list<int>> &  getActionsToRPGExtendedNumericStartPreconditions();
    vector<vector<bool>> & calculateNumericDominance();
    void getTimeStampedMaxValues(vector<vector<pair<double,double>>>  & minMaxValues, vector<vector<pair<double,double>>>  & minMaxSteps, int t, MinimalState &theState);
    void getTimeStampedMaxValuesGeneral(vector<vector<pair<double,double>>>  & minMaxValues, vector<vector<pair<double,double>>>  & minMaxSteps, vector<double> & minEffect, int t, MinimalState &theState);
    void getActionsEffects(vector<list<pair<int,double>>> & simpleEffectActionsConstant, vector<list<pair<int,int>>> & linearEffectActionEffectID);

};

#endif /* VariableElimination_hpp */
