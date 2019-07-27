#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "validaciones.h"

/** \brief Obtiene una variable int
 * \param pNum dirección de memoria de la variable donde se cargará el entero
 * \param msg mensaje para solicitar el ingreso del entero
 * \param msgE mensajes de error si el ingreso es inválido
 * \return Devuelve [0] si está todo ok
 *                  [-1] si hay error
 */
int getInt (int* pNum, char* msg, char* msgE)
{
    char number[20];
    int ret = -1;

    printf("%s", msg);

    fflush(stdin);
    if(scanf("%s", number) == 1 && isNumberInt(number) == 1)
    {
        (*pNum) = atoi(number);
        ret = 0;
    }
    else
    {
        printf("%s\n", msgE);
    }

    return ret;
}

/** \brief Valida numeros enteros
* \param pStr array de char
* \return retorna 1 diciendo que no hay error
*/
int isNumberInt (char* pStr)
{
    int i=0;

    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }

    return 1;
}

/** \brief Obtiene una categoria de factura [C], [P] o [B]
 * \param pChar dirección de memoria de la variable donde se cargará la categoria
 * \param msg mensaje para solicitar el ingreso de la categoria
 * \param msgE mensajes de error si el ingreso es inválido
 * \return Devuelve [0] si está todo ok
 *                  [-1] si hay error
 */
int getCategoria (char* pChar, char* msg, char* msgE)
{
    char letter;
    int ret = -1;

    printf("%s", msg);

    fflush(stdin);
    if(scanf("%c", &letter) == 1 && validarCategoria(letter) == 0)
    {
        (*pChar) = toupper(letter);
        ret = 0;
    }
    else
    {
        printf("%s\n", msgE);
    }

    return ret;
}

/** \brief Valida que la categoria sea [C], [P] o [B]
 * \param categoria es el caracter a validar
 * \return Devuelve [0] si está todo ok
 *                  [-1] si hay error
 */
int validarCategoria (char categoria)
{
    int ret = -1;

    if(categoria == 'C' || categoria == 'c'
       || categoria == 'P' || categoria == 'p'
       || categoria == 'B' || categoria == 'b')
    {
        ret = 0;
    }

    return ret;
}

/** \brief Obtiene una variable float
* \param array de float sin especificar
* \param algun mensaje que se quiera expresar
* \param msgE mensajes de error de las funciones
* \return retorna 0 diciendo que no hay error o -1 si lo hay
*/
int getFloat (float *pNum, char* msg, char* msgE)
{
    float number;
    int ret = -1;

    printf("%s", msg);

    if(scanf("%f", &number) == 1)
    {
        (*pNum) = number;
        ret = 0;
    }
    else
    {
        printf("%s\n", msgE);
    }
    return ret;
}
