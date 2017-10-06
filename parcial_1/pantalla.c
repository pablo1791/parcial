#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "pantalla.h"

/** \brief inicializa el los campos del array
 * \param array. estructura recibida por referencia
 * \param longitud. tamaño del array
 * \return 0 ok -1 error
 *
 */
int pantalla_initArray (sPantalla* arrayPantalla, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantalla != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPantalla[i].estadoPantalla = SIN_ALTA;
        }

    }
    return retorno;
}

/***************************************************************************************************/

/** \brief da de alta una pantalla
 * \param arrayPersona del tipo de dato pantalla
 * \param longitud  tamaño del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo realizar la carga
 *
 */
int pantalla_cargarPantalla (sPantalla* arrayPantalla,int longitud)
{
    int retorno = -1;
    int i, indice, contadorIntentos=0;
    char bNombre[51];
    char bPrecio[10];
    char opcion[10];
    int flagMotivo = 0;

    if(arrayPantalla != NULL && longitud >= 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayPantalla[i].estadoPantalla == SIN_ALTA)
            {
                indice = i;
                break;
            }
        }

        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
        {
            if(val_getFloat(bPrecio, "\nIngrese precio: ", "\nError",3,10)== 0)
            {

                do
                {
                    val_getUnsignedInt(opcion, "ingrese tipo de pantalla\n1-LCD\n2-LED\n", "opcion incorrecta\n", 3, 10);
                    switch(atoi(opcion))
                    {
                    case 1:
                        arrayPantalla[indice].tipo = LCD;
                        flagMotivo = 1;
                        break;
                    case 2:
                        arrayPantalla[indice].tipo = LED;
                        flagMotivo = 1;
                        break;
                    }
                    contadorIntentos ++;
                }
                while (flagMotivo == 0 && contadorIntentos < 3);
            }
            if(flagMotivo==1)
            {
                strncpy(arrayPantalla[indice].nombre,bNombre,51);
                arrayPantalla[indice].precio = atof(bPrecio);

                arrayPantalla[indice].id = pantalla_generarProximoId();
                arrayPantalla[indice].estadoPantalla = OCUPADA;
                retorno = 0;
            }
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

int pantalla_generarProximoId (void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/***************************************************************************************************/

/** \brief recorre el array para modificar campos de la estructura
 *
 * \param array recibido porreferencia
 * \param longitud tamaño del array
 * \return 0 ok -1 error
 *
 */
int pantalla_modificar (sPantalla* arrayPantalla,int longitud)
{
    int retorno = -1;
    int idAux;
    char buffer[10];
    int indice, contadorIntentos=0;
    char bNombre[51];
    char bPrecio[10];
    char opcion[10];
    int flagMotivo = 0;

    val_getUnsignedInt(buffer,"Ingrese el ID a modificar", "El ID no se encontro",3,10);
    idAux = atoi(buffer);
    indice = pantalla_buscarIndicePorId(arrayPantalla,longitud,idAux, "No se encontro el id");

    if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
    {
        if(val_getFloat(bPrecio, "\nIngrese precio: ", "\nError",3,10)== 0)
        {
             do
                {
                    val_getUnsignedInt(opcion, "ingrese tipo de pantalla\n1-LCD\n2-LED\n", "opcion incorrecta\n", 3, 10);
                    switch(atoi(opcion))
                    {
                    case 1:
                        arrayPantalla[indice].tipo = LCD;
                        flagMotivo = 1;
                        break;
                    case 2:
                        arrayPantalla[indice].tipo = LED;
                        flagMotivo = 1;
                        break;
                    }
                    contadorIntentos ++;
                }
                while (flagMotivo == 0 && contadorIntentos < 3);
            }
            if(flagMotivo==1)
            {
                strncpy(arrayPantalla[indice].nombre,bNombre,51);
                arrayPantalla[indice].precio = atof(bPrecio);

                arrayPantalla[indice].id = pantalla_generarProximoId();
                arrayPantalla[indice].estadoPantalla = OCUPADA;
                retorno = 0;
            }
        }
        return retorno;
    }



/***************************************************************************************************/

/** \brief recorre el array buscando un indice utilizando un id
 *
 * \param arrayllamada. estructura recibida por referencia
 * \param longitud. tamaño del array
 * \param id recibido para buscar indice
 * \param mensaje
 * \return 0 ok -1 error
 *
 */
int pantalla_buscarIndicePorId (sPantalla* arrayPantalla, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayPantalla != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantalla[i].id == id)
            {
                retorno = i;
                break;
            }
        }
        if(retorno == -1)
        {
            printf("%s", mensaje);
        }
    }
    return retorno;
}

/***************************************************************************************************/

/** \brief recorre el array para haceruna baja logica
 *
 * \param array recibido porreferencia
 * \param longitud tamaño del array
 * \return 0 ok -1 error
 *
 */
int pantalla_darDeBaja (sPantalla* arrayPantalla,int longitud)
{
    int retorno = -1;
    int idAux;
    char buffer[10];
    int indice;

    val_getUnsignedInt(buffer,"Ingrese el ID para dar de baja", "El ID no se encontro",3,10);
    idAux = atoi(buffer);

    indice = pantalla_buscarIndicePorId(arrayPantalla,longitud,idAux, "No se encontro el id");

    if(indice != -1)
    {
        arrayPantalla[indice].estadoPantalla = SIN_ALTA;
        retorno = 0;

    }
    return retorno;
}
