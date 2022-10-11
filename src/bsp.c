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

#include "ciaa.h"
#include "poncho.h"

/* === Definicion y Macros privados ======================================== */

/* === Declaraciones de tipos de datos privados ============================ */

/* === Definiciones de variables privadas ================================== */

static struct board_s board = {0};

/* === Definiciones de variables publicas ================================== */

/* === Declaraciones de funciones privadas ================================= */

/* === Definiciones de funciones privadas ================================== */

/* === Definiciones de funciones publicas ================================== */

board_t BoardCreate(void){

    Chip_SCU_PinMuxSet(LED_R_PORT, LED_R_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_R_FUNC);

    Chip_SCU_PinMuxSet(LED_G_PORT, LED_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_G_FUNC);

    Chip_SCU_PinMuxSet(LED_B_PORT, LED_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_B_FUNC);
    board.led_azul = CrearSalidaDigital(LED_B_GPIO, LED_B_BIT);//LED AZUL


    /**********SALIDAS********/
    Chip_SCU_PinMuxSet(LED_1_PORT, LED_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_1_FUNC);
    board.led_uno_rojo = CrearSalidaDigital(LED_1_GPIO, LED_1_BIT);//LED ROJO

    Chip_SCU_PinMuxSet(LED_2_PORT, LED_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_2_FUNC);
    board.led_dos_amarillo = CrearSalidaDigital(LED_2_GPIO, LED_2_BIT);//LED AMARILLO

    Chip_SCU_PinMuxSet(LED_3_PORT, LED_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_3_FUNC);
    board.led_tres_verde = CrearSalidaDigital(LED_3_GPIO, LED_3_BIT);//LED VERDE
    
    
    /*********ENTRADAS*********/
    Chip_SCU_PinMuxSet(TEC_1_PORT, TEC_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_1_FUNC);
    board.boton_1_prueba = CrearEntradaDigital(TEC_1_GPIO, TEC_1_BIT,true);//prueba

    Chip_SCU_PinMuxSet(TEC_2_PORT, TEC_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_2_FUNC);
    board.boton_2_cambiar = CrearEntradaDigital(TEC_2_GPIO, TEC_2_BIT,true);//cambiar
 
    Chip_SCU_PinMuxSet(TEC_3_PORT, TEC_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_3_FUNC);
    board.boton_3_encender = CrearEntradaDigital(TEC_3_GPIO, TEC_3_BIT,true);//encender
 
    Chip_SCU_PinMuxSet(TEC_4_PORT, TEC_4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_4_FUNC);
    board.boton_4_apagar = CrearEntradaDigital(TEC_4_GPIO, TEC_4_BIT,true);//apagar
    
    
    Chip_SCU_PinMuxSet(TIEMPO_PORT, TIEMPO_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TIEMPO_FUNC);
    board.establecer_tiempo = CrearEntradaDigital(TIEMPO_GPIO, TIEMPO_4_BIT,true);//

    Chip_SCU_PinMuxSet(ALARMA_PORT, ALARMA_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | ALARMA_FUNC);
    board.establecer_tiempo = CrearEntradaDigital(ALARMA_GPIO, ALARMA_BIT,true);//

    return &board;
}

/* === Ciere de documentacion ============================================== */

/** @} Final de la definición del modulo para doxygen */