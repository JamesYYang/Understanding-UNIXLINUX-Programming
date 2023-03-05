chapter = 02
execute = who1
target = CH$(chapter)/$(execute).c

all: clean build

build:
	mkdir bin
	gcc -Wall -o bin/$(execute) $(target)

run:
	bin/$(execute)

clean:
	rm -rf bin