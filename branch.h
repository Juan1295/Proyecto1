#ifndef BRANCH_H
#define BRANCG_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

//Se crea la funcion registro BL (Branch with Link(immediate))
/**
* \brief Función que mueve pc un numero determinado de veces.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param lr guarda la direccion siguiente a la instrucción
* \return No retorna ningun parametro.
*/

void BL(uint32_t *pc,uint32_t imm,uint32_t *lr);//Se define la funcion BL (Branch with Link(immediate))

//Se crea la funcion registro BX (Branch and Exchange)
/**
* \brief Función que mueve pc a una dieccion especifica de instrucciones.
* \param pc número de la instruccion a ejecutar.
* \param rm número de la instruccion a la que se dese ir.
* \return No retorna ningun parametro.
*/

void BX(uint32_t *pc,uint32_t rm);//Se define la funcion BX (Branch and Exchange)

//Se crea la funcion registro BLX (Branch with Link and Exchange(register))
/**
* \brief Función que mueve pc un numero determinado de veces.
* \param pc número de la instruccion a ejecutar.
* \param rm número de instrucciones a ignorar.
* \param lr guarda la direccion siguiente a la instrucción
* \return No retorna ningun parametro.
*/

void BLX(uint32_t *pc,uint32_t rm,uint32_t *lr);//Se define la funcion BLX (Branch with Link and Exchange(register))

//Se crea la funcion registro B (Branch)
/**
* \brief Función que mueve pc un numero determinado de veces.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \return No retorna ningun parametro.
*/
void BAL(uint32_t *pc,uint32_t imm);//Se define la funcion B(Branch)

//Se crea la funcion registro BEQ
/**
* \brief Función que mueve pc un numero determinado de veces si si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param z bandera de cero.
* \return No retorna ningun parametro.
*/
void BEQ(uint32_t *pc,uint32_t imm,char z);//Se define la funcion BEQ

//Se crea la funcion registro B (Branch)
/**
* \brief Función que mueve pc un numero determinado de veces.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \return No retorna ningun parametro.
*/

void B(uint32_t *pc,uint32_t imm);//Se define la funcion B(Branch)


//Se crea la funcion registro BNE
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param z bandera de cero.
* \return No retorna ningun parametro.
*/

void BNE(uint32_t *pc,uint32_t imm,char z);//Se define la funcion BNE

//Se crea la funcion registro BCS
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param c bandera de carry.
* \return No retorna ningun parametro.
*/

void BCS(uint32_t *pc,uint32_t imm,char c);//Se define la funcion BCS

//Se crea la funcion registro BCC
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param c bandera de carry.
* \return No retorna ningun parametro.
*/

void BCC(uint32_t *pc,uint32_t imm,char c);//Se define la funcion BCC

//Se crea la funcion registro BMI
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param n bandera de negativo.
* \return No retorna ningun parametro.
*/

void BMI(uint32_t *pc,uint32_t imm,char c);//Se define la funcion BMI

//Se crea la funcion registro BPL
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param n bandera de negativo.
* \return No retorna ningun parametro.
*/

void BPL(uint32_t *pc,uint32_t imm,char n);//Se define la funcion BPL

//Se crea la funcion registro BVS
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param v bandera de sobreflujo.
* \return No retorna ningun parametro.
*/

void BVS(uint32_t *pc,uint32_t imm,char v);//Se define la funcion BVS

//Se crea la funcion registro BVC
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param v bandera de sobreflujo.
* \return No retorna ningun parametro.
*/

void BVC(uint32_t *pc,uint32_t imm,char v);//Se define la funcion BVC

//Se crea la funcion registro BHI
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param c y z bandera de carry y cero.
* \return No retorna ningun parametro.
*/

void BHI(uint32_t *pc,uint32_t imm,char c,char z);//Se define la funcion BHI

//Se crea la funcion registro BLS
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param c y z bandera de carry y cero.
* \return No retorna ningun parametro.
*/

void BLS(uint32_t *pc,uint32_t imm,char c,char z);//Se define la funcion BLS

//Se crea la funcion registro BGE
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param n y v bandera de negativo y sobreflujo.
* \return No retorna ningun parametro.
*/

void BGE(uint32_t *pc,uint32_t imm,char n,char v);//Se define la funcion BGE

//Se crea la funcion registro BLT
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param n y v bandera de negativo y sobreflujo.
* \return No retorna ningun parametro.
*/

void BLT(uint32_t *pc,uint32_t imm,char n,char v);//Se define la funcion BLT

//Se crea la funcion registro BGT
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param z,n y v bandera de zero,negativo y sobreflujo.
* \return No retorna ningun parametro.
*/

void BGT(uint32_t *pc,uint32_t imm,char z,char n,char v);//Se define la funcion BGT

//Se crea la funcion registro BLE
/**
* \brief Función que mueve pc un numero determinado de veces si la condicion se cumple.
* \param pc número de la instruccion a ejecutar.
* \param imm número de instrucciones a ignorar.
* \param z,n y v bandera de zero,negativo y sobreflujo.
* \return No retorna ningun parametro.
*/

void BLE(uint32_t *pc,uint32_t imm,char z,char n,char v);//Se define la funcion BLE


#endif // BRANCH_H
