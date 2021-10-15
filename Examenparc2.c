#include <stdio.h>
#define N 5

void CapturaDatos(char nombre[N], int clave[N], float est[N][N], float suel[N][N]);
void BusquedaEst(float est[N][N]);
void FuncionImpresion(char nombre[N], int clave[N], float est[N][N], float suel[N][N]);
void OrdBurbuja(char nombre[N], int clave[N], float est[N][N], float suel[N][N]);
void swapd(int *izq, int *der);
void swapf(float *izq, float *der);
void swaps(char *izq, char *der);

int main()
{
	char nombre[N];
    int clave[N];
    float est[N][N], suel[N][N];
    
	CapturaDatos(nombre, clave, est, suel);
	OrdBurbuja(nombre[N], clave[N], est[N][N], suel[N][N]);
	FuncionImpresion(nombre[N], clave[N], est[N][N], suel[N][N]);
	BusquedaEst(est[N][N]);
	
	return(0);
}

void CapturaDatos(char nombre[N], int clave[N], float est[N][N], float suel[N]][N])
{
    for (int i = 0; i < N; i++)
    {
        printf("Clave del usuario: ");
        scanf("%d", &clave[i]);
        printf("Nombre del usuario: ");
        scanf("%s", &nombre[i]);
        printf("Estatura del usuario: ");
        scanf("%f", &est[i][i]);
        printf("Sueldo del usuario: ");
        scanf("%f", &suel[i][i]);
        
    }
    
}

void BusquedaEst(float est[N][N])
{
    float mayor = est[0][0];
    int posicion, i;
    
    for (i=0; i<N; i++)
    {
        if(mayor<est[i][i])
        {
            mayor= est[i][i];
            posicion=i;
        }
    }
    
    printf("La posicion de la estatura mas alta es: %d", posicion);
    
}

void FuncionImpresion(char nombre[N], int clave[N], float est[N][N], float suel[N][N])
{
    printf("Clave");
    printf("Nombre");
    printf("Estatura");
    printf("Sueldo");
    for (int i=0; i<N; i++)
    {
        printf("%d", clave[i]);
        printf("%s", nombre[i]);
        printf("%f", est[i][i]);
        printf("%f", suel[i][i]);
    }
}

void OrdBurbuja(char nombre[N], int clave[N], float est[N][N], float suel[N][N])
{
    int aux,izq,der;
    float izqsue, dersue, izqes, derees;
    char izqnom, dernom;
    for (int i=0; i<N-1; i++)
    {
        for (int j=0; j<N-(i + 1); j++)
        {
            if(sueldos[j] > suel[j + 1])
            {
                izqsue = suel[j][j];
                dersue = suel[j+1][j+1];
                swapf(&izqsue, &dersue);
                izqnom = nombre[j];
                dernom = nombre[j+1];
                swaps(&izqnom, &dernom);
                izq = clave[j];
                der = clave[j+1];
                swapd(&izq, &der);
                izqes = est[j][j];
                deres = est[j+1][j+1];
                swapf(&izqes, &deres);
            }
        }
    }
}

void swapd(int *izq, int *der)
{
	int aux;
	aux=*izq;
	*izq=*der;
	*der=aux;
}

void swapf(float *izq, float *der)
{
	int aux;
	aux=*izq;
	*izq=*der;
	*der=aux;
}

void swaps(char *izq, char *der)
{
	int aux;
	aux=*izq;
	*izq=*der;
	*der=aux;
}

