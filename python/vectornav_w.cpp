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
    .def_readwrite("ypr", &VnDeviceCompositeData::ypr);

    // vn100.h (not implemented all)
    boost::python::class_<Vn100>("Vn100");
    boost::python::def( "vn100_connect", &vn100_connect );
    boost::python::def( "vn100_setAsynchronousDataOutputType", &vn100_setAsynchronousDataOutputType );
    boost::python::def( "vn100_getCurrentAsyncData", &vn100_getCurrentAsyncData );
}
