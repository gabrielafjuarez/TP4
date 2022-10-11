/* Copyright 2022, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 */


/** \brief Plantilla de archivos de cabecera 
 **
 ** \addtogroup hal HAL
 ** \brief Hardware abstraction layer
 ** @{ 
 */

/* === Inclusiones de cabeceras ============================================ */

#include "bsp.h"
#include "chip.h"

#include "poncho.h"

/* === Definicion y Macros privados ======================================== */

/* === Declaraciones de tipos de datos privados ============================ */

/* === Definiciones de variables privadas ================================== */

static struct board_s board = {0};

/* === Definiciones de variables publicas ================================== */

/* === Declaraciones de funciones privadas ================================= */
void InicializarDigitos(void);
void InicializarSegmentos(void);

void InicializarZumbador(void);
void InicializarTeclas(void);

/* === Definiciones de funciones privadas ================================== */
void InicializarDigitos(void){

}
void InicializarSegmentos(void){

}

void InicializarZumbador(){
    /**********SALIDAS********/
    Chip_SCU_PinMuxSet(ZUMBADOR_PORT, ZUMBADOR_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | ZUMBADOR_FUNC);
    board.zumbador = CrearSalidaDigital(ZUMBADOR_GPIO, ZUMBADOR_BIT);//LED VERDE 
}

void InicializarTeclas(){
/*********ENTRADAS*********/
    Chip_SCU_PinMuxSet(TIEMPO_PORT, TIEMPO_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TIEMPO_FUNC);
    board.establecer_tiempo = CrearEntradaDigital(TIEMPO_GPIO, TIEMPO_BIT,true);//

    Chip_SCU_PinMuxSet(ALARMA_PORT, ALARMA_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | ALARMA_FUNC);
    board.establecer_alarma = CrearEntradaDigital(ALARMA_GPIO, ALARMA_BIT,true);//

    Chip_SCU_PinMuxSet(ACEPTAR_PORT, ACEPTAR_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | ACEPTAR_FUNC);
    board.aceptar = CrearEntradaDigital(ACEPTAR_GPIO, ACEPTAR_BIT,true);//
        
    Chip_SCU_PinMuxSet(CANCELAR_PORT, CANCELAR_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | CANCELAR_FUNC);
    board.cancelar = CrearEntradaDigital(CANCELAR_GPIO, CANCELAR_BIT,true);//
    
    Chip_SCU_PinMuxSet(INCREMENTAR_PORT, INCREMENTAR_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | INCREMENTAR_FUNC);
    board.incrementar = CrearEntradaDigital(INCREMENTAR_GPIO, INCREMENTAR_BIT,true);//
    
    Chip_SCU_PinMuxSet(DECREMENTAR_PORT, DECREMENTAR_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | DECREMENTAR_FUNC);
    board.decrementar = CrearEntradaDigital(DECREMENTAR_GPIO, DECREMENTAR_BIT,true);//
}
/* === Definiciones de funciones publicas ================================== */

board_t BoardCreate(void){

    InicializarDigitos();
    InicializarSegmentos();
    InicializarZumbador();
    InicializarTeclas();
          
    return &board;
}

/* === Ciere de documentacion ============================================== */

/** @} Final de la definición del modulo para doxygen */