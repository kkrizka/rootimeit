#include <iostream>

#include "LoadBase.h"
#include "LoadVector.h"
#include "LoadArray.h"
#include "LoadTClonesArray.h"

int main(int argc, char* argv[])
{
  LoadBase *lb=0;

  lb=new LoadVector();
  lb->setPath("/ssdisk02/rootimeit/test_nbr00050_comp0.root");
  lb->setNBranches(50);
  lb->setNHists(0);
  std::cout << "vector " << lb->runTest() << std::endl;

  lb=new LoadArray();
  lb->setPath("/ssdisk02/rootimeit/test_array_nbr00050_comp0.root");
  lb->setNBranches(50);
  lb->setNHists(0);
  std::cout << "array " << lb->runTest() << std::endl;

  lb=new LoadTClonesArray();
  lb->setPath("/ssdisk02/rootimeit/test_tclonesarray_nbr00050_comp0.root");
  lb->setNBranches(50);
  lb->setNHists(0);
  std::cout << "TClonesArray " << lb->runTest() << std::endl;
}
