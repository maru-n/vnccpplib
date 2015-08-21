#!/usr/bin/env python

from vectornav import *
import time
import sys

def listener(sender, data):
    print("python_listener ypr:   % 10.7f % 10.7f % 10.7f" % (data.ypr.yaw, data.ypr.pitch, data.ypr.roll))

vn100 = Vn100()

device = sys.argv[1]

err_code = vn100_connect(vn100, device, 115200)
if err_code != VNERR_NO_ERROR:
    print('Error code: %d' % err_code)
    exit()

err_code = vn100_setAsynchronousDataOutputType(
    vn100,
    VNASYNC_OFF,
    True)
if err_code != VNERR_NO_ERROR:
    print('Error code: %d' % err_code)
    exit()

err_code = vn100_setBinaryOutput1Configuration(
    vn100,
    BINARY_ASYNC_MODE_SERIAL_2,
    100,
    BG1_YPR,
    BG3_NONE,
    BG5_NONE,
    True)
if err_code != VNERR_NO_ERROR:
    print('Error code: %d' % err_code)
    exit()

err_code = vn100_registerAsyncDataReceivedListener(vn100, listener);

while True:
    pass

err_code = vn100_unregisterAsyncDataReceivedListener(vn100, listener);
err_code = vn100_disconnect(vn100);
