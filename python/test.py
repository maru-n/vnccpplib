#!/usr/bin/env python

import vectornav
import time
import sys

vn100 = vectornav.Vn100()


device = sys.argv[1]
err = vectornav.vn100_connect(vn100, device, 115200)
print(err)
err = vectornav.vn100_setAsynchronousDataOutputType(vn100, 1, True)
print(err)

for i in range(30):
    data = vectornav.VnDeviceCompositeData()
    vectornav.vn100_getCurrentAsyncData(vn100, data)
    print("%f %f %f" % (data.ypr.yaw, data.ypr.pitch, data.ypr.roll))
    time.sleep(0.5)
