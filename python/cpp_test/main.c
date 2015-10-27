#include <stdio.h>
#include <unistd.h>
#include "vectornav.h"

/* Change the connection settings to your configuration. */
const char* const COM_PORT = "/dev/ttyO1";
const int BAUD_RATE = 115200;

void asyncDataListener(
	void* sender,
	VnDeviceCompositeData* data);

int main()
{
	VN_ERROR_CODE errorCode;
	Vn100 vn100;

	errorCode = vn100_connect(
		&vn100,
		COM_PORT,
		BAUD_RATE);
	printf("error_cod: %d\n", errorCode);

	/* Make sure the user has permission to use the COM port. */
	if (errorCode == VNERR_PERMISSION_DENIED) {

		printf("Current user does not have permission to open the COM port.\n");
		printf("Try running again using 'sudo'.\n");

		return 0;
	}
	else if (errorCode != VNERR_NO_ERROR)
	{
		printf("Error encountered when trying to connect to the sensor.\n");

		return 0;
	}

	/* Disable ASCII asynchronous messages since we want to demonstrate the
	   the binary asynchronous messages. */
	errorCode = vn100_setAsynchronousDataOutputType(
        &vn100,
        VNASYNC_OFF,
        true);
	printf("error_cod: %d\n", errorCode);

	/* Now configure the binary messages output. Notice how the configuration
	   flags can be joined using the binary OR. */
	errorCode = vn100_setBinaryOutput1Configuration(
		&vn100,
		BINARY_ASYNC_MODE_SERIAL_2,		/* Data will be output on serial port 1. This should be the one we are connected to now. */
		400,							/* Outputting binary data at 4 Hz (800 Hz on-board filter / 200 = 4 Hz). */
		//BG1_NONE,
		BG1_TIME_STARTUP|BG1_DELTA_THETA|BG1_DELTA_THETA|BG1_QTN|BG1_YPR, //NG
		//BG1_DELTA_THETA|BG1_DELTA_THETA|BG1_QTN|BG1_YPR, //NG
		//BG1_DELTA_THETA|BG1_DELTA_THETA|BG1_QTN, //OK
		//BG3_NONE,
		//BG3_ACCEL,
		BG3_ACCEL|BG3_GYRO|BG3_UNCOMP_MAG,
		BG5_NONE,
		true);
	printf("error_cod: %d\n", errorCode);
	printf("Yaw, Pitch, Roll\n");

	/* Now register to receive notifications when a new binary asynchronous
	   packet is received. */
	errorCode = vn100_registerAsyncDataReceivedListener(&vn100, &asyncDataListener);

	/* Sleep for 10 seconds. Data will be received by the asycDataListener
	   during this time. */
	sleep(1);

	errorCode = vn100_unregisterAsyncDataReceivedListener(&vn100, &asyncDataListener);

	errorCode = vn100_disconnect(&vn100);

	if (errorCode != VNERR_NO_ERROR)
	{
		printf("Error encountered when trying to disconnect from the sensor.\n");

		return 0;
	}

	return 0;
}

void asyncDataListener(void* sender, VnDeviceCompositeData* data)
{

	printf("  %+#7.2f %+#7.2f %+#7.2f\n",
		data->ypr.yaw,
		data->ypr.pitch,
		data->ypr.roll);
}
