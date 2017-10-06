#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED
typedef struct{
    char nombre[51];
    char cuit[51];
    int dias;
    unsigned int estadoContrato;
    int id;
    int idPantalla;
}sContratos;


#endif // CONTRATACIONES_H_INCLUDED

#define SIN_CONTRATO 0
#define EN_CURSO 1
#define TERMINADO 1

int contrato_initArray (sContratos* arrayContrato, int longitud);
int contrato_generarProximoId (void);
int contrato_altaDeContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla );
int contrato_bajaDeContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla );
int contrato_modificarContrato (sContratos* arrayContrato, int longitudContrato, sPantalla* arrayPantalla, int longitudPantalla );
