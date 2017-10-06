#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "pantalla.h"
#include "contrataciones.h"

#define CANT_PANT 5
#define CANT_CONTRATOS 8


int main()
{
    sPantalla listaPant[CANT_PANT];
    sContratos listaContratos[CANT_CONTRATOS];

    pantalla_initArray(listaPant, CANT_PANT);
    contrato_initArray(listaContratos, CANT_CONTRATOS);

    char opcion[10];
    int salir = 1;
    do
    {
        val_getUnsignedInt(opcion,"\n\n1- Alta de pantalla.\n2- Modificar datos de pantalla.\n3- Baja de pantalla.\n4- Nueva publicacion.\n5- modificar publocacion.\n6- baja de publicacion.\n7- consultar facturacion.\n8- listar contrataciones.\n9- listar pantallas.\n10- informar.\n11- Salir.\n\nIngrese una opcion: ","\nIngrese una opcion valida.\n",3,10);

        switch(atoi(opcion))
        {
        case 1:
            pantalla_cargarPantalla(listaPant, CANT_PANT);
            break;
        case 2:
            pantalla_modificar(listaPant, CANT_PANT);
            break;
        case 3:
            pantalla_darDeBaja(listaPant, CANT_PANT);
            break;
        case 4:
            contrato_altaDeContrato(listaContratos,CANT_CONTRATOS, listaPant, CANT_PANT);
            break;
        case 5:
            contrato_modificarContrato(listaContratos, CANT_CONTRATOS, listaPant, CANT_PANT);
            break;
        case 6:
            contrato_bajaDeContrato(listaContratos, CANT_CONTRATOS, listaPant, CANT_PANT);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            informe_pantalla(listaPant, CANT_PANT);
            break;
        case 10:

            break;
        case 11:
            salir = 0;
            break;
        }
    }
    while(salir != 0);
    return 0;
}



