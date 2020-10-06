typedef struct
{
	int id;
	char description[60];
	int size;
	char nationality[40];
	int isEmpty;
} eRaza;

void initRaza(eRaza* Raza, int tam, int harcoded);
void printRaza(eRaza* Raza, int j);