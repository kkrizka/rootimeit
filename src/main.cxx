#include <iostream>

#include "LoadBase.h"

int main(int argc, char* argv[])
{
  LoadBase lb;
  lb.setPath("/ssdisk02/test.root");
  lb.setNBranches(50);
  
  lb.setNHists(0);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(1000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(10000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(20000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(30000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(40000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(50000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(60000);
  std::cout << lb.runTest() << std::endl;

  lb.setNHists(70000);
  std::cout << lb.runTest() << std::endl;
}
