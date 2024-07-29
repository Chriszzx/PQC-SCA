#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "polyvec.h"
#include <stdio.h>
#include <string.h>
#include "kem.h"
#include "indcpa.h"
#include "randombytes.h"
#include "params.h"
#include "indcpa.h"
#include "verify.h"
#include "symmetric.h"
#include "reduce.h"

uint8_t pk[KYBER_INDCPA_PUBLICKEYBYTES];
uint8_t sk[KYBER_INDCPA_SECRETKEYBYTES];
uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
uint8_t key_a[CRYPTO_BYTES];
uint8_t key_b[CRYPTO_BYTES];
uint8_t m[KYBER_INDCPA_MSGBYTES];
uint8_t buf[2*KYBER_SYMBYTES];

uint8_t get_sk(uint8_t* data, uint8_t dlen)
{
  hash_g(buf, buf, KYBER_SYMBYTES);
  simpleserial_put('r', 32, data);
  return 0;
}


//////////////////////////////


int main(void)
{	
	platform_init();
	init_uart();
	trigger_setup();	
	simpleserial_init();
  
  simpleserial_addcmd('p',32,get_sk);

	while(1)
		simpleserial_get();
}