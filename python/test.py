#!/usr/bin/env python

from vectornav import *
import time
import sys

class ListenerTestClass(object):
    """docstring for ListenerTestClass"""
    def __init__(self):
        super(ListenerTestClass, self).__init__()

    def listener(self, sender, data):
        #print(self)
        print("python_listener ypr:   % 10.7f % 10.7f % 10.7f" % (data.ypr.yaw, data.ypr.pitch, data.ypr.roll))


def listener(sender, data):
    print("python_listener ypr:   % 10.7f % 10.7f % 10.7f" % (data.ypr.yaw, data.ypr.pitch, data.ypr.roll))


vn100 = Vn100()

device = sys.argv[1]

err_code = vn100_connect(vn100, device, int(sys.argv[2]))
print("vn100_connect error code: %d" % err_code)

err_code = vn100_setAsynchronousDataOutputType(
    vn100,
    VNASYNC_OFF,
    True)
print("vn100_setAsynchronousDataOutputType: %d" % err_code)

err_code = vn100_setBinaryOutput1Configuration(
    vn100,
    BINARY_ASYNC_MODE_SERIAL_2,
    8,
    BG1_YPR,
    BG3_NONE,
    BG5_NONE,
    True)
print("vn100_setBinaryOutput1Configuration: %d" % err_code)

err_code = vn100_registerAsyncDataReceivedListener(vn100, listener);
#a = ListenerTestClass()
#err_code = vn100_registerAsyncDataReceivedListener(vn100, a.listener);
print("vn100_registerAsyncDataReceivedListener: %d" % err_code)

time.sleep(5.0)

err_code = vn100_unregisterAsyncDataReceivedListener(vn100, listener);
print("vn100_unregisterAsyncDataReceivedListener: %d" % err_code)

err_code = vn100_disconnect(vn100);
print("vn100_disconnect: %d" % err_code)
