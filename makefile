CC=g++
FLAGS= -O0 -Wall

IDIR:= Code/inc/
SDIR:= Code/*.cpp Test/*.cpp

test:
	$(CC) $(FLAGS) -I $(IDIR) $(SDIR) -o test
