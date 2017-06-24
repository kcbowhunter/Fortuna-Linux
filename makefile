

all: FortunaMain.o
	g++ FortunaMain.o -o FortunaMain.exe

FortunaMain.o: FortunaMain.cpp
	g++ -I . -c FortunaMain.cpp -o FortunaMain.o

clean:
	rm -rf *.o FortunaMain.exe
