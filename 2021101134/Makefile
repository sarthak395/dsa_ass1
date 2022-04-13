CC=gcc
FLAGS= -Wall

all: q1.out q2.out q3.out clean

#---------------------------------
q1.out: main1.o my_dll.o node.o 
	$(CC) $(FLAGS) main.o my_dll.o node.o -o q1.out 

main1.o: ./1/main.c 
	$(CC) $(FLAGS) -c ./1/main.c 

my_dll.o: ./1/my_dll.c 
	$(CC) $(FLAGS) -c ./1/my_dll.c

node.o: ./1/node.c 
	$(CC) $(FLAGS) -c ./1/node.c

#-------------------------------------
q2.out: main2.o complex.o
	$(CC) $(FLAGS)  main.o complex.o -o q2.out 

main2.o: ./2/main.c
	$(CC) $(FLAGS)  -c ./2/main.c  

complex.o: ./2/complex.c
	$(CC) $(FLAGS)  -c ./2/complex.c

#----------------------------------

q3.out: main3.o musicplayer.o song.o user.o
	$(CC) $(FLAGS)  main.o musicplayer.o song.o user.o -o q3.out

main3.o: ./3/main.c
	$(CC) $(FLAGS) -c ./3/main.c 

musicplayer.o: ./3/musicplayer.c 
	$(CC) $(FLAGS) -c ./3/musicplayer.c

song.o: ./3/song.c
	$(CC) $(FLAGS) -c ./3/song.c

user.o: ./3/user.c 
	$(CC) $(FLAGS) -c ./3/user.c
#-----------------------------------

clean:
	-rm -f *.o core *.core

clean_ex:
	-rm *.out
