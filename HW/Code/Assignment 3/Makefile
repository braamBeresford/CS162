CC = g++ -g 
exe_file = assignment3

$(exe_file): driver.o house.o property.o tenant.o apartment.o business.o
	$(CC) driver.o house.o property.o tenant.o apartment.o business.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
house.o: house.cpp
	$(CC) -c house.cpp
property.o: property.cpp
	$(CC) -c property.cpp
tenant.o: tenant.cpp
	$(CC) -c tenant.cpp
apartment.o: apartment.cpp
	$(CC) -c apartment.cpp
business.o: business.cpp
	$(CC) -c business.cpp
run: $(exe_file)
	$(exe_file)
clean:
	rm -f *.out *.o *~ $(exe_file)
