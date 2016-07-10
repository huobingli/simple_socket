cc=g++
start:client.o clientSocket.o param.h
	$(cc) -o client client.o -lpthread
client.o:
	$(cc) -c -o client.o client.cpp -lpthread
clientSocket:
	$(cc) -c -o clientSocket.o clientSocket.cpp
clean:
	rm -f *.o