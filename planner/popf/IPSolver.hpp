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

#ifndef IPSolver_hpp
#define IPSolver_hpp

#include <stdio.h>
#include <list>
#include <string>

using namespace std;

enum VarType {IPInteger = 0, IPBoolean = 1, IPBooleanAux = 2, IPContinous = 3};
enum EqType {IPGreater = 0, IPEqual = 1, IPLess = 2};
enum BoundType {LB = 0, UB = 1};

class IPSolver{
public:
    IPSolver(bool d) : debug(d)  {}
    ~IPSolver(){}
    struct IPConstraint{
        VarType varType;
        int index;
        double coefficient;
    };
    
    virtual void initialise() = 0;
    virtual void addCol(VarType type, double min, double max, string name) = 0;
    virtual void addObjective(list<IPConstraint> coefficients) = 0;
    virtual void addRow(list<IPConstraint> coefficients, EqType eqType, double constCoeff) = 0;
    virtual void addRow(int index, double w, VarType varType, EqType eqType, double constCoeff) = 0;
    virtual void updateCol(int index, VarType varType, BoundType bType, double value) = 0;
    virtual bool solve() = 0;
    virtual void setLPRelaxation(bool b) = 0;
    virtual double getValue(VarType varType, int index) = 0;
    virtual double getObjectiveValue() = 0;
    virtual void eliminateConstraint(int id) = 0;
    virtual void eliminateObjective() = 0;
    virtual int getNConstraint() = 0;
    virtual void update(){
        
    }
protected:
    bool debug;
};
#endif /* IPSolver_hpp */
