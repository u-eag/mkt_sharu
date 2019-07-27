#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "validaciones.h"

/** \brief  Esta función permite procesar una cantidad desconocida de clientes,
 *          que finaliza con el número 0.
 *
 * \param   totalClientes es el total de clientes procesados
 * \param   categoriaMayorAbono es la categoría que dejó más ganancias
 * \param   totalFacturasB es la cantidad de facturas bonificadas B que hubo
 * \return  Devuelve [0] si está todo ok
 *                   [-1] si hay error
 *
 */
int procesarClientes(int* totalClientes, char* categoriaMayorAbono, int* totalFacturasB)
{
    int retorno = -1;
    int idCliente = -1;
    int contadorClientes = 0;
    int contadorCategoriaB = 0;
    float contadorImporteC = 0;
    float contadorImporteP = 0;
    float abonoTotalC = 0;
    float abonoTotalP = 0;

    do
    {
        if(getInt(&idCliente, "\nIngrese el ID del cliente: ", "Número de cliente invalido") == 0 && idCliente != 0)
        {
            printf("\n******** CLIENTE ID: %d ********\n", idCliente);
            if(ingresarImportes(&contadorCategoriaB, &contadorImporteC, &contadorImporteP) == 0)
            {
                contadorClientes++;
            }

            printf("\nTOTAL CLIENTE %d:\n", idCliente);
            printf("Abono C: %.2f", contadorImporteC);
            printf("\nAbono P: %.2f\n", contadorImporteP);

            (*totalFacturasB) += contadorCategoriaB;

            abonoTotalC += contadorImporteC;
            abonoTotalP += contadorImporteP;

            if(abonoTotalC > abonoTotalP)
            {
                *categoriaMayorAbono = 'C';
            }
            else if(abonoTotalC < abonoTotalP)
            {
                *categoriaMayorAbono = 'P';
            }
            else
            {
                *categoriaMayorAbono = 'E'; // en caso de empate
            }

            contadorImporteC = 0;
            contadorImporteP = 0;
        }

    }while(idCliente != 0);

    *totalClientes = contadorClientes;

    retorno = 0;

    return retorno;
}

/** \brief  Esta función permite ingresar 12 importes de facturación,
 *          variando la categoría de cliente en cada una.
 *
 * \param   facturasB cantidad de facturas B por cliente
 * \param   abonoFacturasC total abonado en facturas C por cliente
 * \param   abonoFacturasP total abonado en facturas P por cliente
 * \return  Devuelve [0] si está todo ok
 *                   [-1] si hay error
 *
 */
int ingresarImportes(int* facturasB, float* abonoFacturasC, float* abonoFacturasP)
{
    int retorno = -1;
    char categoria;
    int contadorCategoriaB = 0;
    int contadorCategoriaC = 0;
    int contadorCategoriaP = 0;
    float importe;
    float contadorImporteC = 0;
    float contadorImporteP = 0;
    int i;

    for(i=0;i<12;i++)
    {
        printf("\n **** FACTURA Numero %d ****\n", i+1);

        if (getCategoria(&categoria, "Ingrese la categoria del cliente para la factura: ", "Categoria invalida") != 0)
        {
            i--;
        }
        else if(categoria == 'B')
        {
            contadorCategoriaB++;
        }
        else if(categoria == 'C')
        {
            if(getFloat(&importe, "Ingrese el importe: ", "Importe invalido") != 0)
            {
                i--;
            }
            else
            {
                contadorCategoriaC++;
                contadorImporteC += importe;
            }
        }
        else if(categoria == 'P')
        {
            if(getFloat(&importe, "Ingrese el importe: ", "Importe invalido") != 0)
            {
                i--;
            }
            else
            {
                contadorCategoriaP++;
                contadorImporteP += importe;
            }
        }
    }

    *facturasB = contadorCategoriaB;
    *abonoFacturasC = contadorImporteC;
    *abonoFacturasP = contadorImporteP;

    retorno = 0;

    return retorno;
}
