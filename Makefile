all: clean build run

build:
	gcc -Wall bits.c -o bits
	@echo "------------------------"

run:
	./bits

clean:
	rm -rf *.o bits