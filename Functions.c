#define MAX_MASCOTAS 10
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start()
{
	eMascota Mascota[MAX_MASCOTAS] =
		//tipo 0 -> gato, 1 -> perro, 2 -> raro
	{	{0, "Chusen", 8, 'm', 0, 0, 0},
		{1, "Bestia", 11, 'm', 1, 0, 1},
		{2, "Hana", 4, 'f', 0, 0, 2},
		{3, "Hachiko", 7, 'm', 1, 0, 3},
		{4, "Guppy", 5, 'f', 0, 0, 0},
	};

	eRaza Raza[MAX_MASCOTAS] =
		//tipo 0 -> chico, 1 -> mediano, 2 -> grande
	{ {0, "Gato Siames", 0, "Tailandia", 0},
		{1, "Doberman", 2, "Alemania", 0},
		{2, "Gato Persa", 1, "Persia", 0},
		{3, "Pastor Belga", 2, "Belgica", 0} 
	};

	int tam = MAX_MASCOTAS;
	//Hay que cambiar las variables de abajo de acuerdo a la cantidad de mascotas o razas harcodeadas
	int mascotasHarcoded = 5;
	int razasHarcoded = 4;

	initMascota(Mascota, tam, mascotasHarcoded);
	initRaza(Raza, tam, razasHarcoded);
	menu(Mascota, Raza);
}

void menu(eMascota* Mascota, eRaza* Raza)
{
	printf("Bienvenido/a!");
	int opcion = 0;
	while (opcion != 1 && opcion != 9 && opcion != 2)
	{
		printf("1. Listar mascotas con sus razas y paises de origen.");
		printf("\n2. Agregar mascota");
		printf("\n9. Salir");
		printf("\nElija su opcion: ");
		scanf("%d", &opcion);
	}
	switch (opcion)
	{
	case 1:
		listarMascotasRazas(Mascota, Raza, MAX_MASCOTAS);
		break;
	case 2:
		addMascota(Mascota, Raza, MAX_MASCOTAS);
	case 9:
		printf("\nGracias por usar el programa!");
		break;
	}
}

void listarMascotasRazas(eMascota* Mascota, eRaza* Raza, int tam)
{
	printf("\nid\tnombre\t\tedad\tsexo\ttipo\traza\t\t\t\tpais");
	for (int i = 0; i < MAX_MASCOTAS; i++)
	{
		if (!Mascota[i].isEmpty)
		{
			printMascota(Mascota, tam, i);
			for (int j = 0; j < MAX_MASCOTAS; j++)
			{
				if (Mascota[i].razaId == Raza[j].id)
				{
					printRaza(Raza, j);
				}
			}
		}
	}
	confirm();
	menu(Mascota, Raza);
}

void addMascota(eMascota* Mascota, eRaza* Raza, int tam)
{
	int i = 0;
	int flag = 0;
	char buffer[1000] = "";
	char name[21];
	char sexo = 'a';
	int tipo = -1;
	while(i < tam && !flag)
	{
		if (Mascota[i].isEmpty)
		{
			flag = 0;
			printf("\nAgregar nueva mascota ID #%d", Mascota[i].id);
			printf("\nNombre: ");
			my_fflush();
			scanf("%[^\n]", buffer);
			while (strlen(buffer) > 20)
			{
				printf("El nombre de la mascota no puede tener mas de 20 letras, por favor reingreselo: ");
				my_fflush();
				scanf("%[^\n]", buffer);
			}
			strcpy(name, buffer);
			capitalize(name);
			printf("El nombre (%s), fue ingresado correctamente", name);
			strcpy(Mascota[i].name, name);
			confirm();
			printf("\nIngrese edad de la mascota: ");
			scanf("%d", &Mascota[i].age);
			printf("\nIngrese sexo (m = masculino, f = femenino): ");
			my_fflush();
			scanf("%c", &sexo);
			while (sexo != 'm' && sexo != 'f')
			{
				printf("\nEl sexo de la mascota debe ser 'm' o 'f', por favor reintentelo: ");
				my_fflush();
				scanf("%c", &sexo);
			}
			Mascota[i].sexo = sexo;
			printf("\nIngrese tipo de mascota (0: gato, 1: perro, 2: raro): ");
			my_fflush();
			scanf("%d", &tipo);
			while (tipo < 0 || tipo > 2)
			{
				printf("\nReingrese tipo de mascota (0: gato, 1: perro, 2: raro): ");
				my_fflush();
				scanf("%d", &tipo);
			}
			Mascota[i].tipo = tipo;
			printf("id\tdescripcion\t\tpais");
			for (int j = 0; j < MAX_MASCOTAS; j++)
			{
				if (!Raza[j].isEmpty)
				{
					printf("\n%d\t", Raza[j].id);
					printRaza(Raza, j);
				}
			}
			printf("\nElegir ID de raza: ");
			int idRaza = -1;
			my_fflush();
			scanf("%d", &idRaza);
			int k = 0;
			while (k < MAX_MASCOTAS && !flag)
			{
				if (idRaza == Raza[k].id && !Raza[k].isEmpty)
				{
					Mascota[i].razaId = idRaza;
					flag = 1;
				}
				else
				{
					k++;
				}
			}
			while (!flag)
			{
				printf("Ingreso un id equivocado. Por favor, reintente: ");
				scanf("%d", &idRaza);
				k = 0;
				while (k < MAX_MASCOTAS && !flag)
				{
					if (idRaza == Raza[k].id && !Raza[k].isEmpty)
					{
						Mascota[i].razaId = idRaza;
						flag = 1;
					}
					else
					{
						k++;
					}
				}
			}
			Mascota[i].isEmpty = 0;
			printf("\nLa mascota ha sido agregada!");
			confirm();
			menu(Mascota, Raza);
		}
		else
		{
			i++;
		}
	}
	if (!flag)
	{
		printf("\nNo hay espacio para mas mascotas. Por favor, elimine.");
		confirm();
		menu(Mascota, Raza);

	}
}

void confirm()
{
	char cont = '\0';
	my_fflush();
	while (cont == '\0')
	{
		printf("\nIngrese una tecla para continuar: ");
		scanf("%c", &cont);
		my_fflush();
	}
}

void my_fflush()
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n');
}

char capitalize(char name[])
{
	int len = strlen(name);
	int skip = 0;

	if (name[0] > 96 && name[0] <= 122)
	{
		name[0] -= 32;
	}

	for (int i = 1; i < len; i++)
	{
		if (i != skip)
		{
			if (name[i] > 64 && name[i] < 91)
			{
				name[i] += 32;
			}
			if (name[i] == 32 && name[i + 1] != '\0')
			{
				skip = i + 1;
				if (name[i + 1] > 96 && name[i + 1] < 122)
				{
					name[i + 1] -= 32;
				}
			}
		}
	}
	return name;
}