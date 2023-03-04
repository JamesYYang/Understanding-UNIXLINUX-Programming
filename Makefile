chapter = 01
execute = more02
target = CH$(chapter)/$(execute).c

all: clean build

build:
	mkdir bin
	gcc -Wall -o bin/$(execute) $(target)

run:
	bin/$(execute)

clean:
	rm -rf bin