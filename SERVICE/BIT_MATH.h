
// Header Guard 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR , BITNO)        VAR|=  (1 << BITNO)   // Or sets value from 0 to 1.
#define CLR_BIT(VAR , BITNO)        VAR&= ~(1 << BITNO)   // and clear/reset value from 1 to 0.
#define GET_BIT(VAR , BITNO)      ((VAR>>BITNO)&1)       // To get the value of a certain pin.
#define TOG_BIT(VAR , BITNO)  VAR^= (1 << BITNO)   // XOR it toggles the value of the bit from 0 to 1 and from 1 to 0
#define SET_PORT(VAR)               VAR|=255             // To set  whole port pins to 1.
#define CLR_PORT(VAR)               VAR&=0               // To clear  whole port pins to 0.
#define GET_PORT(VAR)               VAR=VAR              // To get port value.
#define SET_VALUE(VAR, VALUE)       VAR=VALUE

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif 
