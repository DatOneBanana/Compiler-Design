CFLAGS = -g -Wall -ansi -pedantic

minil: mini_l.lex mini_l.y
	bison -d -v mini_l.y
	flex mini_l.lex	
	g++ $(CFLAGS) -std=c++11 lex.yy.c mini_l.tab.c -lfl -o minil
	rm -f lex.yy.c

clean:
	rm -f minil mini_l.tab.* mini_l.output *~ lex.yy.c ./tests/*~ ./milFiles/_* ./milFiles/*~

test: minil
	./minil ./tests/primes.min > ./milFiles/primes.mil
	./minil ./tests/mytest.min > ./milFiles/mytest.mil
	./minil ./tests/fibonacci.min > ./milFiles/fibonacci.mil