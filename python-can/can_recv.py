from UsbCan import UsbCan
import time
import can

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--cantime', default='50')
parser.add_argument('--pause', default='1')
args = parser.parse_args()

count_argv= int(args.cantime)
pause_time = float(args.pause)
"""
if count_argv > 255:
    count_argv = 255
    """
Ucan = UsbCan()
txdata = [1,2,3,4,5,6,7,8]
Ucan.open()



for i in range(count_argv):
    msg = can.Message(arbitration_id=0x001,
                      is_extended_id= False,
                      data=[1,1,1,1,1,1,1,1]
                      #data=[i,i + 1,i + 2,i + 3,i + 4,i + 5,i + 6,i + 7]
                      )
    Ucan.send(msg)
    print('{}:{}'.format(i,msg))
    time.sleep(pause_time)

"""
for i in range(30): #test code
    msg = can.Message(
            arbitration_id=0x001, 
            is_extended_id =0, 
            data=[255,255,255,255,255,255,255,255])
    print(msg)
    Ucan.send(msg)
    time.sleep(0.005)
"""

'''
while True:
    msg = can.Message(
        	arbitration_id=0x001, 
            is_extended_id =1, 
            data=[1,2,3,4,5,6,7,8])
    print(msg)
    Ucan.send(msg)
    time.sleep(0.005)

for i in range(30):
    msg = can.Message(
        arbitration_id=0x001, 
        is_extended_id =1, 
        data=[i,i,i,i,i,i,i,i])
    print(msg)
    Ucan.send(msg)
    time.sleep(0.005)
'''

Ucan.close()

 
 
 
    