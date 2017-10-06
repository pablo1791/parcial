#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct{
    char nombre[51];
    int tipo;
    char precio;
    int id;
    unsigned int estadoPantalla;
}sPantalla;


#endif // PANTALLA_H_INCLUDED

#define SIN_ALTA 0
#define LIBRE 1
#define OCUPADA 2

#define LCD 0
#define LED 1

int pantalla_initArray (sPantalla* arrayPantalla, int longitud);
int pantalla_cargarPantalla (sPantalla* arrayPantalla,int longitud);
int pantalla_generarProximoId (void);
int pantalla_buscarIndicePorId (sPantalla* arrayPantalla, int longitud, int id, char* mensaje);
int pantalla_modificar (sPantalla* arrayPantalla,int longitud);
int pantalla_darDeBaja (sPantalla* arrayPantalla,int longitud);
