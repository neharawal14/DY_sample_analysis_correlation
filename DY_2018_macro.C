#define DY_2018_macro_cxx
#include "DY_2018_macro.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
void DY_2018_macro::Loop()
{
     gROOT->SetBatch(kTRUE);
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
   //for (Long64_t jentry=0; jentry<nentries;jentry++) {
   for (Long64_t jentry=0; jentry<1000000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) { std::cout<<"entry is breaking"<<std::endl;
                        std::cout<<"entry number "<<jentry<<std::endl; 
        break;}
      nb = fChain->GetEntry(jentry);   nbytes += nb;


       hist_gen_pT1 ->Fill(genLep_pt1);      
       hist_gen_pT2 ->Fill(genLep_pt2);      
       hist_id1 ->Fill(Id1);      
       hist_id2 ->Fill(Id2);      
       hist_gen_Zmass ->Fill(GENmass2l);      
      // if (Cut(ientry) < 0) continue;

     // analyzing just positive muons
      if(Id1==13)    
      {
        if(debug_base==true) { std::cout<<" positive muon has higher pT with lep_id : "<<Id1<<std::endl;
                             std::cout<<"pT positive and pT negative muon :  "<<genLep_pt1<<"  "<<genLep_pt2<<std::endl; } 

        // dividing in pT bins
        
        if(0<= genLep_pt1 && genLep_pt1 < 20) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_1stbin->Fill(GENmass2l);
        }

        if(20 <= genLep_pt1  && genLep_pt1 < 40) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_2ndbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt1 && genLep_pt1 < 60) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_3rdbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt1 && genLep_pt1 < 80) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_4thbin->Fill(GENmass2l);
        }

        if( 80 < genLep_pt1 && genLep_pt1 < 100) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_5thbin->Fill(GENmass2l);
        }

        if( 100 <= genLep_pt1  && genLep_pt1 < 120) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_6thbin->Fill(GENmass2l);
        }

        if( 120 <= genLep_pt1 && genLep_pt1 < 140) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_7thbin->Fill(GENmass2l);
        }

        if( 140 <= genLep_pt1 && genLep_pt1 < 160) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_8thbin->Fill(GENmass2l);
        }
    
        if( 160 <= genLep_pt1 && genLep_pt1 < 180) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_9thbin->Fill(GENmass2l);
        }

        if( 180 <= genLep_pt1 && genLep_pt1 < 200) {
         hist_gen_positive_mu->Fill(genLep_pt1);
         hist_id_positive_mu->Fill(Id1);        
         hist_Zmass_positive_10thbin->Fill(GENmass2l);
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
 
         if(0< genLep_pt2 && genLep_pt2 < 20) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_1stbin->Fill(GENmass2l);
        }

        if(20 <= genLep_pt2  && genLep_pt2 < 40) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_2ndbin->Fill(GENmass2l);
        }

        if( 40 <= genLep_pt2 && genLep_pt2 < 60) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_3rdbin->Fill(GENmass2l);
        }

        if( 60 <= genLep_pt2 && genLep_pt2 < 80) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_4thbin->Fill(GENmass2l);
        }

        if( 80 < genLep_pt2 && genLep_pt2 < 100) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_5thbin->Fill(GENmass2l);
        }

        if( 100 <= genLep_pt2  && genLep_pt2 < 120) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_6thbin->Fill(GENmass2l);
        }

        if( 120 <= genLep_pt2 && genLep_pt2 < 140) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_7thbin->Fill(GENmass2l);
        }

        if( 140 <= genLep_pt2 && genLep_pt2 < 160) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_8thbin->Fill(GENmass2l);
        }
 
        if( 160 <= genLep_pt2 && genLep_pt2 < 180) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_9thbin->Fill(GENmass2l);
        }
         if( 180 <= genLep_pt2 && genLep_pt2 < 200) {
         hist_gen_positive_mu->Fill(genLep_pt2);
         hist_id_positive_mu->Fill(Id2);        
         hist_Zmass_positive_10thbin->Fill(GENmass2l);
        }
 
    //    if( genLep_pt2 >= 400)   
   //       std::cout<<" event with pT not in between 0 and 200 GeV "<<genLep_pt2<<std::endl;
      // end of id loop 
      }

 
//end of loop of entries   
 }
  


   // plotting histograms on canvas 
   //
    plotting_hist(hist_Zmass_positive_1stbin,"Z mass for 1st pT  bin","Zmass_1stbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_2ndbin,"Z mass for 2nd pT  bin","Zmass_2ndbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_3rdbin,"Z mass for 3rd pT  bin","Zmass_3rdbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_4thbin,"Z mass for 4th pT  bin","Zmass_4thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_5thbin,"Z mass for 5th pT  bin","Zmass_5thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_6thbin,"Z mass for 6th pT  bin","Zmass_6thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_7thbin,"Z mass for 7th pT  bin","Zmass_7thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_8thbin,"Z mass for 8th pT  bin","Zmass_8thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_9thbin,"Z mass for 9th pT  bin","Zmass_9thbin_pT", "m(#mu^{+}#mu^{-})");
    plotting_hist(hist_Zmass_positive_10thbin,"Z mass for 10th pT  bin","Zmass_10thbin_pT", "m(#mu^{+}#mu^{-})");


    plotting_hist(hist_gen_positive_mu," pT of #mu^{+} ","gen_pT_positive_mu","pT (GeV)");
    plotting_hist(hist_id_positive_mu,"id of #mu^{+} ","id_positive_mu", " ");
  
    plotting_hist(hist_gen_pT1," pT of first muon ","gen_pT1","pT (GeV)");
    plotting_hist(hist_gen_pT2," pT of second muon ","gen_pT2","pT (GeV)");
    plotting_hist(hist_id1," id 1st muon ","id1", "");
    plotting_hist(hist_id2," id 2nd muon ","id2", "");
    plotting_hist(hist_gen_Zmass," Gen Z mass ","gen_massZ", "m(#mu^{+}#mu^{-})");
    // after every entry is done, we have to find mean of each histogram and plot it with respect to pT
   // next steps
   //
   //
   mean_sigma[0] =  plotting_fitting_mass(hist_Zmass_positive_1stbin,"Zmass_1stbin_pT_fit");
 //  mean[0] = plotting_fitting_mass(hist_Zmass_positive_1stbin,"Zmass_1stbin_pT_fit");
   mean_sigma[1] = plotting_fitting_mass(hist_Zmass_positive_2ndbin,"Zmass_2ndbin_pT_fit");
   mean_sigma[2] = plotting_fitting_mass(hist_Zmass_positive_3rdbin,"Zmass_3rdbin_pT_fit");
   mean_sigma[3] = plotting_fitting_mass(hist_Zmass_positive_4thbin,"Zmass_4thbin_pT_fit");
   mean_sigma[4] = plotting_fitting_mass(hist_Zmass_positive_5thbin,"Zmass_5thbin_pT_fit");
   mean_sigma[5] = plotting_fitting_mass(hist_Zmass_positive_6thbin,"Zmass_6thbin_pT_fit");
   mean_sigma[6] = plotting_fitting_mass(hist_Zmass_positive_7thbin,"Zmass_7thbin_pT_fit");
   mean_sigma[7] = plotting_fitting_mass(hist_Zmass_positive_8thbin,"Zmass_8thbin_pT_fit");
   mean_sigma[8] = plotting_fitting_mass(hist_Zmass_positive_9thbin,"Zmass_9thbin_pT_fit");
   mean_sigma[9] = plotting_fitting_mass(hist_Zmass_positive_10thbin,"Zmass_10thbin_pT_fit");

       ofstream myfile;
       myfile.open("mean_Zmass.txt"); //,std::ios_base::app);
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;

       for(int i= 0 ; i<10;i++){
       mean[i] = mean_sigma[i].first;
       sigma[i] = mean_sigma[i].second;
       myfile<<i<<"\t \t "<<mean[i]<<"\t\t  "<<sigma[i]<<std::endl; 
      // sigma[i]<<std::endl;
       }
// graph to plot mean z mass with pT
   graph_mean_pT();

// end of program
}
