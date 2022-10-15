#include "reloj.h"
#include <string.h>

#define SIZE_TIEMPO 6
#define VALOR_INICIAL 0

struct reloj_s{
    bool valida;
    uint8_t tiempo[SIZE_TIEMPO];
};

static struct reloj_s instancias;

//pongo la hora en cero
reloj_t CrearReloj(uint16_t ticks_por_segundo){
    instancias.valida = false;
    memset(instancias.tiempo, VALOR_INICIAL, SIZE_TIEMPO);
    return &instancias;
}

bool TraerHoraReloj(reloj_t reloj, uint8_t * tiempo, uint8_t size){
    memcpy(tiempo, reloj->tiempo, size);
    return reloj->valida;
}

void ConfigurarReloj(reloj_t reloj, uint8_t const * const tiempo, uint8_t size){
    memcpy(reloj->tiempo, tiempo, size);
    reloj->valida = true;
}