/* Copyright 2022, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 */

#ifndef PONCHO_H
#define PONCHO_H

/** \brief Plantilla de archivos de cabecera 
 **
 ** \addtogroup hal HAL
 ** \brief Hardware abstraction layer
 ** @{ 
 */

/* === Inclusiones de archivos externos ==================================== */

#include "digital.h"

/* === Cabecera C++ ======================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros publicos ======================================== */
//  DEFINICIONES PARA CADA UNA DE LAS TECLAS NUEVAS
// DEFINICIONES DE LOS RECURSOS ASOCIADOS A LAS TECLAS DEL PONCHO

#define TIEMPO_PORT 4
#define TIEMPO_PIN 8
#define TIEMPO_FUNC SCU_MODE_FUNC4
#define TIEMPO_GPIO 5
#define TIEMPO_BIT 12

#define ALARMA_PORT 4
#define ALARMA_PIN 9
#define ALARMA_FUNC SCU_MODE_FUNC4
#define ALARMA_GPIO 5
#define ALARMA_BIT 13

#define INCREMENTAR_PORT 4
#define INCREMENTAR_PIN 10
#define INCREMENTAR_FUNC SCU_MODE_FUNC4
#define INCREMENTAR__GPIO 5
#define INCREMENTAR_BIT 14

#define DECREMENTAR_PORT 6
#define DECREMENTAR_PIN 7
#define DECREMENTAR_FUNC SCU_MODE_FUNC4
#define DECREMENTAR_GPIO 5
#define DECREMENTAR_BIT 15

#define ACEPTAR_PORT 2
#define ACEPTAR_PIN 3
#define ACEPTAR_FUNC SCU_MODE_FUNC4
#define ACEPTAR_GPIO 5
#define ACEPTAR_BIT 9

#define CANCELAR_PORT 3
#define CANCELAR_PIN 1
#define CANCELAR_FUNC SCU_MODE_FUNC4
#define CANCELAR_GPIO 5
#define CANCELAR_BIT 8

//DEFINICION DEL RECURSO ASOCIADO AL ZUMBADOR
#define ZUMBADOR_PORT 2
#define ZUMBADOR_PIN 2
#define ZUMBADOR_FUNC SCU_MODE_FUNC4
#define ZUMBADOR_GPIO 5
#define ZUMBADOR_BIT 2
/* == Declaraciones de tipos de datos publicos ============================= */

/* === Declaraciones de variables publicas ================================= */

/* === Declaraciones de funciones publicas ================================= */

/* === Ciere de documentacion ============================================== */

#ifdef __cplusplus
}
#endif

/** @} Final de la definición del modulo para doxygen */

#endif   /* PONCHO_H */