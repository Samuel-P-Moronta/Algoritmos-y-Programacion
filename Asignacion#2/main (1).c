#include <stdio.h>
#include <string.h>

typedef struct /* Declaración de la estructura vendedor. */
{
    int num; /* Número de vendedor. */
    char nom[20]; /* Nombre del vendedor. */
    float ven;; /* Ventas del mes*/

    float sal; /* Salario mensual. */

} vendedor;
void Lectura(vendedor *, int);
void v1(vendedor *, int);
void v2(vendedor *, int); /* Prototipos de funciones. */
void v3(vendedor *, int);
void lista(vendedor *, int t);
int screenheader();
void imprimir();
int cant_caracteresNumero(float numero);

int screenheader()
/*El objetivo de esta funcion es siempre presentar el encabezado del programa*/
{

    printf("\n                           __________________________________________________________");
    printf("\n                          |                                                          |");
    printf("\n                          |   S I S T E M A    D E  I N F O R M A C I O N   D E L    |");
    printf("\n                          |                    E M P L E A D O                       |");
    printf("\n                          |__________________________________________________________|");
}
void main(void)
{
    screenheader();
    vendedor VENDEDORES[100];
    /* Declaración del arreglo unidimensional de tipo estructura vendedor. */
    int TAM;
    do
    {
        printf("\n\n\t\t\t\t\tDIGITE NUMERO DE VENDEDORES: ");
        scanf("%d", &TAM);
    }
    while (TAM < 1);
    /* Se verifica que el número de elementos del arreglo sea correcto. */
    Lectura (VENDEDORES, TAM);
    v1 (VENDEDORES, TAM);
    v2 (VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA");
}
void Lectura(vendedor A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de tipo
➥estructura vendedor de T elementos. */
{
    int I, J;
    for (I=0; I<T; I++)
    {
        printf("\n                          _____________________________________________________________");
        printf("\n\t\t\t\t\tDIGITE DATOS DEL VENDEDOR %d", I+1);
        printf("\n\t\t\t\t\tNOMBRE DEL VENDEDOR [%d]: ",I+1);
        fflush(stdin);
        gets(A[I].nom);
        do
        {
            printf("\n\t\t\t\t\tSALARIO DEL VENDEDOR [%d]: ",I+1);
            scanf("%f", &A[I].sal);
            if(A[I].sal < 0)
            {
                printf("\n\t\t\t\t\tDIGITE UN SALARIO VALIDO!!");
            }
        }
        while(A[I].sal < 0);
        do
        {
            printf("\n\t\t\t\t\tVENTAS DEL MES DEL VENDEDOR [%d]: ",I+1);
            scanf("%f", &A[I].ven);
            if(A[I].ven < 0)
            {
                printf("\n\t\t\t\t\tDIGITE VENTA DEL MES VALIDO!!");
            }
        }
        while(A[I].ven < 0);
    }
}

void v1(vendedor A[], int T)
/* Esta función se utiliza para generar las comisiones de cada uno
de los vendedores */
{
    for (int I=0; I<T; I++)
    {
        if(A[I].ven <= 1000)
        {
            A[I].ven*= (0.035);
        }

        if(A[I].ven > 1000 && A[I].ven <= 2000)
        {
            A[I].ven *= (0.045);
        }

        if(A[I].ven > 2000)
        {
            A[I].ven *= (0.054);
        }

    }
}

void v2(vendedor A[], int T)
{
    int I;
    system("cls");
    screenheader();

    printf("\n\nNOMBRE:            SUELDO:        COMISION:        SUELDO NETO:");
    printf("        ");
    int largo = 0;
    for (I=0; I<T; I++)
    {
        float neto = A[I].sal+=A[I].ven;

        printf("\n%s",A[I].nom);
        largo = strlen(A[I].nom);
        int tamano=0;
        int p = 0;
        if(largo<12)
        {

            tamano = 18 - largo;


            for(int y=0; y<=tamano; y++)
            {
                printf(" ");

            }
            largo =0;
        }

        printf("%.2f",A[I].sal);
        impriEspacio(14, cant_caracteresNumero( A[I].sal));
        printf("%.2f",A[I].ven);
        impriEspacio(9+6,cant_caracteresNumero( A[I].ven));
        printf(" %.2f\n",neto);
    }
    printf("EMPLEADO MAYOR COMISION: %s con %.2f\n",A[I].nom);
    printf("EMPLEADO MENOR COMISION: %s con %.2f\n",A[I].nom);
    printf("EMPLEADO MAYOR SUELDO: %s con %.2f\n",A[I].nom);
    printf("EMPLEADO MENOR SUELDO: %s con %.2f\n",A[I].nom);

}
int cant_caracteresNumero(float numero)
{
    int contador=1;
    int num1 = numero*100;
    while(num1/10>0)
    {
        num1=num1/10;
        contador++;
    }
    contador = contador + 1;

    return contador;

}
//Decir cuanto cracteres hay ocupados, int los espacio que se quieren dejar vacio
int impriEspacio(int espacioOcupado, int cant)
{
    int n = espacioOcupado;
    for(int y=0; y<=(n-cant); y++)
    {
        printf(" ");

    }
}





