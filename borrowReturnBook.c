#include "bookStructure.h"
#include "studentStructure.h"
#include "borrowReturnBook.h"
#include "addRemoveBook.h"
#include "register.h"

// checks if the given user has borrowed the maximum amount of books they are allowed to and
// adds the specified book ID to the specified user's borrowed books

int borrowBook(int userId, int bookId){

  if (checkBookCatalogue(bookId) == 0){

    if (checkBorrowedBooks(userId, bookId) == 0){

      // user has already borrowed book

      return 0;
    }
    else{

      for (int i=0; i<100; i++){

        if (users[i].id == userId){

          for (int k=0; k<15; k++){

            if (users[i].borrowed[k] == 0){

              users[i].borrowed[k] = bookId;

              // book borrowed successfully

              return 1;
            }
          }

          // user has borrowed the max books

          return 2;
        }
      }
    }
  }

  // book is not in catalogue

  return 3;
}

// removes the given book from the given user's borrowed books after checking if they are
// currently borrowing that book

int returnBook(int userId, int bookId){

  for (int i=0; i<100; i++){

    if (users[i].id == userId){

      for (int k=0; k<15; k++){

        if (users[i].borrowed[k] == bookId){

          users[i].borrowed[k] = 0;

          // book returned successfully

          return 0;
        }
      }

      // user has not borrowed book

      return 1;
    }
  }
}

// checks if there is a book in the library catalogue with the given ID

int checkBookCatalogue(int bookId){

  for (int i=0; i<100; i++){

    if (books[i].id == bookId){

      return 0;
    }
  }

  return 1;
}

// checks if the given user is borrowing the given book

int checkBorrowedBooks(int userId, int bookId){

  for (int i=0; i<100; i++){

    if (users[i].id == userId){

      for (int k=0; k<15; k++){

        if (users[i].borrowed[k] == bookId){

          // user has borrowed book

          return 0;
        }
      }

      // user has not borrowed book

      return 1;
    }
  }
}
