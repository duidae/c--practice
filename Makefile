# See README.txt.

.PHONY: all cpp clean

all: cpp

cpp: Date.cpp fig09_19.cpp

clean:
	rm -f *.o

fig09_19: Date.cpp fig09_19.cpp
	c++ Date.cpp fig09_19.cpp -o fig09_19.o

