#ifndef LOADARRAY_H_
#define LOADARRAY_H_

#include "LoadBase.h"

class LoadArray : public LoadBase
{
public:
  LoadArray();
  ~LoadArray();

protected:
  void setupBranches();

  void runLoop();

private:
  float m_pointers[10000][10];
};

#endif // LOADARRAY_H_
