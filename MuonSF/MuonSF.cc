#include "MuonSF.h"
#include "TFile.h"
#include <iostream>
MuonSF::MuonSF(const std::string& filename, const std::string& idname){
  _f = new TFile(filename.c_str());
  _h = dynamic_cast<TH2F*> (_f->Get(idname.c_str()));
  float pt = 5.2;
  int ipt = _h->GetXaxis()->FindBin(pt);
}

MuonSF::sfMuon
MuonSF::sf(double pt, double eta){
  MuonSF::sfMuon val;
  int ipt = _h->GetXaxis()->FindBin(pt);
  int ieta = _h->GetYaxis()->FindBin(eta);
  val.value = _h->GetBinContent(ipt,ieta);
  val.error = _h->GetBinError(ipt,ieta);
  return val;
}

MuonSF::~MuonSF(){
  delete _h;
  delete _f;
}
