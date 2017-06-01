#include "LoadTClonesArray.h"

#include <sstream>
#include <ctime>
#include <iostream>

LoadTClonesArray::LoadTClonesArray()
  : LoadBase()
{
  test=new TClonesArray("Test");
}

LoadTClonesArray::~LoadTClonesArray()
{ }

void LoadTClonesArray::setupBranches()
{
  //LoadBase::setupBranches();
  m_tree->GetBranch("test")->SetAutoDelete(kFALSE);
  m_tree->SetBranchAddress("test",&test);
}

void LoadTClonesArray::runLoop()
{
  for(uint i=0;i<m_tree->GetEntries();i++)
    {
      m_tree->GetEntry(i);
      for(uint hidx=0;hidx<m_hists.size();hidx++)
	m_hists[hidx]->Fill(1.); //m_pointers[hidx%m_nBranches]->at(0));
    }
}
