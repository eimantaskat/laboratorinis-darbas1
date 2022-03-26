main:
	g++ -o main main.cpp functions/*.cpp list_functions/*.cpp -O3
run:
	g++ -o main main.cpp functions/*.cpp list_functions/*.cpp -O3; ./main
clean:
	rm *.exe *.txt