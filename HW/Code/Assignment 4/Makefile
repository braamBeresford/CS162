CC = g++ -g  
exe_file = assignment4

$(exe_file): driver.o house.o property.o tenant.o apartment.o business.o player.o
	$(CC) driver.o house.o property.o tenant.o apartment.o business.o player.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
run: $(exe_file)
	$(exe_file)
clean:
	rm -f *.out *.o *~ $(exe_file)
