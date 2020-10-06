#include "Mascotas.h"

void initMascota(eMascota* Mascota, int tam, int harcoded)
{
	for (int i = harcoded; i < tam; i++)
	{
		Mascota[i].id = i;
		Mascota[i].isEmpty = 1;
	}
}

void printMascota(eMascota* Mascota, int tam, int i)
{
	printf("\n%d\t%s\t\t%d\t", Mascota[i].id, Mascota[i].name, Mascota[i].age);
	if (Mascota[i].sexo == 'm')
	{
		printf("Masc\t");
	}
	else
	{
		printf("Fem\t");
	}
	switch (Mascota[i].tipo)
	{
	case 0:
		printf("Gato\t");
		break;
	case 1:
		printf("Perro\t");
		break;
	case 2:
		printf("Raro\t");
		break;
	}
}