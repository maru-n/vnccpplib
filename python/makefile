SRC = vectornav_w.cpp ../src/vn100.c ../src/vndevice.c ../src/arch/linux/vncp_services.c

all: $(SRC)
	g++ -I`python -c 'from distutils.sysconfig import *; print(get_python_inc())'` -I../include -DPIC -shared -fPIC -o vectornav.so $(SRC) -lboost_python

clean:
	rm -f *.o *.so
