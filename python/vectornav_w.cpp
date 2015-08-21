#include <boost/python.hpp>
#include "vectornav.h"
/*
#include <string>
#include <typeinfo>
#include <cxxabi.h>
*/

boost::python::api::object py_async_data_received_listener;
void async_data_received_listener_wrapper(void* sender, VnDeviceCompositeData* data)
{
    py_async_data_received_listener((VnDevice*)sender, data);
}
VN_ERROR_CODE vn100_registerAsyncDataReceivedListener_wrapper(
    Vn100* vn100,
    boost::python::api::object listener)
{
    py_async_data_received_listener = listener;
    return vn100_registerAsyncDataReceivedListener(vn100, &async_data_received_listener_wrapper);
}

DLL_EXPORT VN_ERROR_CODE vn100_unregisterAsyncDataReceivedListener_wrapper(
    Vn100* vn100,
    boost::python::api::object listener)
{
    return vn100_unregisterAsyncDataReceivedListener(vn100, &async_data_received_listener_wrapper);
}

BOOST_PYTHON_MODULE(vectornav)
{
    // vn_kinematics.h
    boost::python::class_<VnYpr>("VnYpr")
    .def_readwrite("yaw", &VnYpr::yaw)
    .def_readwrite("pitch", &VnYpr::pitch)
    .def_readwrite("roll", &VnYpr::roll);
    boost::python::class_<VnQuaternion>("VnQuaternion")
    .def_readwrite("x", &VnQuaternion::x)
    .def_readwrite("y", &VnQuaternion::y)
    .def_readwrite("z", &VnQuaternion::z)
    .def_readwrite("w", &VnQuaternion::w);


    // vn_linearAlgebra.h
    boost::python::class_<VnVector3>("VnVector3")
    .def_readwrite("c0", &VnVector3::c0)
    .def_readwrite("c1", &VnVector3::c1)
    .def_readwrite("c2", &VnVector3::c2);
    boost::python::class_<VnMatrix3x3>("VnMatrix3x3")
    .def_readwrite("c00", &VnMatrix3x3::c00)
    .def_readwrite("c01", &VnMatrix3x3::c01)
    .def_readwrite("c02", &VnMatrix3x3::c02)
    .def_readwrite("c10", &VnMatrix3x3::c10)
    .def_readwrite("c11", &VnMatrix3x3::c11)
    .def_readwrite("c12", &VnMatrix3x3::c12)
    .def_readwrite("c20", &VnMatrix3x3::c20)
    .def_readwrite("c21", &VnMatrix3x3::c21)
    .def_readwrite("c22", &VnMatrix3x3::c22);


    // vndevice.h (not implemented all)
    boost::python::class_<VnDevice>("VnDevice");
    boost::python::class_<VnDeviceCompositeData>("VnDeviceCompositeData")
    .def_readwrite("ypr", &VnDeviceCompositeData::ypr)
    .def_readwrite("quaternion", &VnDeviceCompositeData::quaternion)
    .def_readwrite("magnetic", &VnDeviceCompositeData::magnetic)
    .def_readwrite("acceleration", &VnDeviceCompositeData::acceleration)
    .def_readwrite("angularRate", &VnDeviceCompositeData::angularRate)
    .def_readwrite("dcm", &VnDeviceCompositeData::dcm)
    .def_readwrite("temperature", &VnDeviceCompositeData::temperature)
    .def_readwrite("magneticVoltage", &VnDeviceCompositeData::magneticVoltage)
    .def_readwrite("accelerationVoltage", &VnDeviceCompositeData::accelerationVoltage)
    .def_readwrite("angularRateVoltage", &VnDeviceCompositeData::angularRateVoltage)
    .def_readwrite("temperatureVoltage", &VnDeviceCompositeData::temperatureVoltage)
    .def_readwrite("angularRateBias", &VnDeviceCompositeData::angularRateBias)
    .def_readwrite("attitudeVariance", &VnDeviceCompositeData::attitudeVariance)
    .def_readwrite("angularRateBiasVariance", &VnDeviceCompositeData::angularRateBiasVariance)
    .def_readwrite("timeStartup", &VnDeviceCompositeData::timeStartup)
    .def_readwrite("timeGps", &VnDeviceCompositeData::timeGps)
    .def_readwrite("timeSyncIn", &VnDeviceCompositeData::timeSyncIn)
    .def_readwrite("latitudeLongitudeAltitude", &VnDeviceCompositeData::latitudeLongitudeAltitude)
    .def_readwrite("velocity", &VnDeviceCompositeData::velocity)
    .def_readwrite("angularRateUncompensated", &VnDeviceCompositeData::angularRateUncompensated)
    .def_readwrite("accelerationUncompensated", &VnDeviceCompositeData::accelerationUncompensated)
    .def_readwrite("magneticUncompensated", &VnDeviceCompositeData::magneticUncompensated)
    .def_readwrite("pressure", &VnDeviceCompositeData::pressure)
    .def_readwrite("deltaTime", &VnDeviceCompositeData::deltaTime)
    .def_readwrite("deltaTheta", &VnDeviceCompositeData::deltaTheta)
    .def_readwrite("deltaVelocity", &VnDeviceCompositeData::deltaVelocity)
    .def_readwrite("insStatus", &VnDeviceCompositeData::insStatus)
    .def_readwrite("syncInCnt", &VnDeviceCompositeData::syncInCnt)
    .def_readwrite("timeGpsPps", &VnDeviceCompositeData::timeGpsPps)
    .def_readwrite("gpsTowSec", &VnDeviceCompositeData::gpsTowSec)
    .def_readwrite("gpsTowNs", &VnDeviceCompositeData::gpsTowNs)
    .def_readwrite("gpsWeek", &VnDeviceCompositeData::gpsWeek)
    .def_readwrite("timeUtc", &VnDeviceCompositeData::timeUtc)
    .def_readwrite("sensSat", &VnDeviceCompositeData::sensSat)
    .def_readwrite("numSats", &VnDeviceCompositeData::numSats)
    .def_readwrite("gpsFix", &VnDeviceCompositeData::gpsFix)
    .def_readwrite("gpsPosEcef", &VnDeviceCompositeData::gpsPosEcef)
    .def_readwrite("gpsVelEcef", &VnDeviceCompositeData::gpsVelEcef)
    .def_readwrite("gpsPosU", &VnDeviceCompositeData::gpsPosU)
    .def_readwrite("gpsVelU", &VnDeviceCompositeData::gpsVelU)
    .def_readwrite("timeU", &VnDeviceCompositeData::timeU)
    .def_readwrite("timeAccSec", &VnDeviceCompositeData::timeAccSec)
    .def_readwrite("vpeStatus", &VnDeviceCompositeData::vpeStatus)
    .def_readwrite("magNed", &VnDeviceCompositeData::magNed)
    .def_readwrite("accelNed", &VnDeviceCompositeData::accelNed)
    .def_readwrite("linearAccelBody", &VnDeviceCompositeData::linearAccelBody)
    .def_readwrite("linearAccelNed", &VnDeviceCompositeData::linearAccelNed)
    .def_readwrite("yprU", &VnDeviceCompositeData::yprU)
    .def_readwrite("velBody", &VnDeviceCompositeData::velBody)
    .def_readwrite("velNed", &VnDeviceCompositeData::velNed)
    .def_readwrite("gpsPosLla", &VnDeviceCompositeData::gpsPosLla)
    .def_readwrite("gpsVelocity", &VnDeviceCompositeData::gpsVelocity)
    .def_readwrite("posEcef", &VnDeviceCompositeData::posEcef)
    .def_readwrite("velEcef", &VnDeviceCompositeData::velEcef)
    .def_readwrite("magEcef", &VnDeviceCompositeData::magEcef)
    .def_readwrite("accelEcef", &VnDeviceCompositeData::accelEcef)
    .def_readwrite("linearAccelEcef", &VnDeviceCompositeData::linearAccelEcef)
    .def_readwrite("posU", &VnDeviceCompositeData::posU)
    .def_readwrite("velU", &VnDeviceCompositeData::velU)
    .def_readwrite("attitudeUncertainty", &VnDeviceCompositeData::attitudeUncertainty);

    //boost::python::def( "VnDeviceNewAsyncDataReceivedListener", &VnDeviceNewAsyncDataReceivedListener );

    boost::python::scope().attr("VNASYNC_OFF") = VNASYNC_OFF;
    boost::python::scope().attr("VNASYNC_VNYPR") = VNASYNC_VNYPR;
    boost::python::scope().attr("VNASYNC_VNQTN") = VNASYNC_VNQTN;
    boost::python::scope().attr("VNASYNC_VNQTM") = VNASYNC_VNQTM;
    boost::python::scope().attr("VNASYNC_VNQTA") = VNASYNC_VNQTA;
    boost::python::scope().attr("VNASYNC_VNQTR") = VNASYNC_VNQTR;
    boost::python::scope().attr("VNASYNC_VNQMA") = VNASYNC_VNQMA;
    boost::python::scope().attr("VNASYNC_VNQAR") = VNASYNC_VNQAR;
    boost::python::scope().attr("VNASYNC_VNQMR") = VNASYNC_VNQMR;
    boost::python::scope().attr("VNASYNC_VNDCM") = VNASYNC_VNDCM;
    boost::python::scope().attr("VNASYNC_VNMAG") = VNASYNC_VNMAG;
    boost::python::scope().attr("VNASYNC_VNACC") = VNASYNC_VNACC;
    boost::python::scope().attr("VNASYNC_VNGYR") = VNASYNC_VNGYR;
    boost::python::scope().attr("VNASYNC_VNMAR") = VNASYNC_VNMAR;
    boost::python::scope().attr("VNASYNC_VNYMR") = VNASYNC_VNYMR;
    boost::python::scope().attr("VNASYNC_VNYCM") = VNASYNC_VNYCM;
    boost::python::scope().attr("VNASYNC_VNYBA") = VNASYNC_VNYBA;
    boost::python::scope().attr("VNASYNC_VNYIA") = VNASYNC_VNYIA;
    boost::python::scope().attr("VNASYNC_VNICM") = VNASYNC_VNICM;
    boost::python::scope().attr("VNASYNC_VNIMU") = VNASYNC_VNIMU;
    boost::python::scope().attr("VNASYNC_VNGPS") = VNASYNC_VNGPS;
    boost::python::scope().attr("VNASYNC_VNINS") = VNASYNC_VNINS;
    boost::python::scope().attr("VNASYNC_VNRAW") = VNASYNC_VNRAW;
    boost::python::scope().attr("VNASYNC_VNCMV") = VNASYNC_VNCMV;
    boost::python::scope().attr("VNASYNC_VNSTV") = VNASYNC_VNSTV;
    boost::python::scope().attr("VNASYNC_VNCOV") = VNASYNC_VNCOV;
    boost::python::scope().attr("BINARY_ASYNC_MODE_NONE") = BINARY_ASYNC_MODE_NONE;
    boost::python::scope().attr("BINARY_ASYNC_MODE_SERIAL_1") = BINARY_ASYNC_MODE_SERIAL_1;
    boost::python::scope().attr("BINARY_ASYNC_MODE_SERIAL_2") = BINARY_ASYNC_MODE_SERIAL_2;
    boost::python::scope().attr("BINARY_ASYNC_MODE_SERIAL_1_AND_2") = BINARY_ASYNC_MODE_SERIAL_1_AND_2;

    boost::python::scope().attr("BG1_NONE") = BG1_NONE;
    boost::python::scope().attr("BG1_TIME_STARTUP") = BG1_TIME_STARTUP;
    boost::python::scope().attr("BG1_TIME_GPS") = BG1_TIME_GPS;
    boost::python::scope().attr("BG1_TIME_SYNC_IN") = BG1_TIME_SYNC_IN;
    boost::python::scope().attr("BG1_YPR") = BG1_YPR;
    boost::python::scope().attr("BG1_QTN") = BG1_QTN;
    boost::python::scope().attr("BG1_ANGULAR_RATE") = BG1_ANGULAR_RATE;
    boost::python::scope().attr("BG1_POSITION") = BG1_POSITION;
    boost::python::scope().attr("BG1_VELOCITY") = BG1_VELOCITY;
    boost::python::scope().attr("BG1_ACCEL") = BG1_ACCEL;
    boost::python::scope().attr("BG1_IMU") = BG1_IMU;
    boost::python::scope().attr("BG1_MAG_PRES") = BG1_MAG_PRES;
    boost::python::scope().attr("BG1_DELTA_THETA") = BG1_DELTA_THETA;
    boost::python::scope().attr("BG1_INS_STATUS") = BG1_INS_STATUS;
    boost::python::scope().attr("BG1_SYNC_IN_CNT") = BG1_SYNC_IN_CNT;

    boost::python::scope().attr("BG2_NONE") = BG2_NONE;
    boost::python::scope().attr("BG2_TIME_STARTUP") = BG2_TIME_STARTUP;
    boost::python::scope().attr("BG2_TIME_GPS") = BG2_TIME_GPS;
    boost::python::scope().attr("BG2_GPS_TOW") = BG2_GPS_TOW;
    boost::python::scope().attr("BG2_GPS_WEEK") = BG2_GPS_WEEK;
    boost::python::scope().attr("BG2_TIME_SYNC_IN") = BG2_TIME_SYNC_IN;
    boost::python::scope().attr("BG2_TIME_PPS") = BG2_TIME_PPS;
    boost::python::scope().attr("BG2_TIME_UTC") = BG2_TIME_UTC;
    boost::python::scope().attr("BG2_SYNC_IN_CNT") = BG2_SYNC_IN_CNT;

    boost::python::scope().attr("BG3_NONE") = BG3_NONE;
    boost::python::scope().attr("BG3_UNCOMP_MAG") = BG3_UNCOMP_MAG;
    boost::python::scope().attr("BG3_UNCOMP_ACCEL") = BG3_UNCOMP_ACCEL;
    boost::python::scope().attr("BG3_UNCOMP_GYRO") = BG3_UNCOMP_GYRO;
    boost::python::scope().attr("BG3_TEMP") = BG3_TEMP;
    boost::python::scope().attr("BG3_PRES") = BG3_PRES;
    boost::python::scope().attr("BG3_DELTA_THETA") = BG3_DELTA_THETA;
    boost::python::scope().attr("BG3_DELTA_V") = BG3_DELTA_V;
    boost::python::scope().attr("BG3_MAG") = BG3_MAG;
    boost::python::scope().attr("BG3_ACCEL") = BG3_ACCEL;
    boost::python::scope().attr("BG3_GYRO") = BG3_GYRO;
    boost::python::scope().attr("BG3_SENS_SAT") = BG3_SENS_SAT;

    boost::python::scope().attr("BG4_NONE") = BG4_NONE;
    boost::python::scope().attr("BG4_UTC") = BG4_UTC;
    boost::python::scope().attr("BG4_TOW") = BG4_TOW;
    boost::python::scope().attr("BG4_WEEK") = BG4_WEEK;
    boost::python::scope().attr("BG4_NUM_SATS") = BG4_NUM_SATS;
    boost::python::scope().attr("BG4_FIX") = BG4_FIX;
    boost::python::scope().attr("BG4_POS_LLA") = BG4_POS_LLA;
    boost::python::scope().attr("BG4_POS_ECEF") = BG4_POS_ECEF;
    boost::python::scope().attr("BG4_VEL_NED") = BG4_VEL_NED;
    boost::python::scope().attr("BG4_VEL_ECEF") = BG4_VEL_ECEF;
    boost::python::scope().attr("BG4_POS_U") = BG4_POS_U;
    boost::python::scope().attr("BG4_VEL_U") = BG4_VEL_U;
    boost::python::scope().attr("BG4_TIME_U") = BG4_TIME_U;

    boost::python::scope().attr("BG5_NONE") = BG5_NONE;
    boost::python::scope().attr("BG5_VPE_STATUS") = BG5_VPE_STATUS;
    boost::python::scope().attr("BG5_YPR") = BG5_YPR;
    boost::python::scope().attr("BG5_QUATERNION") = BG5_QUATERNION;
    boost::python::scope().attr("BG5_DCM") = BG5_DCM;
    boost::python::scope().attr("BG5_MAG_NED") = BG5_MAG_NED;
    boost::python::scope().attr("BG5_ACCEL_NED") = BG5_ACCEL_NED;
    boost::python::scope().attr("BG5_LINEAR_ACCEL_BODY") = BG5_LINEAR_ACCEL_BODY;
    boost::python::scope().attr("BG5_LINEAR_ACCEL_NED") = BG5_LINEAR_ACCEL_NED;
    boost::python::scope().attr("BG5_YPR_U") = BG5_YPR_U;

    boost::python::scope().attr("BG6_NONE") = BG6_NONE;
    boost::python::scope().attr("BG6_INS_STATUS") = BG6_INS_STATUS;
    boost::python::scope().attr("BG6_POS_LLA") = BG6_POS_LLA;
    boost::python::scope().attr("BG6_POS_ECEF") = BG6_POS_ECEF;
    boost::python::scope().attr("BG6_VEL_BODY") = BG6_VEL_BODY;
    boost::python::scope().attr("BG6_VEL_NED") = BG6_VEL_NED;
    boost::python::scope().attr("BG6_VEL_ECEF") = BG6_VEL_ECEF;
    boost::python::scope().attr("BG6_MAG_ECEF") = BG6_MAG_ECEF;
    boost::python::scope().attr("BG6_ACCEL_ECEF") = BG6_ACCEL_ECEF;
    boost::python::scope().attr("BG6_LINEAR_ACCEL_ECEF") = BG6_LINEAR_ACCEL_ECEF;
    boost::python::scope().attr("BG6_POS_U") = BG6_POS_U;
    boost::python::scope().attr("BG6_VEL_U") = BG6_VEL_U;


    // vn_errorCodes.h
    boost::python::scope().attr("VNERR_NO_ERROR") = VNERR_NO_ERROR;
    boost::python::scope().attr("VNERR_UNKNOWN_ERROR") = VNERR_UNKNOWN_ERROR;
    boost::python::scope().attr("VNERR_NOT_IMPLEMENTED") = VNERR_NOT_IMPLEMENTED;
    boost::python::scope().attr("VNERR_TIMEOUT") = VNERR_TIMEOUT;
    boost::python::scope().attr("VNERR_INVALID_VALUE") = VNERR_INVALID_VALUE;
    boost::python::scope().attr("VNERR_FILE_NOT_FOUND") = VNERR_FILE_NOT_FOUND;
    boost::python::scope().attr("VNERR_NOT_CONNECTED") = VNERR_NOT_CONNECTED;
    boost::python::scope().attr("VNERR_PERMISSION_DENIED") = VNERR_PERMISSION_DENIED;
    boost::python::scope().attr("VNERR_SENSOR_HARD_FAULT") = VNERR_SENSOR_HARD_FAULT;
    boost::python::scope().attr("VNERR_SENSOR_SERIAL_BUFFER_OVERFLOW") = VNERR_SENSOR_SERIAL_BUFFER_OVERFLOW;
    boost::python::scope().attr("VNERR_SENSOR_INVALID_CHECKSUM") = VNERR_SENSOR_INVALID_CHECKSUM;
    boost::python::scope().attr("VNERR_SENSOR_INVALID_COMMAND") = VNERR_SENSOR_INVALID_COMMAND;
    boost::python::scope().attr("VNERR_SENSOR_NOT_ENOUGH_PARAMETERS") = VNERR_SENSOR_NOT_ENOUGH_PARAMETERS;
    boost::python::scope().attr("VNERR_SENSOR_TOO_MANY_PARAMETERS") = VNERR_SENSOR_TOO_MANY_PARAMETERS;
    boost::python::scope().attr("VNERR_SENSOR_INVALID_PARAMETER") = VNERR_SENSOR_INVALID_PARAMETER;
    boost::python::scope().attr("VNERR_SENSOR_UNAUTHORIZED_ACCESS") = VNERR_SENSOR_UNAUTHORIZED_ACCESS;
    boost::python::scope().attr("VNERR_SENSOR_WATCHDOG_RESET") = VNERR_SENSOR_WATCHDOG_RESET;
    boost::python::scope().attr("VNERR_SENSOR_OUTPUT_BUFFER_OVERFLOW") = VNERR_SENSOR_OUTPUT_BUFFER_OVERFLOW;
    boost::python::scope().attr("VNERR_SENSOR_INSUFFICIENT_BAUD_RATE") = VNERR_SENSOR_INSUFFICIENT_BAUD_RATE;
    boost::python::scope().attr("VNERR_SENSOR_ERROR_BUFFER_OVERFLOW") = VNERR_SENSOR_ERROR_BUFFER_OVERFLOW;


    // vn100.h (not implemented all)
    boost::python::class_<Vn100>("Vn100");
    boost::python::def( "vn100_connect", &vn100_connect );
    boost::python::def( "vn100_disconnect", &vn100_disconnect );
    boost::python::def( "vn100_setAsynchronousDataOutputType", &vn100_setAsynchronousDataOutputType );
    boost::python::def( "vn100_setBinaryOutput1Configuration", &vn100_setBinaryOutput1Configuration );
    boost::python::def( "vn100_getCurrentAsyncData", &vn100_getCurrentAsyncData );
    boost::python::def( "vn100_registerAsyncDataReceivedListener", &vn100_registerAsyncDataReceivedListener_wrapper );
    boost::python::def( "vn100_unregisterAsyncDataReceivedListener", &vn100_unregisterAsyncDataReceivedListener_wrapper );
}
