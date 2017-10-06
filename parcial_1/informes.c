#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "pantalla.h"
#include "contrataciones.h"

int informe_pantalla (sPantalla* arrayPantalla, int longitud)
{
    int i, retorno=-1;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayPantalla[i].estadoPantalla != SIN_ALTA)
            {
                printf("\nnombre: %s\ttipo: %d\tprecio: %d\tID: %d", arrayPantalla[i].nombre, arrayPantalla[i].tipo, arrayPantalla[i].precio, arrayPantalla[i].id);
                retorno=0;
            }

        }
    }

    return retorno;
}

int informe_pantalla (sPantalla* arrayPantalla, int longitud)
{
    int i, retorno=-1;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayPantalla[i].estadoPantalla != SIN_ALTA)
            {
                printf("\nnombre: %s\ttipo: %d\tprecio: %d\tID: %d", arrayPantalla[i].nombre, arrayPantalla[i].tipo, arrayPantalla[i].precio, arrayPantalla[i].id);
                retorno=0;
            }

        }
    }

    return retorno;
}

