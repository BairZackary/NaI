
# coding: utf-8

# In[1]:


import os
import sys
class NullWriter(object):
    def write(self, arg):
        pass
from HTSDKScope import Oscilloscope
#help(Oscilloscope)


def SetScope(Ch1VDivIndex=0,Ch2VDivIndex=0,TimeDivIndex=11): 
    VScale2 = VScale1= TScale = 1
    
#{0: ('20 mV/Div', 0.02), 1: ('50 mV/Div', 0.05), 2: ('100 mV/Div', 0.1), 
#3: ('200 mV/Div', 0.2), 4: ('500 mV/Div', 0.5), 5: ('1 V/Div', 1.0), 
#6: ('2 V/Div', 2.0), 7: ('5 V/Div', 5.0)}    
    if(Ch1VDivIndex==0): VScale1 = 0.02/32
    elif(Ch1VDivIndex==1): VScale1 = 0.05/32
    elif(Ch1VDivIndex==2): VScale1 = 0.1/32
    elif(Ch1VDivIndex==3): VScale1 = 0.2/32
    elif(Ch1VDivIndex==4): VScale1 = 0.5/32
    elif(Ch1VDivIndex==5): VScale1 = 1.0/32
    elif(Ch1VDivIndex==6): VScale1 = 2.0/32
    else: VScale1 = 5.0/32
        
    if(Ch1VDivIndex==0): VScale2 = 0.02/32 
    elif(Ch1VDivIndex==1): VScale2 = 0.05/32
    elif(Ch1VDivIndex==2): VScale2 = 0.1/32
    elif(Ch1VDivIndex==3): VScale2 = 0.2/32
    elif(Ch1VDivIndex==4): VScale2 = 0.5/32
    elif(Ch1VDivIndex==5): VScale2 = 1.0/32
    elif(Ch1VDivIndex==6): VScale2 = 2.0/32
    else: VScale2 = 5.0/32
# Need to return VScale2 and TScale also eventually          
# TimeDivIndex 
#{0: ('48 MSa/s', 48000000.0), 1: ('48 MSa/s', 48000000.0), 2: ('48 MSa/s', 48000000.0), 3: ('48 MSa/s', 48000000.0),
#4: ('48 MSa/s', 48000000.0), 5: ('48 MSa/s', 48000000.0), 6: ('48 MSa/s', 48000000.0), 7: ('48 MSa/s', 48000000.0), 
#8: ('48 MSa/s', 48000000.0), 9: ('48 MSa/s', 48000000.0), 10: ('48 MSa/s', 48000000.0), 
#11: ('16 MSa/s', 16000000.0), 12: ('8 MSa/s', 8000000.0), 13: ('4 MSa/s', 4000000.0), 
#14: ('1 MSa/s', 1000000.0), 15: ('1 MSa/s', 1000000.0), 16: ('1 MSa/s', 1000000.0), 
#17: ('1 MSa/s', 1000000.0), 18: ('1 MSa/s', 1000000.0), 19: ('1 MSa/s', 1000000.0), 20: ('1 MSa/s', 1000000.0), 
#21: ('1 MSa/s', 1000000.0), 22: ('1 MSa/s', 1000000.0), 23: ('1 MSa/s', 1000000.0), 24: ('1 MSa/s', 1000000.0), 
#25: ('500 KSa/s', 500000.0), 26: ('200 KSa/s', 200000.0), 27: ('100 KSa/s', 100000.0)}
    if(Ch1VDivIndex==0): TScale = 2e4
    elif(Ch1VDivIndex==1): TScale = 2e4*3.
    else: TScale = 2e4*3.

    scope0 = Oscilloscope(scopeid=0)
    scope0.set_voltage_division(1, Ch1VDivIndex)
    scope0.set_voltage_division(2, Ch2VDivIndex)
    scope0.set_sampling_rate(TimeDivIndex)
    import sys

    nullwrite = NullWriter()
    oldstdout = sys.stdout
    sys.stdout = nullwrite # disable output
    scope0.setup_dso_cal_level() 
    sys.stdout = oldstdout # enable output 
    return scope0, TScale, VScale1, VScale2


# In[ ]:


import os
import time
import numpy as np
import matplotlib.pyplot as plt
get_ipython().magic(u'matplotlib inline')
 
# VDiv 0 -> max 100mV # VDiv 1 -> max 250mV
# VDiv 2 -> max 500mV # VDiv 3 -> max 1V
# VDiv 4 -> max 2.5V # VDiv 5 -> max 5.0V
# VDiv 6 -> max 10.0V # VDiv 7 -> max 25.0V
scope0,TScale,VScale1,VScale2=SetScope(3,3,11)
#TenXProbe=True
#if(TenXProbe): 
#    VScale1=VScale1*10
#    VScale2=VScale2*10

#(3,3,11) <-- 10:48Mhz 11:16Mhz
numSampRead = 2000
numSampSave = 2000/2
Ch1Trig = -0.1
Ch2Trig = 0.01
TriggerType = "Negative"
#TriggerType = "Veto"
#TriggerType = "Coincidence"
MaxTrig = 10
PlotIt = False
if(MaxTrig < 11): 
    PlotIt = True
else:
    outputFile = "C:\Users\DarkMatter\Documents\Data\Co60_20180801_HV1600_Gain1000_VDiv5_Trig0.1V_1M.csv"
    try: os.remove(outputFile)
    except OSError: pass
    f_handle = file(outputFile, 'a')
    
    
Triggered = False
NumTrig = 0
numDouble=0.
start_time = time.time()
print("Waiting for Trigger start time: ",time.time())   
while(MaxTrig > NumTrig):
    rawData = scope0.read_data_from_scope(data_points=numSampRead)
    ch1Data = np.asarray(rawData[0])*VScale1
    ch2Data = np.asarray(rawData[1])*VScale2
    timeData = np.asarray(rawData[2])*TScale# conversion to microsec
    
    if(TriggerType == "Negative" and ch1Data.min() < Ch1Trig):  
        NumTrig=NumTrig+1
        ch1Max = np.argmax(ch1Data)
        if(NumTrig % 1000 == 0):
            print("Triggered on Ch1 at ",Ch1Trig," V, NumTrig= ",NumTrig, " time ", time.time()- start_time)
        if(ch1Max+numSampSave > numSampRead): ch1Max = numSampRead-numSampSave
        if(ch1Max-numSampSave < 0): ch1Max = numSampSave
        
        if(PlotIt == True):
            plt.plot(timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch1Data[ch1Max-numSampSave:ch1Max+numSampSave], 'y-',
                     timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch2Data[ch1Max-numSampSave:ch1Max+numSampSave], 'b-')
            plt.xlabel("time[us]")
            plt.ylabel("Volt [V]")
            plt.show()
        else:
            np.savetxt(f_handle, [ch1Data[ch1Max-numSampSave:ch1Max+numSampSave],
                      ch2Data[ch1Max-numSampSave:ch1Max+numSampSave],
                      timeData[ch1Max-numSampSave:ch1Max+numSampSave]], delimiter=",", fmt='%f')
    
    if(TriggerType == "Veto" and ch1Data.max() > Ch1Trig and ch2Data.max() < Ch2Trig):  
        NumTrig=NumTrig+1
        ch1Max = np.argmax(ch1Data)
        if(NumTrig % 1000 == 0):
            print("Triggered on Ch1 at ",Ch1Trig," V, NumTrig= ",NumTrig, " time ", time.time()- start_time)
        if(ch1Max+numSampSave > numSampRead): ch1Max = numSampRead-numSampSave
        if(ch1Max-numSampSave < 0): ch1Max = numSampSave
        
        if(PlotIt == True):
            plt.plot(timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch1Data[ch1Max-numSampSave:ch1Max+numSampSave], 'y-',
                     timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch2Data[ch1Max-numSampSave:ch1Max+numSampSave], 'b-')
            plt.xlabel("time[us]")
            plt.ylabel("Volt [V]")
            plt.show()
        else:
            np.savetxt(f_handle, [ch1Data[ch1Max-numSampSave:ch1Max+numSampSave],
                      ch2Data[ch1Max-numSampSave:ch1Max+numSampSave],
                      timeData[ch1Max-numSampSave:ch1Max+numSampSave]], delimiter=",", fmt='%f')
            
    if(TriggerType == "Coincidence" and ch1Data.max() > Ch1Trig and ch2Data.max() > Ch2Trig):  
        NumTrig=NumTrig+1
        ch1Max = np.argmax(ch1Data)
        if( (NumTrig % 1000 == 0) or (NumTrig < 1000 and NumTrig % 10 == 0) ):
            print("Triggered on Ch1 at ",Ch1Trig," V, NumTrig= ",NumTrig, " time ", time.time()- start_time)
        if(ch1Max+numSampSave > numSampRead): ch1Max = numSampRead-numSampSave
        if(ch1Max-numSampSave < 0): ch1Max = numSampSave
        
        if(PlotIt == True):
            plt.plot(timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch1Data[ch1Max-numSampSave:ch1Max+numSampSave], 'y-',
                     timeData[ch1Max-numSampSave:ch1Max+numSampSave], ch2Data[ch1Max-numSampSave:ch1Max+numSampSave], 'b-')
            plt.xlabel("time[us]")
            plt.ylabel("Volt [V]")
            plt.show()
        else:
            np.savetxt(f_handle, [ch1Data[ch1Max-numSampSave:ch1Max+numSampSave],
                        ch2Data[ch1Max-numSampSave:ch1Max+numSampSave],
                        timeData[ch1Max-numSampSave:ch1Max+numSampSave]], delimiter=",", fmt='%f')
if(not PlotIt): f_handle.close()


# In[ ]:


f_handle.close() # Always do this to close the file if you interrupted data taking.

