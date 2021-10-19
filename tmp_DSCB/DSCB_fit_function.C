double macro::DSCB_fit(TH1F *histogram,std::string saving_name, TString canvas_name) {


RooRealVar m4mu("m4mu", "var", minimum,maximum, "");
//RooRealVar var("var","var",minimum,maximum);
RooDataHist histo("histo","dataset with var",m4mu,histogram);

RooRealVar Mean("Mean", "Mean",0, -0.01,0.01);
RooRealVar Sigma("#sigma", "#sigma", 0.01, 0.001, 0.05);//sigma[decay]);
RooRealVar AlphaL("#alpha_{L}", "#alpha_{L}", 1, 0, 30);//alphaL[decay]);
RooRealVar ExpL("n_{L}", "n_{L}", 1, 0, 30);//expL[decay]);
RooRealVar AlphaR("#alpha_{R}", "#alpha_{R}", 1, 0, 30);//alphaR[decay]);
RooRealVar ExpR("n_{R}", "n_{R}", 1, 1, 50);//expR[decay]);

/*RooRealVar Mean_corr("#mu^{corr}", "#mu^{corr}", 125, 120, 130);
RooRealVar Sigma_corr("#sigma^{corr}", "#sigma^{corr}", 1, 0, 10);//sigma[decay]);
RooRealVar AlphaL_corr("#alpha_{L}^{corr}", "#alpha_{L}^{corr}", 1, 0, 30);//alphaL[decay]);
RooRealVar ExpL_corr("n_{L}^{corr}", "n_{L}^{corr}", 1, 0, 30);//expL[decay]);
RooRealVar AlphaR_corr("#alpha_{R}^{corr}", "#alpha_{R}^{corr}", 1, 0, 30);//alphaR[decay]);
RooRealVar ExpR_corr("n_{R}^{corr}", "n_{R}^{corr}", 1, 1, 50);//expR[decay]);
*/
RooMyPDF_DSCB DSCB("DSCB", "DSCB", m4mu, Mean, Sigma, AlphaL, ExpL, AlphaR, ExpR);
//RooMyPDF_DSCB DSCB_corr("DSCB_corr", "DSCB_corr", m4mu_corr, Mean_corr, Sigma_corr, AlphaL_corr, ExpL_corr, AlphaR_corr, ExpR_corr);

TCanvas *c_MC = new TCanvas("c_MC", "c_MC", 800, 600);
c_MC->SetFrameFillColor(0);
// c_MC->cd(1)->SetBottomMargin(0.2);
// c_MC->SetLogy();

TString title = canvas_name;
RooPlot* xframe = m4mu.frame(RooFit::Title(title));
//RooPlot* xframe_corr = m4mu_corr.frame(RooFit::Title(title));
histo.plotOn(xframe);
//rds_corr.plotOn(xframe_corr);

Int_t color = kRed+2;
Double_t size_text = 0.020;
DSCB.fitTo(histo, RooFit::Range(minimum,maximum));
DSCB.plotOn(xframe, RooFit::LineColor(color));
DSCB.paramOn(xframe, RooFit::Layout(0.15, 0.35, 0.90));
xframe->getAttText()->SetTextSize(size_text);
xframe->getAttText()->SetTextColor(color);
xframe->GetXaxis()->SetTitle("#frac{#Delta p_{T}}{p_{T}}");
xframe->GetYaxis()->SetTitle("number of events");
xframe->GetXaxis()->SetTitleOffset(1.4);
c_MC->Print( (save_dir_path+ saving_name).c_str());// + ".pdf");

// param.push_back(Mean.getVal());
// param.push_back(Sigma.getVal());

// Draw the plots.
// TCanvas * c1 = new TCanvas("c1", "c1", 600, 700);
// h_m4mu->Draw();
// c1->SaveAs("/ufrc/avery/rosedj1/HiggsMassMeasurement/Utils_ROOT/TestingROOT/test_draw.pdf");

return sigma_value;
}
                       
