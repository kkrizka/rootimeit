#include "LoadArray.h"

#include <sstream>
#include <ctime>
#include <iostream>

LoadArray::LoadArray()
  : LoadBase()
{ }

LoadArray::~LoadArray()
{ }

void LoadArray::setupBranches()
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

void LoadArray::runLoop()
{
  for(uint i=0;i<m_tree->GetEntries();i++)
    {
      m_tree->GetEntry(i);
      for(uint hidx=0;hidx<m_hists.size();hidx++)
	m_hists[hidx]->Fill(m_pointers[hidx%m_nBranches][0]);
    }
}
