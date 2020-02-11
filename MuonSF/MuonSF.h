#ifndef TAU3MUMUONSF_H
#define TAU3MUMUONSF_H

#include <string>

#include "TFile.h"
#include "TH2F.h"

class MuonSF {

 public:
  struct sfMuon{
    float value=1.0;
    float error=0.0;
  };
  MuonSF(){};
  ~MuonSF();
  MuonSF(const std::string& filename, const std::string& idname);
  sfMuon sf(double pt, double eta);

  
 private:
  TFile* _f;
  TH2F* _h;
};  
#endif
