#include <TFile.h>
#include <TTree.h>

#include <ctime>
#include <iostream>

void test()
{
  TFile *fh=TFile::Open("/ssdisk02/mergedata/user.kkrizka.data16.periodA.dijet.20170314-01_tree.root");
  TTree *t=dynamic_cast<TTree*>(fh->Get("outTree"));

  //t->SetBranchStatus("*",0);
  //t->SetBranchStatus("jet_pt",1);

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
