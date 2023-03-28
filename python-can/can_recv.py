from UsbCan import UsbCan

can = UsbCan()

try:
    can.open()
    
    can.send(1,128)
except OSError:
	print('error OS')
 
 
    