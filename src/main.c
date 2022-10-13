/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Esteban Volentini <evolentini@herrera.unt.edu.ar>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include "bsp.h"
#include <stdbool.h>
#include "poncho.h"
#include "chip.h"

/* === Macros definitions ====================================================================== */
//DEFINICION DE BITS ASOCIADOS A CADA SEGMENTO PARA CONSTRUIR DIGITOS
//defino los segmentos
#define SEGMENT_A (1 << 0)
#define SEGMENT_B (1 << 1)    
#define SEGMENT_C (1 << 2)
#define SEGMENT_D (1 << 3)
#define SEGMENT_E (1 << 4)
#define SEGMENT_F (1 << 5)
#define SEGMENT_G (1 << 6)
#define SEGMENT_P (1 << 7)

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */
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

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
//apagar pantalla
void ApagarPantalla(){
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, DIGITS_GPIO, DIGITS_MASK);//pongo en cero los digitos 
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, SEGMENTS_GPIO, SEGMENTS_MASK);//pongo en cero los segmentos
}

//funcion que de acuerdo al numero que le indico, pinta los segmentos correspondientes 
//a ese numero
void EscribirNumero(uint8_t numero){
//DIBUJAR[numero]
    Chip_GPIO_SetValue(LPC_GPIO_PORT, SEGMENTS_GPIO, DIBUJAR[numero]);
}

void SeleccionarDigito(uint8_t digito){
    Chip_GPIO_SetValue(LPC_GPIO_PORT, DIGITS_GPIO, (1 << digito)); 
}

/* === Public function implementation ========================================================= */

int main(void) {
   //uint8_t valor = 0; // lo que veo en pantalla
    uint8_t actual = 0; //posicion en la que veo lo que esta en pantalla
    //bool refrescar = true; 
        //bool current_state, last_state = false;
    
    uint8_t pantalla[4] = {1,2,3,4};
    //declaramos un arreglo donde decimos que numero se va a ver en que posicion

    board_t board = BoardCreate();
        //CUANDO LLAMAMOS A BOARDCRWATE, TENEMOS LA PANTALLA APAGADA
    
    //PARA ENCENDER UN NUMERO TENEMOS QUE PONER UN DIGITO EN 1 Y LOS SEGMENTOS TAMBIEN EN 1
    // EscribirNumero(valor);
    // SeleccionarDigito(actual);
    //Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_A_GPIO, SEGMENT_A_BIT, true);//prendo la salida que corresponde al segmento A
    //usamos esta funcion para prender un bit
    //Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_1_GPIO, DIGIT_1_BIT, true);
//    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_2_GPIO, DIGIT_2_BIT, true);

    while (true) {
        // if (refrescar){
        //     refrescar = false;
            ApagarPantalla();
            EscribirNumero(pantalla[actual]);
            SeleccionarDigito(actual);
       // }
        
        if (actual == 3) {
            actual = 0;
        } else {
            actual = actual + 1;
        }



        // if (ActivaEntradaDigital(board->establecer_tiempo)){
        //     if (valor == 9) {
        //         valor = 0;
        //     } else {
        //         valor = valor + 1;
        //     }
        //     refrescar = true;
        // }
        // if (ActivaEntradaDigital(board->establecer_alarma)){
        //     if (valor == 0) {
        //         valor = 9;
        //     } else {
        //         valor = valor - 1;
        //     }
        //     refrescar = true;
        // }

        // if (ActivaEntradaDigital(board->incrementar)){
        //     if (actual == 3) {
        //         actual = 0;
        //     } else {
        //         actual = actual + 1;
        //     }
        //     refrescar = true;
        // }
        // if (ActivaEntradaDigital(board->decrementar)){
        //     if (actual == 0) {
        //         actual = 3;
        //     } else {
        //         actual = actual - 1;
        //     }
        //     refrescar = true;
        // }



        //for (int index = 0; index < 100; index++) {
            for (int delay = 0; delay < 2500; delay++) {
                __asm("NOP");
            }
        //}
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
