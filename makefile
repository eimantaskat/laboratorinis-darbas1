main:
	g++ -o main main.cpp functions/*.cpp list_functions/*.cpp deque_functions/*.cpp -O3
run:
	g++ -o main main.cpp functions/*.cpp list_functions/*.cpp deque_functions/*.cpp -O3; ./main
clean:
	rm *.exe *.txt

test:
	g++ -o test test.cpp student.cpp functions.cpp driver_functions.cpp vector_functions.cpp average.cpp list_functions.cpp deque_functions.cpp