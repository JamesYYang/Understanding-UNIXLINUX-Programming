chapter = 11
execute = timeserv
target = CH$(chapter)/$(execute).c

all: clean build

build:
	mkdir bin
	gcc -Wall -o bin/$(execute) $(target)

run:
	bin/$(execute)

clean:
	rm -rf bin