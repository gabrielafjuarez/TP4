
/** \brief Definiciones de abstraccion de pantalla multiplexada de Siete segmentos
 **
 ** \addtogroup hal HAL
 ** \brief capa de abstraccion de Hardware
 ** @{ */

/* === Inclusiones de cabeceras ============================================ */
#include "pantalla.h"
#include "poncho.h"
#include <string.h>
#include "chip.h"
/* === Definicion y Macros privados ======================================== */

#ifndef DISPLAY_MAX_DIGITS
    #define DISPLAY_MAX_DIGITS 8
#endif


/* === Declaraciones de tipos de datos privados ============================ */
struct display_s{
    uint8_t digits;
    uint8_t active_digit;
    uint8_t memory[DISPLAY_MAX_DIGITS];//tiene que ser igual o menor que la cantidad de digitos
};

/* === Definiciones de variables privadas ================================== */

static struct display_s instances [1];

static const uint8_t DIBUJAR [] = {
    SEGMENT_A + SEGMENT_B + SEGMENT_C + SEGMENT_D + SEGMENT_E + SEGMENT_F,              // CERO
    SEGMENT_B + SEGMENT_C,                                                              // UNO
    SEGMENT_A + SEGMENT_B + SEGMENT_G + SEGMENT_E + SEGMENT_D,                          //! < 2
    SEGMENT_A + SEGMENT_B + SEGMENT_C + SEGMENT_D + SEGMENT_G,                          //! < 3
    SEGMENT_F + SEGMENT_B + SEGMENT_G + SEGMENT_C,                                      //! < 4
    SEGMENT_A + SEGMENT_F + SEGMENT_G + SEGMENT_C + SEGMENT_D,                          //! < 5
    SEGMENT_A + SEGMENT_F + SEGMENT_E + SEGMENT_D + SEGMENT_C + SEGMENT_G,              //! < 6
    SEGMENT_A + SEGMENT_B + SEGMENT_C,                                                  //! < 7
    SEGMENT_A + SEGMENT_B + SEGMENT_C + SEGMENT_D + SEGMENT_E + SEGMENT_F+ SEGMENT_G,   //! < 8
    SEGMENT_A + SEGMENT_B + SEGMENT_C + SEGMENT_F + SEGMENT_G,                          //! < 9
};

/* === Definiciones de variables publicas ================================== */

/* === Declaraciones de funciones privadas ================================= */

/* === Definiciones de funciones privadas ================================== */

//apagar pantalla
void ApagarPantalla(){
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, DIGITS_GPIO, DIGITS_MASK);//pongo en cero los digitos 
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, SEGMENTS_GPIO, SEGMENTS_MASK);//pongo en cero los segmentos
}

//funcion que de acuerdo al numero que le indico, pinta los segmentos correspondientes 
//a ese numero
void EscribirNumero(uint8_t segmentos){
//DIBUJAR[numero]
    Chip_GPIO_SetValue(LPC_GPIO_PORT, SEGMENTS_GPIO, segmentos);
}

void SeleccionarDigito(uint8_t digito){
    Chip_GPIO_SetValue(LPC_GPIO_PORT, DIGITS_GPIO, (1 << digito)); 
}


/* === Definiciones de funciones publicas ================================== */

display_t CrearPantalla(uint8_t digits){
    display_t display = instances;

    display->digits = digits;
    display->active_digit = digits - 1;
    memset(display->memory, 0, sizeof(display->memory)); //limpiar la memoria
    
    ApagarPantalla();

    return display;
}


void EscribirPantallaBCD(display_t display, uint8_t * number, uint8_t size){
    memset(display->memory, 0, sizeof(display->memory)); //limpiar la memoria
    for (int index = 0; index < size; index++){
        if(index >= display->digits) break;
        display->memory[index] = DIBUJAR[number[index]];
    }
}


void RefrescarPantalla(display_t display){
    ApagarPantalla();
    
    if (display->active_digit == display->digits - 1) {
        display->active_digit = 0;
    } else {
        display->active_digit = display->active_digit + 1;
    }

    EscribirNumero(display->memory[display->active_digit]);
    SeleccionarDigito(display->active_digit);
}

/* === Ciere de documentacion ============================================== */

/** @} Final de la definición del modulo para doxygen */

