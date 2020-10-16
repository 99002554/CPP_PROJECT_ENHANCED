all: all.out 
all.out : main.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
main.o : main.cpp	banquethall.h	cost.h	Client.h	hotelroom.h	restaurant.h
	g++ $< -c

clean:
	rm -rf *.o *.out
