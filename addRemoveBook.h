// allows other source files to use the books array
extern Book books[100];

// function definitions
void initialiseBooks();
void add(char title[150], char authorFirstName[25], char authorSurname[25]);
int removeBook(int id);
