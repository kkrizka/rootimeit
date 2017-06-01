#ifndef LOADTCLONESARRAY_H_
#define LOADTCLONESARRAY_H_

#include <vector>

#include <TClonesArray.h>

#include "LoadBase.h"

class LoadTClonesArray : public LoadBase
{
public:
  LoadTClonesArray();
  ~LoadTClonesArray();

protected:
  void setupBranches();

  void runLoop();

private:
  TClonesArray *test;
};

#endif // LOADTCLONESARRAY_H_
