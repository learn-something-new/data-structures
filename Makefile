program:
	g++ -c -o stack/lib/stack.o stack/stack.cpp
	g++ -c -o stack/lib/main.o stack/main.cpp
	g++ -o bin/stack stack/lib/stack.o stack/lib/main.o

	g++ -c -o queue/lib/queue.o queue/queue.cpp
	g++ -c -o queue/lib/main.o queue/main.cpp
	g++ -o bin/queue queue/lib/queue.o queue/lib/main.o
