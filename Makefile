# See README.txt.

.PHONY: all cpp clean

all: cpp

cpp: Time.cpp fig09_03.cpp

clean:
	rm -f *.o

fig09_03: Time.cpp fig09_03.cpp
	c++ Time.cpp fig09_03.cpp -o fig09_03.o

