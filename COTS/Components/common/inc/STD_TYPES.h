//
// Created by ali on 12/17/24.
//

#ifndef STD_TYPES_H
#define STD_TYPES_H

#define NULL    ((void*)0)
//#define TRUE    (0==0)
//#define FALSE   (0!=0)
#define HIGH    1
#define LOW     0
#define ON      1
#define OFF     0

typedef unsigned char				uint8_t;
typedef signed char					sint8_t;
typedef unsigned short int			uint16_t;
typedef signed short int			sint16_t;
typedef unsigned long int			uint32_t;
typedef signed long int				sint32_t;
typedef float						float32_t;
typedef unsigned long long int		uint64_t;
typedef signed long long int		sint64_t;
typedef double						float64_t;
typedef long double					float128_t;

typedef enum {
    TRUE  =  (0==0),
    FALSE =  (0!=0)
}bool;

#endif //STD_TYPES_H