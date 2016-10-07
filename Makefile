# for comments
# @ for echoing of that line is suppressed

CC=gcc
CFLAGS=-Wall

#all:
	# for FILE in $(ls *.c) do $(CC) $(CFLAGS) -o ${FILE::-2}.o $FILE; done
	#ls *.c

run:
	$(CC) $(CFLAGS) -o $(FILE).o $(FILE).c
	@chmod +x $(FILE).o
	@echo "Executing $(FILE)...\n"
	@./$(FILE).o

build:
	@docker run --rm -v "${PWD}":/usr/src/myapp -w /usr/src/myapp gcc:6.2 make FILE=$(FILE) run

clean:
	@rm -f *.o
