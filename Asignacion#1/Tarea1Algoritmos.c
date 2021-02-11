#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
SAMUEL P. MORONTA 20170570
*/

int reconocer_enter();
int titulo();

int main()
{
    int num1, num2,cantidad;
    titulo();//Llamo la funcion para presentar el titulo: NUMEROS FELICES

    do
    {
        do
        {
            printf("\nDIGITE LIMITE INFERIOR:");
            scanf("%i",&num1);
            if (num1 <= 0)
            {
                printf("\nEL LIMITE INFERIOR DEBE SER MAYOR QUE CERO");
                system("pause");
            }

        }while(num1<=0);
        do
        {
            printf("\nDIGITE LIMITE SUPERIOR:");
            scanf("%i",&num2);
            if (num2 <= 0)
            {
                printf("\nEL LIMITE SUPERIOR DEBE SER MAYOR QUE CERO");
                system("pause");
            }

        }while(num2<=0);

        if(num1>=num2)
        {
            printf("EL RANGO ELEGIDO [%i,%i] ES INCORRECTO",num1,num2);
            printf("\nDIGITE UN RANGO CORRECTO:");
            printf("\n---->PRESIONE CUALQUIER TECLA PARA DIGITAR UN RANGO CORRECTO<----");
            getch();
        }
    }while(num2<=num1);

    int cant_columna = 0;
    int cant_lineas = 0;

    do
    {
        printf("\nNUMERO DE COLUMNA PARA PRESENTAR LOS DATOS: ");
        scanf("%i",&cant_columna);
        system("cls");
        titulo();
        printf("\nPARA EL RANGO [%d,%d]:\n",num1,num2);

        if (cant_columna > 4 || cant_columna < 1)
        {
            printf("\n\n");
        }
    }while(cant_columna > 4 || cant_columna < 1);


    for(int num = num1; num <= num2; num++)
    {
        int resultado = num; //Le asigno a resultado lo que contenga la variavle num

        while(resultado != 1 && resultado != 4) //Condicion para los numeros felices segun su definicion
        {
            resultado = feliz(resultado);//Llamo la funcion feliz
        }

        if(resultado == 1)
        {
            cantidad++;
            printf("%5d F",num);
        }
        if(resultado!=1)
        {
            cantidad++;
            printf("%5d  ",num);

        }
        if ( cantidad % cant_columna == 0 )
        {
            printf(" \n");

            cant_lineas++;

            if (cant_lineas == 20)
            {
                printf("\n_________________________________________________________________________________________________");
                printf("\nPRESIONE [ENTER] PARA PRESENTAR LOS NUMEROS FELICES QUE RESTAN POR PRESENTAR EN EL RANGO [%i, %i]",num1,num2);
                printf("\n_________________________________________________________________________________________________");
                reconocer_enter();
                cant_lineas =0;
                system("cls");
                printf("\n",titulo());
            }
        }
    }

    return 0;
}
/*
   Funcion: Feliz.
   Objetivo: Determinar la suma de los
             cuadrados de los digitos de un numero.
   Argumento: Entero num.
   Retorno: (int) Suma de los cuadrados
*/
int feliz(int num)
{
    int dig = 0, sumaF = 0;
    while(num > 0)
    {
        dig = num % 10;
        sumaF = sumaF + (dig*dig);
        num/=10;
    }
    return sumaF;
}
/*
   Funcion: Titulo.
   Objetivo: Presentar este encabezado durante
             todo el programa.
*/

int titulo()
{
    printf("\ -----------------------------");
    printf("\n|N U M E R O S  F E L I C E S|");
    printf("\n------------------------------");
}
int existe(int arr[], int n, int val)
{
    int ind;

    for ( ind = 0; ind < n; ind ++ )
        if ( arr[ind] == val )
            return 1;

    return 0;
}
/*
   Funcion: Reconocer enter
   Objetivo: Validar la pulsacion de la TECLA ENTER
*/

int reconocer_enter()
{

    int enter_val = 0;

    do
    {
        enter_val = getch();
        if (enter_val != 13);

    }while (enter_val != 13);

}
