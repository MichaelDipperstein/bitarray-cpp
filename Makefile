############################################################################
# Makefile for bitarray class library and sample
#
############################################################################

CPP = g++
LD = g++
CPPFLAGS = -O2 -Wall -Wextra -pedantic -c
LDFLAGS = -O2 -o

# libraries
LIBS = -L. -lbitarray

# Treat NT and non-NT windows the same
ifeq ($(OS),Windows_NT)
	OS = Windows
endif

ifeq ($(OS),Windows)
	EXE = .exe
	DEL = del
else	#assume Linux/Unix
	EXE =
	DEL = rm
endif

all:		sample$(EXE)

sample$(EXE):	sample.o libbitarray.a
		$(LD) $^ $(LDFLAGS) $@

sample.o:	sample.cpp bitarray.h
		$(CPP) $(CPPFLAGS) $<

libbitarray.a:	bitarray.o
	ar crv libbitarray.a bitarray.o
	ranlib libbitarray.a

bitarray.o:	bitarray.cpp bitarray.h
		$(CPP) $(CPPFLAGS) $<

clean:
		$(DEL) *.o
		$(DEL) *.a
		$(DEL) sample$(EXE)
