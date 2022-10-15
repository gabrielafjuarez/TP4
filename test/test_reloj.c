#include "unity.h"
#include "reloj.h"

//Configurar libreria, consultar hora, y la hora debe ser invalida
void test_hora_inicial(void){
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];

    reloj_t reloj = CrearReloj(5);
    TEST_ASSERT_FALSE(TraerHoraReloj(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, 6);
}