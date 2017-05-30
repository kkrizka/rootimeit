#!/usr/bin/env python

import ROOT
import timeit
import matplotlib.pyplot as plt

x=range(50)
y=[]
t=[]

for n in x:
    formula='+'.join(['test%02d[0]'%i for i in range(n+1)])
    time=timeit.timeit('t.Draw("%s")'%formula, setup='import ROOT; fh=ROOT.TFile("/ssdisk02/test.root"); t=fh.Get("tree"); t.Draw("test00")', number=1)/1
    print(n,100e3/time/1000,time)
    y.append(100e3/time/1000)
    t.append(time)

# plt.plot(x,y)
# plt.xlabel('# of branches')
# plt.ylabel('Rate (kHz)')
# plt.savefig('test.pdf')

plt.plot(x,t)
plt.xlabel('# of branches')
plt.ylabel('time (s)')
plt.savefig('testtime.pdf')
