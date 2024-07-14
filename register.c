#include <string.h>
#include "studentStructure.h"
#include "register.h"

// definitions for global variables
Student users[100];
int idCounter2 = 1;

// sets the values of the elements of users to a default state
void initialiseUsers() {
  for (int i = 0; i < 100; i++) {
    users[i].id = 0;
    strcpy(users[i].firstName, "");
    strcpy(users[i].surname, "");

    for (int k = 0; k < 15; k++) {
      users[i].borrowed[k] = 0;
    }
  }
}

// adds a user account to the users array using the given information and generates an ID number for it
int registerUser(char firstName[25], char surname[25]) {
  // find first array element that is empty
  for (int i = 0; i < 100; i++) {
    if (users[i].id == 0) {
      users[i].id = idCounter2;
      strcpy(users[i].firstName, firstName);
      strcpy(users[i].surname, surname);
      idCounter2++;
      
      return users[i].id;
    }
  }
}
