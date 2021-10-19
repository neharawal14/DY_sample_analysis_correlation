//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 22 10:00:04 2021 by ROOT version 6.24/04
// from TTree passedEvents/passedEvents
// found on file: DY_2018.root
//////////////////////////////////////////////////////////

#ifndef DY_2018_macro_h
#define DY_2018_macro_h
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooHistPdf.h"
#include "RooPolynomial.h"
#include "RooAbsArg.h"
#include "RooPlot.h"

#include "RooAddPdf.h"
#include "RooFitResult.h"
#include "TAxis.h"
#include "TH1.h"
using namespace RooFit ;
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DY_2018_macro {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        GENmass2l;
   Double_t        genLep_pt1;
   Double_t        genLep_pt2;
   Double_t        genLep_eta1;
   Double_t        genLep_eta2;
   Double_t        genLep_phi1;
   Double_t        genLep_phi2;
   Int_t           NInt;
   Int_t           NVtx;
   Double_t        PvX;
   Double_t        PvY;
   Double_t        PvZ;
   Double_t        BsX;
   Double_t        BsY;
   Double_t        BsZ;
   Double_t        massZ;
   Double_t        massZErr;
   Double_t        massZ_FSR;
   Double_t        massZErr_FSR;
   Double_t        massZ_single_BS;
   Double_t        massZ_vtx;
   Double_t        massZ_vtx_FSR;
   Double_t        massZErr_vtx;
   Double_t        massZErr_vtx_FSR;
   Double_t        massZ_vtxChi2;
   Double_t        massZ_vtx_BS;
   Double_t        massZ_vtx_BS_FSR;
   Double_t        massZErr_vtx_BS;
   Double_t        massZErr_vtx_BS_FSR;
   Double_t        massZ_vtxChi2_BS;
   Double_t        PvX1;
   Double_t        PvX2;
   Double_t        PvY1;
   Double_t        PvY2;
   Double_t        PvZ1;
   Double_t        PvZ2;
   Double_t        BsX1;
   Double_t        BsX2;
   Double_t        BsY1;
   Double_t        BsY2;
   Double_t        BsZ1;
   Double_t        BsZ2;
   Double_t        muonPV_x1;
   Double_t        muonPV_y1;
   Double_t        muonPV_z1;
   Double_t        muonPV_x2;
   Double_t        muonPV_y2;
   Double_t        muonPV_z2;
   Double_t        pT1_FromMuonBestTrack;
   Double_t        pT2_FromMuonBestTrack;
   Double_t        eta1_FromMuonBestTrack;
   Double_t        eta2_FromMuonBestTrack;
   Double_t        phi1_FromMuonBestTrack;
   Double_t        phi2_FromMuonBestTrack;
   Double_t        pT1_genFromReco;
   Double_t        pT2_genFromReco;
   Double_t        pT1;
   Double_t        pT2;
   Double_t        eta1;
   Double_t        eta2;
   Double_t        phi1;
   Double_t        phi2;
   Double_t        m1;
   Double_t        m2;
   Double_t        pT_FSR1;
   Double_t        pT_FSR2;
   Double_t        eta_FSR1;
   Double_t        eta_FSR2;
   Double_t        phi_FSR1;
   Double_t        phi_FSR2;
   Double_t        m_FSR1;
   Double_t        m_FSR2;
   Double_t        Tracker1;
   Double_t        Tracker2;
   Double_t        single_BS_pT1;
   Double_t        single_BS_pT2;
   Double_t        single_BS_eta1;
   Double_t        single_BS_eta2;
   Double_t        single_BS_phi1;
   Double_t        single_BS_phi2;
   Double_t        single_BS_m1;
   Double_t        single_BS_m2;
   Double_t        vtx_pT1;
   Double_t        vtx_pT2;
   Double_t        vtx_eta1;
   Double_t        vtx_eta2;
   Double_t        vtx_phi1;
   Double_t        vtx_phi2;
   Double_t        vtx_m1;
   Double_t        vtx_m2;
   Double_t        vtx_BS_pT1;
   Double_t        vtx_BS_pT2;
   Double_t        vtx_BS_eta1;
   Double_t        vtx_BS_eta2;
   Double_t        vtx_BS_phi1;
   Double_t        vtx_BS_phi2;
   Double_t        vtx_BS_m1;
   Double_t        vtx_BS_m2;
   Double_t        vtx_pT_FSR1;
   Double_t        vtx_pT_FSR2;
   Double_t        vtx_eta_FSR1;
   Double_t        vtx_eta_FSR2;
   Double_t        vtx_phi_FSR1;
   Double_t        vtx_phi_FSR2;
   Double_t        vtx_m_FSR1;
   Double_t        vtx_m_FSR2;
   Double_t        vtx_BS_pT_FSR1;
   Double_t        vtx_BS_pT_FSR2;
   Double_t        vtx_BS_eta_FSR1;
   Double_t        vtx_BS_eta_FSR2;
   Double_t        vtx_BS_phi_FSR1;
   Double_t        vtx_BS_phi_FSR2;
   Double_t        vtx_BS_m_FSR1;
   Double_t        vtx_BS_m_FSR2;
   Double_t        d0BS1;
   Double_t        d0BS2;
   Double_t        d0BS_vtx_BS1;
   Double_t        d0BS_vtx_BS2;
   Int_t           Id1;
   Int_t           Id2;
   Double_t        pterr1;
   Double_t        pterr2;
   Double_t        pterr1_VX;
   Double_t        pterr2_VX;
   Double_t        pterr1_VX_BS;
   Double_t        pterr2_VX_BS;
   Double_t        weight;
   Int_t           nFSRPhotons;

   // List of branches
   TBranch        *b_GENmass2l;   //!
   TBranch        *b_genLep_pt1;   //!
   TBranch        *b_genLep_pt2;   //!
   TBranch        *b_genLep_eta1;   //!
   TBranch        *b_genLep_eta2;   //!
   TBranch        *b_genLep_phi1;   //!
   TBranch        *b_genLep_phi2;   //!
   TBranch        *b_NInt;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_PvX;   //!
   TBranch        *b_PvY;   //!
   TBranch        *b_PvZ;   //!
   TBranch        *b_BsX;   //!
   TBranch        *b_BsY;   //!
   TBranch        *b_BsZ;   //!
   TBranch        *b_massZ;   //!
   TBranch        *b_massZErr;   //!
   TBranch        *b_massZ_FSR;   //!
   TBranch        *b_massZErr_FSR;   //!
   TBranch        *b_massZ_single_BS;   //!
   TBranch        *b_massZ_vtx;   //!
   TBranch        *b_massZ_vtx_FSR;   //!
   TBranch        *b_massZErr_vtx;   //!
   TBranch        *b_massZErr_vtx_FSR;   //!
   TBranch        *b_massZ_vtxChi2;   //!
   TBranch        *b_massZ_vtx_BS;   //!
   TBranch        *b_massZ_vtx_BS_FSR;   //!
   TBranch        *b_massZErr_vtx_BS;   //!
   TBranch        *b_massZErr_vtx_BS_FSR;   //!
   TBranch        *b_massZ_vtxChi2_BS;   //!
   TBranch        *b_PvX1;   //!
   TBranch        *b_PvX2;   //!
   TBranch        *b_PvY1;   //!
   TBranch        *b_PvY2;   //!
   TBranch        *b_PvZ1;   //!
   TBranch        *b_PvZ2;   //!
   TBranch        *b_BsX1;   //!
   TBranch        *b_BsX2;   //!
   TBranch        *b_BsY1;   //!
   TBranch        *b_BsY2;   //!
   TBranch        *b_BsZ1;   //!
   TBranch        *b_BsZ2;   //!
   TBranch        *b_muonPV_x1;   //!
   TBranch        *b_muonPV_y1;   //!
   TBranch        *b_muonPV_z1;   //!
   TBranch        *b_muonPV_x2;   //!
   TBranch        *b_muonPV_y2;   //!
   TBranch        *b_muonPV_z2;   //!
   TBranch        *b_pT1_FromMuonBestTrack;   //!
   TBranch        *b_pT2_FromMuonBestTrack;   //!
   TBranch        *b_eta1_FromMuonBestTrack;   //!
   TBranch        *b_eta2_FromMuonBestTrack;   //!
   TBranch        *b_phi1_FromMuonBestTrack;   //!
   TBranch        *b_phi2_FromMuonBestTrack;   //!
   TBranch        *b_pT1_genFromReco;   //!
   TBranch        *b_pT2_genFromReco;   //!
   TBranch        *b_pT1;   //!
   TBranch        *b_pT2;   //!
   TBranch        *b_eta1;   //!
   TBranch        *b_eta2;   //!
   TBranch        *b_phi1;   //!
   TBranch        *b_phi2;   //!
   TBranch        *b_m1;   //!
   TBranch        *b_m2;   //!
   TBranch        *b_pT_FSR1;   //!
   TBranch        *b_pT_FSR2;   //!
   TBranch        *b_eta_FSR1;   //!
   TBranch        *b_eta_FSR2;   //!
   TBranch        *b_phi_FSR1;   //!
   TBranch        *b_phi_FSR2;   //!
   TBranch        *b_m_FSR1;   //!
   TBranch        *b_m_FSR2;   //!
   TBranch        *b_Tracker1;   //!
   TBranch        *b_Tracker2;   //!
   TBranch        *b_single_BS_pT1;   //!
   TBranch        *b_single_BS_pT2;   //!
   TBranch        *b_single_BS_eta1;   //!
   TBranch        *b_single_BS_eta2;   //!
   TBranch        *b_single_BS_phi1;   //!
   TBranch        *b_single_BS_phi2;   //!
   TBranch        *b_single_BS_m1;   //!
   TBranch        *b_single_BS_m2;   //!
   TBranch        *b_vtx_pT1;   //!
   TBranch        *b_vtx_pT2;   //!
   TBranch        *b_vtx_eta1;   //!
   TBranch        *b_vtx_eta2;   //!
   TBranch        *b_vtx_phi1;   //!
   TBranch        *b_vtx_phi2;   //!
   TBranch        *b_vtx_m1;   //!
   TBranch        *b_vtx_m2;   //!
   TBranch        *b_vtx_BS_pT1;   //!
   TBranch        *b_vtx_BS_pT2;   //!
   TBranch        *b_vtx_BS_eta1;   //!
   TBranch        *b_vtx_BS_eta2;   //!
   TBranch        *b_vtx_BS_phi1;   //!
   TBranch        *b_vtx_BS_phi2;   //!
   TBranch        *b_vtx_BS_m1;   //!
   TBranch        *b_vtx_BS_m2;   //!
   TBranch        *b_vtx_pT_FSR1;   //!
   TBranch        *b_vtx_pT_FSR2;   //!
   TBranch        *b_vtx_eta_FSR1;   //!
   TBranch        *b_vtx_eta_FSR2;   //!
   TBranch        *b_vtx_phi_FSR1;   //!
   TBranch        *b_vtx_phi_FSR2;   //!
   TBranch        *b_vtx_m_FSR1;   //!
   TBranch        *b_vtx_m_FSR2;   //!
   TBranch        *b_vtx_BS_pT_FSR1;   //!
   TBranch        *b_vtx_BS_pT_FSR2;   //!
   TBranch        *b_vtx_BS_eta_FSR1;   //!
   TBranch        *b_vtx_BS_eta_FSR2;   //!
   TBranch        *b_vtx_BS_phi_FSR1;   //!
   TBranch        *b_vtx_BS_phi_FSR2;   //!
   TBranch        *b_vtx_BS_m_FSR1;   //!
   TBranch        *b_vtx_BS_m_FSR2;   //!
   TBranch        *b_d0BS1;   //!
   TBranch        *b_d0BS2;   //!
   TBranch        *b_d0BS_vtx_BS1;   //!
   TBranch        *b_d0BS_vtx_BS2;   //!
   TBranch        *b_Id1;   //!
   TBranch        *b_Id2;   //!
   TBranch        *b_pterr1;   //!
   TBranch        *b_pterr2;   //!
   TBranch        *b_pterr1_VX;   //!
   TBranch        *b_pterr2_VX;   //!
   TBranch        *b_pterr1_VX_BS;   //!
   TBranch        *b_pterr2_VX_BS;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_nFSRPhotons;   //!

   DY_2018_macro(TTree *tree=0);
   virtual ~DY_2018_macro();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   // classes  and varaibles declared further apart from base macro
  

   public:
    // variables
    double pi = TMath::Pi();    
    bool debug_base = false;
    bool analyze_pT = false;
    bool analyze_eta = true;
    bool analyze_phi = false;

    TString saving_path = "/afs/cern.ch/user/n/nrawal/work/DY_analysis/plots/plots_eta/";
    double pT_list[10] = {7.5,22.5,35,45,55,65,82.5,100,120,165};
    double eta_list[8] = {0.3,0.9,1.5,2.1,-2.1,-1.5,-0.9,-0.3}; 
    double phi_list[8] = {pi/8,3*pi/8,5*pi/8,7*pi/8,9*pi/8,11*pi/8,13*pi/8,15*pi/8}; 
    std::pair<double,double> mean_sigma_Zmass;
    std::pair<double,double> mean_sigma_positive[10];
    std::pair<double,double> mean_sigma_positive_phi[8];
    std::pair<double,double> mean_sigma_positive_eta[8];
    std::pair<double,double> mean_sigma_negative[10];
    std::pair<double,double> mean_sigma_negative_phi[8];
    std::pair<double,double> mean_sigma_negative_eta[8];
    double mean_positive[10];
    double sigma_positive[10];
    double sigma_positive_eta[8];
     double mean_positive_eta[8];
    double mean_positive_phi[8];
     double mean_negative[10];
    double sigma_negative[10];
    double sigma_negative_eta[8];
    double mean_negative_eta[8];
    double mean_negative_phi[8];
    double sigma_negative_phi[8];
    double sigma_positive_phi[8];
    TH1D * hist_Zmass_positive_1stbin = new TH1D("hist_Zmass_positive_1stbin"," Gen Z mass for  #mu^{+} between 0 and 15 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_2ndbin = new TH1D("hist_Zmass_positive_2ndbin"," Gen Z mass for  #mu^{+} between 15 and 30 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_3rdbin = new TH1D("hist_Zmass_positive_3rdbin"," Gen Z mass for  #mu^{+} between 30 and 40 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_4thbin = new TH1D("hist_Zmass_positive_4thbin"," Gen Z mass for  #mu^{+} between 40 and 50 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_5thbin = new TH1D("hist_Zmass_positive_5thbin"," Gen Z mass for  #mu^{+} between 50 and 60 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_6thbin = new TH1D("hist_Zmass_positive_6thbin"," Gen Z mass for  #mu^{+} between 60 and 75 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_7thbin = new TH1D("hist_Zmass_positive_7thbin"," Gen Z mass for  #mu^{+} between 75 and 90 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_8thbin = new TH1D("hist_Zmass_positive_8thbin"," Gen Z mass for  #mu^{+} between 90 and 110 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_9thbin = new TH1D("hist_Zmass_positive_9thbin"," Gen Z mass for  #mu^{+} between 110 and 130 GeV",300,60,120); 
    TH1D * hist_Zmass_positive_10thbin = new TH1D("hist_Zmass_positive_10thbin"," Gen Z mass for  #mu^{+} between 130 and 200 GeV",300,60,120); 

   TH1D * hist_Zmass_negative_1stbin = new TH1D("hist_Zmass_negative_1stbin"," Gen Z mass for  #mu^{-} between 0 and 15 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_2ndbin = new TH1D("hist_Zmass_negative_2ndbin"," Gen Z mass for  #mu^{-} between 15 and 30 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_3rdbin = new TH1D("hist_Zmass_negative_3rdbin"," Gen Z mass for  #mu^{-} between 30 and 40 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_4thbin = new TH1D("hist_Zmass_negative_4thbin"," Gen Z mass for  #mu^{-} between 40 and 50 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_5thbin = new TH1D("hist_Zmass_negative_5thbin"," Gen Z mass for  #mu^{-} between 50 and 60 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_6thbin = new TH1D("hist_Zmass_negative_6thbin"," Gen Z mass for  #mu^{-} between 60 and 75 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_7thbin = new TH1D("hist_Zmass_negative_7thbin"," Gen Z mass for  #mu^{-} between 75 and 90 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_8thbin = new TH1D("hist_Zmass_negative_8thbin"," Gen Z mass for  #mu^{-} between 90 and 110 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_9thbin = new TH1D("hist_Zmass_negative_9thbin"," Gen Z mass for  #mu^{-} between 110 and 130 GeV",300,60,120); 
    TH1D * hist_Zmass_negative_10thbin = new TH1D("hist_Zmass_negative_10thbin"," Gen Z mass for  #mu^{-} between 130 and 200 GeV",300,60,120); 

    TH1D * hist_Zmass_negative_1st_etabin = new TH1D("hist_Zmass_negative_1st_etabin"," Gen Z mass for 0 #leq #eta < 0.6",300,60,120); 
    TH1D * hist_Zmass_negative_2nd_etabin = new TH1D("hist_Zmass_negative_2nd_etabin"," Gen Z mass for 0.6 #leq #eta < 1.2",300,60,120); 
    TH1D * hist_Zmass_negative_3rd_etabin = new TH1D("hist_Zmass_negative_3rd_etabin"," Gen Z mass for 1.2 #leq #eta < 1.8",300,60,120); 
    TH1D * hist_Zmass_negative_4th_etabin = new TH1D("hist_Zmass_negative_4th_etabin"," Gen Z mass for 1.8 #leq #eta #leq 2.4",300,60,120); 
    TH1D * hist_Zmass_negative_5th_etabin = new TH1D("hist_Zmass_negative_5th_etabin"," Gen Z mass for -2.4 #leq #eta < -1.8",300,60,120); 
    TH1D * hist_Zmass_negative_6th_etabin = new TH1D("hist_Zmass_negative_6th_etabin"," Gen Z mass for -1.8 #leq #eta < -1.2",300,60,120); 
    TH1D * hist_Zmass_negative_7th_etabin = new TH1D("hist_Zmass_negative_7th_etabin"," Gen Z mass for -1.2 #leq #eta < -0.6",300,60,120); 
    TH1D * hist_Zmass_negative_8th_etabin = new TH1D("hist_Zmass_negative_8th_etabin"," Gen Z mass for -0.6 #leq #eta < 0",300,60,120); 

    TH1D * hist_Zmass_positive_1st_etabin = new TH1D("hist_Zmass_positive_1st_etabin"," Gen Z mass for 0 #leq #eta < 0.6",300,60,120); 
    TH1D * hist_Zmass_positive_2nd_etabin = new TH1D("hist_Zmass_positive_2nd_etabin"," Gen Z mass for 0.6 #leq #eta < 1.2",300,60,120); 
    TH1D * hist_Zmass_positive_3rd_etabin = new TH1D("hist_Zmass_positive_3rd_etabin"," Gen Z mass for 1.2 #leq #eta < 1.8",300,60,120); 
    TH1D * hist_Zmass_positive_4th_etabin = new TH1D("hist_Zmass_positive_4th_etabin"," Gen Z mass for 1.8 #leq #eta #leq 2.4",300,60,120); 
    TH1D * hist_Zmass_positive_5th_etabin = new TH1D("hist_Zmass_positive_5th_etabin"," Gen Z mass for -2.4 #leq #eta < -1.8",300,60,120); 
    TH1D * hist_Zmass_positive_6th_etabin = new TH1D("hist_Zmass_positive_6th_etabin"," Gen Z mass for -1.8 #leq #eta < -1.2",300,60,120); 
    TH1D * hist_Zmass_positive_7th_etabin = new TH1D("hist_Zmass_positive_7th_etabin"," Gen Z mass for -1.2 #leq #eta < -0.6",300,60,120); 
    TH1D * hist_Zmass_positive_8th_etabin = new TH1D("hist_Zmass_positive_8th_etabin"," Gen Z mass for -0.6 #leq #eta < 0",300,60,120); 

    TH1D * hist_Zmass_negative_1st_phibin = new TH1D("hist_Zmass_negative_1st_phibin"," Gen Z mass for 0 #leq #phi < 0.6",300,60,120); 
    TH1D * hist_Zmass_negative_2nd_phibin = new TH1D("hist_Zmass_negative_2nd_phibin"," Gen Z mass for 0.6 #leq #phi < 1.2",300,60,120); 
    TH1D * hist_Zmass_negative_3rd_phibin = new TH1D("hist_Zmass_negative_3rd_phibin"," Gen Z mass for 1.2 #leq #phi < 1.8",300,60,120); 
    TH1D * hist_Zmass_negative_4th_phibin = new TH1D("hist_Zmass_negative_4th_phibin"," Gen Z mass for 1.8 #leq #phi #leq 2.4",300,60,120); 
    TH1D * hist_Zmass_negative_5th_phibin = new TH1D("hist_Zmass_negative_5th_phibin"," Gen Z mass for -2.4 #leq #phi < -1.8",300,60,120); 
    TH1D * hist_Zmass_negative_6th_phibin = new TH1D("hist_Zmass_negative_6th_phibin"," Gen Z mass for -1.8 #leq #phi < -1.2",300,60,120); 
    TH1D * hist_Zmass_negative_7th_phibin = new TH1D("hist_Zmass_negative_7th_phibin"," Gen Z mass for -1.2 #leq #phi < -0.6",300,60,120); 
    TH1D * hist_Zmass_negative_8th_phibin = new TH1D("hist_Zmass_negative_8th_phibin"," Gen Z mass for -0.6 #leq #phi < 0",300,60,120); 

    TH1D * hist_Zmass_positive_1st_phibin = new TH1D("hist_Zmass_positive_1st_phibin"," Gen Z mass for 0 #leq #phi < 0.6",300,60,120); 
    TH1D * hist_Zmass_positive_2nd_phibin = new TH1D("hist_Zmass_positive_2nd_phibin"," Gen Z mass for 0.6 #leq #phi < 1.2",300,60,120); 
    TH1D * hist_Zmass_positive_3rd_phibin = new TH1D("hist_Zmass_positive_3rd_phibin"," Gen Z mass for 1.2 #leq #phi < 1.8",300,60,120); 
    TH1D * hist_Zmass_positive_4th_phibin = new TH1D("hist_Zmass_positive_4th_phibin"," Gen Z mass for 1.8 #leq #phi #leq 2.4",300,60,120); 
    TH1D * hist_Zmass_positive_5th_phibin = new TH1D("hist_Zmass_positive_5th_phibin"," Gen Z mass for -2.4 #leq #phi < -1.8",300,60,120); 
    TH1D * hist_Zmass_positive_6th_phibin = new TH1D("hist_Zmass_positive_6th_phibin"," Gen Z mass for -1.8 #leq #phi < -1.2",300,60,120); 
    TH1D * hist_Zmass_positive_7th_phibin = new TH1D("hist_Zmass_positive_7th_phibin"," Gen Z mass for -1.2 #leq #phi < -0.6",300,60,120); 
    TH1D * hist_Zmass_positive_8th_phibin = new TH1D("hist_Zmass_positive_8th_phibin"," Gen Z mass for -0.6 #leq #phi < 0",300,60,120); 



    TH1D * hist_gen_pT1 = new TH1D("hist_gen_pT1", " Gen pT of first lepton " , 400,0,200);
    TH1D * hist_gen_pT2 = new TH1D("hist_gen_pT2", " Gen pT of second lepton " , 400,0,200);
    TH1D * hist_id1 = new TH1D("hist_id1", " id  of first lepton " , 30,-15,15);
    TH1D * hist_id2 = new TH1D("hist_id2", " id  of second lepton " , 30,-15,15);
    TH1D * hist_gen_Zmass = new TH1D("hist_gen_Zmass"," Gen Z mass",300,60,120); 
    
    TH1D * hist_gen_positive_mu = new TH1D("hist_gen_positive_mu", " Gen pT (#mu^{+}) " , 400,0,200);
    TH1D * hist_id_positive_mu = new TH1D("hist_id_positive_mu", " id (#mu^{+}) " , 15,0,15);
   
    TH1D * hist_gen_negative_mu = new TH1D("hist_gen_negative_mu", " Gen pT (#mu^{-}) " , 400,0,200);
    TH1D * hist_id_negative_mu = new TH1D("hist_id_negative_mu", " id (#mu^{-}) " , 15,-15,0);
  

        // functions
    std::pair<double,double> plotting_fitting_mass_BW(TH1D* hist_fit, TString saving_name);
    std::pair<double,double> plotting_fitting_mass_DSCB(TH1D* hist_fit, TString saving_name);
    void  plotting_hist(TH1D* hist_draw, TString title, TString saving_name, TString title_name_axis); 

    void graph_mean_pT();
    void graph_mean_eta();
    void graph_mean_phi();
};


   void DY_2018_macro :: graph_mean_pT(){
   TGraphErrors *gr_positive = new TGraphErrors(10, pT_list,mean_positive, 0,sigma_positive);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_positive->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_positive->GetXaxis()->SetTitle("pT (GeV)");
   gr_positive->SetTitle("#mu^{+}");
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})");
   graph_canvas->cd(); 
   
   gr_positive->Draw("AP*");
   graph_canvas->SaveAs(saving_path+"mean_pT_mu_positive.pdf"); 
 
   TGraphErrors *gr_negative = new TGraphErrors(10, pT_list,mean_negative, 0,sigma_negative);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_negative->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_negative->GetXaxis()->SetTitle("pT (GeV)");
   gr_negative->SetTitle("#mu^{-}");
   TCanvas *graph_canvas_1 = new TCanvas("graph_canvas_1","mass(#mu^{+}#mu^{-})");
   graph_canvas_1->cd(); 
   
   gr_negative->Draw("AP*");
   graph_canvas_1->SaveAs(saving_path+"mean_pT_mu_negative.pdf"); 
  
   }

   void DY_2018_macro :: graph_mean_eta(){
   TGraphErrors *gr_positive = new TGraphErrors(8, eta_list,mean_positive_eta, 0,sigma_positive_eta);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_positive->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_positive->GetXaxis()->SetTitle("#eta");
   gr_positive->SetTitle("#mu^{+}");
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})");
   graph_canvas->cd(); 
   
   gr_positive->Draw("AP*");
   graph_canvas->SaveAs(saving_path+"mean_eta_mu_positive.pdf"); 
 
   TGraphErrors *gr_negative = new TGraphErrors(8, eta_list,mean_negative_eta, 0,sigma_negative_eta);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_negative->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_negative->GetXaxis()->SetTitle("#eta");
   gr_negative->SetTitle("#mu^{-}");
   TCanvas *graph_canvas_1 = new TCanvas("graph_canvas_1","mass(#mu^{+}#mu^{-})");
   graph_canvas_1->cd(); 
   
   gr_negative->Draw("AP*");
   graph_canvas_1->SaveAs(saving_path+"mean_eta_mu_negative.pdf"); 
  
   }

   void DY_2018_macro :: graph_mean_phi(){
   TGraphErrors *gr_positive = new TGraphErrors(8, phi_list,mean_positive_phi, 0,sigma_positive_phi);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_positive->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_positive->GetXaxis()->SetTitle("#phi");
   gr_positive->SetTitle("#mu^{+}");
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})");
   graph_canvas->cd(); 
   
   gr_positive->Draw("AP*");
   graph_canvas->SaveAs(saving_path+"mean_phi_mu_positive.pdf"); 
 
   TGraphErrors *gr_negative = new TGraphErrors(8, phi_list,mean_negative_phi, 0,sigma_negative_phi);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_negative->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_negative->GetXaxis()->SetTitle("#phi");
   gr_negative->SetTitle("#mu^{-}");
   TCanvas *graph_canvas_1 = new TCanvas("graph_canvas_1","mass(#mu^{+}#mu^{-})");
   graph_canvas_1->cd(); 
   
   gr_negative->Draw("AP*");
   graph_canvas_1->SaveAs(saving_path+"mean_phi_mu_negative.pdf"); 
  
   }

   void DY_2018_macro :: plotting_hist(TH1D * hist_draw, TString title, TString saving_name, TString title_name_axis){
    TCanvas * c = new TCanvas("c",title);
    c->cd();
    hist_draw->GetXaxis()->SetTitle(title_name_axis);
    hist_draw->Draw();
    c->SaveAs(saving_path+saving_name+".pdf");

   }

   std::pair<double,double> DY_2018_macro :: plotting_fitting_mass_BW(TH1D * hist_fit, TString saving_name){
  // Fit the mass into Breit Wigner
     TString title_name = " m(#mu^{+}  #mu^{-}) ";
     RooRealVar mass_var("mass_var","mass_var",60,120);
     RooDataHist histo("histo","mass dataset",mass_var,hist_fit);
     RooRealVar mean_mass("mean_mass","mean of Z mass",91,87,95);
     RooRealVar width("width","width of Z mass",4,0.01,10);
   
     RooPlot *xframe=mass_var.frame(Title(title_name));
     histo.plotOn(xframe);
     histo.statOn(xframe);
   
     RooBreitWigner BW("BW","Breit Wigner fit",mass_var, mean_mass,width);
     BW.fitTo(histo,Range(60,120));
    
     BW.plotOn(xframe,RooFit::LineColor(kRed+2));
    
     BW.paramOn(xframe,RooFit::Layout(0.6,0.9,0.7));
     
     TCanvas *tmp = new TCanvas("tmp","Gen Z mass", 800,400);
     tmp->cd();
     gPad->SetLeftMargin(0.15);
     xframe->getAttText()->SetTextSize(0.025);
     xframe->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}}");
     
     xframe->GetYaxis()->SetTitle("N/0.2 (GeV)");
     xframe->Draw();
     gStyle->SetOptStat();
     tmp->SaveAs(saving_path+ saving_name+".pdf");
    
     std::cout<<" Z mass mean : "<<mean_mass.getVal()<<" width : "<<width.getVal()<<std::endl;
     return std::make_pair(mean_mass.getVal(),mean_mass.getError());   
     }
  
   std::pair<double,double> DY_2018_macro :: plotting_fitting_mass_DSCB(TH1D * hist_fit, TString saving_name){
  // Fit the mass into DSCB
    RooRealVar m4mu("m4mu", "var", 60,120, "");
    RooDataHist histo("histo","dataset with var",m4mu,histogram);
    RooRealVar Mean("Mean", "Mean",91, 88,94);
    RooRealVar Sigma("#sigma", "#sigma", 2.88, 1, 5);//sigma[decay]);
    RooRealVar AlphaL("#alpha_{L}", "#alpha_{L}", 1, 0, 30);//alphaL[decay]);
    RooRealVar ExpL("n_{L}", "n_{L}", 1, 0, 30);//expL[decay]);
    RooRealVar AlphaR("#alpha_{R}", "#alpha_{R}", 1, 0, 30);//alphaR[decay]);
    RooRealVar ExpR("n_{R}", "n_{R}", 1, 1, 50);//expR[decay]);
    RooMyPDF_DSCB DSCB("DSCB", "DSCB", m4mu, Mean, Sigma, AlphaL, ExpL, AlphaR, ExpR);
   
    TCanvas *c_MC = new TCanvas("c_MC", "c_MC", 800, 600);
    c_MC->SetFrameFillColor(0);
    c_MC->cd();  
    TString title = "m(#mu^{+} #mu^{-})";
    RooPlot* xframe = m4mu.frame(RooFit::Title(title));
    histo.plotOn(xframe);
   
    Int_t color = kRed+2;
    Double_t size_text = 0.020;
    DSCB.fitTo(histo, Range(60,120));
    DSCB.plotOn(xframe, RooFit::LineColor(color));
    DSCB.paramOn(xframe, RooFit::Layout(0.15, 0.35, 0.90));
    xframe->getAttText()->SetTextSize(size_text);
    xframe->getAttText()->SetTextColor(color);
    xframe->GetXaxis()->SetTitle("m(#mu^{+} #mu^{-})");
    xframe->GetYaxis()->SetTitle("N/(0.2 GeV)");
    xframe->GetXaxis()->SetTitleOffset(1.4);
    gStyle->SetOptStat();
    c_MC->SaveAs(save_dir_path+ saving_name + ".pdf");
    // + ".pdf");
    
    std::cout<<" Z mass mean : "<<Mean.getVal()<<" width : "<<Sigma.getVal()<<std::endl;
    return std::make_pair(Mean.getVal(),Mean.getError());   
}
#endif

#ifdef DY_2018_macro_cxx
DY_2018_macro::DY_2018_macro(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DY_2018.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DY_2018.root");
      }
      f->GetObject("passedEvents",tree);

   }
   Init(tree);
}

DY_2018_macro::~DY_2018_macro()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DY_2018_macro::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DY_2018_macro::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DY_2018_macro::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   cout<<"started"<<endl;
   fChain->SetBranchAddress("GENmass2l", &GENmass2l, &b_GENmass2l);
   fChain->SetBranchAddress("genLep_pt1", &genLep_pt1, &b_genLep_pt1);
   fChain->SetBranchAddress("genLep_pt2", &genLep_pt2, &b_genLep_pt2);
   fChain->SetBranchAddress("genLep_eta1", &genLep_eta1, &b_genLep_eta1);
   fChain->SetBranchAddress("genLep_eta2", &genLep_eta2, &b_genLep_eta2);
   fChain->SetBranchAddress("genLep_phi1", &genLep_phi1, &b_genLep_phi1);
   fChain->SetBranchAddress("genLep_phi2", &genLep_phi2, &b_genLep_phi2);
   fChain->SetBranchAddress("NInt", &NInt, &b_NInt);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("PvX", &PvX, &b_PvX);
   fChain->SetBranchAddress("PvY", &PvY, &b_PvY);
   fChain->SetBranchAddress("PvZ", &PvZ, &b_PvZ);
   fChain->SetBranchAddress("BsX", &BsX, &b_BsX);
   fChain->SetBranchAddress("BsY", &BsY, &b_BsY);
   fChain->SetBranchAddress("BsZ", &BsZ, &b_BsZ);
   fChain->SetBranchAddress("massZ", &massZ, &b_massZ);
   fChain->SetBranchAddress("massZErr", &massZErr, &b_massZErr);
   fChain->SetBranchAddress("massZ_FSR", &massZ_FSR, &b_massZ_FSR);
   fChain->SetBranchAddress("massZErr_FSR", &massZErr_FSR, &b_massZErr_FSR);
   fChain->SetBranchAddress("massZ_single_BS", &massZ_single_BS, &b_massZ_single_BS);
   fChain->SetBranchAddress("massZ_vtx", &massZ_vtx, &b_massZ_vtx);
   fChain->SetBranchAddress("massZ_vtx_FSR", &massZ_vtx_FSR, &b_massZ_vtx_FSR);
   fChain->SetBranchAddress("massZErr_vtx", &massZErr_vtx, &b_massZErr_vtx);
   fChain->SetBranchAddress("massZErr_vtx_FSR", &massZErr_vtx_FSR, &b_massZErr_vtx_FSR);
   fChain->SetBranchAddress("massZ_vtxChi2", &massZ_vtxChi2, &b_massZ_vtxChi2);
   fChain->SetBranchAddress("massZ_vtx_BS", &massZ_vtx_BS, &b_massZ_vtx_BS);
   fChain->SetBranchAddress("massZ_vtx_BS_FSR", &massZ_vtx_BS_FSR, &b_massZ_vtx_BS_FSR);
   fChain->SetBranchAddress("massZErr_vtx_BS", &massZErr_vtx_BS, &b_massZErr_vtx_BS);
   fChain->SetBranchAddress("massZErr_vtx_BS_FSR", &massZErr_vtx_BS_FSR, &b_massZErr_vtx_BS_FSR);
   fChain->SetBranchAddress("massZ_vtxChi2_BS", &massZ_vtxChi2_BS, &b_massZ_vtxChi2_BS);
   fChain->SetBranchAddress("PvX1", &PvX1, &b_PvX1);
   fChain->SetBranchAddress("PvX2", &PvX2, &b_PvX2);
   fChain->SetBranchAddress("PvY1", &PvY1, &b_PvY1);
   fChain->SetBranchAddress("PvY2", &PvY2, &b_PvY2);
   fChain->SetBranchAddress("PvZ1", &PvZ1, &b_PvZ1);
   fChain->SetBranchAddress("PvZ2", &PvZ2, &b_PvZ2);
   fChain->SetBranchAddress("BsX1", &BsX1, &b_BsX1);
   fChain->SetBranchAddress("BsX2", &BsX2, &b_BsX2);
   fChain->SetBranchAddress("BsY1", &BsY1, &b_BsY1);
   fChain->SetBranchAddress("BsY2", &BsY2, &b_BsY2);
   fChain->SetBranchAddress("BsZ1", &BsZ1, &b_BsZ1);
   fChain->SetBranchAddress("BsZ2", &BsZ2, &b_BsZ2);
   fChain->SetBranchAddress("muonPV_x1", &muonPV_x1, &b_muonPV_x1);
   fChain->SetBranchAddress("muonPV_y1", &muonPV_y1, &b_muonPV_y1);
   fChain->SetBranchAddress("muonPV_z1", &muonPV_z1, &b_muonPV_z1);
   fChain->SetBranchAddress("muonPV_x2", &muonPV_x2, &b_muonPV_x2);
   fChain->SetBranchAddress("muonPV_y2", &muonPV_y2, &b_muonPV_y2);
   fChain->SetBranchAddress("muonPV_z2", &muonPV_z2, &b_muonPV_z2);
   fChain->SetBranchAddress("pT1_FromMuonBestTrack", &pT1_FromMuonBestTrack, &b_pT1_FromMuonBestTrack);
   fChain->SetBranchAddress("pT2_FromMuonBestTrack", &pT2_FromMuonBestTrack, &b_pT2_FromMuonBestTrack);
   fChain->SetBranchAddress("eta1_FromMuonBestTrack", &eta1_FromMuonBestTrack, &b_eta1_FromMuonBestTrack);
   fChain->SetBranchAddress("eta2_FromMuonBestTrack", &eta2_FromMuonBestTrack, &b_eta2_FromMuonBestTrack);
   fChain->SetBranchAddress("phi1_FromMuonBestTrack", &phi1_FromMuonBestTrack, &b_phi1_FromMuonBestTrack);
   fChain->SetBranchAddress("phi2_FromMuonBestTrack", &phi2_FromMuonBestTrack, &b_phi2_FromMuonBestTrack);
   fChain->SetBranchAddress("pT1_genFromReco", &pT1_genFromReco, &b_pT1_genFromReco);
   fChain->SetBranchAddress("pT2_genFromReco", &pT2_genFromReco, &b_pT2_genFromReco);
   fChain->SetBranchAddress("pT1", &pT1, &b_pT1);
   fChain->SetBranchAddress("pT2", &pT2, &b_pT2);
   fChain->SetBranchAddress("eta1", &eta1, &b_eta1);
   fChain->SetBranchAddress("eta2", &eta2, &b_eta2);
   fChain->SetBranchAddress("phi1", &phi1, &b_phi1);
   fChain->SetBranchAddress("phi2", &phi2, &b_phi2);
   fChain->SetBranchAddress("m1", &m1, &b_m1);
   fChain->SetBranchAddress("m2", &m2, &b_m2);
   fChain->SetBranchAddress("pT_FSR1", &pT_FSR1, &b_pT_FSR1);
   fChain->SetBranchAddress("pT_FSR2", &pT_FSR2, &b_pT_FSR2);
   fChain->SetBranchAddress("eta_FSR1", &eta_FSR1, &b_eta_FSR1);
   fChain->SetBranchAddress("eta_FSR2", &eta_FSR2, &b_eta_FSR2);
   fChain->SetBranchAddress("phi_FSR1", &phi_FSR1, &b_phi_FSR1);
   fChain->SetBranchAddress("phi_FSR2", &phi_FSR2, &b_phi_FSR2);
   fChain->SetBranchAddress("m_FSR1", &m_FSR1, &b_m_FSR1);
   fChain->SetBranchAddress("m_FSR2", &m_FSR2, &b_m_FSR2);
   fChain->SetBranchAddress("Tracker1", &Tracker1, &b_Tracker1);
   fChain->SetBranchAddress("Tracker2", &Tracker2, &b_Tracker2);
   fChain->SetBranchAddress("single_BS_pT1", &single_BS_pT1, &b_single_BS_pT1);
   fChain->SetBranchAddress("single_BS_pT2", &single_BS_pT2, &b_single_BS_pT2);
   fChain->SetBranchAddress("single_BS_eta1", &single_BS_eta1, &b_single_BS_eta1);
   fChain->SetBranchAddress("single_BS_eta2", &single_BS_eta2, &b_single_BS_eta2);
   fChain->SetBranchAddress("single_BS_phi1", &single_BS_phi1, &b_single_BS_phi1);
   fChain->SetBranchAddress("single_BS_phi2", &single_BS_phi2, &b_single_BS_phi2);
   fChain->SetBranchAddress("single_BS_m1", &single_BS_m1, &b_single_BS_m1);
   fChain->SetBranchAddress("single_BS_m2", &single_BS_m2, &b_single_BS_m2);
   fChain->SetBranchAddress("vtx_pT1", &vtx_pT1, &b_vtx_pT1);
   fChain->SetBranchAddress("vtx_pT2", &vtx_pT2, &b_vtx_pT2);
   fChain->SetBranchAddress("vtx_eta1", &vtx_eta1, &b_vtx_eta1);
   fChain->SetBranchAddress("vtx_eta2", &vtx_eta2, &b_vtx_eta2);
   fChain->SetBranchAddress("vtx_phi1", &vtx_phi1, &b_vtx_phi1);
   fChain->SetBranchAddress("vtx_phi2", &vtx_phi2, &b_vtx_phi2);
   fChain->SetBranchAddress("vtx_m1", &vtx_m1, &b_vtx_m1);
   fChain->SetBranchAddress("vtx_m2", &vtx_m2, &b_vtx_m2);
   fChain->SetBranchAddress("vtx_BS_pT1", &vtx_BS_pT1, &b_vtx_BS_pT1);
   fChain->SetBranchAddress("vtx_BS_pT2", &vtx_BS_pT2, &b_vtx_BS_pT2);
   fChain->SetBranchAddress("vtx_BS_eta1", &vtx_BS_eta1, &b_vtx_BS_eta1);
   fChain->SetBranchAddress("vtx_BS_eta2", &vtx_BS_eta2, &b_vtx_BS_eta2);
   fChain->SetBranchAddress("vtx_BS_phi1", &vtx_BS_phi1, &b_vtx_BS_phi1);
   fChain->SetBranchAddress("vtx_BS_phi2", &vtx_BS_phi2, &b_vtx_BS_phi2);
   fChain->SetBranchAddress("vtx_BS_m1", &vtx_BS_m1, &b_vtx_BS_m1);
   fChain->SetBranchAddress("vtx_BS_m2", &vtx_BS_m2, &b_vtx_BS_m2);
   fChain->SetBranchAddress("vtx_pT_FSR1", &vtx_pT_FSR1, &b_vtx_pT_FSR1);
   fChain->SetBranchAddress("vtx_pT_FSR2", &vtx_pT_FSR2, &b_vtx_pT_FSR2);
   fChain->SetBranchAddress("vtx_eta_FSR1", &vtx_eta_FSR1, &b_vtx_eta_FSR1);
   fChain->SetBranchAddress("vtx_eta_FSR2", &vtx_eta_FSR2, &b_vtx_eta_FSR2);
   fChain->SetBranchAddress("vtx_phi_FSR1", &vtx_phi_FSR1, &b_vtx_phi_FSR1);
   fChain->SetBranchAddress("vtx_phi_FSR2", &vtx_phi_FSR2, &b_vtx_phi_FSR2);
   fChain->SetBranchAddress("vtx_m_FSR1", &vtx_m_FSR1, &b_vtx_m_FSR1);
   fChain->SetBranchAddress("vtx_m_FSR2", &vtx_m_FSR2, &b_vtx_m_FSR2);
   fChain->SetBranchAddress("vtx_BS_pT_FSR1", &vtx_BS_pT_FSR1, &b_vtx_BS_pT_FSR1);
   fChain->SetBranchAddress("vtx_BS_pT_FSR2", &vtx_BS_pT_FSR2, &b_vtx_BS_pT_FSR2);
   fChain->SetBranchAddress("vtx_BS_eta_FSR1", &vtx_BS_eta_FSR1, &b_vtx_BS_eta_FSR1);
   fChain->SetBranchAddress("vtx_BS_eta_FSR2", &vtx_BS_eta_FSR2, &b_vtx_BS_eta_FSR2);
   fChain->SetBranchAddress("vtx_BS_phi_FSR1", &vtx_BS_phi_FSR1, &b_vtx_BS_phi_FSR1);
   fChain->SetBranchAddress("vtx_BS_phi_FSR2", &vtx_BS_phi_FSR2, &b_vtx_BS_phi_FSR2);
   fChain->SetBranchAddress("vtx_BS_m_FSR1", &vtx_BS_m_FSR1, &b_vtx_BS_m_FSR1);
   fChain->SetBranchAddress("vtx_BS_m_FSR2", &vtx_BS_m_FSR2, &b_vtx_BS_m_FSR2);
   fChain->SetBranchAddress("d0BS1", &d0BS1, &b_d0BS1);
   fChain->SetBranchAddress("d0BS2", &d0BS2, &b_d0BS2);
   fChain->SetBranchAddress("d0BS_vtx_BS1", &d0BS_vtx_BS1, &b_d0BS_vtx_BS1);
   fChain->SetBranchAddress("d0BS_vtx_BS2", &d0BS_vtx_BS2, &b_d0BS_vtx_BS2);
   fChain->SetBranchAddress("Id1", &Id1, &b_Id1);
   fChain->SetBranchAddress("Id2", &Id2, &b_Id2);
   fChain->SetBranchAddress("pterr1", &pterr1, &b_pterr1);
   fChain->SetBranchAddress("pterr2", &pterr2, &b_pterr2);
   fChain->SetBranchAddress("pterr1_VX", &pterr1_VX, &b_pterr1_VX);
   fChain->SetBranchAddress("pterr2_VX", &pterr2_VX, &b_pterr2_VX);
   fChain->SetBranchAddress("pterr1_VX_BS", &pterr1_VX_BS, &b_pterr1_VX_BS);
   fChain->SetBranchAddress("pterr2_VX_BS", &pterr2_VX_BS, &b_pterr2_VX_BS);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("nFSRPhotons", &nFSRPhotons, &b_nFSRPhotons);
   Notify();
}

Bool_t DY_2018_macro::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DY_2018_macro::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DY_2018_macro::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DY_2018_macro_cxx
