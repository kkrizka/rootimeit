#include "LoadBase.h"

#include <sstream>
#include <ctime>
#include <iostream>

LoadBase::LoadBase()
  : m_fh(0), m_tree(0),
    m_nBranches(0),m_nHists(0),
    m_cacheSize(0)
{
  for(uint i=0;i<10000;i++)
    m_pointers[i]=new std::vector<float>();
}

LoadBase::~LoadBase()
{
  for(uint i=0;i<10000;i++)
    {
      delete m_pointers[i];
      m_pointers[i]=0;
    }
}

void LoadBase::setPath(const std::string& path)
{ m_path=path; }

void LoadBase::setNBranches(uint nBranches)
{ m_nBranches=nBranches; }

void LoadBase::setNHists(uint nHists)
{ m_nHists=nHists; }

void LoadBase::setCacheSize(uint cacheSize)
{ m_cacheSize=cacheSize; }

void LoadBase::setupInput()
{
  if(m_fh!=0) m_fh->Close();
  m_fh=TFile::Open(m_path.c_str());
  m_tree=dynamic_cast<TTree*>(m_fh->Get("tree"));
  m_tree->SetCacheSize(m_cacheSize*1024*1024);
  m_tree->SetCacheLearnEntries(1000);
}

void LoadBase::setupBranches()
{
  m_tree->SetBranchStatus("*", 0);
  
  std::stringstream ss;
  for(uint i=0;i<m_nBranches;i++)
    {
      ss.str("");
      ss << "test" << std::setfill('0') << std::setw(2) << i;
      m_tree->SetBranchStatus(ss.str().c_str(), 1);
      m_tree->SetBranchAddress(ss.str().c_str(), &m_pointers[i]);
    }  
}

void LoadBase::setupHists()
{
  //for(auto hist : m_hists)
  //delete hist;
  m_hists.clear();

  std::stringstream ss;  
  for(uint i=0;i<m_nHists;i++)
    {
      ss.str("");
      ss << "hist" << std::setfill('0') << std::setw(10) << i;
      m_hists.push_back(new TH1F(ss.str().c_str(),"",10,-0.5,9.5));
    }

}

double LoadBase::eventSize()
{
  setupInput();
  return m_fh->GetSize()/m_tree->GetEntries();
}

double LoadBase::runTest()
{
  double x=0.;
  double xx=0.;
  uint n=0;
  for(uint i=0;i<10;i++)
    {
      setupInput();
      setupBranches();
      setupHists();

      std::clock_t tbegin = std::clock();
      for(uint i=0;i<m_tree->GetEntries();i++)
	{
	  m_tree->GetEntry(i);
	  for(uint hidx=0;hidx<m_hists.size();hidx++)
	    m_hists[hidx]->Fill(m_pointers[hidx%m_nBranches]->at(0));
	}
      std::clock_t tend = std::clock(); 
      double elapsed_secs = double(tend - tbegin) / CLOCKS_PER_SEC;
      //std::cout << elapsed_secs << std::endl;

      // Statistics
      x+=elapsed_secs;
      xx+=elapsed_secs*elapsed_secs;
      n++;
    }
  //std::cout << "time " << elapsed_secs << std::endl;
  //std::cout << "rate " << m_tree->GetEntries()/elapsed_secs << std::endl;
  return x/m_tree->GetEntries()/n;
}
