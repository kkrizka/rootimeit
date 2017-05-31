#!/usr/bin/env python

import ROOT

fh=ROOT.TFile('test.root','RECREATE')

t=ROOT.TTree('tree','tree')

pointers=[]
for i in range(50):
    vec = ROOT.vector('double')()
    for x in range(5):
        vec.push_back(x)
    t.Branch('test%02d'%i,vec)
    pointers.append(vec)

for i in range(100000):
    t.Fill()

t.Write()

fh.Close()
