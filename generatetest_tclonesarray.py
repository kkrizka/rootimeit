#!/usr/bin/env python

import ROOT
import random
import os.path
import array

ROOT.gSystem.Load('src/librootimeit.so')

def generate(nbr=50,compress=0):
    outname='/ssdisk02/rootimeit/test_tclonesarray_nbr%05d_comp%d.root'%(nbr,compress)
    #if os.path.exists(outname): return

    random.seed(1)
    fh=ROOT.TFile(outname,'RECREATE','',compress)

    t=ROOT.TTree('tree','tree')

    pointer=ROOT.TClonesArray('Test',10)
    t.Branch('test','TClonesArray',ROOT.AddressOf(pointer))
    data=[]
    for br in range(50):
        data.append([])
        for x in range(10):
            data[br].append(random.random())

    for x in range(10):
        test=ROOT.Test()
        for br in range(50):
            setattr(test,'test%02d'%br,data[br][x])
        pointer[x]=test

    t.SetBranchStatus('*',0)
    for i in range(nbr):
        t.SetBranchStatus('test.test%02d'%i,1)

    for i in range(100000):
        t.Fill()

    t.Write()

    fh.Close()


for compress in [0,1,9]:
    for nbr in [1,5,10,25,50,100]:
        if nbr==0: nbr=1
        generate(nbr,compress)
