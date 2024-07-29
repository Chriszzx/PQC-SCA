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

uint8_t pk[KYBER_PUBLICKEYBYTES];
uint8_t sk[KYBER_SECRETKEYBYTES];
uint8_t m[KYBER_INDCPA_MSGBYTES];
uint8_t ct[KYBER_CIPHERTEXTBYTES];
uint8_t ss[KYBER_SSBYTES];
uint8_t buf[2*KYBER_SYMBYTES];
const uint8_t coins[KYBER_SYMBYTES] = {124, 153, 53, 160, 176, 118, 148, 170, 12, 109, 16, 228, 219, 107, 26, 221, 47, 216, 26, 37, 204, 177, 72, 3, 45, 205, 115, 153, 54, 115, 127, 45};

uint8_t get_sk(uint8_t* data, uint8_t dlen)
{
	size_t i;
	PQCLEAN_KYBER512_CLEAN_crypto_kem_keypair_derand(pk,sk,coins);
	uint8_t temp[32];
	for(i=0;i<32;i++){
		temp[i] = sk[1600+i];
	}
	PQCLEAN_KYBER512_CLEAN_crypto_kem_enc_derand(ct,ss,pk,data);
	PQCLEAN_KYBER512_CLEAN_crypto_kem_dec(ss,ct,sk);
	simpleserial_put('r', 32, temp);
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