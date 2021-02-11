#include <stdio.h>
#include <stdlib.h>


/*Programa que te permite calcular el promedio de los numeros exitosos en un rango emitido por el usuario.

SAMUEL P. MORONTA 20170570
*/

//Funciones de tipo entero
int exitoso(int num);
int abundante(int num);

int main()
{
   /*
   num1 limite inferior del rango. Num2 limite superior del rango
   sexitosos es la sumatoria de los numeros exitosos en el rango
   emitido por el usuario. cexitosos es la cantidad de numeros
   exitosos en el rango indicado. Prom variable de tipo flotante,
   idica el resultado de haber obtenido el cociente de la division de
   la sumatoria de lo numeros exitosos entre la cantidad de los exitosos
   */

   int num1,num2,val,sexitosos,cexitosos,exit;
   float prom = 0;


   do
    {
        printf("Digite el limite inferior:");
        scanf("%i",&num1);
        if(num1<0)
        {
            printf("\nEl valor debe ser mayor que cero");
        }

    }
    while(num1<0);
    do
    {
    	system("cls");
        printf("Digite el limite superior:");
        scanf("%i",&num2);
        if(num2<0 && num2<num1)
        {
            printf("\nRango incorrecto");
        }
    }
    while(num2<0 && num2<num1);

    sexitosos = 0;
    cexitosos = 0;
    val = num1; //A val se le asigna el limite inferior


    while ( val <= num2 )
    {
        exit = exitoso(val);

        if ( exit == 1 )
        {
            sexitosos += val; 
            cexitosos++;
        }

          val ++;
    }

   if(cexitosos>0)
   {
       prom = sexitosos/cexitosos;
       printf("\nEl promedio de los numeros exitosos en el rango [%i,%i] es: %.2f",num1,num2,prom);
   }
   else
   {
      printf("\nNo hay exitosos en el rango [%i,%i]",num1,num2);
   }

}
/* Funciion de los numeros exitosos, que recibe como parametro el num
y retorna un 1 si se cumple la condicion de que la candidad de abundates 
en el rango indicado por el usuario es mayor que la cantidad de divisores
 entre 2, de lo contrario si no se cumple esta condicion el valor de retorno es 0
*/ 
int exitoso(int num)
{
    int cdiv = 0, div = 1, topediv = num/2, cdivabun = 0;

    while ( div <= topediv )
    {
        if ( num % div == 0 )
        {
            cdivabun += abundante(div);
            cdiv++;
        }
        div ++;
    }
   if(cdivabun > cdiv/2)
   {
      return 1;
   }
   else
   {
      return 0;
   }

}
/* Funcion de los numeros abundantes, que recibe como parametro el num
y retorna 1, si se cumple la condicion de que la suma de los divisores en 
el rango indicado por el usuario es mayor que el numero que recibe como 
parametro de entrada, de lo contrario si esta condicion no se cumple rtorna 
un  0
*/ 
int abundante(int num)
{
   int sdiv = 0, div = 1, topediv = num/2;

   while ( div <= topediv )
   {
      if ( num % div == 0 )
      {
         sdiv+=div;
      }
      div ++;
   }
   if (sdiv>num)
   {
      return 1;

   }
   else
   {
      return 0;
   }
}
