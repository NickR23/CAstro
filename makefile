C=g++
CFLAGS=-Wall -o
SRC=main.cpp
OUT=main

default:
	$(C) $(CFLAGS) $(OUT) $(SRC)

clean:
	rm $(OUT)
