#include <string.h>
#include <stdio.h>
#include "bookStructure.h"
#include "searchBooks.h"
#include "addRemoveBook.h"

// definitions for global variables

int matchedBooks[100];

// sets the values of the elements of matchedBooks to a default state

void initialiseMatchedBooks(){

  // for (int i=0; i<10; i++){
  //
  //   printf("%i\n", matchedBooks[i]);
  // }
  //
  // printf("\n");

  for (int i=0; i<100; i++){

    matchedBooks[i] = 0;
  }

  // for (int i=0; i<10; i++){
  //
  //   printf("%i\n", matchedBooks[i]);
  // }
}

// unimplemented function that would allow for more than one member of the books array to
// be searched by splitting up the search term

void splitQuery(char * query){

  char* word = strtok(query, " ");

  while (word != NULL){                          //only goes through while loop once

    printf("here\n");

    searchTitle(word, 0);                           //gives the 1st word to searchTitle()

    // while (searchTitle(&word) != 0){          //remember to return 0
    //
    //   if (matchedBooks[k] == 0){
    //
    //     matchedBooks[k] == books[i].id;
    //     break;
    //   }
    // }
    // searchFirstName(&pointer);
    // searchSurname(&pointer);

    word = strtok(NULL, " ");
  }

  for (int i=0; i<10; i++){

    printf("%i\n", matchedBooks[i]);
  }
}

// uses the given string to find books with the same title. IDs of books that match the
// string are added to the matchedBooks array. The start point is altered to allow for
// multiple books with the same title to be added

void searchTitle(char * word, int start){

  for (int i=start; i<100; i++){

    if (strcmp(books[i].title, word) == 0){

      for (int k=0; k<100; k++){

        if (books[i].id == matchedBooks[k]){

          return;
        }
      }

      // adds book ID to matchedBooks

      for (int j=0; j<100; j++){

        if (matchedBooks[j] == 0){

          matchedBooks[j] = books[i].id;

          searchTitle(word, i+1);

          return;
        }
      }
    }
  }

  return;
}

// uses the given string to find books with the same author's first name. IDs of books that
// match the string are added to the matchedBooks array. The start point is altered to allow
// for multiple books with the same author's first name to be added

void searchFirstName(char * word, int start){

  for (int i=start; i<100; i++){

    if (strcmp(books[i].authorFirstName, word) == 0){

      for (int k=0; k<100; k++){

        if (books[i].id == matchedBooks[k]){

          return;
        }
      }

      // adds book ID to matchedBooks

      for (int j=0; j<100; j++){

        if (matchedBooks[j] == 0){

          matchedBooks[j] = books[i].id;

          searchFirstName(word, i+1);

          return;
        }
      }
    }
  }
}

// uses the given string to find books with the same author's surname. IDs of books that
// match the string are added to the matchedBooks array. The start point is altered to
// allow for multiple books with the same author's surname to be added

void searchSurname(char * word, int start){

  for (int i=start; i<100; i++){

    if (strcmp(books[i].authorSurname, word) == 0){

      for (int k=0; k<100; k++){

        if (books[i].id == matchedBooks[k]){

          return;
        }
      }

      // adds book ID to matchedBooks

      for (int j=0; j<100; j++){

        if (matchedBooks[j] == 0){

          matchedBooks[j] = books[i].id;

          searchSurname(word, i+1);

          return;
        }
      }
    }
  }

  return;
}

// displays the books that have their IDs in the matchedBooks array

void displaySearch(){

  for (int i=0; i<100; i++){

    if (matchedBooks[i] != 0){
      printf("%i,%s,%s,%s\n", books[matchedBooks[i] - 1].id, books[matchedBooks[i] - 1].title, books[matchedBooks[i] - 1].authorFirstName, books[matchedBooks[i] - 1].authorSurname);
    }
  }
}
