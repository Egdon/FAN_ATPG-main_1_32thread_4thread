// **************************************************************************
// File       [ fan_mgr.h ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/08/30 created ]
// **************************************************************************

#ifndef _FAN_FAN_MGR_H_
#define _FAN_FAN_MGR_H_

#include "common/tm_usage.h"

#include "interface/netlist.h"
#include "interface/techlib.h"

#include "core/atpg.h"

namespace FanNs {

class FanMgr {
public:
    FanMgr() {
        lib            = NULL;
        nl             = NULL;
        fListExtract          = NULL;
        pcoll          = NULL;
        cir            = NULL;
        sim            = NULL;
        atpg           = NULL;
        atpgStat.rTime = 0;
    }
    ~FanMgr() {}

    IntfNs::Techlib     *lib;
    IntfNs::Netlist     *nl;
    CoreNs::FaultListExtract   *fListExtract;
    CoreNs::FaultListExtract   *fListExtract_1;

    CoreNs::PatternProcessor *pcoll;
    // CoreNs::PatternProcessor *pcoll_1;

    CoreNs::Circuit *cir;
    CoreNs::Circuit *cir_1;
    CoreNs::Circuit *cir_2;
    CoreNs::Circuit *cir_3;
    CoreNs::Circuit *cir_4;
    CoreNs::Circuit *cir_5;
    CoreNs::Circuit *cir_6;
    CoreNs::Circuit *cir_7;
    CoreNs::Circuit *cir_8;
    CoreNs::Circuit *cir_9;
    CoreNs::Circuit *cir_10;
    CoreNs::Circuit *cir_11;
    CoreNs::Circuit *cir_12;
    CoreNs::Circuit *cir_13;
    CoreNs::Circuit *cir_14;
    CoreNs::Circuit *cir_15;
    CoreNs::Circuit *cir_16;
    CoreNs::Circuit *cir_17;
    CoreNs::Circuit *cir_18;
    CoreNs::Circuit *cir_19;
    CoreNs::Circuit *cir_20;
    CoreNs::Circuit *cir_21;
    CoreNs::Circuit *cir_22;
    CoreNs::Circuit *cir_23;
    CoreNs::Circuit *cir_24;
    CoreNs::Circuit *cir_25;
    CoreNs::Circuit *cir_26;
    CoreNs::Circuit *cir_27;
    CoreNs::Circuit *cir_28;
    CoreNs::Circuit *cir_29;
    CoreNs::Circuit *cir_30;
    CoreNs::Circuit *cir_31;







    CoreNs::Simulator *sim;
    CoreNs::Simulator *sim_1;
    CoreNs::Simulator *sim_2;
    CoreNs::Simulator *sim_3;
    CoreNs::Simulator *sim_4;
    CoreNs::Simulator *sim_5;
    CoreNs::Simulator *sim_6;
    CoreNs::Simulator *sim_7;
    CoreNs::Simulator *sim_8;
    CoreNs::Simulator *sim_9;
    CoreNs::Simulator *sim_10;
    CoreNs::Simulator *sim_11;
    CoreNs::Simulator *sim_12;
    CoreNs::Simulator *sim_13;
    CoreNs::Simulator *sim_14;
    CoreNs::Simulator *sim_15;
    CoreNs::Simulator *sim_16;
    CoreNs::Simulator *sim_17;
    CoreNs::Simulator *sim_18;
    CoreNs::Simulator *sim_19;
    CoreNs::Simulator *sim_20;
    CoreNs::Simulator *sim_21;
    CoreNs::Simulator *sim_22;
    CoreNs::Simulator *sim_23;
    CoreNs::Simulator *sim_24;
    CoreNs::Simulator *sim_25;
    CoreNs::Simulator *sim_26;
    CoreNs::Simulator *sim_27;
    CoreNs::Simulator *sim_28;
    CoreNs::Simulator *sim_29;
    CoreNs::Simulator *sim_30;
    CoreNs::Simulator *sim_31;


    CoreNs::Atpg        *atpg;
    CommonNs::TmUsage   tmusg;
    CommonNs::TmStat    atpgStat;
};

};

#endif


