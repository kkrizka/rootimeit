#include "LoadVector.h"

#include <sstream>
#include <ctime>
#include <iostream>

LoadVector::LoadVector()
  : LoadBase()
{
  for(uint i=0;i<10000;i++)
    m_pointers[i]=new std::vector<float>();
}

LoadVector::~LoadVector()
{
  for(uint i=0;i<10000;i++)
    {
      delete m_pointers[i];
      m_pointers[i]=0;
    }
}

void LoadVector::setupBranches()
{
  LoadBase::setupBranches();

  std::stringstream ss;
  for(uint i=0;i<m_nBranches;i++)
    {
      ss.str("");
      ss << "test" << std::setfill('0') << std::setw(2) << i;
      m_tree->SetBranchAddress(ss.str().c_str(), &m_pointers[i]);
    }  
}

void LoadVector::runLoop()
{
  for(uint i=0;i<m_tree->GetEntries();i++)
    {
      m_tree->GetEntry(i);
      for(uint hidx=0;hidx<m_hists.size();hidx++)
	m_hists[hidx]->Fill(m_pointers[hidx%m_nBranches]->at(0));
    }
}
