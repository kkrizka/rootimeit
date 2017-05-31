#include <iostream>

#include "LoadBase.h"

int main(int argc, char* argv[])
{
  LoadBase lb;
  lb.setPath("/ssdisk02/test.root");
  lb.setNBranches(50);
  lb.setNHists(0);
  std::cout << lb.runTest() << std::endl;
}
