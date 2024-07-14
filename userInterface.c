#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bookStructure.h"
#include "studentStructure.h"
#include "addRemoveBook.h"
#include "listBooks.h"
#include "register.h"
#include "listUsers.h"
#include "borrowReturnBook.h"
#include "searchBooks.h"
#include "userInterface.h"

// displays the initial menu
void startup(){
  initialiseBooks();
  initialiseUsers();

  add("Wuthering Heights", "Emily", "Brontë");
  add("Of Mice And Men", "John", "Steinbeck");
  add("Jane Eyre", "Charlotte", "Brontë");
  registerUser("Brad", "Pitt");
  registerUser("George", "Clooney");
  users[0].borrowed[0] = 2;
  users[0].borrowed[1] = 1;
  users[0].borrowed[2] = 3;
  users[1].borrowed[0] = 1;
  users[1].borrowed[1] = 3;
  users[1].borrowed[2] = 2;

  while (true) {
    int choice1 = 0;

    printf("\nWelcome to the library!\n");
    printf("\n1. Login\n");
    printf("2. Register with the library\n");
    printf("\nEnter the corresponding number for what you would like to do: ");

    scanf("%i", &choice1);

    switch (choice1) {
      case 1:
        login();
        break;

      case 2:
        makeAccount();
        break;

      default:
        printf("\nPlease enter a valid command number.\n");
    }
  }
}

// creates a student account using the information given
void makeAccount() {
  char firstName[25];
  char surname[25];

  printf("\nEnter the following details about yourself:\n");

  printf("\nFirst name: ");
  scanf("%s", firstName);
  printf("Surname: ");
  scanf("%s", surname);

  printf("\nYou have been registered. Your account's ID number is %i.\n", registerUser(firstName, surname));
}

// checks if the account being logged on exists
void login() {
  printf("\nPlease enter your account's ID number: ");

  int id;
  scanf("%i", &id);

  if (id == 0) {
    menu(id);
  }
  else {
    bool found = false;

    for (int i = 0; i < 100; i++) {
      if (id == users[i].id) {
        found = true;
        menu(id);
        break;
      }
    }

    if (found == false) {
      printf("\nThere is no account with this ID. Please register and try logging in again.\n");
    }
  }
}

// displays the appropriate commands for the librarian and student accounts. Gets the information from
// the user required to execute the functions for the corresponding menu options
void menu(int account) {
  int choice = 0;

  if (account == 0) {
    char title[150];
    char authorFirstName[25];
    char authorSurname[25];
    int bookId = 0;

    printf("\nWelcome librarian.\n");

    while (true) {

      printf("\n1. Add a book to the library catalogue\n");
      printf("2. Remove a book from the library catalogue\n");
      printf("3. List all books in the library catalogue\n");
      printf("4. List all registered users\n");
      printf("5. Logout\n");
      printf("6. Quit the program\n");
      printf("\nEnter the corresponding number for what you would like to do: ");

      scanf("%i", &choice);
      getchar();

      switch (choice) {
        case 1:
          printf("\nEnter the following details about the book you want to add to the catalogue:\n");

          printf("\nTitle: ");
          scanf("%[^\n]%*c", title);
          printf("Author's first name: ");
          scanf("%s", authorFirstName);
          printf("Author's surname: ");
          scanf("%s", authorSurname);

          add(title, authorFirstName, authorSurname);
          printf("\nThe book has been added to the catalogue.\n");
          break;

        case 2:
          printf("\nEnter the ID of the book that you want to remove from the catalogue: ");
          scanf("%i", &bookId);

          if (bookId < 1) {
            printf("\nEnter a value greater than 0.\n");
          }
          else {
            if (removeBook(bookId) == 0) {
              printf("\nThe book has been removed from the catalogue.\n");
            }
            else {
              printf("\nThere is no book in the catalogue with the entered ID.\n");
            }
          }

          break;

        case 3:
          printf("\nBelow are all the books that are in the catalogue:\n\n");
          listBooks();
          break;

        case 4:
          printf("\nBelow are all the registered users:\n\n");
          listUsers();
          break;

        case 5:
          printf("\nYou have been logged out.\n");
          return;

        case 6:
          printf("\nThe program has been quit.\n", choice);
          exit(0);

        default:
          printf("\nPlease enter a valid command number.\n");
      }
    }
  }
  else {
    char searchTerm[150];
    int bookId2 = 0;

    printf("\nWelcome %s %s.\n", users[account - 1].firstName, users[account - 1].surname);

    while (true) {
      printf("\n1. List all books in the library catalogue\n");
      printf("2. Search the library catalogue\n");
      printf("3. Borrow a book\n");
      printf("4. Return a book\n");
      printf("5. Logout\n");
      printf("\nEnter the corresponding number for what you would like to do: ");

      scanf("%i", &choice);
      getchar();

      switch (choice) {
        case 1:
          printf("\nBelow are all the books that are in the catalogue:\n\n");
          listBooks();
          break;

        case 2:
          initialiseMatchedBooks();
          printf("\nEnter your search term: ");

          scanf("%[^\n]%*c", searchTerm);
          searchTitle(searchTerm, 0);
          searchFirstName(searchTerm, 0);
          searchSurname(searchTerm, 0);

          printf("\nSearch results:\n\n");
          displaySearch();
          break;

        case 3:
          printf("\nEnter the ID of the book that you want to borrow: ");

          scanf("%i", &bookId2);

          if (bookId2 < 1) {
            printf("\nEnter a value greater than 0.\n");
          }
          else {
            int result = borrowBook(account, bookId2);

            if (result == 0) {
              printf("\nYou are currently borrowing this book.\n");
            }
            else if (result == 1) {
              printf("\nThe book has been added to your borrowed books.\n");
            }
            else if (result == 2) {
              printf("\nYou have reached your borrowed books quota. Please return a book before borrowing another.\n");
            }
            else {

              printf("\nThere is no book in the catalogue with the entered ID.\n");
            }
          }

          break;

        case 4:
          printf("\nEnter the ID of the book that you want to return: ");

          scanf("%i", &bookId2);

          if (bookId2 < 1) {
            printf("\nEnter a value greater than 0.\n");
          }
          else {
            if (returnBook(account, bookId2) == 0) {
              printf("\nThe book has been returned.\n");
            }
            else {
              printf("\nYou have not borrowed this book.\n");
            }
          }

          break;

        case 5:
          printf("\nYou have been logged out.\n");
          return;

        default:
          printf("\nPlease enter a valid command number.\n");
      }
    }
  }
}
