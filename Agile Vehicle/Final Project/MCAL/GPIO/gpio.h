/*
 * gpio.h
 *
 * Created: 27/11/2018 10:06:56 ص
 *  Author: cisco126
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define setbit(reg,bit)          reg |=  (1<<(bit))
#define clearbit(reg,bit)        reg &= ~(1<<(bit))
#define toggle(reg,bit)          reg ^=  (1<<(bit))

#define setbits(reg,mask)        reg |=  mask
#define clearbits(reg,mask)      reg &= ~mask
#define togglebits(reg,mask)     reg ^=  mask

#define setallbit(reg)           reg |=  0xff
#define clearallbit(reg)         reg &= ~0xff
#define toggleallbit(reg)        reg ^=  0xff
 
#define getbit(reg,bit)          (reg&(1<<(bit)))
#define getbits(reg,mask)        (reg&mask)

#define writeBits(REG, DATA, MASK)	{							    \
	REG|= DATA & MASK;			\
	REG &= ~((~DATA) & MASK);	\
}

#endif /* GPIO_H_ */