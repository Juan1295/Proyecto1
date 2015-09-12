#include<stdint.h>
#include "desplazamiento.h"


/**
* \brief Funcion que  .
* \param rn Primer registro.
* \param rm Segundo registro.
* \param rx Registro donde se almacena la operacion AND.
* \return No retorna.
*/

void flags(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);//Se declara la funci�n variable

void flags_logica(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);

void flags_desplazamiento(uint32_t rx,uint32_t rn, uint32_t rm,struct flg *punt);
