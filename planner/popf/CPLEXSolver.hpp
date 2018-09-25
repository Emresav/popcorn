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

#ifndef CPLEXSolver_hpp
#define CPLEXSolver_hpp

#include <stdio.h>
#include "IPSolver.hpp"
#include <ilcplex/ilocplex.h>

class CPLEXSolver :  public IPSolver {
public:
    CPLEXSolver(bool d) : IPSolver(d){

    }
    ~CPLEXSolver(){
        
    }
    virtual void initialise();
    virtual void addCol(VarType type, double min, double max, string name);
    virtual void addObjective(list<IPConstraint> coefficients);
    virtual void addRow(list<IPConstraint> coefficients, EqType eqType, double constCoeff);
    virtual void addRow(int index, double w, VarType varType, EqType eqType, double constCoeff);
    virtual bool solve();
    virtual void setLPRelaxation(bool b);
    virtual double getValue(VarType varType, int index);
    virtual double getObjectiveValue(){
        return round(cplex.getObjValue()*1000000)/1000000;
    }
    virtual void updateCol(int index, VarType varType, BoundType bType, double value);
    virtual void eliminateConstraint(int id);
    virtual void eliminateObjective();
    virtual int getNConstraint();
protected:
    struct var {
        IloIntVarArray x;
        IloNumVarArray y;
        IloNumVarArray v;
        IloIntVarArray m;
    };
    IloCplex cplex;
    IloModel model;
    IloConstraintArray constraints;
    IloObjective objective;
    var x;

};
#endif /* CPLEXSolver_hpp */
