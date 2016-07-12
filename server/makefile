cc=g++
start: param.h server.o serverSocket.o epoll.o cacheLinkTable.o threadPool.o threadControl.o
	$(cc) -o server server.o  -lpthread
server.o: 
	$(cc) -c -o server.o server.cpp -lpthread
epoll.o: 
	$(cc) -c -o epoll.o epoll.cpp
cacheLinkTable.o: 
	$(cc) -c -o cacheLinkTable.o cacheLinkTable.cpp
serverSocket.o: 
	$(cc) -c -o serverSocket.o serverSocket.cpp
threadControl.o:
	$(cc) -c -o threadControl.o threadControl.cpp -lpthread
threadPool.o:
	$(cc) -c -o threadPool.o threadPool.cpp -lpthread
clean:
	rm -f *.o

# epoll.o: epoll.cpp
# 	g++ -c -o epoll.o epoll.cpp
# serverSocket.o: param.h serverSocket.cpp 
# 	g++ -c -o serverSocket.o serverSocket.cpp
# server.o: server.cpp param.h
# 	g++ -c -o server.o server.cpp -lpthread
# cacheLinkTable.o: cacheLinkTable.cpp
# 	g++ -c -o cacheLinkTable.o cacheLinkTable.cpp