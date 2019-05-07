#!/usr/local/make -f

INCLUDE_DIR := $(shell pwd)

run: all
	./build/basik

all:
	@mkdir -p build
	clang $(shell find src -name \*.c -type f) -I ${INCLUDE_DIR}/include/ -o ./build/basik

clean:
	@rm -rf build
