#include <stdio.h>
#include "bookStructure.h"
#include "listBooks.h"
#include "addRemoveBook.h"

// displays all of the books in the library catalogue

void listBooks(){

  for (int i=0; i<100; i++){

    if (books[i].id != 0){

      printf("%i,%s,%s,%s\n", books[i].id, books[i].title, books[i].authorFirstName, books[i].authorSurname);
    }
  }
}
