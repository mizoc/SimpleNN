gcc-opt = -std=c++17 -Wall --pedantic-errors

SimpleNN : main.cpp
	g++ $(gcc-opt) $< -o $@

run :
	./SimpleNN

clean :
	rm -f ./SimpleNN

.PHONY : run clean
