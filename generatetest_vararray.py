#!/usr/bin/env python

import ROOT
import random
import os.path
import array

def generate(nbr=50,compress=0):
    outname='/ssdisk02/rootimeit/test_vararray_nbr%05d_comp%d.root'%(nbr,compress)
    if os.path.exists(outname): return

    random.seed(1)
    fh=ROOT.TFile(outname,'RECREATE','',compress)

    t=ROOT.TTree('tree','tree')

    pointers=[]
    n = array.array('i',[10])
    t.Branch('ntest',n,'ntest/I')
    for i in range(nbr):
        vec = array.array('d',[0.]*10)
        for x in range(10):
            vec[x]=random.random()
        t.Branch('test%02d'%i,vec,'test%02d[ntest]/D'%i)
        pointers.append(vec)

    for i in range(100000):
        t.Fill()
    t.Show(0)

    t.Write()

    fh.Close()


for compress in [0,1,9]:
    for nbr in [1,5,10,25,50,100]:
        if nbr==0: nbr=1
        generate(nbr,compress)
