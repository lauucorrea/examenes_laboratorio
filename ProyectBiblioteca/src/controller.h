
int controller_sortBooks(LinkedList* pArrayListBook);
int controller_calculateId(LinkedList* pArrayListBook);
int controller_ListBooks(LinkedList* pArrayListBook);
int controller_addBook(LinkedList* pArrayListBook);

int controller_saveBooksAsText(char* path , LinkedList* pArrayListBook);
int controller_saveLastBookAsText(char* path, int id);

int controller_loadLastBookIdFromText(char* path);
int controller_loadBooksFromFile(LinkedList* listaLibros ,int option, int* pFlagFileLoaded, char* nameFile);
int controller_loadBooksFromText(char* path , LinkedList* pArrayListBook);

int controller_loadEditorialsFromText(char* path , LinkedList* pArrayListEditorial);
int controller_loadEditorialsFromFile(LinkedList* listaEditoriales ,int option, int* pFlagFileLoaded, char* nameFile);

int controller_listBooksFromEditorialMinotauro(LinkedList* bookList);
