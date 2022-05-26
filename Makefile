.PHONY: all clean

all:
	cmake -S . -B build/ -G Ninja

install:
	ninja -C build/

clean:
	ninja -C build -t clean
