#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "polyvec.h"
#include <stdio.h>
#include <string.h>
#include "randombytes.h"
#include "api.h"
#include "indcpa.h"

#define NTESTS 1000

uint8_t get_key(uint8_t* k, uint8_t len)
{
    return 0x00;
}

uint8_t get_pt(uint8_t* pt, uint8_t len)
{
    // value sent from Python stored in pt
    // array for storing the 8 values sent from Python
    uint16_t pt_value[8];

    // convert the 16 bytes of pt to 8 numbers
    for (int i = 0; i < 16; i++)
    {
        pt_value[i/2] = (pt_value[i/2] << 8) | pt[i];
    }

    int32_t ret;   // initialize to 0
    poly a;   // 0..3328 from pt
    poly b;   // 2649 317 2649 317...	
	poly a_prime;

    trigger_high();
    poly_basemul_opt_16_32(&ret, &a, &b,&a_prime); // call function here
    trigger_low();



    // send 16 bytes in pt back
    simpleserial_put('r', 16, pt);
    
    
    /* End user-specific code here. *
    ********************************/

    return 0x00;
}

uint8_t reset(uint8_t* x, uint8_t len)
{
    // Reset key here if needed
    return 0x00;
}

int main(void)
{
    platform_init();
    init_uart();
    trigger_setup();

    simpleserial_init();
    simpleserial_addcmd('k', 16, get_key);
    simpleserial_addcmd('p', 16, get_pt);
    simpleserial_addcmd('x', 0, reset);
    while (1){
        simpleserial_get();
    }

}

