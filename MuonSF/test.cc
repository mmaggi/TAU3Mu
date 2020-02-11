#include "MuonSF.h"
#include <iostream>
int main(){

  // this should be transferred as EDMAnalyser parameters...
  MuonSF  pippo("Tau3MuMuonSF.root","LooseID_abseta_pt_Bins");

  // lets'get a muon kinematics...
  float pt  = 5.8; // GeV
  float eta = 1.3;
  MuonSF::sfMuon val = pippo.sf(pt,eta);

  std::cout <<"  Muon Safety Factor "<<val.value<<" +- "<<val.error<<std::endl;
  
}
