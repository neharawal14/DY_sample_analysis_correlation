#define DY_2018_macro_cxx
#include "DY_2018_macro.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
void DY_2018_macro::Loop()
{
     gROOT->SetBatch(kTRUE);
     double pi = TMath::Pi();
//   In a ROOT session, you can do:
//      root> .L DY_2018_macro.C
//      root> DY_2018_macro t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//   for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) { 
        std::cout<<"entry is breaking"<<std::endl;
                        std::cout<<"entry number "<<jentry<<std::endl; 
        break;
      }
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;


       hist_gen_pT1 ->Fill(genLep_pt1);      
       hist_gen_pT2 ->Fill(genLep_pt2);      
       hist_id1 ->Fill(Id1);      
       hist_id2 ->Fill(Id2);      
       hist_gen_Zmass ->Fill(GENmass2l);      
      // if (Cut(ientry) < 0) continue;

     // analyzing just positive muons
     // when positive muon has higher pT than negative one
      if(Id1==13)    
      {
        if(debug_base==true) { std::cout<<" positive muon has higher pT with lep_id : "<<Id1<<std::endl;
                             std::cout<<"pT positive and pT negative muon :  "<<genLep_pt1<<"  "<<genLep_pt2<<std::endl; } 

        // dividing in pT bins
       

       // if you just want to analyze pT 
       //
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_gen_negative_mu->Fill(genLep_pt2);
         hist_id_negative_mu->Fill(Id2); 


       if(analyze_pT == true){
        if(0<= genLep_pt1 && genLep_pt1 < 15) {
         hist_Zmass_positive_1stbin->Fill(GENmass2l);
         }

        if(15 <= genLep_pt1  && genLep_pt1 < 30) {
         hist_Zmass_positive_2ndbin->Fill(GENmass2l);
        }

        if( 30 <= genLep_pt1 && genLep_pt1 < 40) {
         hist_Zmass_positive_3rdbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt1 && genLep_pt1 < 50) {
         hist_Zmass_positive_4thbin->Fill(GENmass2l);
        }

        if( 50 < genLep_pt1 && genLep_pt1 < 60) {
         hist_Zmass_positive_5thbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt1  && genLep_pt1 < 75) {
         hist_Zmass_positive_6thbin->Fill(GENmass2l);
        }

        if( 75 <= genLep_pt1 && genLep_pt1 < 90) {
         hist_Zmass_positive_7thbin->Fill(GENmass2l);
        }


        if( 90 <= genLep_pt1 && genLep_pt1 < 110) {
         hist_Zmass_positive_8thbin->Fill(GENmass2l);
        }

        if( 110 <= genLep_pt1 && genLep_pt1 < 130) {
         hist_Zmass_positive_9thbin->Fill(GENmass2l);
        }
    
        if( 130 <= genLep_pt1 && genLep_pt1 < 200) {
         hist_Zmass_positive_10thbin->Fill(GENmass2l);
        }
 

       // for negative muons 
        if(0<= genLep_pt2 && genLep_pt2 < 15) {
         hist_Zmass_negative_1stbin->Fill(GENmass2l);
         }

        if(15 <= genLep_pt2  && genLep_pt2 < 30) {
         hist_Zmass_negative_2ndbin->Fill(GENmass2l);
        }

        if( 30 <= genLep_pt2 && genLep_pt2 < 40) {
         hist_Zmass_negative_3rdbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt2 && genLep_pt2 < 50) {
         hist_Zmass_negative_4thbin->Fill(GENmass2l);
        }

        if( 50 < genLep_pt2 && genLep_pt2 < 60) {
         hist_Zmass_negative_5thbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt2  && genLep_pt2 < 75) {
         hist_Zmass_negative_6thbin->Fill(GENmass2l);
        }

        if( 75 <= genLep_pt2 && genLep_pt2 < 90) {
         hist_Zmass_negative_7thbin->Fill(GENmass2l);
        }


        if( 90 <= genLep_pt2 && genLep_pt2 < 110) {
         hist_Zmass_negative_8thbin->Fill(GENmass2l);
        }

        if( 110 <= genLep_pt2 && genLep_pt2 < 130) {
         hist_Zmass_negative_9thbin->Fill(GENmass2l);
        }
    
        if( 130 <= genLep_pt2 && genLep_pt2 < 200) {
         hist_Zmass_negative_10thbin->Fill(GENmass2l);
        }
   
        // end of pT binning loop
      }

       if(analyze_eta == true) 
       // binning in eta 
       {

        if( 0 <= genLep_eta1 && genLep_eta1 < 0.6) {
         hist_Zmass_positive_1st_etabin->Fill(GENmass2l);
        }
        if( 0.6 <= genLep_eta1 && genLep_eta1 < 1.2) {
         hist_Zmass_positive_2nd_etabin->Fill(GENmass2l);
        }

        if( 1.2 <= genLep_eta1 && genLep_eta1 < 1.8) {
         hist_Zmass_positive_3rd_etabin->Fill(GENmass2l);
        }

        if( 1.8 <= genLep_eta1 && genLep_eta1 <= 2.4) {
         hist_Zmass_positive_4th_etabin->Fill(GENmass2l);
        }
        if( -2.4 <= genLep_eta1 && genLep_eta1 < -1.8) {
         hist_Zmass_positive_5th_etabin->Fill(GENmass2l);
        }
        if( -1.8 <= genLep_eta1 && genLep_eta1 < -1.2) {
         hist_Zmass_positive_6th_etabin->Fill(GENmass2l);
        }
        if( -1.2 <= genLep_eta1 && genLep_eta1 < -0.6) {
         hist_Zmass_positive_7th_etabin->Fill(GENmass2l);
        }
       if( -0.6 <= genLep_eta1 && genLep_eta1 < 0) {
         hist_Zmass_positive_8th_etabin->Fill(GENmass2l);
        }



        if( 0 <= genLep_eta2 && genLep_eta2 < 0.6) {
         hist_Zmass_negative_1st_etabin->Fill(GENmass2l);
        }
        if( 0.6 <= genLep_eta2 && genLep_eta2 < 1.2) {
         hist_Zmass_negative_2nd_etabin->Fill(GENmass2l);
        }

        if( 1.2 <= genLep_eta2 && genLep_eta2 < 1.8) {
         hist_Zmass_negative_3rd_etabin->Fill(GENmass2l);
        }

        if( 1.8 <= genLep_eta2 && genLep_eta2 <= 2.4) {
         hist_Zmass_negative_4th_etabin->Fill(GENmass2l);
        }
        if( -2.4 <= genLep_eta2 && genLep_eta2 < -1.8) {
         hist_Zmass_negative_5th_etabin->Fill(GENmass2l);
        }
        if( -1.8 <= genLep_eta2 && genLep_eta2 < -1.2) {
         hist_Zmass_negative_6th_etabin->Fill(GENmass2l);
        }
        if( -1.2 <= genLep_eta2 && genLep_eta2 < -0.6) {
         hist_Zmass_negative_7th_etabin->Fill(GENmass2l);
        }

      if( -0.6 <= genLep_eta2 && genLep_eta2 < 0) {
         hist_Zmass_negative_8th_etabin->Fill(GENmass2l);
        }

     // end of eta binning loop
       }

        if(analyze_phi == true) 
       // binning in phi 
       {

        if( 0 <= genLep_phi1 && genLep_phi1 < pi/4) {
         hist_Zmass_positive_1st_phibin->Fill(GENmass2l);
        }
        if( pi/4 <= genLep_phi1 && genLep_phi1 < pi/2) {
         hist_Zmass_positive_2nd_phibin->Fill(GENmass2l);
        }

        if( pi/2 <= genLep_phi1 && genLep_phi1 < 3*pi/4) {
         hist_Zmass_positive_3rd_phibin->Fill(GENmass2l);
        }

        if( 3*pi/4 <= genLep_phi1 && genLep_phi1 <= pi) {
         hist_Zmass_positive_4th_phibin->Fill(GENmass2l);
        }
        if( -pi/4 <= genLep_phi1 && genLep_phi1 < 0) {
         hist_Zmass_positive_5th_phibin->Fill(GENmass2l);
        }
        if( -pi/2 <= genLep_phi1 && genLep_phi1 < -pi/4) {
         hist_Zmass_positive_6th_phibin->Fill(GENmass2l);
        }
        if( -3*pi/4 <= genLep_phi1 && genLep_phi1 < -pi/2) {
         hist_Zmass_positive_7th_phibin->Fill(GENmass2l);
        }
       if( -pi <= genLep_phi1 && genLep_phi1 < -3*pi/4) {
         hist_Zmass_positive_8th_phibin->Fill(GENmass2l);
        }


        if( 0 <= genLep_phi2 && genLep_phi2 < pi/4) {
         hist_Zmass_negative_1st_phibin->Fill(GENmass2l);
        }
        if( pi/4 <= genLep_phi2 && genLep_phi2 < pi/2) {
         hist_Zmass_negative_2nd_phibin->Fill(GENmass2l);
        }

        if( pi/2 <= genLep_phi2 && genLep_phi2 < 3*pi/4) {
         hist_Zmass_negative_3rd_phibin->Fill(GENmass2l);
        }

        if( 3*pi/4 <= genLep_phi2 && genLep_phi2 <= pi) {
         hist_Zmass_negative_4th_phibin->Fill(GENmass2l);
        }
        if( -pi/4 <= genLep_phi2 && genLep_phi2 < 0) {
         hist_Zmass_negative_5th_phibin->Fill(GENmass2l);
        }
        if( -pi/2 <= genLep_phi2 && genLep_phi2 < -pi/4) {
         hist_Zmass_negative_6th_phibin->Fill(GENmass2l);
        }
        if( -3*pi/4 <= genLep_phi2 && genLep_phi2 < -pi/2) {
         hist_Zmass_negative_7th_phibin->Fill(GENmass2l);
        }
       if( -pi <= genLep_phi2 && genLep_phi2 < -3*pi/4) {
         hist_Zmass_negative_8th_phibin->Fill(GENmass2l);
        }



     // end of phi binning loop
       }

         
      //  if( genLep_pt1 >= 400)   
     //   std::cout<<" event with pT not in between 0 and 200 GeV "<<genLep_pt1<<std::endl;

     }


      // same repetition can be combined with an else statement
      // Storing positive muons with pT less than negative muons
       if(Id2==13)    
      {
         if(debug_base==true) { std::cout<<" positive muon has lower pT with lep_id : "<<Id2<<std::endl;
                                std::cout<<"pT negative and pT positive muon :  "<<genLep_pt1<<"  "<<genLep_pt2<<std::endl; } 

        // dividing in pT bins
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
 
         hist_gen_negative_mu->Fill(genLep_pt1);
         hist_id_negative_mu->Fill(Id1); 



        if(analyze_pT == true) { 
  
          if(0<= genLep_pt2 && genLep_pt2 < 15) {
         hist_Zmass_positive_1stbin->Fill(GENmass2l);
         }

        if(15 <= genLep_pt2  && genLep_pt2 < 30) {
         hist_Zmass_positive_2ndbin->Fill(GENmass2l);
        }

        if( 30 <= genLep_pt2 && genLep_pt2 < 40) {
         hist_Zmass_positive_3rdbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt2 && genLep_pt2 < 50) {
         hist_Zmass_positive_4thbin->Fill(GENmass2l);
        }

        if( 50 < genLep_pt2 && genLep_pt2 < 60) {
         hist_Zmass_positive_5thbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt2  && genLep_pt2 < 75) {
         hist_Zmass_positive_6thbin->Fill(GENmass2l);
        }

        if( 75 <= genLep_pt2 && genLep_pt2 < 90) {
         hist_Zmass_positive_7thbin->Fill(GENmass2l);
        }


        if( 90 <= genLep_pt2 && genLep_pt2 < 110) {
         hist_Zmass_positive_8thbin->Fill(GENmass2l);
        }

        if( 110 <= genLep_pt2 && genLep_pt2 < 130) {
         hist_Zmass_positive_9thbin->Fill(GENmass2l);
        }
    
        if( 130 <= genLep_pt2 && genLep_pt2 < 200) {
         hist_Zmass_positive_10thbin->Fill(GENmass2l);
        }
  
          // for negative muons 
         if(0<= genLep_pt1 && genLep_pt1 < 15) {
         hist_Zmass_negative_1stbin->Fill(GENmass2l);
         }

        if(15 <= genLep_pt1  && genLep_pt1 < 30) {
         hist_Zmass_negative_2ndbin->Fill(GENmass2l);
        }

        if( 30 <= genLep_pt1 && genLep_pt1 < 40) {
         hist_Zmass_negative_3rdbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt1 && genLep_pt1 < 50) {
         hist_Zmass_negative_4thbin->Fill(GENmass2l);
        }

        if( 50 < genLep_pt1 && genLep_pt1 < 60) {
         hist_Zmass_negative_5thbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt1  && genLep_pt1 < 75) {
         hist_Zmass_negative_6thbin->Fill(GENmass2l);
        }

        if( 75 <= genLep_pt1 && genLep_pt1 < 90) {
         hist_Zmass_negative_7thbin->Fill(GENmass2l);
        }


        if( 90 <= genLep_pt1 && genLep_pt1 < 110) {
         hist_Zmass_negative_8thbin->Fill(GENmass2l);
        }

        if( 110 <= genLep_pt1 && genLep_pt1 < 130) {
         hist_Zmass_negative_9thbin->Fill(GENmass2l);
        }
    
        if( 130 <= genLep_pt1 && genLep_pt1 < 200) {
         hist_Zmass_negative_10thbin->Fill(GENmass2l);
        }
       }
       if(analyze_eta == true) 
       // binning in eta 
       {

        if( 0 <= genLep_eta2 && genLep_eta2 < 0.6) {
         hist_Zmass_positive_1st_etabin->Fill(GENmass2l);
        }
        if( 0.6 <= genLep_eta2 && genLep_eta2 < 1.2) {
         hist_Zmass_positive_2nd_etabin->Fill(GENmass2l);
        }

        if( 1.2 <= genLep_eta2 && genLep_eta2 < 1.8) {
         hist_Zmass_positive_3rd_etabin->Fill(GENmass2l);
        }

        if( 1.8 <= genLep_eta2 && genLep_eta2 <= 2.4) {
         hist_Zmass_positive_4th_etabin->Fill(GENmass2l);
        }
        if( -2.4 <= genLep_eta2 && genLep_eta2 < -1.8) {
         hist_Zmass_positive_5th_etabin->Fill(GENmass2l);
        }
        if( -1.8 <= genLep_eta2 && genLep_eta2 < -1.2) {
         hist_Zmass_positive_6th_etabin->Fill(GENmass2l);
        }
        if( -1.2 <= genLep_eta2 && genLep_eta2 < -0.6) {
         hist_Zmass_positive_7th_etabin->Fill(GENmass2l);
        }
       if( -0.6 <= genLep_eta2 && genLep_eta2 < 0) {
         hist_Zmass_positive_8th_etabin->Fill(GENmass2l);
        }



        if( 0 <= genLep_eta1 && genLep_eta1 < 0.6) {
         hist_Zmass_negative_1st_etabin->Fill(GENmass2l);
        }
        if( 0.6 <= genLep_eta1 && genLep_eta1 < 1.2) {
         hist_Zmass_negative_2nd_etabin->Fill(GENmass2l);
        }

        if( 1.2 <= genLep_eta1 && genLep_eta1 < 1.8) {
         hist_Zmass_negative_3rd_etabin->Fill(GENmass2l);
        }

        if( 1.8 <= genLep_eta1 && genLep_eta1 <= 2.4) {
         hist_Zmass_negative_4th_etabin->Fill(GENmass2l);
        }
        if( -2.4 <= genLep_eta1 && genLep_eta1 < -1.8) {
         hist_Zmass_negative_5th_etabin->Fill(GENmass2l);
        }
        if( -1.8 <= genLep_eta1 && genLep_eta1 < -1.2) {
         hist_Zmass_negative_6th_etabin->Fill(GENmass2l);
        }
        if( -1.2 <= genLep_eta1 && genLep_eta1 < -0.6) {
         hist_Zmass_negative_7th_etabin->Fill(GENmass2l);
        }

      if( -0.6 <= genLep_eta1 && genLep_eta1 < 0) {
         hist_Zmass_negative_8th_etabin->Fill(GENmass2l);
        }
       }

        if(analyze_phi == true) 
       // binning in phi 
       {
       

        if( 0 <= genLep_phi2 && genLep_phi2 < pi/4) {
         hist_Zmass_positive_1st_phibin->Fill(GENmass2l);
        }
        if( pi/4 <= genLep_phi2 && genLep_phi2 < pi/2) {
         hist_Zmass_positive_2nd_phibin->Fill(GENmass2l);
        }

        if( pi/2 <= genLep_phi2 && genLep_phi2 < 3*pi/4) {
         hist_Zmass_positive_3rd_phibin->Fill(GENmass2l);
        }

        if( 3*pi/4 <= genLep_phi2 && genLep_phi2 <= pi) {
         hist_Zmass_positive_4th_phibin->Fill(GENmass2l);
        }
         if( -pi/4 <= genLep_phi2 && genLep_phi2 < 0) {
         hist_Zmass_positive_5th_phibin->Fill(GENmass2l);
        }
        if( -pi/2 <= genLep_phi2 && genLep_phi2 < -pi/4) {
         hist_Zmass_positive_6th_phibin->Fill(GENmass2l);
        }
        if( -3*pi/4 <= genLep_phi2 && genLep_phi2 < -pi/2) {
         hist_Zmass_positive_7th_phibin->Fill(GENmass2l);
        }
       if( -pi <= genLep_phi2 && genLep_phi2 < -3*pi/4) {
         hist_Zmass_positive_8th_phibin->Fill(GENmass2l);
        }


        if( 0 <= genLep_phi1 && genLep_phi1 < pi/4) {
         hist_Zmass_negative_1st_phibin->Fill(GENmass2l);
        }
        if( pi/4 <= genLep_phi1 && genLep_phi1 < pi/2) {
         hist_Zmass_negative_2nd_phibin->Fill(GENmass2l);
        }

        if( pi/2 <= genLep_phi1 && genLep_phi1 < 3*pi/4) {
         hist_Zmass_negative_3rd_phibin->Fill(GENmass2l);
        }

        if( 3*pi/4 <= genLep_phi1 && genLep_phi1 <= pi) {
         hist_Zmass_negative_4th_phibin->Fill(GENmass2l);
        }
          if( -pi/4 <= genLep_phi1 && genLep_phi1 < 0) {
         hist_Zmass_positive_5th_phibin->Fill(GENmass2l);
        }
        if( -pi/2 <= genLep_phi1 && genLep_phi1 < -pi/4) {
         hist_Zmass_positive_6th_phibin->Fill(GENmass2l);
        }
        if( -3*pi/4 <= genLep_phi1 && genLep_phi1 < -pi/2) {
         hist_Zmass_positive_7th_phibin->Fill(GENmass2l);
        }
       if( -pi <= genLep_phi1 && genLep_phi1 < -3*pi/4) {
         hist_Zmass_positive_8th_phibin->Fill(GENmass2l);
        }


     // end of phi binning loop

       }
      // end of id loop 
      }

 
//end of loop of entries   
 }
  


   // plotting histograms on canvas 
   //
   if(analyze_pT == true){ 
     plotting_hist(hist_Zmass_positive_1stbin,"Z mass for 1st pT  bin","Zmass_1stbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_2ndbin,"Z mass for 2nd pT  bin","Zmass_2ndbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_3rdbin,"Z mass for 3rd pT  bin","Zmass_3rdbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_4thbin,"Z mass for 4th pT  bin","Zmass_4thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_5thbin,"Z mass for 5th pT  bin","Zmass_5thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_6thbin,"Z mass for 6th pT  bin","Zmass_6thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_7thbin,"Z mass for 7th pT  bin","Zmass_7thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_8thbin,"Z mass for 8th pT  bin","Zmass_8thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_9thbin,"Z mass for 9th pT  bin","Zmass_9thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_10thbin,"Z mass for 10th pT  bin","Zmass_10thbin_pT_positive", "m(#mu^{+}#mu^{-})");
    

   // plotting histograms on canvas negative muons
   //
    plotting_hist(hist_Zmass_negative_1stbin,"Z mass for 1st pT  bin","Zmass_1stbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_2ndbin,"Z mass for 2nd pT  bin","Zmass_2ndbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_3rdbin,"Z mass for 3rd pT  bin","Zmass_3rdbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_4thbin,"Z mass for 4th pT  bin","Zmass_4thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_5thbin,"Z mass for 5th pT  bin","Zmass_5thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_6thbin,"Z mass for 6th pT  bin","Zmass_6thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_7thbin,"Z mass for 7th pT  bin","Zmass_7thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_8thbin,"Z mass for 8th pT  bin","Zmass_8thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_9thbin,"Z mass for 9th pT  bin","Zmass_9thbin_pT_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_10thbin,"Z mass for 10th pT  bin","Zmass_10thbin_pT_negative", "m(#mu^{+}#mu^{-})");
   } 


    plotting_hist(hist_gen_positive_mu," pT of #mu^{+} ","gen_pT_positive_mu","pT (GeV)");
    plotting_hist(hist_id_positive_mu,"id of #mu^{+} ","id_positive_mu", " ");
 
    plotting_hist(hist_gen_negative_mu," pT of #mu^{-} ","gen_pT_negative_mu","pT (GeV)");
    plotting_hist(hist_id_negative_mu,"id of #mu^{-} ","id_negative_mu", " ");
 
    plotting_hist(hist_gen_pT1," pT of first muon ","gen_pT1","pT (GeV)");
    plotting_hist(hist_gen_pT2," pT of second muon ","gen_pT2","pT (GeV)");
    plotting_hist(hist_id1," id 1st muon ","id1", "");
    plotting_hist(hist_id2," id 2nd muon ","id2", "");
    plotting_hist(hist_gen_Zmass," Gen Z mass ","gen_massZ", "m(#mu^{+}#mu^{-})");
    // after every entry is done, we have to find mean of each histogram and plot it with respect to pT
   // next steps
   //
   //
   mean_sigma_Zmass =  plotting_fitting_mass(hist_gen_Zmass,"gen_Zmass_fit");

  if(analyze_pT==true){   
   mean_sigma_positive[0] =  plotting_fitting_mass(hist_Zmass_positive_1stbin,"Zmass_1stbin_pT_fit_positive");
   mean_sigma_positive[1] = plotting_fitting_mass(hist_Zmass_positive_2ndbin,"Zmass_2ndbin_pT_fit_positive");
   mean_sigma_positive[2] = plotting_fitting_mass(hist_Zmass_positive_3rdbin,"Zmass_3rdbin_pT_fit_positive");
   mean_sigma_positive[3] = plotting_fitting_mass(hist_Zmass_positive_4thbin,"Zmass_4thbin_pT_fit_positive");
   mean_sigma_positive[4] = plotting_fitting_mass(hist_Zmass_positive_5thbin,"Zmass_5thbin_pT_fit_positive");
   mean_sigma_positive[5] = plotting_fitting_mass(hist_Zmass_positive_6thbin,"Zmass_6thbin_pT_fit_positive");
   mean_sigma_positive[6] = plotting_fitting_mass(hist_Zmass_positive_7thbin,"Zmass_7thbin_pT_fit_positive");
   mean_sigma_positive[7] = plotting_fitting_mass(hist_Zmass_positive_8thbin,"Zmass_8thbin_pT_fit_positive");
   mean_sigma_positive[8] = plotting_fitting_mass(hist_Zmass_positive_9thbin,"Zmass_9thbin_pT_fit_positive");
   mean_sigma_positive[9] = plotting_fitting_mass(hist_Zmass_positive_10thbin,"Zmass_10thbin_pT_fit_positive");

   mean_sigma_negative[0] =  plotting_fitting_mass(hist_Zmass_negative_1stbin,"Zmass_1stbin_pT_fit_negative");
   mean_sigma_negative[1] = plotting_fitting_mass(hist_Zmass_negative_2ndbin,"Zmass_2ndbin_pT_fit_negative");
   mean_sigma_negative[2] = plotting_fitting_mass(hist_Zmass_negative_3rdbin,"Zmass_3rdbin_pT_fit_negative");
   mean_sigma_negative[3] = plotting_fitting_mass(hist_Zmass_negative_4thbin,"Zmass_4thbin_pT_fit_negative");
   mean_sigma_negative[4] = plotting_fitting_mass(hist_Zmass_negative_5thbin,"Zmass_5thbin_pT_fit_negative");
   mean_sigma_negative[5] = plotting_fitting_mass(hist_Zmass_negative_6thbin,"Zmass_6thbin_pT_fit_negative");
   mean_sigma_negative[6] = plotting_fitting_mass(hist_Zmass_negative_7thbin,"Zmass_7thbin_pT_fit_negative");
   mean_sigma_negative[7] = plotting_fitting_mass(hist_Zmass_negative_8thbin,"Zmass_8thbin_pT_fit_negative");
   mean_sigma_negative[8] = plotting_fitting_mass(hist_Zmass_negative_9thbin,"Zmass_9thbin_pT_fit_negative");
   mean_sigma_negative[9] = plotting_fitting_mass(hist_Zmass_negative_10thbin,"Zmass_10thbin_pT_fit_negative");
  }
   if(analyze_eta == true){ 
     plotting_hist(hist_Zmass_positive_1st_etabin,"Z mass for 1st eta  bin","Zmass_1stbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_2nd_etabin,"Z mass for 2nd eta  bin","Zmass_2ndbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_3rd_etabin,"Z mass for 3rd eta  bin","Zmass_3rdbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_4th_etabin,"Z mass for 4th eta  bin","Zmass_4thbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_5th_etabin,"Z mass for 5th eta  bin","Zmass_5thbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_6th_etabin,"Z mass for 6th eta  bin","Zmass_6thbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_7th_etabin,"Z mass for 7th eta  bin","Zmass_7thbin_eta_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_8th_etabin,"Z mass for 8th eta  bin","Zmass_8thbin_eta_positive", "m(#mu^{+}#mu^{-})");
    

   // plotting histograms on canvas negative muons
   //
    plotting_hist(hist_Zmass_negative_1st_etabin,"Z mass for 1st eta  bin","Zmass_1stbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_2nd_etabin,"Z mass for 2nd eta  bin","Zmass_2ndbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_3rd_etabin,"Z mass for 3rd eta  bin","Zmass_3rdbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_4th_etabin,"Z mass for 4th eta  bin","Zmass_4thbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_5th_etabin,"Z mass for 5th eta  bin","Zmass_5thbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_6th_etabin,"Z mass for 6th eta  bin","Zmass_6thbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_7th_etabin,"Z mass for 7th eta  bin","Zmass_7thbin_eta_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_8th_etabin,"Z mass for 8th eta  bin","Zmass_8thbin_eta_negative", "m(#mu^{+}#mu^{-})");
   } 


   if(analyze_eta==true){
   mean_sigma_positive_eta[0] =  plotting_fitting_mass(hist_Zmass_positive_1st_etabin,"Zmass_1stbin_eta_fit_positive");
   mean_sigma_positive_eta[1] = plotting_fitting_mass(hist_Zmass_positive_2nd_etabin,"Zmass_2ndbin_eta_fit_positive");
   mean_sigma_positive_eta[2] = plotting_fitting_mass(hist_Zmass_positive_3rd_etabin,"Zmass_3rdbin_eta_fit_positive");
   mean_sigma_positive_eta[3] = plotting_fitting_mass(hist_Zmass_positive_4th_etabin,"Zmass_4thbin_eta_fit_positive");
   mean_sigma_positive_eta[4] = plotting_fitting_mass(hist_Zmass_positive_5th_etabin,"Zmass_5thbin_eta_fit_positive");
   mean_sigma_positive_eta[5] = plotting_fitting_mass(hist_Zmass_positive_6th_etabin,"Zmass_6thbin_eta_fit_positive");
   mean_sigma_positive_eta[6] = plotting_fitting_mass(hist_Zmass_positive_7th_etabin,"Zmass_7thbin_eta_fit_positive");
   mean_sigma_positive_eta[7] = plotting_fitting_mass(hist_Zmass_positive_8th_etabin,"Zmass_8thbin_eta_fit_positive");
 
   mean_sigma_negative_eta[0] =  plotting_fitting_mass(hist_Zmass_negative_1st_etabin,"Zmass_1stbin_eta_fit_negative");
   mean_sigma_negative_eta[1] = plotting_fitting_mass(hist_Zmass_negative_2nd_etabin,"Zmass_2ndbin_eta_fit_negative");
   mean_sigma_negative_eta[2] = plotting_fitting_mass(hist_Zmass_negative_3rd_etabin,"Zmass_3rdbin_eta_fit_negative");
   mean_sigma_negative_eta[3] = plotting_fitting_mass(hist_Zmass_negative_4th_etabin,"Zmass_4thbin_eta_fit_negative");
   mean_sigma_negative_eta[4] = plotting_fitting_mass(hist_Zmass_negative_5th_etabin,"Zmass_5thbin_eta_fit_negative");
   mean_sigma_negative_eta[5] = plotting_fitting_mass(hist_Zmass_negative_6th_etabin,"Zmass_6thbin_eta_fit_negative");
   mean_sigma_negative_eta[6] = plotting_fitting_mass(hist_Zmass_negative_7th_etabin,"Zmass_7thbin_eta_fit_negative");
   mean_sigma_negative_eta[7] = plotting_fitting_mass(hist_Zmass_negative_8th_etabin,"Zmass_8thbin_eta_fit_negative");



   } 
   if(analyze_phi == true){ 
     plotting_hist(hist_Zmass_positive_1st_phibin,"Z mass for 1st phi  bin","Zmass_1stbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_2nd_phibin,"Z mass for 2nd phi  bin","Zmass_2ndbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_3rd_phibin,"Z mass for 3rd phi  bin","Zmass_3rdbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_4th_phibin,"Z mass for 4th phi  bin","Zmass_4thbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_5th_phibin,"Z mass for 5th phi  bin","Zmass_5thbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_6th_phibin,"Z mass for 6th phi  bin","Zmass_6thbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_7th_phibin,"Z mass for 7th phi  bin","Zmass_7thbin_phi_positive", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_8th_phibin,"Z mass for 8th phi  bin","Zmass_8thbin_phi_positive", "m(#mu^{+}#mu^{-})");
    

   // plotting histograms on canvas negative muons
   //
    plotting_hist(hist_Zmass_negative_1st_phibin,"Z mass for 1st phi  bin","Zmass_1stbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_2nd_phibin,"Z mass for 2nd phi  bin","Zmass_2ndbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_3rd_phibin,"Z mass for 3rd phi  bin","Zmass_3rdbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_4th_phibin,"Z mass for 4th phi  bin","Zmass_4thbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_5th_phibin,"Z mass for 5th phi  bin","Zmass_5thbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_6th_phibin,"Z mass for 6th phi  bin","Zmass_6thbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_7th_phibin,"Z mass for 7th phi  bin","Zmass_7thbin_phi_negative", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_negative_8th_phibin,"Z mass for 8th phi  bin","Zmass_8thbin_phi_negative", "m(#mu^{+}#mu^{-})");
   } 


   if(analyze_phi==true){
   mean_sigma_positive_phi[0] =  plotting_fitting_mass(hist_Zmass_positive_1st_phibin,"Zmass_1stbin_phi_fit_positive");
   mean_sigma_positive_phi[1] = plotting_fitting_mass(hist_Zmass_positive_2nd_phibin,"Zmass_2ndbin_phi_fit_positive");
   mean_sigma_positive_phi[2] = plotting_fitting_mass(hist_Zmass_positive_3rd_phibin,"Zmass_3rdbin_phi_fit_positive");
   mean_sigma_positive_phi[3] = plotting_fitting_mass(hist_Zmass_positive_4th_phibin,"Zmass_4thbin_phi_fit_positive");
   mean_sigma_positive_phi[4] = plotting_fitting_mass(hist_Zmass_positive_5th_phibin,"Zmass_5thbin_phi_fit_positive");
   mean_sigma_positive_phi[5] = plotting_fitting_mass(hist_Zmass_positive_6th_phibin,"Zmass_6thbin_phi_fit_positive");
   mean_sigma_positive_phi[6] = plotting_fitting_mass(hist_Zmass_positive_7th_phibin,"Zmass_7thbin_phi_fit_positive");
   mean_sigma_positive_phi[7] = plotting_fitting_mass(hist_Zmass_positive_8th_phibin,"Zmass_8thbin_phi_fit_positive");
 
   mean_sigma_negative_phi[0] =  plotting_fitting_mass(hist_Zmass_negative_1st_phibin,"Zmass_1stbin_phi_fit_negative");
   mean_sigma_negative_phi[1] = plotting_fitting_mass(hist_Zmass_negative_2nd_phibin,"Zmass_2ndbin_phi_fit_negative");
   mean_sigma_negative_phi[2] = plotting_fitting_mass(hist_Zmass_negative_3rd_phibin,"Zmass_3rdbin_phi_fit_negative");
   mean_sigma_negative_phi[3] = plotting_fitting_mass(hist_Zmass_negative_4th_phibin,"Zmass_4thbin_phi_fit_negative");
   mean_sigma_negative_phi[4] = plotting_fitting_mass(hist_Zmass_negative_5th_phibin,"Zmass_5thbin_phi_fit_negative");
   mean_sigma_negative_phi[5] = plotting_fitting_mass(hist_Zmass_negative_6th_phibin,"Zmass_6thbin_phi_fit_negative");
   mean_sigma_negative_phi[6] = plotting_fitting_mass(hist_Zmass_negative_7th_phibin,"Zmass_7thbin_phi_fit_negative");
   mean_sigma_negative_phi[7] = plotting_fitting_mass(hist_Zmass_negative_8th_phibin,"Zmass_8thbin_phi_fit_negative");



   } 

   ofstream myfile;
       myfile.open("mean_Zmass.txt"); //,std::ios_base::app);
 
       myfile<<"gen Z mass fit"<<std::endl; 
       myfile<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;
       myfile<<mean_sigma_Zmass.first<<"\t\t  "<<mean_sigma_Zmass.second<<std::endl;
 
       myfile<<"for positive muons in pT binned"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;

       if(analyze_pT==true){
       for(int i= 0 ; i<10;i++){
       mean_positive[i] = mean_sigma_positive[i].first;
       sigma_positive[i] = mean_sigma_positive[i].second;
       myfile<<i<<"\t \t "<<mean_positive[i]<<"\t\t  "<<sigma_positive[i]<<std::endl; 
      // sigma[i]<<std::endl;
       }

       myfile<<"for negative muons in pT binned"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;

       for(int i= 0 ; i<10;i++){
       mean_negative[i] = mean_sigma_negative[i].first;
       sigma_negative[i] = mean_sigma_negative[i].second;
       myfile<<i<<"\t \t "<<mean_negative[i]<<"\t\t  "<<sigma_negative[i]<<std::endl; 
      // sigma[i]<<std::endl;
      } 
     }
       if(analyze_eta==true){
       for(int i= 0 ; i<8;i++){
       mean_positive_eta[i] = mean_sigma_positive_eta[i].first;
       sigma_positive_eta[i] = mean_sigma_positive_eta[i].second;
       myfile<<i<<"\t \t "<<mean_positive_eta[i]<<"\t\t  "<<sigma_positive_eta[i]<<std::endl; 
      // sigma[i]<<std::endl;
       }

       for(int i= 0 ; i<8;i++){
       mean_negative_eta[i] = mean_sigma_negative_eta[i].first;
       sigma_negative_eta[i] = mean_sigma_negative_eta[i].second;
       myfile<<i<<"\t \t "<<mean_negative_eta[i]<<"\t\t  "<<sigma_negative_eta[i]<<std::endl; 
       }


       }
       if(analyze_phi==true){
       for(int i= 0 ; i<8;i++){
       mean_positive_phi[i] = mean_sigma_positive_phi[i].first;
       sigma_positive_phi[i] = mean_sigma_positive_phi[i].second;
       myfile<<i<<"\t \t "<<mean_positive_phi[i]<<"\t\t  "<<sigma_positive_phi[i]<<std::endl; 
      // sigma[i]<<std::endl;
       }

       for(int i= 0 ; i<8;i++){
       mean_negative_phi[i] = mean_sigma_negative_phi[i].first;
       sigma_negative_phi[i] = mean_sigma_negative_phi[i].second;
       myfile<<i<<"\t \t "<<mean_negative_phi[i]<<"\t\t  "<<sigma_negative_phi[i]<<std::endl; 
       }


       }


// graph to plot mean z mass with pT
    if(analyze_pT == true){
       graph_mean_pT();
    }

    if(analyze_eta == true){
   graph_mean_eta();
    }  
   if(analyze_phi == true){

   graph_mean_phi();
    }
// end of program
}
