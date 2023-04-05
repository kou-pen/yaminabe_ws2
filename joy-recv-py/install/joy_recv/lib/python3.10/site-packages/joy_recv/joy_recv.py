#!/usr/bin/env /usr/bin/python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy

import can
from UsbCan import UsbCan

class JoyRecv(Node):
    node_name = 'joy_recv'
    topic_name = 'joy'
    Ucan = UsbCan()
    def __init__(self) -> None:
        super().__init__(self.node_name)
        self.sub = self.create_subscription(Joy, self.topic_name, self.callback, 10)
        self.Ucan.open()
        
        
    def __del__(self):
        self.Ucan.close()
    
    def callback(self, joy):
        buttondata = [0] * 8
        buttondata[0] = joy.axes[0] * 127 + 128 #0~256
        buttondata[1] = joy.axes[1] * 127 + 128
        buttondata[2] = joy.axes[3] * 127 + 128
        buttondata[3] = joy.axes[4] * 127 + 128 
        buttondata[4] = joy.buttons[0]
        buttondata[5] = joy.buttons[1]
        buttondata[6] = joy.buttons[2]
        buttondata[7] = joy.buttons[3]
        msg = can.Message(arbitration_id=0x001,
                    is_extended_id= False,
                    data= [int(buttondata[0]),int(buttondata[1]),int(buttondata[2]),int(buttondata[3]),int(buttondata[4]),int(buttondata[5]),int(buttondata[6]),int(buttondata[7])]
        )
        self.Ucan.send(msg)
        buttondata = map(int,buttondata)
        print_text = "axis:{},{},{},{}, button:a{},b{},x{},y{}"
        self.get_logger().info(print_text.format(*buttondata))
    
        
def main(args=None):
    rclpy.init(args=args)
    joy_recv = JoyRecv()
    try:
        rclpy.spin(joy_recv)
    except KeyboardInterrupt:
        pass
    finally:
        joy_recv.destroy_node()
        
if __name__ == '__main__':
    main()
