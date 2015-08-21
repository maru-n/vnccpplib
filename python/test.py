#!/usr/bin/env python

from vectornav import *
import time
import sys

vn100 = Vn100()

device = sys.argv[1]

err_code = vn100_connect(vn100, device, 115200)
if err_code != VNERR_NO_ERROR:
    print('Error code: %d' % err_code)
    exit()

err_code = vn100_setAsynchronousDataOutputType(
    vn100,
    VNASYNC_VNQMR,
    True)
if err_code != VNERR_NO_ERROR:
    print('Error code: %d' % err_code)
    exit()

for i in range(30):
    data = VnDeviceCompositeData()
    vn100_getCurrentAsyncData(vn100, data)
    print("q:     % 15.12f % 15.12f % 15.12f % 15.12f" % (data.quaternion.x, data.quaternion.y, data.quaternion.z, data.quaternion.w))
    print("accel: % 15.12f % 15.12f % 15.12f" % (data.acceleration.c0, data.acceleration.c1, data.acceleration.c2))
    print("gyro:  % 15.12f % 15.12f % 15.12f" % (data.angularRate.c0, data.angularRate.c1, data.angularRate.c2))
    print("mag:   % 15.12f % 15.12f % 15.12f" % (data.magnetic.c0, data.magnetic.c1, data.magnetic.c2))
    print("")
    time.sleep(0.1)
