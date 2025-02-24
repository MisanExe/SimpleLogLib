


lib/libLogger.a: build/logger.o
	ar rcs lib/libLogger.a build/logger.o
build/logger.o: src/SimpleLogger.cpp include/SimpleLogger.h
	g++ -c -std=c++20 src/SimpleLogger.cpp -o build/logger.o
example:
	g++ -std=c++20 examples/main.cpp -Llib -lLogger -o build/example
clean:
	rm -rf build/*