#include "Razas.h"

void initRaza(eRaza* Raza, int tam, int harcoded)
{
	for (int i = harcoded; i < tam; i++)
	{
		Raza[i].id = i;
		Raza[i].isEmpty = 1;
	}
}

void printRaza(eRaza* Raza, int j)
{
	printf("%s\t\t\t", Raza[j].description);
	printf("%s", Raza[j].nationality);
}