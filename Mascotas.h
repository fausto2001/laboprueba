typedef struct
{
	int id;
	char name[21];
	int age;
	char sexo;
	int tipo;
	int isEmpty;
	int razaId;
} eMascota;

void initMascota(eMascota* Mascota, int tam, int harcoded);
void printMascota(eMascota* Mascota, int tam, int i);