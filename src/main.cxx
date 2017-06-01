#include <iostream>

#include "LoadBase.h"
#include "LoadVector.h"

int main(int argc, char* argv[])
{
  LoadBase *lb=new LoadVector();
  lb->setPath("/ssdisk02/rootimeit/test_nbr00050_comp0.root");
  lb->setNBranches(50);
  lb->setNHists(0);
  std::cout << lb->runTest() << std::endl;
}
