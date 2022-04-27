main:
	g++ -o main main.cpp functions/*.cpp list_functions/*.cpp deque_functions/*.cpp -O3
clean:
	rm *.exe i*.txt