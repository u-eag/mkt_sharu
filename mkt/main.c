#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "validaciones.h"

int main()
{
    int totalClientesProcesados = 0;
    char categoriaMayorGanancia;
    int cantidadFacturasB = 0;

    if(procesarClientes(&totalClientesProcesados, &categoriaMayorGanancia, &cantidadFacturasB) == 0)
    {
        printf("\na. Total de clientes procesados: %d\n", totalClientesProcesados);

        if(categoriaMayorGanancia == 'E') // empate
        {
            printf("b. Categoria que dejo mas ganancias: C y P dejaron la misma cantidad de ganancias\n");
        }
        else
        {
            printf("b. Categoria que dejo mas ganancias: %c\n", categoriaMayorGanancia);
        }

        printf("c. Cantidad de facturas bonificadas (B): %d", cantidadFacturasB);
    }

    return 0;
}

