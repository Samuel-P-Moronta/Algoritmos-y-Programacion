#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<conio.c>
//PROYECTO FINAL PARA LA MATERIA DE ALGORITMOS Y PROGRAMACION
//CREADO POR SAMUEL P. MORONTA 20170570
//SE TRATA DE UN SISTEMA DE INVENTARIO Y FACURACION DE SUPERMERCADOS, SE PUEDE REGISTRAR
//UN ADMINISTRADOR QUE ES EL ENCARGADO DE MANEJAR TODAS LAS INFORMACIONES IMPORTANTES EN
//LA EMPRESA, LLEVA EL REGISTRO DE VENTAS, ES EL ENCARGADO DE AGREGAR UN ARCHIVO, MODIFICARLO
//ELIMINARLO, ESTOS ARCHIVOS CONTIENEN INFORMACION DEL PRODUCTO COMO: CODIGO DEL PRODUCTO, PRECIO
//DEL PRODUCTO.
#define COLOR_BACKGROUND WHITE
#define COLOR_TXT_PUCMM1 BLUE
#define COLOR_TXT_PUCMM2 GREEN
#define COLOR_TXT_PUCMM3 CYAN
#define COLOR_TXT_PUCMM4 MAGENTA
#define COLOR_TXT_PUCMM5 RED
#define COLOR_TXT_PUCMM6 YELLOW
#define COLOR_TXT_PUCMM7 BROWN
#define COLOR_TXT_PUCMM8 DARKGRAY
#define COLOR_TXT_PUCMM9 LIGHTBLUE
#define COLOR_TXT_PUCMM10 LIGHTGREEN
#define COLOR_TXT_PUCMM11 LIGHTCYAN
#define COLOR_TXT_PUCMM12 LIGHTRED
#define COLOR_TXT_PUCMM13 LIGHTMAGENTA
#define color_return BLACK

#define space "\t\t\t"

#define MAXCOL_TITULO 300
#define MAXFIL_TITULO 20


COORD coord= {0,0};
void gotoxy1(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void add_products(); //Agregar productos
void delete_product(); //Eliminar productos
void modify_product(); //Modificar productos que se ingresen
void view_products(); // Ver los productos que se han ingresado
void admin_menu();//Menu del administrados, encargado de todo lo principal en la compania
void billing();//Funcion para facturacion
void cashier_menu();//Funcion para el cajero, es decir el vendedor que no tiene acceso al almacen
char admin_username[100],admin_password[100],cashier_user[100],cashier_password[100],*tempstr,account[100];
int count = 0;

//Estructura que se encarga de manejar los que es el nombre del producto, las cantidades de que se quieran
//adquirir del producto que se quiera comprar, esta es para la parte de facturacion de los producto.
struct bill
{
    char name[100];//Variable de tipo char, contiene los nombres de los productos, con un maximo de 100 productos
    int quantity;//Variable cantitad de tipo entero, encargado de llevar la cantida de los prodcutos que se quieran comprar
    char code[100];//Variable de tipo char que contiene el codigo de los productos, 100 productos como maximo
    double rate; //Variable de tipo rate, encargado de la tarifa que se obtiene de la compra
} bill[100];

//Funcion que se encarga de "Setear el color" que le sera impuesto a los textos en todo el programa
void setColor(int ct)
{
    textcolor(ct);
}
//Funcion que se encarga de ponerle el color de fondo al programa
void setBackgroundColor(int bc)
{
    textbackground(bc);
}
//Funcion choice, elige el color con el que sera presentada la animacion del programa PUCMM
void choice(int ch)
{
    if(ch == 1)
        setColor(COLOR_TXT_PUCMM1);
    if(ch == 2)
        setColor(COLOR_TXT_PUCMM2);
    if(ch == 3)
        setColor(COLOR_TXT_PUCMM3);
    if(ch == 4)
        setColor(COLOR_TXT_PUCMM4);
    if(ch == 5)
        setColor(COLOR_TXT_PUCMM5);
    if(ch == 6)
        setColor(COLOR_TXT_PUCMM6);
    if(ch == 7)
        setColor(COLOR_TXT_PUCMM7);
    if(ch == 8)
        setColor(COLOR_TXT_PUCMM8);
    if(ch == 9)
        setColor(COLOR_TXT_PUCMM9);
    if(ch == 10)
        setColor(COLOR_TXT_PUCMM10);
    if(ch == 11)
        setColor(COLOR_TXT_PUCMM11);
    if(ch == 12)
        setColor(COLOR_TXT_PUCMM12);
    if(ch == 13)
        setColor(COLOR_TXT_PUCMM13);
    if(ch == 14)
        setColor(COLOR_TXT_PUCMM1);
}
//Funcion animacion, esta encargado de presentar la animacion al inicio del programa
//Como fundamento principal, utiliza una matriz de caracteres obtenido de CODIGOS ASCII
//De forma que rellena esto, con colores.
void animation()
{
    int num_color = 1, ind, J;
    char a = 219;
    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {

        {0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a},
        {0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a},
        {0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a},
        {0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a},
        {0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a},
        {0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a},
        {0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a},
        {0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    };

    while(num_color != 5)
    {
        choice(num_color);
        num_color++;
        system("cls");
        for(ind = 0; ind < 5; ind++)
        {
            printf("\n");
        }
        for(ind = 0; ind < MAXFIL_TITULO; ind++ )
        {
            printf(space "\t");
            for(J = 0; J < MAXCOL_TITULO; J++)
            {

                printf("%c",anm[ind][J]);
            }
            Sleep(10);
            printf("\n");

        }
        setColor(COLOR_TXT_PUCMM2);
        // printf(space space"\t\tSUPERMERCADOS\n");
        Sleep(1);
        setColor(color_return);
    }
}
//Menu principal, esta encargado de manejar todo lo relacionado con la ventana principal del programa
//Es decir, presenta la opcion de ingresar cuentaa una administrador, un vendedor que es el cajero encargado
//de realizar las ventas de los productos
void main_menu()//home page
{
       setBackgroundColor(COLOR_BACKGROUND);
    system("cls");
    char user[100];
    setColor(COLOR_TXT_PUCMM1);
    int b = 201,c = 205,d = 187,e = 188,f = 200,g = 186;
    int ind, J, a = 219;
    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {
        {b,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
    };
    label2 :

    setColor(COLOR_TXT_PUCMM1);

    for(ind = 0; ind < 5; ind ++)
    {
        printf("\n");
    }
    for(ind = 0; ind < MAXFIL_TITULO; ind++ )
    {
        printf(space"\t");

        for(J = 0; J < MAXCOL_TITULO; J++)
        {
            printf("%c",anm[ind][J]);
        }
        Sleep(30);
        printf("\n");

    }
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t        %c\t\t       SUPERMERCADOS\t\t\t\t%c",186,186,186);
    Sleep(80);
    setColor(color_return);
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t\t\t\t        %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    char opcion;

    printf("\t\t\t                                %c",186);
    printf("      1.ADMINISTRADOR ");
    printf("   2.VENDEDOR");
    printf("      3.SALIR\t        %c",186);
    printf("\t\t\t\t\t\t        %c",200);

    for(ind = 0; ind < 63; ind++)
    {

        printf("%c", 205);
    }
    printf("%c",188);
    printf("\n\n");

    printf(space"ELIGE UNA OPCION:");
    fflush(stdin);
    opcion = _getch();

    if(opcion == '1')
    {
        system("cls");
        admin_account_login(user);
    }
    if(opcion == '2')
    {
        system("cls");
        cashier_account_login(user);

    }
    else
    {
        exit(0);
    }
}
//Funcion que maneja el login del administrador, maneja memoria dinamica
//Y archivos, que contienen la informacion de los administradores, si se tiene mas
//De un administrador lo crea, y luego cuando inica seccion la misma cantidad de
//Aministradores, estos pueden ver los producto; es decir la jerarquia de la funcion
//Administrador, cualquiera que cree una cuenta de administrador puede acceder a los productos
int admin_account_login(char *user)//admin login
{
    system("cls");
    char BS = 8;
    char opcion;
    char b = 201, c = 205,d = 187,e = 188,f = 200,g = 186;
    char x, n;
    int i, j, a = 219;
    FILE *fp;
    tempstr = (char*)malloc(sizeof(char));

    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {
        {b,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
    };

label2 :
    system("cls");
    setColor(COLOR_TXT_PUCMM1);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < MAXFIL_TITULO; i++)
    {
        printf(space"\t");
        for(j = 0; j < 200; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t        %c\t\t       SUPERMERCADOS\t\t\t\t%c",186,186,186);
    Sleep(100);
    setColor(COLOR_TXT_PUCMM1);
    i = 0;
#define space1 "  "
    printf("\t\t\t\t\t\t        %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\t                                                %c",186);
    printf(space1"1. INICIAR SESION  ");
    printf(space1"2. REGISTRARSE  ");
    printf(space1"3. MENU PRINCIPAL     %c",186);
    printf("        \t\t\t                        %c",200);

    for(i = 0; i < 63; i++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    printf("\n"space space "ELIGE UNA OPCION:");
    fflush(stdin);
    opcion = _getch();
    if(opcion == '1')
    {

        system("cls");
        printf("\n\n\n\n"space space"ADMINISTRADOR");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tNOMBRE   : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", admin_username);
        i = 0;
        while(admin_username[i] != '\0')
        {
            user[i] = admin_username[i];
            i++;
        }
        user[i] = '&';
        user[i + 1] = '\0';
        i = 0;
        //Contrasena
        printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tCONTRASENA:%c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,15);
        i = 0;
        while((x = _getch()) != '\r')
        {
            if(x != BS)
            {
                printf("*");
                admin_password[i++] = x;
            }
        }
        admin_password[i] = '\0';
        i = 0;
        strcat(admin_username,admin_password);
        fp = fopen("billing_system_admin_DB.txt","r");
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        account[i] = '\0';
        fclose(fp);
        if(NULL == strstr(account, admin_username))
        {
            printf("\n\n"space space"*Nombre o contrase%ca incorrecta*",164);
            _getch();
            goto label2;
        }
        else
        {
            tempstr = strstr(account, admin_username);
        }
        i = 0;
        while(tempstr[i] != '|')
        {
            i++;
        }
        if(i == strlen(admin_username))
        {
            admin_menu();
        }
        else
        {
            printf("\n\n"space space"*Nombre o contrase%ca incorrecta*",164);
            _getch();
            goto label2;
        }
    }
    else if(opcion == '2')//sign up page
    {
label1 :
        system("cls");
        printf("\n\n\n\n"space space"Crear cuenta de administrador");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tNombre   : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", admin_username);
        i = 0;
        while((x = admin_username[i]) != '\0')
        {
            if(x == '*' || x == '@' || x == '|')
            {
                printf("\n"space space "*El nombre no puede contener caracteres espaciales como |, *, @, # etc.");
                _getch();
                goto label1;
            }
            i++;
        }
        fp = fopen("billing_system_admin_DB.txt","r");
        i = 0;
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        fclose(fp);
        if(NULL == strstr(account, admin_username))
        {
            printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space "\t       Contrase%ca: %c                       %c\n",164,179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(53,15);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x == '&' || x == '|' || x == ')')
                {
                    printf("\n"space space"*El nombre no puede contener caracteres espaciales como |, *, @, # etc.");
                    _getch();
                    goto label1;
                }
                if(x != BS)
                {
                    printf("*");
                    admin_password[i++] = x;
                }
            }
            admin_password[i] = '\0';
            printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n" "                    Digite contrase%ca nuevamente : %c                       %c\n",164,179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(53,18);
            i = 0;
            while((x = _getch()) != '\r')
            {
                printf("*");
                tempstr[i++] = x;
            }
            tempstr[i] = '\0';
            if(strcmp(admin_password, tempstr) == 0)
            {
                i = 0;
                fp = fopen("billing_system_admin_DB.txt","a");
                fputc('|',fp);
                while((x = admin_username[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                i = 0;
                while((x = admin_password[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                fputc('|',fp);
                fclose(fp);
                printf("\n\n"space space"Iniciando seccion correctamente...");
                _getch();
                goto label2;
            }
            else
            {
                printf("\n\n"space space"*Contrase%ca incorrecta, intente nuevamente",164);
                _getch();
                goto label1;
            }
        }
        else
        {
            printf("\n"space space"     Este nombre ya esta en uso");
            _getch();
            goto label1;
        }
    }
    else if(opcion == '3')
        main_menu();
    else
    {
        setColor(RED);
        printf(space"Entrada invalida\n");
        setColor(BLACK);
        _getch();
        goto label2;
    }
}
void admin_menu()
{
    system("cls");
    char b = 201, c = 205,d = 187,e = 188,f = 200,g = 186;
    char x, n;
    int i, j, a = 219;
    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {
        {b,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
    };
label2:
    system("cls");
    setColor(COLOR_TXT_PUCMM1);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < MAXFIL_TITULO; i++)
    {
        printf(space"\t");
        for(j = 0; j < 200; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    FILE *fp;
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t        %c\t\t       SUPERMERCADOS\t\t\t\t%c",186,186,186);
    Sleep(100);
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t\t\t                %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\t                                                %c",186);
    printf(space1"1->VER PRODUCTOS  ");
    printf(space1"              2->AGREGAR PRODUCTOS       %c",186);
    printf("                          \t\t\t        %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\t                                                %c",186);
    printf(space1"3->MODIFICAR PRODUCTOS");
    printf(space1"         4->ELIMINAR PRODUCTOS       %c",186);
    printf(space1"                                                     %c  5->CERRAR SECCION                                            %c",186,186);
    printf("  \t\t\t                                %c",200);


    for(int ind = 0; ind < 63; ind++)
    {

        printf("%c", 205);
    }
    printf("%c",188);
    printf("\n\n");

    printf(space"ELIGE UNA OPCION:");
    fflush(stdin);
    char opcion;

    opcion = _getch();
    if(opcion == '1')
    {
        view_products();
    }
    else if(opcion == '2')
    {
        add_products();
    }
    else if(opcion == '3')
    {
        modify_product();
    }
    else if(opcion == '4')
    {
        delete_product();
    }
    else if(opcion == '5')
    {
        main_menu();
    }
    goto  label2;
}

void view_products()
{
    system("cls");
    FILE *fp, *fp1;
    char x;
    int size;
    fp = fopen("billing_system_products_DB.txt","r");
    if(fp != NULL)
    {
        fseek (fp, 0, 2);
        size = ftell(fp);
        fclose(fp);
        int i;
        if (size == 0)
        {
            setColor(RED);
            for(i = 0; i < 10; i++)
            {
                printf("\n");
            }
            printf(space space"No hay productos disponibles!!");
            setColor(BLACK);
            _getch();
        }
        else
        {
            fp = fopen("billing_system_products_DB.txt","r");
            printf("\n\n");
            printf(space"\t   Codigo producto\t   Precio producto\tNombre producto\n");
            printf(space);
            for(i = 0; i < 72; i++)
            {
                printf("%c", 205);
            }
            printf("\n\n");
            while((x = fgetc(fp))!=EOF)
            {
                if(x == '*'||x == '$')
                {
                    printf("\t\t");
                }
                else if(x == '|')
                {
                    printf("\n\t\t"space);
                }
                else
                {
                    setColor(GREEN);
                    printf("%c",x);
                }
            }
            setColor(BLACK);
            fclose(fp);
            int i;
            printf("\n"space);
            for(i = 0; i < 72; i++)
            {
                printf("%c", 205);
            }
            _getch();
        }
    }
    else
    {
        fclose(fp);
        setColor(RED);
        printf("\n\n"space"No hay prodcutos disponibles!!\n");
        setColor(BLACK);
        _getch();
    }
}
void add_products()
{
    while(1)
    {
        system("cls");
        FILE *fp;
        char product_no[100],product_name[100],product_price[100],x;
        printf("\n\n\n\n\n\n\n\n\n"space space"Agregar prductos");
        int i;
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"\t Nombre producto : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,12);
        fflush(stdin);
        gets(product_name);
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"      Digite no producto : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        printf("\n"space space"   **Digite 3 numeros para el codigo del producto");
        gotoxy1(53,16);
        scanf("%s",product_no);
        printf("\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"     Precio              : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,21);
        scanf("%s",product_price);
        i = 0;
        fp = fopen("billing_system_products_DB.txt","a");
        fputc('|',fp);
        while((x = product_no[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        i = 0;
        fputc('*',fp);
        while((x = product_price[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        fputc('$',fp);
        i = 0;
        while((x = product_name[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        fputc('|',fp);
        fclose(fp);
        char ch;
        printf("\n\n"space"Agregado satisfactoriamente...!!\n");
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n"space"Quieres agregar mas?(y/n): ");
        fflush(stdin);
        ch = _getch();
        if(ch=='n')
        {
            break;
        }
    }
}
void modify_product()
{
    system("cls");
    FILE *fp,*fp1;
    char temp, a;
    int h = 0;
    char product_no[100],cpydata[100],product_name[100],product_price[100];
    fp = fopen("billing_system_products_DB.txt","r");
    printf("\n\n\n\n\n\n\n\n"space space"Modificar productos\n");
    int i;
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t    producto num : %c                       %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    int j = 0;
    i = 0;
    char x;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i++] = x;
    }
    fclose(fp);
    cpydata[i] = '\0';
    if(strstr(cpydata,product_no) == NULL)
    {
        setColor(RED);
        printf("\n"space space"El producto no fue encontrado....");
        setColor(BLACK);
        _getch();
        admin_menu();
    }
    else
    {
        fflush(stdin);
        printf("\n"space space"Digite datos para modificar \n");
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"\t Nombre producto : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,18);
        scanf("%[^\n]s",product_name);
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"     Precio              : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,22);
        scanf("%s",product_price);
        int flag = 0, i = 0, j = 0, k = 0, l = 0, idx;
        char x;
        char tempstring[100];
        while(cpydata[i] != '\0')
        {
            if(cpydata[i] == product_no[0] && cpydata[i+1] == product_no[1] && cpydata[i+2] == product_no[2] && flag == 0)
            {
                i = i + 1;
                while(cpydata[i] != '|')
                {
                    i++;
                }
                for(idx = 0; idx < 3; idx++)
                {
                    tempstring[j] = product_no[idx];
                    j++;
                }
                tempstring[j] = '*';
                j++;
                for(idx = 0; product_price[idx] != '\0'; idx++)
                {
                    tempstring[j] = product_price[idx];
                    j++;
                }
                tempstring[j] = '$';
                j++;
                for(idx = 0; product_name[idx] != '\0'; idx++)
                {
                    tempstring[j] = product_name[idx];
                    j++;
                }
                tempstring[j] = '|';
                j++;
                flag = 1;
            }
            else
            {
                tempstring[j] = cpydata[i];
                j++;
            }
            i++;
        }
        tempstring[j] = '\0';
        fp1 = fopen("replica.txt","w");
        i = 0;
        while((x = tempstring[i]) != '\0')
        {
            fputc(x,fp1);
            i++;
        }
        fclose(fp1);
        remove("billing_system_products_DB.txt");
        rename("replica.txt","billing_system_products_DB.txt");
        printf("\n"space"Modified!!");
    }
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    _getch();
}
void delete_product()//remove product
{
    system("cls");
    FILE *fp,*fp1;
    char tempstring[100];
    char product_no[100],cpydata[100];
    fp = fopen("billing_system_products_DB.txt","r");
    printf("\n\n\n\n\n\n\n\n"space space"Eliminar productos..\n");
    int i;
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t    producto num : %c                       %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    int j = 0;
    i = 0;
    char x;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i++] = x;
    }
    fclose(fp);
    cpydata[i] = '\0';
    if(strstr(cpydata,product_no) == NULL)
    {
        setColor(RED);
        printf("\n"space"Product not found!!");
        setColor(BLACK);
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        admin_menu();
    }
    else
    {
        i = 0;
        while(cpydata[i] != '\0')
        {
            if(cpydata[i] == product_no[0] && cpydata[i+1] == product_no[1] && cpydata[i+2] == product_no[2])
            {
                while(cpydata[i] != '|')
                {
                    i++;
                }
                i++;
                tempstring[j-1] = cpydata[i];
                i = i+1;
            }
            tempstring[j] = cpydata[i];
            j++;
            i++;
        }
        tempstring[j] = '\0';
    }
    i = 0;
    fp1 = fopen("replica.txt","w");
    while(tempstring[i] != '\0')
    {
        fputc(tempstring[i],fp1);
        i++;
    }
    fclose(fp1);
    remove("billing_system_products_DB.txt");
    rename("replica.txt","billing_system_products_DB.txt");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Producto eliminado!!");
    _getch();
}
int cashier_account_login(char *user)
{
    int i, j, a = 219;
    char BS = 8;
    int b = 201,c = 205,d = 187,e = 188,f = 200,g = 186;
    int ind, J;
    char x, n;
    FILE *fp;
    system("cls");
    tempstr=(char*)malloc(sizeof(char));
    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {
        {b,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
    };

label2 :
    system("cls");
    setColor(COLOR_TXT_PUCMM1);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < MAXFIL_TITULO; i++)
    {
        printf(space"\t");
        for(j = 0; j < 200; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t        %c\t\t       SUPERMERCADOS\t\t\t\t%c",186,186,186);
    Sleep(100);
    setColor(COLOR_TXT_PUCMM1);
    i = 0;
#define space1 "  "
    printf("\t\t\t\t\t\t        %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\t                                                %c",186);
    printf(space1"1. INICIAR SESION  ");
    printf(space1"2. REGISTRARSE  ");
    printf(space1"3. MENU PRINCIPAL     %c",186);
    printf("        \t\t\t                        %c",200);

    for(i = 0; i < 63; i++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    printf("\n"space space "ELIGE UNA OPCION:");
    fflush(stdin);
    n = _getch();
    if(n == '1')//login page
    {
        system("cls");
        printf("\n\n\n\n"space space"Cajero");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tNombre   : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", cashier_user);
        i = 0;
        while(cashier_user[i] != '\0')
        {
            user[i] = cashier_user[i];
            i++;
        }
        user[i] = '\0';
        i = 0;
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"\t\tPassword : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,15);
        i = 0;
        while((x = _getch()) != '\r')
        {
            if(x != BS)
            {
                printf("*");
                cashier_password[i++] = x;
            }
        }
        cashier_password[i] = '\0';
        i = 0;
        strcat(cashier_user, cashier_password);
        fp = fopen("billing_system_cashier_DB.txt","r");
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        account[i] = '\0';
        fclose(fp);
        if(NULL == strstr(account, cashier_user))
        {
            printf("\n\n"space space"*Usuario o contrasena incorrectos..");
            _getch();
            goto label2;
        }
        else
        {
            tempstr = strstr(account, cashier_user);
        }
        i = 0;
        while(tempstr[i] != '|')
        {
            i++;
        }
        if(i == strlen(cashier_user))
        {
            cashier_menu();
        }
        else
        {
            printf("\n\n"space space"*Usuario o contrasena incorrectos..");
            _getch();
            goto label2;
        }
    }
    else if(n == '2')//sign up page
    {
label1 :
        system("cls");
        printf("\n\n\n\n"space space"Crear cuenta de administrador");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tNombre   : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", cashier_user);
        i = 0;
        while((x = cashier_user[i]) != '\0')
        {
            if(x == '#' || x == '@' || x == '|')
            {
                printf("\n"space space "*La contrasena no puede contener caracteres peciales como |, *, @, # etc.");
                _getch();
                goto label1;
            }
            i++;
        }
        fp = fopen("billing_system_cashier_DB.txt","r");
        i = 0;
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        fclose(fp);
        if(NULL == strstr(account, cashier_user))
        {
            printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space"\t\tPassword : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy1(53,14);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x == '&' || x == '|' || x == ')')
                {
                    printf("\n"space space"*El nombre no puede contener caracteres espaciales como |, *, @, # etc.");
                    _getch();
                    goto label1;
                }
                if(x != BS)
                {
                    printf("*");
                    cashier_password[i++] = x;
                }
            }
            cashier_password[i] = '\0';
            printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n" "                    Digite contrase%ca nuevamente : %c                       %c\n",164,179,179);
            printf(space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy1(53,17);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x != BS)
                {
                    printf("*");
                    tempstr[i++] = x;
                }
            }
            tempstr[i] = '\0';
            if(strcmp(cashier_password, tempstr) == 0)
            {
                i = 0;
                fp = fopen("billing_system_cashier_DB.txt","a");
                fputc('|',fp);
                while((x = cashier_user[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                i = 0;
                while((x = cashier_password[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                fputc('|',fp);
                fclose(fp);
                printf("\n\n"space space"Iniciando seccion correctamente..");
                _getch();
                goto label2;
            }
            else
            {
                printf("\n\n"space space"*Contrasena incorrecta, intente nuevamente");
                _getch();
                goto label1;
            }
        }
        else
        {
            printf("\n"space space"     *Este nombre ya esta en uso..");
            _getch();
            goto label1;
        }
    }
    else if(n=='3')
    {
        main_menu();
    }
    else
    {
        setColor(RED);
        printf(space"Entrada invalida...\n");
        setColor(BLACK);
        _getch();
        goto label2;
    }
    return 0;
}
void cashier_menu()
{
    system("cls");
    char a = 219;
    char b = 201, c = 205,d = 187,e = 188,f = 200,g = 186;
    char x, n;
    int i, j;
    char anm[MAXFIL_TITULO][MAXCOL_TITULO] =
    {
        {b,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,d},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,a,a,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,0,a,a,0,0,0,a,a,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,a,a,0,0,0,0,0,0,0,a,a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,0,0,a,a,0,a,0,0,g},
        {g,0,0,a,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,a,0,0,g},
        {g,0,0,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
        {g,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,g},
    };

label2 :
    system("cls");
    setColor(COLOR_TXT_PUCMM1);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < MAXFIL_TITULO; i++)
    {
        printf(space"\t");
        for(j = 0; j < 200; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(COLOR_TXT_PUCMM1);
    printf("\t\t\t        %c\t\t       SUPERMERCADOS\t\t\t\t%c",186,186,186);
    Sleep(100);
    setColor(COLOR_TXT_PUCMM1);
    i = 0;
#define space1 "  "
    printf("\t\t\t\t\t\t        %c",204);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\t                                                %c",186);
    printf(space1"1. VER PRODUCTOS    ");
    printf(space1"2. FACTURACION  ");
    printf(space1"3. SALIR             %c",186);
    printf("        \t\t\t                        %c",200);

    for(i = 0; i < 63; i++)
    {
        printf("%c",205);
    }
    printf("%c",188);

    printf("\n"space space "ELIGE UNA OPCION:");
    char ch;
    ch = _getch();
    if(ch == '1')
    {
        view_products();
    }
    else if(ch == '2')
    {
        billing();
    }
    else if(ch == '3')
    {
        main_menu();
    }
    else
    {
        setColor(RED);
        printf("invalid input\n");
        setColor(BLACK);
    }
    goto label2;
}

void billing()//generating bill
{
    system("cls");
    char product_no[100], *tempstring, cpydata[100], mrp[100];
    int i, k, j, x, flag = 0, temp1 = count, l = 0;
    double total = 0;
    tempstring = (char *)malloc(sizeof(char)*1);
    FILE *fp;
label:
    fp = fopen("billing_system_products_DB.txt","r");
    i = 0;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i] = x;
        i++;
    }
    cpydata[i] = '\0';
    fclose(fp);
    system("cls");
    printf("\n\n\n\n\n\n\n"space space"\t\tFacturacion.");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\tNo. Producto     : %c            %c\n",179,179);
    printf(space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t  Cantidad       : %c            %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,15);
    scanf("%d", &bill[count].quantity);
    if(strstr(cpydata,product_no) == NULL)
    {
        char ch;
        setColor(RED);
        printf("\n"space"Codigo del producto invalido!!");
        setColor(BLACK);
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        cashier_menu();
    }
    else
    {
        tempstring = strstr(cpydata,product_no);
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        flag = 0;
        while(tempstring[i] != '\0' )
        {
            if(tempstring[i] == '|')
            {
                break;
            }
            else if(tempstring[i] == '$')
            {
                flag = 2;
            }
            else if(flag == 2)
            {
                bill[count].name[k] = tempstring[i];
                k++;
            }
            else if(tempstring[i] != '*' && flag == 0)
            {
                bill[count].code[j] = tempstring[i];
                j++;
            }
            else if(tempstring[i] == '*')
            {
                bill[count].code[j] == '\0';
                flag = 1;
            }
            else
            {
                mrp[l] = tempstring[i];
                l++;
            }
            i++;
        }
        bill[count].name[k] = '\0';
        mrp[l] = '\0';
    }
    bill[count].rate = strtod(mrp,NULL);
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n"space"Quieres agregar mas productos?(y/n)?");
    char ch;
    ch = _getch();
    if(ch == 'y')
    {
        count++;
        goto label;
    }
    else//print bill
    {
        system("cls");
        printf("%d\n", count);
        printf(space"Codigo del producto\t   precio del producto\tcantidad\t  nombre del producto\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n");
        for(i = temp1; i <= count; i++)
        {
            printf(space"   %s\t\t   %lf  \t\t%d\t\t  %s\n\n", bill[i].code, bill[i].rate, bill[i].quantity, bill[i].name);
            total = total + ((bill[i].rate) * (bill[i].quantity));
        }
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space"Sub Total %lf", total);
        int rnd;
        rnd = round(total);
        printf("\n"space"Redondenado: %d", rnd);
        printf("\n"space"Total de monto por pagar: %d",rnd);
        count++;
    }
    _getch();
    cashier_menu();
}

int main()
{
    setBackgroundColor(COLOR_BACKGROUND);
    system("color f0");
    animation();
    main_menu();
    return 0;
}
