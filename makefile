
CFLAGS=-I. -std=c++11 -Wall

all: Source.o Pool.o FortunaMain.o Fortuna.o PoolManager.o
	g++ $(CFLAGS) Source.o Pool.o Fortuna.o FortunaMain.o PoolManager.o -o FortunaMain.exe

FortunaMain.o: FortunaMain.cpp
	g++ $(CFLAGS) -c FortunaMain.cpp -o FortunaMain.o

Fortuna.o: Fortuna.cpp Fortuna.h PoolManager.h
	g++ $(CFLAGS) -c Fortuna.cpp -o Fortuna.o
 
PoolManager.o: PoolManager.cpp PoolManager.h Pool.h
	g++ $(CFLAGS) -c PoolManager.cpp -o PoolManager.o

Pool.o: Pool.cpp Pool.h
	g++ $(CFLAGS) -c Pool.cpp -o Pool.o


Source.o: Source.cpp Source.h
	g++ $(CFLAGS) -c Source.cpp -o Source.o

clean:
	rm -rf *.o FortunaMain.exe
