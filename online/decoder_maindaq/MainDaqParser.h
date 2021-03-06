#ifndef _MAIN_DAQ_PARSER_H_
#define _MAIN_DAQ_PARSER_H_
#include "DecoData.h"
#include "DecoParam.h"
class CodaInputManager;

class MainDaqParser {
  static const int file_size_min = 32768;
  static const int sec_wait      = 15;
  static const int n_wait        = 40;

  CodaInputManager* coda;

  /// Variables for data storage
  RunData run_data;
  SpillDataMap* list_sd;
  EventDataMap* list_ed;
  
  SpillData   * sd_now; //< Contain the spill info of the current spill
  EventDataMap* list_ed_now; //< Contain the event info only in the current spill

/** Error flags to be inserted to the "Event.dataQuality" field.
 * We should add more types.
 * Ref: https://cdcvs.fnal.gov/redmine/projects/seaquest-production/wiki/Data_Quality_in_our_Productions
 */
  typedef enum { 
    EVT_ERR_N_TDC     = 0x001, // No or extra TDC-board info
    EVT_ERR_V1495     = 0x002, // v1495 Readout Problem, i.e. 0xD1AD, 0xD2AD 0xD3AD issues.
    EVT_ERR_N_V1495_0 = 0x004, // No    v1495 info
    EVT_ERR_N_V1495_2 = 0x008, // Extra v1495 info
    EVT_ERR_N_TRIGB_0 = 0x010, // No    trigger-bit info
    EVT_ERR_N_TRIGB_2 = 0x020, // Extra trigger-bit info
    EVT_ERR_N_TRIGC_0 = 0x040, // No    trigger-count info
    EVT_ERR_N_TRIGC_2 = 0x080, // Extra trigger-count info
    EVT_ERR_N_QIE_0   = 0x100, // No    QIE info
    EVT_ERR_N_QIE_2   = 0x200  // Extra QIE info
    //EVT_ERR_ID    = 0x20  // Event-ID mismatch between ROCs.
    // 0x00000800...0x20000000 ... Taiwan-TDC readout error on bit_number=roc_ID where roc_ID=12...30.
  } EventErrorFlag_t;
  
  // Handlers of CODA Event
  int ProcessCodaPrestart   (int* words);
  int ProcessCodaFee        (int* words);
  int ProcessCodaFeeBoard   (int* words);
  int ProcessCodaFeePrescale(int* words);
  int ProcessCodaPhysics    (int* words);

  // Handlers of CODA PHYSICS Event
  int ProcessPhysRunDesc     (int* words);
  int ProcessPhysPrestart    (int* words);
  int ProcessPhysSlow        (int* words);
  int ProcessPhysSpillCounter(int* words);
  int ProcessPhysBOSEOS      (int* words, const int type);
  int ProcessPhysFlush       (int* words);

  // Handlers of Board data in flush event
  int ProcessBoardData        (int* words, int idx, int idx_roc_end, int e906flag);
  int ProcessBoardScaler      (int* words, int j);
  int ProcessBoardTriggerBit  (int* words, int j);
  int ProcessBoardTriggerCount(int* words, int j);
  int ProcessBoardFeeQIE      (int* words, int j);
  int ProcessBoardV1495TDC    (int* words, int idx);
  int ProcessBoardJyTDC2      (int* words, int idx_begin, int idx_roc_end);

  int PackOneSpillData();
  int ParseOneSpill();
  void SetEventInfo(EventInfo* evt, const int eventID);

public:
  typedef enum {
    TYPE_BOS = 1,
    TYPE_EOS = 2
  } SpillType_t;

  MainDaqParser();
  ~MainDaqParser();

  int OpenCodaFile(const std::string fname, const int file_size_min=32768, const int sec_wait=15, const int n_wait=40);
  bool NextPhysicsEvent(EventData*& ed, SpillData*& sd, RunData*& rd);
  int End();

  DecoParam dec_par;
};

#endif // _MAIN_DAQ_PARSER_H_
