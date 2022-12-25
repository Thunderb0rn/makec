build:
	g++ main.cxx file_command.cxx -o makec

run:
	./makec

clean:
	rm -r *.o

clear:
	rm -r makec

