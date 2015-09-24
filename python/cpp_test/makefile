main: main.o vn100.o vncp_services.o vndevice.o
	gcc -pthread -o main main.o vn100.o vndevice.o vncp_services.o -lrt

main.o: main.c
	gcc -c -Wall -I../../include main.c

vn100.o: ../../src/vn100.c
	gcc -c -Wall -I../../include ../../src/vn100.c

vndevice.o: ../../src/vndevice.c
	gcc -c -Wall -I../../include ../../src/vndevice.c

vncp_services.o: ../../src/arch/linux/vncp_services.c
	gcc -c -Wall -I../../include ../../src/arch/linux/vncp_services.c

clean:
	rm -f *.o main
