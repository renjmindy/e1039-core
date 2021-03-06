#include "DecoData.h"

//ClassImp(FeeData);
//ClassImp(RunData);

//ClassImp(SlowControlData);
//ClassImp(ScalerData);
//ClassImp(SpillData);

////////////////////////////////////////////////////////////////
//
// Run Data
//
FeeData::FeeData() :
  roc(0), board(0), hard(0), falling_enabled(0), segmentation(0), 
  multihit_elim_enabled(0), updating_enabled(0), elim_window(0), 
  lowLimit(0), highLimit(0), selectWindow(0)
{
  ;
}

RunData::RunData() : 
  run_id(0), run_desc(""),
  n_fee_event(0), n_fee_prescale(0), n_run_desc(0)
{
  memset(trig_bit, 0, sizeof(trig_bit));
  memset(prescale, 0, sizeof(prescale));
}


////////////////////////////////////////////////////////////////
//
// Spill Data
//

SlowControlData::SlowControlData() :
  ts(""), name(""), value(""), type("")
{
  ;
}

ScalerData::ScalerData() :
  type(0), coda(0), roc(0), board(0), chan(0), value(0), name("")
{
  ;
}

SpillData::SpillData() : 
  spill_id(0), spill_id_cntr(0), run_id(0), targ_pos(0), 
  bos_coda_id(0), bos_vme_time(0), eos_coda_id(0), eos_vme_time(0), 
  n_bos_spill(0), n_eos_spill(0), n_slow(0), n_scaler(0)
{
  ;
}

////////////////////////////////////////////////////////////////
//
// Event Data
//

HitData::HitData() :
  event(0), id(0), roc(0), board(0), chan(0), det(0), ele(0), time(0)
{
  ;
}

EventInfo::EventInfo() :
  eventID(0), codaEventID(0), runID(0), spillID(0), 
  dataQuality(0), vmeTime(0), trigger_bits(0),
  qieFlag(0), triggerCount(0), turnOnset(0), rfOnset(0)
{
    memset(RawMATRIX     , 0, sizeof(RawMATRIX     ));
    memset(AfterInhMATRIX, 0, sizeof(AfterInhMATRIX));
    memset(NIM           , 0, sizeof(NIM           ));
    memset(MATRIX        , 0, sizeof(MATRIX        ));
    memset(sums          , 0, sizeof(sums          ));
    memset(rf            , 0, sizeof(rf            ));
}

EventData::EventData() : 
  n_qie(0), n_v1495(0), n_tdc(0), n_trig_b(0), n_trig_c(0)
{
  ;
}

