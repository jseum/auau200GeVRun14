#ifndef StPicoNpeHists__h
#define StPicoNpeHists__h

/* **************************************************
 *  A class to create and save Npe production QA
 *  histograms.
 *
 *  Authors:  **Kunsu OH        (kunsuoh@gmail.com)
 *            Mustafa Mustafa (mmustafa@lbl.gov)
 *
 *  **Code Maintainer
 * **************************************************
 */

#include "TObject.h"

class TH1F;
class TH2F;
class TFile;
class TString;
class StPicoPrescales;
class StPicoTrack;
class StPicoEvent;
class StPicoNpeEvent;
class StElectronPair;


class StPicoNpeHists: public TObject
{
 public:
  StPicoNpeHists(TString fileBaseName);
  virtual ~StPicoNpeHists();
  void addEvent(StPicoEvent const &, StPicoNpeEvent const &,unsigned int const nHftTracks);
  void addEventCutQa(StPicoEvent const*, int type);
  void fill1dHist(int type, float value);
  void fill2dHist(int type, float xValue, float yValue);
  void addElectronPair(StElectronPair const*, float electronPt, bool fillMass);
  void closeFile();

 private:
  StPicoNpeHists(){}

  StPicoPrescales* mPrescales;
  TFile* mOutFile;
  TH1F* mh1TotalEventsInRun;
  TH1F* mh1TotalHftTracksInRun;
  TH1F* mh1TotalGRefMultInRun;

  TH1F* mh1TotalElectronsInRun;
  TH1F* mh1TotalPartnersInRun;
  TH1F* mh1TotalPhECandidatesInRun;

  // Event cut QA plots
  TH1F* mh1QaEventCutTpcVz_raw;
  TH1F* mh1QaEventCutTpcVz_cut;
  TH1F* mh1QaEventCutTpcVz_fin;

  TH1F* mh1QaEventCutVpdVz_raw;
  TH1F* mh1QaEventCutVpdVz_cut;
  TH1F* mh1QaEventCutVpdVz_fin;

  TH1F* mh1QaEventCutDffVz_raw;
  TH1F* mh1QaEventCutDffVz_cut;
  TH1F* mh1QaEventCutDffVz_fin;

  TH2F* mh2QaEventCutTpcVzVsVpdVz_raw;
  TH2F* mh2QaEventCutTpcVzVsVpdVz_cut;
  TH2F* mh2QaEventCutTpcVzVsVpdVz_fin;
  // Event cut QA plots end

  TH2F* mh2NElectronsVsNPartners;
  TH2F* mh2PairDcaVsPt;
  TH2F* mh2InvariantMassVsPt;
  TH2F* mh2ConversionPosition;
    
  TH2F* mh2PairDcaVsPtQaCut;
  TH2F* mh2InvariantMassVsPtQaCut;
  TH2F* mh2ConversionPositionQaCut;
    
  ClassDef(StPicoNpeHists, 2)
    };
#endif
