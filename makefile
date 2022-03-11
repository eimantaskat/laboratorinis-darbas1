main:
	g++ -o main main.cpp functions/*.cpp -O3
run:
	g++ -o main main.cpp functions/*.cpp -O3; ./main
clean:
	rm *.exe