#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "pantalla.h"
#include "contrataciones.h"
#include "pantalla.h"
#include "informes.h"


/** \brief inicializa el los campos del array
 * \param array. estructura recibida por referencia
 * \param longitud. tamaño del array
 * \return 0 ok -1 error
 *
 */
int contrato_initArray (sContratos* arrayContrato, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrato != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayContrato[i].estadoContrato = SIN_CONTRATO;
        }

    }
    return retorno;
}

/***************************************************************************************************/

/** \brief genera un id auto-incrementable
 *
 * \return id
 *
 */
static int idAutoincrementable = -1;

int contrato_generarProximoId (void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/***************************************************************************************************/

/** \brief da de alta una pantalla
 * \param arrayPersona del tipo de dato pantalla
 * \param longitud  tamaño del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo realizar la carga
 *
 */
int contrato_altaDeContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla )
{
    int retorno = -1;
    int i, idAux, indice;
    char bNombre[51];
    char bCuit[15];
    char bDias[15];
    char buffer[10];


    if(informe_pantalla(arrayPantalla, longitudPantalla)!=-1)
    {
        if(arrayContrato != NULL && longitudContrato >= 0)
        {
            for(i=0; i<longitudContrato; i++)
            {
                if(arrayContrato[i].estadoContrato== SIN_CONTRATO)
                {
                    indice = i;
                    break;
                }
            }

            val_getUnsignedInt(buffer,"\nIngrese ID pantalla: ", "\nError",3,10);
            idAux = atoi(buffer);
            indice = pantalla_buscarIndicePorId(arrayPantalla,longitudPantalla, idAux, "\nNo se encontro el id");

            if(val_getString(bNombre,"\nIngrese su nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
            {
                if(val_getUnsignedInt(bCuit, "\nIngrese cuit: ", "\nError",3,15)== 0)
                {
                    if(val_getUnsignedInt(bDias,"\nIngrese el tiempo de contrato (dias): ","\nError ",2,15)== 0)
                    {
                        strncpy(arrayContrato[indice].nombre,bNombre,51);
                        strcpy(arrayContrato[indice].cuit, bCuit);
                        arrayContrato[indice].dias = atoi(bDias);
                        arrayContrato[indice].id = contrato_generarProximoId();
                        arrayContrato[indice].idPantalla = arrayPantalla[indice].id;
                        arrayContrato[indice].estadoContrato = EN_CURSO;
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

/***************************************************************************************************/

/** \brief da baja un contrato
 * \param arrayPersona del tipo de dato p
 * \param longitud  tamaño del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo realizar la carga
 *
 */
int contrato_bajaDeContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla )
{
    int retorno = -1;
    int i;
    char bCuit[15];
    val_getUnsignedInt(bCuit, "\nIngrese cuit: ", "\nError",3,15);

    if(arrayContrato != NULL && longitudContrato >= 0)
    {
        for(i=0; i<longitudContrato; i++)
        {
            if(arrayContrato[i].estadoContrato== EN_CURSO)
            {
                if(strcmp(bCuit,arrayContrato[i].cuit)==0)
                {
                    arrayContrato[i].estadoContrato= TERMINADO;
                    retorno=0;
                }
            }
            break;
        }
    }
    return retorno;
}


/***************************************************************************************************/

/** \brief da baja un contrato
 * \param arrayPersona del tipo de dato p
 * \param longitud  tamaño del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo realizar la carga
 *
 */
int contrato_modificarContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla )
{
    int retorno = -1;
    int indiceCont, indicepan;

    char bNombre[51];
    char bCuit[15];
    char bDias[15];

    val_getUnsignedInt(bCuit, "\nIngrese cuit: ", "\nError",3,15);
    informe_pantalla(arrayPantalla, longitudPantalla);

    if(arrayContrato != NULL && longitudContrato >= 0)
    {
        for(indiceCont=0; indiceCont<longitudContrato; indiceCont++)
        {
            if(strcmp(arrayContrato[indiceCont].cuit, bCuit)==0)
            {
                if(arrayContrato[indiceCont].estadoContrato != SIN_CONTRATO)
                {
                    for(indicepan=0; indicepan<0; indicepan++)
                    {
                        if(arrayContrato[indiceCont].idPantalla == arrayPantalla[indicepan].id)
                        {
                            printf("\nNOMBRE: %s\tPRECIO: %d\tTIPO: %s\tID: %d\n",
                                   arrayPantalla[indicepan].nombre, arrayPantalla[indicepan].precio,
                                   arrayPantalla[indicepan].tipo, arrayPantalla[indicepan].id);
                            retorno=0;
                        }
                    }
                }
            }
            break;
        }
        if(val_getString(bNombre,"\nIngrese su nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
        {
            if(val_getUnsignedInt(bCuit, "\nIngrese cuit: ", "\nError",3,15)== 0)
            {
                if(val_getUnsignedInt(bDias,"\nIngrese el tiempo de contrato (dias): ","\nError ",2,15)== 0)
                {
                    strncpy(arrayContrato[indiceCont].nombre,bNombre,51);
                    strcpy(arrayContrato[indiceCont].cuit, bCuit);
                    arrayContrato[indiceCont].dias = atoi(bDias);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


