#include <string.h>
#include "bookStructure.h"
#include "addRemoveBook.h"

// definitions for global variables
Book books[100];
int idCounter = 1;

// sets the values of the elements of books to a default state
void initialiseBooks() {
  for (int i = 0; i < 100; i++) {
    books[i].id = 0;
    strcpy(books[i].title, "");
    strcpy(books[i].authorFirstName, "");
    strcpy(books[i].authorSurname, "");
  }
}

// adds a book to the books array using the given information and generates an ID number for it
void add(char title[150], char authorFirstName[25], char authorSurname[25]) {
  for (int i = 0; i < 100; i++) {
    if (books[i].id == 0) {
      books[i].id = idCounter;
      strcpy(books[i].title, title);
      strcpy(books[i].authorFirstName, authorFirstName);
      strcpy(books[i].authorSurname, authorSurname);
      idCounter++;
      break;
    }
  }
}

// removes the book which has the corresponding ID from the books array and sets the values of
// that array element to the default values
int removeBook(int id) {
  for (int i = 0; i < 100; i++) {
    if (books[i].id == id) {
      books[i].id = 0;
      strcpy(books[i].title, "");
      strcpy(books[i].authorFirstName, "");
      strcpy(books[i].authorSurname, "");
      return 0;
    }
  }

  return 1;
}
