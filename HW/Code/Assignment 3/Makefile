CC = g++ -g
exe_file = assignment2

$(exe_file): driver.o menu.o pizza.o restaurant.o driver_functions.o
	$(CC) driver.o menu.o pizza.o restaurant.o driver_functions.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
driver_functions.o: driver_functions.cpp
	$(CC) -c driver_functions.cpp
run: $(exe_file)
	$(exe_file)
clean:
	rm -f *.out *.o *~ $(exe_file)
