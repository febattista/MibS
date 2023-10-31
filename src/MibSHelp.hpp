/*===========================================================================*/
/* This file is part of a Mixed Integer Bilevel Solver                       */
/* developed using the BiCePS Linear Integer Solver (BLIS).                  */
/*                                                                           */
/* Authors: Scott DeNegre, Lehigh University                                 */
/*          Ted Ralphs, Lehigh University                                    */
/*          Sahar Tahernajad, Lehigh University                              */
/*                                                                           */
/* Copyright (C) 2007-2023 Lehigh University, Scott DeNegre, and Ted Ralphs. */
/* All Rights Reserved.                                                      */
/*                                                                           */
/* This software is licensed under the Eclipse Public License. Please see    */
/* accompanying file for terms.                                              */
/*===========================================================================*/

#ifndef MibSHelp_h_
#define MibSHelp_h_

//#############################################################################

struct LINKING_SOLUTION{
    int tag;
    double lowerObjValue;
    double UBObjValue;
    std::vector<double> lowerSolution;
    std::vector<double> UBSolution;
};

// feb223
struct IMPROVING_DIRECTION {
    std::vector<int> idx;
    std::vector<double> vals;
    std::vector<int> uselessIneqsIdx;
    std::vector<double> uselessIneqsVals;
    double quality;
    double numIneqs;
    
    bool operator<(const IMPROVING_DIRECTION& other) const {
        if (idx.size() != other.idx.size())
            return idx.size() < other.idx.size();
        if ((idx == other.idx) && (vals == other.vals))
            return true;
        if (numIneqs != other.numIneqs)
            return numIneqs < other.numIneqs;
        else
            return quality < other.quality;
    }

    bool operator==(const IMPROVING_DIRECTION& other) const {
        return (idx == other.idx) && (vals == other.vals);
    }
};

struct ID_STATISTICS {
    int enumerated;
    int fracCalls;
    int intCalls;
    int fracCallSuccess;
    int intCallSuccess;
};

#endif
