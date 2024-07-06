//#include <stdio.h>
//#include <string.h>
//#include "bookStructure.h"
//#include "studentStructure.h"
//#include "addRemoveBook.h"
//#include "listBooks.h"
//#include "register.h"
//#include "listUsers.h"
//#include "borrowReturnBook.h"
//#include "searchBooks.h"
#include "userInterface.h"

int main(){

  // for (int i=0; i<10; i++){

  //   printf("%i,%s,%s,%s\n", books[i].id, books[i].title, books[i].authorFirstName, books[i].authorSurname);
  // }

  // initialiseBooks();                                                //this was uncommented
  //
  // add("Wuthering Heights", "Emily", "Brontë");                    //this was uncommented
  // add("Of Mice And Men", "John", "Steinbeck");
  // add("Sense And Sensibility", "Jane", "Austen");
  // add("Of Mice And Men", "Fake", "Author");
  // add("Pride And Prejudice", "Jane", "Austen");

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,%s\n", books[i].id, books[i].title, books[i].authorFirstName, books[i].authorSurname);
  // }

  //printf("\n");

  // removeBook(3);                                    //this was uncommented

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,%s\n", books[i].id, books[i].title, books[i].authorFirstName, books[i].authorSurname);
  // }
  //
  // printf("\n");

  // add("Great Expectations", "Charles", "Dickens");                  //this was uncommented
  // add("Moby-Dick", "Herman", "Melville");

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,%s\n", books[i].id, books[i].title, books[i].authorFirstName, books[i].authorSurname);
  // }

  // listBooks();                                    //this was uncommented

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,", users[i].id, users[i].firstName, users[i].surname);
  //
  //   for (int k=0; k<10; k++){
  //
  //     printf("%i/", users[i].borrowed[k]);
  //
  //     if (k == 9){
  //       printf("\n");
  //     }
  //   }
  // }

  // printf("\n");

  // initialiseUsers();                                 //this was uncommented

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,", users[i].id, users[i].firstName, users[i].surname);
  //
  //   for (int k=0; k<10; k++){
  //
  //     printf("%i/", users[i].borrowed[k]);
  //
  //     if (k == 9){
  //       printf("\n");
  //     }
  //   }
  // }
  //
  // printf("\n");

  // registerUser("Brad", "Pitt");                      //this was uncommented
  // registerUser("George", "Clooney");
  // registerUser("Dwayne", "Johnson");
  // registerUser("Denzel", "Washington");
  // registerUser("Nicolas", "Cage");

  // for (int i=0; i<10; i++){
  //
  //   printf("%i,%s,%s,", users[i].id, users[i].firstName, users[i].surname);
  //
  //   for (int k=0; k<10; k++){
  //
  //     printf("%i/", users[i].borrowed[k]);
  //
  //     if (k == 9){
  //       printf("\n");
  //     }
  //   }
  // }

  // listUsers();                                   //this was uncommented
  // printf("\n");

  // borrowBook(1, 1);                              //this was uncommented
  // borrowBook(1, 2);
  // borrowBook(1, 3);
  // borrowBook(1, 4);
  // borrowBook(1, 5);

  // for (int i=1; i<4; i++){
  //
  //   for (int k=1; k<6; k++){
  //
  //     borrowBook(i, k);
  //   }
  // }

  // listUsers();                                      //this was uncommented
  // printf("\n");

  //returnBook(1, 1);                              //this was uncommented
  //returnBook(1, 2);
  //returnBook(1, 3);
  //returnBook(1, 4);
  //returnBook(1, 5);

  // for (int i=1; i<4; i++){                       //this was uncommented

    // for (int k=0; k<6; k++){
    //
    //   returnBook(i, k);
    // }

    // returnBook(i, 2);
    // returnBook(i, 4);
  // }

  // listUsers();                                  //this was uncommented
  // printf("\n");

  // borrowBook(1, 6);                         //this was uncommented
  // borrowBook(1, 7);

  // for (int i=1; i<4; i++){                     //this was uncommented
  //
  //   borrowBook(i, 6);
  //   borrowBook(i, 7);
  // }

  // listUsers();                                   //this was uncommented

  // initialiseMatchedBooks();
  //
  // char query[] = "Of Mice And Men";
  // char query1[] = "Jane";
  // char query2[] = "Austen";
  //
  // printf("Search queries in order of execution:\n\n");
  // printf("Search query for title: %s\n", query);
  // printf("Search query for first name: %s\n", query1);
  // printf("Search query for surname: %s\n\n", query2);

  // splitQuery(query);               //for advanced searching
  // searchTitle(query, 0);
  // searchFirstName(query1, 0);
  // searchSurname(query2, 0);
  // displaySearch();

  startup();

  return 0;
}
