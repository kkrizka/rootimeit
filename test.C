#include <TFile.h>
#include <TTree.h>
#include <TString.h>

#include <ctime>
#include <iostream>

void test()
{
  TFile *fh=TFile::Open("/ssdisk02/test.root");
  //TFile *fh=TFile::Open("test.root");
  TTree *t=dynamic_cast<TTree*>(fh->Get("tree"));

  t->SetBranchStatus("*",0);
  for(uint i=0;i<50;i++)
    t->SetBranchStatus(TString::Format("test%02d",i).Data(),1);

  std::clock_t tbegin = std::clock();
  for(uint i=0;i<t->GetEntries();i++)
    {
      t->GetEntry();
    }
  std::clock_t tend = std::clock(); 
  double elapsed_secs = double(tend - tbegin) / CLOCKS_PER_SEC;
  std::cout << "time " << elapsed_secs << std::endl;
  std::cout << "rate " << t->GetEntries()/elapsed_secs << std::endl;

  fh->Close();
}
