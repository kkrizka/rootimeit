#!/usr/bin/env python

import ROOT
import random
import os.path
import array

ROOT.gSystem.Load('src/librootimeit.so')

def generate(compress=0):
    outname='/ssdisk02/rootimeit/test_tclonesarray_nbr00050_comp%d.root'%(compress)
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

    for i in range(100000):
        t.Fill()

    t.Write()

    fh.Close()


for compress in [0,1,9]:
    generate(compress)
