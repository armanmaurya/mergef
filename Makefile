build:./main.cpp
	g++ main.cpp -o mergef

clean:
	rm -f mergef

run:
	./mergef file1.txt file2.txt file3.txt -o filefinal.txt
