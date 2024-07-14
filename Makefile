# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.c addRemoveBook.c listBooks.c register.c listUsers.c borrowReturnBook.c searchBooks.c userInterface.c

# generic build details

CC=      cc
COPT=    -std=c99 -g
CFLAGS=

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c userInterface.h

addRemoveBook.o: addRemoveBook.c bookStructure.h addRemoveBook.h

listBooks.o: listBooks.c bookStructure.h listBooks.h addRemoveBook.h

register.o: register.c studentStructure.h register.h

listUsers.o: listUsers.c studentStructure.h listUsers.h register.h

borrowReturnBook.o: borrowReturnBook.c bookStructure.h studentStructure.h borrowReturnBook.h addRemoveBook.h register.h

searchBooks.o: searchBooks.c bookStructure.h searchBooks.h addRemoveBook.h

userInterface.o: userInterface.c bookStructure.h studentStructure.h addRemoveBook.h listBooks.h register.h listUsers.h borrowReturnBook.h searchBooks.h userInterface.h
