build:
	g++ main.cxx file_command.cxx -o makec

run:
	./makec

clear:
	rm -r *.o
