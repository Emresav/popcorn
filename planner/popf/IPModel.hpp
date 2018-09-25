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

#ifndef IPModel_hpp
#define IPModel_hpp

#include <stdio.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include "RPGBuilder.h"
#include "IPSolver.hpp"

using namespace std;
using namespace Planner;


class IPModel{
public:
    IPModel(bool d = false) : maxT(RPGBuilder::numberOfActions()),pL(0), h(-1), debug(d), addWarmStart(false), iBool(0), iBoolAux(0), iInt(0), iCount(0) { initialised = true; isTimeLimit = false; checkOptimal = false;}
    IPModel(int mT, bool d = false) : maxT(mT), pL(0), h(-1), debug(d), addWarmStart(false), iInt(0), iCount(0) { initialised = true; isTimeLimit = false; checkOptimal = false; }
    ~IPModel(){
        delete solver;
    }
    bool solve();
    double getObjectiveValue(){
        return h;
    }
    int getCol(int i){
        return i%maxT;
    }
    int getRow(int i){
        return i/maxT;
    }
    
    // int col time, row index;
    virtual int getIndex(int row, int col){
        return row*maxT + col;
    }
    void setTimeLimit(double tl){
        isTimeLimit = true;
        timeLimit = tl;
    }
    void start (MinimalState & state);
    void setLPRelaxation(bool b);
    void getSolution(){
        cout << solution.str();
    };
    bool checkOptimal;
    void checkOptimality(){ checkOptimal = true; }
    double getPlanLength() {return pL; };
    virtual void addMIPStart(list<int> solution){
        
    };
    list<int> extractSolutionList(){
        return solutionIP;
    }
    void setSolver(IPSolver *s){
        solver = s;
    }
    void printSolution(){
        cout << solution.str();
    };
    
    virtual void incrementTimeHorizon(MinimalState & state,int increment){
        
    }
protected:
    
    IPSolver *solver;
    void initialise();
    int iBool;
    int iBoolAux;
    int iInt;
    int iCount;
    virtual void initialiseVariables() = 0;
    virtual void buildConstraints() = 0;
    virtual void updateConstraints(MinimalState & state) = 0;
    virtual void extractSolution() = 0;
    bool debug;
    int maxT;
    double h;
    double pL;
    bool isLPRelaxation;
    bool initialised;
    bool isTimeLimit;
    double timeLimit;
    ostringstream solution;
    bool addWarmStart;
    list<int> solutionIP;
};

#endif /* IPModel_hpp */
