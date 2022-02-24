main:
	g++ -o main main.cpp functions/functions.cpp functions/verification.cpp functions/sorting.cpp functions/input.cpp
run:
	g++ -o main main.cpp functions/functions.cpp functions/verification.cpp functions/sorting.cpp functions/input.cpp; ./main
clean:
	rm *.exe