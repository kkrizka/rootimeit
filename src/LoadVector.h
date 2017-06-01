#ifndef LOADVECTOR_H_
#define LOADVECTOR_H_

#include <vector>

#include "LoadBase.h"

class LoadVector : public LoadBase
{
public:
  LoadVector();
  ~LoadVector();

protected:
  void setupBranches();

  void runLoop();

private:
  std::vector<float>* m_pointers[10000];
};

#endif // LOADVECTOR_H_
