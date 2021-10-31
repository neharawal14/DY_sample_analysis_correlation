#define DY_2018_macro_cxx 
#include "DY_2018_macro.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
//#include "RooMyPDF_DSCB.h"
//#include "RooMyPDF_DSCB.cxx"

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

 
       if(analyze_eta == true) 
       // binning in eta 
       {
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta1 && genLep_eta1 < eta_list[i+1]){
           histogram_filling_positive_eta(i);
          }
         }

         // filling Z mass for negative eta bins 
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta2 && genLep_eta2 < eta_list[i+1]){
           histogram_filling_negative_eta(i);
          }
         }
       }


       // smear pT of individual lepton and then reconstruct Z mass
       if(smearing == true){
         // smear individual pT
         smearing_pT();

         // reconstruct mass of Z from Lorentzvector for individual lepton 
         reconstruct_Zmass();


        // fill the reconstructed Z mass into a histogram
        hist_reco_Zmass ->Fill(massZ_reconstruct);
        hist_gen_pT1_smear ->Fill(genLep_pt1);      
        hist_gen_pT2_smear ->Fill(genLep_pt2);      
        hist_id1_smear ->Fill(Id1);      
        hist_id2_smear ->Fill(Id2);      
        hist_gen_Zmass_smear ->Fill(GENmass2l);      
 
        hist_gen_positive_mu_smear->Fill(genLep_pt1);
        hist_id_positive_mu_smear->Fill(Id1);        
        hist_gen_negative_mu_smear->Fill(genLep_pt2);
        hist_id_negative_mu_smear->Fill(Id2); 

       }
     
      // have to be run after the pT is smeared  
       if(analyze_eta == true && smearing == true){

         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta1 && genLep_eta1 < eta_list[i+1]){
           histogram_filling_positive_eta_smear(i);
          }
         }

         // filling Z mass for negative eta bins 
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta2 && genLep_eta2 < eta_list[i+1]){
           histogram_filling_negative_eta_smear(i);
          }
         }
       }
       
  }
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



        if(analyze_eta == true) 
       // binning in eta 
       {
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta2 && genLep_eta2 < eta_list[i+1]){
           histogram_filling_positive_eta(i);
          }
         }
    
         // filling Z mass for negative eta bins 
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta1 && genLep_eta1 < eta_list[i+1]){
           histogram_filling_negative_eta(i);
          }
         }
       }

 
           if(smearing == true){
         // smear individual pT
         smearing_pT();

         // reconstruct mass of Z from Lorentzvector for individual lepton 
         reconstruct_Zmass();


        // fill the reconstructed Z mass into a histogram
        hist_reco_Zmass ->Fill(massZ_reconstruct);
        hist_gen_pT1_smear ->Fill(genLep_pt1);      
        hist_gen_pT2_smear ->Fill(genLep_pt2);      
        hist_id1_smear ->Fill(Id1);      
        hist_id2_smear ->Fill(Id2);      
        hist_gen_Zmass_smear ->Fill(GENmass2l);      
 
        hist_gen_positive_mu_smear->Fill(genLep_pt2);
        hist_id_positive_mu_smear->Fill(Id2);        
        hist_gen_negative_mu_smear->Fill(genLep_pt1);
        hist_id_negative_mu_smear->Fill(Id1); 

       }   
      // have to be run after the pT is smeared  
       if(analyze_eta == true && smearing == true){

         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta2 && genLep_eta2 < eta_list[i+1]){
           histogram_filling_positive_eta_smear(i);
          }
         }

         // filling Z mass for negative eta bins 
         for(int i=0; i<8; i++){
          if(eta_list[i] <= genLep_eta1 && genLep_eta1 < eta_list[i+1]){
           histogram_filling_negative_eta_smear(i);
          }
         }
       }
   // end of id2 loop
      }

       // end of entries loop
 }
    plotting_hist(hist_gen_positive_mu," pT of #mu^{+} ","gen_pT_positive_mu","pT (GeV)");
    plotting_hist(hist_id_positive_mu,"id of #mu^{+} ","id_positive_mu", " ");
 
    plotting_hist(hist_gen_negative_mu," pT of #mu^{-} ","gen_pT_negative_mu","pT (GeV)");
    plotting_hist(hist_id_negative_mu,"id of #mu^{-} ","id_negative_mu", " ");
 
    plotting_hist(hist_gen_pT1," pT of first muon ","gen_pT1","pT (GeV)");
    plotting_hist(hist_gen_pT2," pT of second muon ","gen_pT2","pT (GeV)");
    plotting_hist(hist_id1," id 1st muon ","id1", "");
    plotting_hist(hist_id2," id 2nd muon ","id2", "");

    plotting_hist(hist_gen_positive_mu_smear," pT of #mu^{+} after smearing ","gen_pT_positive_mu_smear","pT (GeV)");
    plotting_hist(hist_id_positive_mu_smear,"id of #mu^{+} after smearing ","id_positive_mu_smear", " ");
 
    plotting_hist(hist_gen_negative_mu_smear," pT of #mu^{-} after smearing ","gen_pT_negative_mu_smear","pT (GeV)");
    plotting_hist(hist_id_negative_mu_smear,"id of #mu^{-} after smearing ","id_negative_mu_smear", " ");
 
    plotting_hist(hist_gen_pT1_smear," pT of first muon after smearing ","gen_pT1_smear","pT (GeV)");
    plotting_hist(hist_gen_pT2_smear," pT of second muon after smearing ","gen_pT2_smear","pT (GeV)");
    plotting_hist(hist_id1_smear," id 1st muon after smearing ","id1_smear", "");
    plotting_hist(hist_id2_smear," id 2nd muon after smearing ","id2_smear", "");


    // after every entry is done, we have to find mean of each histogram and plot it with respect to pT
   // next steps
   //
   //
   mean_sigma_Zmass =  plotting_fitting_mass_BW(hist_gen_Zmass,"gen_Zmass_fit");
   mean_sigma_Zmass_DSCB =  plotting_fitting_mass_DSCB(hist_gen_Zmass,"gen_Zmass_fit");

   if(analyze_eta == true){ 
     for (int i=0; i<8;i++){
     TString title = TString::Format("Z mass for #mu^{+} :  %.1f  #leq #eta %.1f " , eta_list[i], eta_list[i+1] );
     TString saving_name_hist = "Zmass_"+bin_number[i]+"_eta_positive";
     plotting_hist(histogram_Zmass_positive_eta[i],title,saving_name_hist, "m(#mu^{+}#mu^{-})");
     } 
   
     for (int i=0; i<8;i++){

     TString title = TString::Format("Z mass for #mu^{-} :  %.1f  #leq #eta %.1f " , eta_list[i], eta_list[i+1] );
     TString saving_name_hist = "Zmass_"+bin_number[i]+"_eta_negative";
     plotting_hist(histogram_Zmass_negative_eta[i],title,saving_name_hist, "m(#mu^{+}#mu^{-})");
     }
   }

 

    if(analyze_eta == true && smearing == true){ 
     for (int i=0; i<8;i++){
     TString title = TString::Format("Z mass after smearing for #mu^{+} :  %.1f  #leq #eta %.1f " , eta_list[i], eta_list[i+1] );
     TString saving_name_hist = "Zmass_"+bin_number[i]+"_eta_positive_smear";
     plotting_hist(histogram_Zmass_positive_eta_smear[i],title,saving_name_hist, "m(#mu^{+}#mu^{-})");
     } 
   
     for (int i=0; i<8;i++){

     TString title = TString::Format("Z mass after smearing for #mu^{-} :  %.1f  #leq #eta %.1f " , eta_list[i], eta_list[i+1] );
     TString saving_name_hist = "Zmass_"+bin_number[i]+"_eta_negative_smear";
     plotting_hist(histogram_Zmass_negative_eta_smear[i],title,saving_name_hist, "m(#mu^{+}#mu^{-})");
     }
   } 


    // evaluating results from fit
   if(analyze_eta==true){

  for (int i=0; i<8;i++){
     TString saving_name_hist_fit = "Zmass_"+bin_number[i]+"_eta_fit_positive";
     mean_sigma_positive_eta[i] = plotting_fitting_mass_DSCB(histogram_Zmass_positive_eta[i],saving_name_hist_fit);
     }
 
  for (int i=0; i<8;i++){
     TString saving_name_hist_fit = "Zmass_"+bin_number[i]+"_eta_fit_negative";
     mean_sigma_negative_eta[i] = plotting_fitting_mass_DSCB(histogram_Zmass_negative_eta[i],saving_name_hist_fit);
     }
   }


   if(analyze_eta==true && smearing==true){
    for (int i=0; i<8;i++){
    TString saving_name_hist_fit = "Zmass_"+bin_number[i]+"_eta_smear_fit_positive";
    cout<<"saving name of histogram after fit after smearing"<<saving_name_hist_fit<<endl;
    mean_sigma_positive_reco_eta[i] = plotting_fitting_mass_DSCB(histogram_Zmass_positive_eta_smear[i],saving_name_hist_fit);
    }

    for (int i=0; i<8;i++){
    TString saving_name_hist_fit = "Zmass_"+bin_number[i]+"_eta_smear_fit_negative";
    mean_sigma_negative_reco_eta[i] = plotting_fitting_mass_DSCB(histogram_Zmass_negative_eta_smear[i],saving_name_hist_fit);
    }
  }

       ofstream myfile;
       myfile.open("mean_Zmass.txt"); //,std::ios_base::app);
 
       myfile<<"gen Z mass fit"<<std::endl; 
       myfile<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;
       myfile<<mean_sigma_Zmass.first<<"\t\t  "<<mean_sigma_Zmass.second<<std::endl;
 
       myfile<<"gen Z mass fit DSCB"<<std::endl; 
       myfile<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;
       myfile<<mean_sigma_Zmass_DSCB.first<<"\t\t  "<<mean_sigma_Zmass_DSCB.second<<std::endl;


       if(analyze_eta==true ){
 
       myfile<<"for positive muons in eta bins"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;


       for(int i= 0 ; i<8;i++){
       mean_positive_eta[i] = mean_sigma_positive_eta[i].first;
       sigma_positive_eta[i] = mean_sigma_positive_eta[i].second;
       myfile<<i<<"\t \t "<<mean_positive_eta[i]<<"\t\t  "<<sigma_positive_eta[i]<<std::endl; 
       }
  
       myfile<<"for negative muons in eta bins"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;


       for(int i= 0 ; i<8;i++){
       mean_negative_eta[i] = mean_sigma_negative_eta[i].first;
       sigma_negative_eta[i] = mean_sigma_negative_eta[i].second;
       myfile<<i<<"\t \t "<<mean_negative_eta[i]<<"\t\t  "<<sigma_negative_eta[i]<<std::endl; 
       }

    if(smearing==true){
       myfile<<"for positive muons after smearing in eta bins"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;


       for(int i= 0 ; i<8;i++){
       mean_positive_reco_eta[i] = mean_sigma_positive_reco_eta[i].first;
       sigma_positive_reco_eta[i] = mean_sigma_positive_reco_eta[i].second;
       diff_Zmass_positive_gen_reco[i] = (mean_positive_reco_eta[i] - mean_positive_eta[i]) / mean_positive_eta[i] ; 
       myfile<<i<<"\t \t "<<mean_positive_reco_eta[i]<<"\t\t  "<<sigma_positive_reco_eta[i]<<std::endl; 
     }

       myfile<<"for negative muons after smearing in eta bins"<<std::endl; 
       myfile<<"bin no."<<"\t \t"<<"mean Z"<<"\t\t  "<<"Sigma Z"<<std::endl;


       for(int i= 0 ; i<8;i++){
       mean_negative_reco_eta[i] = mean_sigma_negative_reco_eta[i].first;
       sigma_negative_reco_eta[i] = mean_sigma_negative_reco_eta[i].second;
       diff_Zmass_negative_gen_reco[i] = (mean_negative_reco_eta[i] - mean_negative_eta[i]) / mean_negative_eta[i] ; 
       myfile<<i<<"\t \t "<<mean_negative_reco_eta[i]<<"\t\t  "<<sigma_negative_reco_eta[i]<<std::endl; 
     }
 
    }
       } 

// graph to plot mean z mass with pT
   if(analyze_eta == true){
   graph_mean_eta();
   graph_mean_eta_reco();
   graph_diff_Zmass_gen_reco();
   } 
// end of program

}

