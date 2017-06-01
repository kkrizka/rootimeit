#ifndef LOADBASE_H_
#define LOADBASE_H_

#include <vector>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TH1.h>

class LoadBase
{
public:
  LoadBase();
  ~LoadBase();

  void setPath(const std::string& path);
  void setNBranches(uint nBranches);
  void setNHists(uint nHists);

  void setCacheSize(uint size);
  
  double eventSize();

  double runTest();

protected:
  virtual void setupInput();
  virtual void setupBranches();
  virtual void setupHists();

  virtual void runLoop() =0;

  std::string m_path;
  uint m_nBranches;
  uint m_nHists;

  uint m_cacheSize;

  TFile *m_fh;
  TTree *m_tree;

  std::vector<TH1*> m_hists;
};

#endif // LOADBASE_H_
