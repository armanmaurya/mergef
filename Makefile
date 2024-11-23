build:./main.cpp
	g++ main.cpp -o build

clean:
	rm -f build

run:
	./build file1.txt file2.txt file3.txt -o filefinal.txt
