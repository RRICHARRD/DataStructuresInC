#This file was created to help compiling and run source code more easilly

program_name = main.exe
datastructure_name = DoublyLinkedList

#Default output for typing '$ make' in the terminal
All:
	@echo "# Instructions to use make file"
	@echo "# '$$ make compile' to compile source code"
	@echo "# '$$ make run' to run compiled source code"
	@echo "# '$$ make cr' to compile source code and run automatically after"


#Only compile the code
compile c:
	@echo "# Compiling $(program_name), please wait..."
	@gcc -c ./src/$(datastructure_name).c -I ./include -o ./obj/$(datastructure_name).o
	@gcc -O1 -O2 -O3 -Wall ./apps/main.c ./obj/$(datastructure_name).o -I ./include -o ./bin/main.exe
	@echo "# Successfully compiled!!!"
	@echo "# Type '$$ make run' to execute the program"


#Run the compiled code
run r:
	@echo "# Starting process for $(program_name), wait..."
	@echo ""
	@bin/.\$(program_name)


#Compile and run
cr: compile run


#create folder struture
createBoiler:
	@echo "Creating folders structure to project..."
	@mkdir apps bin include obj src
	@touch ./apps/main.c


#delete folders struture
deleteBoiler:
	@echo "Deleting folders structure..."
	@rmdir apps bin include obj src