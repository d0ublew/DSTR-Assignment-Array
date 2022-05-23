.PHONY: all clean

all:
	cmake -S . -B build/ -G Ninja && ninja -C build/

clean:
	ninja -C build -t clean
