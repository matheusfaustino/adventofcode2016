# for comments
# @ for echoing of that line is suppressed

# CC=gcc
CC=clang
CFLAGS=-Wall -std=c99 -Wextra -g -I/usr/local/opt/openssl/include
LDFLAGS=-lm  -lcrypto

#all:
	# for FILE in $(ls *.c) do $(CC) $(CFLAGS) -o ${FILE::-2}.o $FILE; done
	#ls *.c

# run:
# 	INPUT="input/$(FILE)";
# 	@echo $(FILE);
# 	@echo $(INPUT);
	# @if [[ "$(INPUT)" ]]; then\
	# 	INPUT = "input/$(FILE)";\
	# if
	# echo $(INPUT)
	# $(CC) $(CFLAGS) -o $(FILE).o $(FILE).c
	# @chmod +x $(FILE).o
	# @echo "Executing $(FILE)...\n"
	# @./$(FILE).o $(INPUT)

# build:
# 	@docker run --rm -v "${PWD}":/usr/src/myapp -w /usr/src/myapp gcc:6.2 make FILE=$(FILE) INPUT=$(INPUT) run

# all: first_day.o second_day.o third_day.o
# all: helper first_day.o second_day.o third_day.o

# helper:
# 	$(CC) $(CFLAGS) -c -o adventofcode.c adventofcode.o
# 	chmod +x adventofcode.o

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $< adventofcode.o
# 	chmod +x $@

compile:
	$(CC) $(CFLAGS) -c -o $(FILE).o $(FILE).c
	$(CC) $(LDFLAGS) -o $(FILE) $(FILE).o adventofcode.c

run: compile
	./$(FILE) input/$(FILE)

test: compile
	./$(FILE) example/$(FILE)

clean:
	rm -f *.o
	@ls *.c | cut -d '.' -f1 | xargs rm
