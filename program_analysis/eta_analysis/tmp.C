#include <iostream>
#include <string>

void tmp(){
  TH1D*histogram_name_eta[2];
 for(int i=0; i<2;i++){
TString histogram_name = TString::Format("histogram_name_eta[%d]",i);

std::cout<<histogram_name<<std::endl;
   TString title = "Gen Z mass for "+  std::to_string(i);
   histogram_name_eta[i] = new TH1D(histogram_name,title,300,60,120);
std::cout<<"histogram got defined "<<i<<" time"<<std::endl;
    histogram_name_eta[i]->Fill(i*7);
std::cout<<"hist filled successfully"<<std::endl;
  } 
  

}
