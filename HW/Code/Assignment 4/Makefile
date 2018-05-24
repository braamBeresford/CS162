CC = g++ -g 
exe_file = assignment4

$(exe_file): driver.o insect.o bodyguard.o gameEngine.o harvester.o longT.o ninja.o player.o shortT.o thrower.o wall.o bee.o fire.o
	$(CC) driver.o insect.o bodyguard.o gameEngine.o harvester.o longT.o ninja.o player.o shortT.o thrower.o wall.o bee.o fire.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
insect.o: insect.cpp
	$(CC) -c insect.cpp
bodyguard.o: bodyguard.cpp
	$(CC) -c bodyguard.cpp
gameEngine.o: gameEngine.cpp
	$(CC) -c gameEngine.cpp
harvester.o: harvester.cpp
	$(CC) -c harvester.cpp
longT.o: longT.cpp
	$(CC) -c longT.cpp
ninja.o: ninja.cpp
	$(CC) -c ninja.cpp
player.o: player.cpp
	$(CC) -c player.cpp
shortT.o: shortT.cpp
	$(CC) -c shortT.cpp
thrower.o: thrower.cpp
	$(CC) -c thrower.cpp
wall.o: wall.cpp
	$(CC) -c wall.cpp
bee.o: bee.cpp
	$(CC) -c bee.cpp
fire.o: fire.cpp
	$(CC) -c fire.cpp
run: $(exe_file)
	./$(exe_file)
clean:
	rm -f *.out *.o *~ $(exe_file)
