CC = gcc 

all : sort

sort : main.o tool.o stAlg.o 
    $(CC) -o sort main.o tool.o stAlg.o

tool.o : tool.c tool.h
    $(CC) -c tool.c -o tool.o  

stAlg.o : stAlg.c stAlg.h tool.h
    $(CC) -c stAlg.c -o stAlg.o

main.o : main.c
    $(CC) -c main.c -o main.o

clean :
    del -f sort.exe
    del -f *.o
