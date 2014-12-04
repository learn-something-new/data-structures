program:
	g++ -g -c -o stack/lib/stack.o stack/stack.cpp
	g++ -g -c -o stack/lib/main.o stack/main.cpp
	g++ -g -o bin/stack stack/lib/stack.o stack/lib/main.o
	g++ -g -c -o queue/lib/queue.o queue/queue.cpp
	g++ -g -c -o queue/lib/main.o queue/main.cpp
	g++ -g -o bin/queue queue/lib/queue.o queue/lib/main.o
	g++ -g -c -o linkedlist/lib/linkedlist.o linkedlist/linkedlist.cpp
	g++ -g -c -o linkedlist/lib/main.o linkedlist/main.cpp
	g++ -g -o bin/linkedlist linkedlist/lib/linkedlist.o linkedlist/lib/main.o
	g++ -g -c -o stackedlist/lib/stack.o stackedlist/stack.cpp
	g++ -g -c -o stackedlist/lib/main.o stackedlist/main.cpp
	g++ -g -o bin/stackedlist stackedlist/lib/stack.o stackedlist/lib/main.o
	g++ -g -c -o queuedlist/lib/queue.o queuedlist/queue.cpp
	g++ -g -c -o queuedlist/lib/main.o queuedlist/main.cpp
	g++ -g -o bin/queuedlist queuedlist/lib/queue.o queuedlist/lib/main.o
	g++ -g -c -o doublylinkedlist/lib/linkedlist.o doublylinkedlist/linkedlist.cpp
	g++ -g -c -o doublylinkedlist/lib/main.o doublylinkedlist/main.cpp
	g++ -g -o bin/doublylinkedlist doublylinkedlist/lib/linkedlist.o doublylinkedlist/lib/main.o
	g++ -g -c -o binarysearchtree/lib/bst.o binarysearchtree/bst.cpp
	g++ -g -c -o binarysearchtree/lib/main.o binarysearchtree/main.cpp
	g++ -g -o bin/binarysearchtree binarysearchtree/lib/bst.o binarysearchtree/lib/main.o
	g++ -g -c -o avl/lib/node.o avl/node.cpp
	g++ -g -c -o avl/lib/avl.o avl/avl.cpp
	g++ -g -c -o avl/lib/main.o avl/main.cpp
	g++ -g -o bin/avltree avl/lib/node.o avl/lib/avl.o avl/lib/main.o
