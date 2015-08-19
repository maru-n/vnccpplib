#include <boost/python.hpp>
#include "vectornav.h"

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


    // vndevice.h (not implemented all)
    boost::python::class_<VnDeviceCompositeData>("VnDeviceCompositeData")
    .def_readwrite("ypr", &VnDeviceCompositeData::ypr)
    .def_readwrite("quaternion", &VnDeviceCompositeData::quaternion);

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
    boost::python::def( "vn100_setAsynchronousDataOutputType", &vn100_setAsynchronousDataOutputType );
    boost::python::def( "vn100_getCurrentAsyncData", &vn100_getCurrentAsyncData );
}
