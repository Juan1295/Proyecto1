#include<stdint.h>
#include<stdbool.h>

/**
* \brief Funcion que  .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param rx Registro donde se almacena la operacion AND.
* \return No retorna.
*/
    struct flg //se define una estructura para las banderas.
    {
        bool negativo;
        bool zero;
        bool carry;
        bool sobreflujo;
    };

void flags(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);//Se declara la función variable
