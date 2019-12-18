C=g++
CFLAGS=-Wall -g
SRC=main.cpp
OUT=main
OBJECTS=main.o astroMath.o

output: $(OBJECTS)
	$(C) $(CFLAGS) $(OBJECTS) -o main

main.o: $(SRC) imageFormat.h
	$(C) -c $(SRC)

astroMath.o: astroMath.cpp astroMath.h imageFormat.h
	$(C) -c astroMath.cpp

clean:
	rm $(OUT)
	rm image.ppm
