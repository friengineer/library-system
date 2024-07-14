#include <stdio.h>
#include "studentStructure.h"
#include "listUsers.h"
#include "register.h"

// displays all of the registered users
void listUsers() {
  for (int i = 0; i < 100; i++) {
    if (users[i].id != 0) {
      printf("%i,%s,%s,", users[i].id, users[i].firstName, users[i].surname);

      for (int k = 0; k < 15; k++) {
        printf("%i/", users[i].borrowed[k]);

        if (k == 14) {
          printf("\n");
        }
      }
    }
  }
}
