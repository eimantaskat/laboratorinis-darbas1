main:
	g++ -o main main.cpp container_functions/*.cpp functions/*.cpp student/*.cpp person/*.cpp -O3
clean_output:
	rm *i.txt
clean:
	rm *.exe *.txt
test:
	g++ -o test test.cpp student/*.cpp person/*.cpp -O3