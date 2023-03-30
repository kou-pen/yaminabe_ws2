from UsbCan import UsbCan
import time
import can

Ucan = UsbCan()
txdata = [1,2,3,4,5,6,7,8]
Ucan.open()

count = int(input('how many times'))
if count > 255:
    count = 255

for i in range(count):
    msg = can.Message(arbitration_id=0x001,
                      is_extended_id= False,
                      data=[i,255,255,255,255,255,255,255]
                      )
    Ucan.send(msg)
    print('{}:{}'.format(i,msg))
    time.sleep(0.005)

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

 
 
 
    