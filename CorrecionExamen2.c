#include <stdio.h>
#include <string.h>
#define N 3
#define Col_ESTA 0
#define Col_SUEL 1

void capturaDatos(int clave[N], char nombre[N][20], float datos[N][2]);
int BusquedaEmpAlto(float datos[N][2]);
void OrdenaEmpleados(int clave[N], char nombre[N][20], float datos[N][2]);
void ImprimeDatos(int clave[N], char nombre[N][20], float datos[N][2]);

int main()
{
	int clave[N], posicion;
	char nombre[N][20];
	float datos[N][2];
	
	capturaDatos(clave, nombre, datos);
	
	OrdenaEmpleados(clave, nombre, datos);
	
	ImprimeDatos(clave, nombre, datos);
	
	posicion=BusquedaEmpAlto(datos);
	
	printf("Nombre del empleado mas alto: %s\n", nombre[posicion]);
	printf("Su estatura es: %.2f\n", datos[posicion][Col_ESTA]);	
	
	return 0;
}

void capturaDatos(int clave[N], char nombre[N][20], float datos[N][2])
{
	int i;
	
	for(i=0; i<N; i++)
	{
		printf("Clave[%d]: ", i);
		scanf("%d", &clave[i]);
		printf("Nombre[%d]: ", i);
		scanf("%s", &nombre[i]);
		printf("Estatura[%d]: ", i);
		scanf("%f", &datos[i][Col_ESTA]);
		printf("sueldo[%d]: ", i);
		scanf("%f", &nombre[i][Col_SUEL]);
	}
	
}

int BusquedaEmpAlto(float datos[N][2])
{
	int i, posicion=0;
	float mayor = datos[0][Col_ESTA];
	
	for(i=0; i<N; i++)
	{
		if(datos[i][Col_ESTA] > mayor)
		{
			mayor = datos[i][Col_ESTA];
			posicion = i;
		}
	}
	
	return posicion;

}

void OrdenaEmpleados(int clave[N], char nombre[N][20], float datos[N][2])
{
	int i, j, auxclav;
	float aux;
	char auxnom[20];
	
	for(i=0; i<N-1; i++)
	{
		for(j=0; j<N-1; j++)
		{
			if(datos[j][Col_SUEL] < datos[j+1][Col_SUEL])
			{
				//int sueldo
				aux = datos[j][Col_SUEL];
				datos[j][Col_SUEL] = datos[j+1][Col_SUEL];
				datos[j+1][Col_SUEL] = aux; 
				
				//int clave
				auxclav = clave[j];
				clave[j] = clave[j+1];
				clave[j+1] = auxclav;
				
				//int nombre
				strcpy(auxnom, nombre[j]);
				strcpy(nombre[j], nombre[j+1]);
				strcpy(nombre[j+1], auxnom);
					
				//int estatura
				aux = datos[j][Col_ESTA];
				datos[j][Col_ESTA] = datos[j+1][Col_ESTA];
				datos[j+1][Col_ESTA] = aux; 
			}
		}
	}
}

void ImprimeDatos(int clave[N], char nombre[N][20], float datos[N][2])
{
	int i;
	
	printf("Clave	Nombre	Estatura	Sueldo\n");
	
	for(i=0; i<N; i++)
	{
		printf("%d\t", clave[i]);
		printf("%s\t", nombre[i]);
		printf("%.2f\t", datos[i][Col_ESTA]);
		printf("%.2f\n", datos[i][Col_SUEL]);	
	}
}

