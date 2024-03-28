#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../randombytes.h"
#include "../sign.h"
#include "../packing.h"
#include "../poly.h"
#include "../polyvec.h"
#include "../params.h"
#include "../reduce.h"

#define MLEN 32
#define NTESTS 1


void print_poly(poly p);
void print_polyveck(polyveck t1);
void print_polyvecl(polyvecl t1);
bool compare_poly(const poly p1, const poly p2);
bool are_polyvecks_equal(const polyveck t1, const polyveck t2);
bool are_polyvecls_equal(const polyvecl t1, const polyvecl t2);
void convert_hex_to_uint8(const char* hex_str, uint8_t* seedbuf);


void print_poly(poly p) {
  for (int i = 0; i < N; ++i) {
    printf("%d ", p.coeffs[i]);
  }
  printf("\n");
}

void print_polyveck(polyveck t1) {
  for (int k = 0; k < K; ++k) {
    print_poly(t1.vec[k]);
  }
}

void print_polyvecl(polyvecl t1) {
  for (int k = 0; k < L; ++k){ 
    print_poly(t1.vec[k]);
  }
}

bool compare_poly(const poly p1, const poly p2) {
  for (int i = 0; i < N; ++i) {
    if (p1.coeffs[i] != p2.coeffs[i]) {
      return false;
    }
  }
  return true;
}

bool are_polyvecks_equal(const polyveck t1, const polyveck t2) {
  for (int k = 0; k < K; ++k) {
    if (!compare_poly(t1.vec[k], t2.vec[k])) {
      return false;
    }
  }
  return true;
}

bool are_polyvecls_equal(const polyvecl t1, const polyvecl t2) {
  for (int k = 0; k < L; ++k) {
    if (!compare_poly(t1.vec[k], t2.vec[k])) {
      return false;
    }
  }
  return true;
}


void convert_hex_to_uint8(const char* hex_str, uint8_t* seedbuf) {
    static const char hexmap[128] = {
        ['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3,
        ['4'] = 4, ['5'] = 5, ['6'] = 6, ['7'] = 7,
        ['8'] = 8, ['9'] = 9, ['a'] = 10, ['b'] = 11,
        ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15,
        ['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13,
        ['E'] = 14, ['F'] = 15,
    };

    for (size_t i = 0; i < 64 - 1; i += 2) {
        int high = hexmap[(unsigned char)hex_str[i]];
        int low = hexmap[(unsigned char)hex_str[i + 1]];

        if (high == -1 || low == -1) {
            printf("Invalid character in the hexadecimal string!\n");
            return;
        }

        seedbuf[i / 2] = (uint8_t)((high << 4) | low);
    }
}

int main(void)
{
  size_t i, j;
  int ret;
  size_t mlen, smlen;
  uint8_t b;
  uint8_t m[MLEN] = {146, 171, 195, 50, 136, 226, 84, 161, 149, 187, 90, 205, 87, 51, 10, 227, 45, 134, 218, 108, 102, 192, 116, 15, 63, 132, 103, 133, 173, 142, 136, 21};
  uint8_t SEED[SEEDBYTES] = {0x3e,0x80,0x9e,0xc8,0xdd,0x0f,0xec,0x0d,0x91,0x1a,0x4e,0x3f,0xac,0x20,0xf7,0x0f,0xbb,0x12,0x8c,0x5d,0xe9,0x4d,0xc7,0x18,0x4c,0xa7,0x31,0x0a,0xe9,0x15,0x7a,0x98};
  //uint8_t m[MLEN];
  //uint8_t SEED[SEEDBYTES];
  uint8_t m2[MLEN];
  uint8_t sm[MLEN + CRYPTO_BYTES];
  uint8_t pk[CRYPTO_PUBLICKEYBYTES];
  uint8_t sk[CRYPTO_SECRETKEYBYTES];
  uint8_t c[SEEDBYTES];
  uint8_t rho[SEEDBYTES];
  //uint8_t rhop[SEEDBYTES];
  uint8_t tr[SEEDBYTES];
  uint8_t key[SEEDBYTES];
  polyveck t1,h,t0,s2;
  polyvecl z,z2,s1,y;
  poly cp;
  //randombytes(m,MLEN);
  //randombytes(SEED,SEEDBYTES);


  for(i = 0; i < NTESTS; ++i) {
    crypto_sign_keypair(pk, sk, SEED);
    unpack_pk(rho, &t1, pk);
    unpack_sk(rho, tr, key, &t0, &s1, &s2, sk);

    //for(size_t a = 0; a < 32; ++a) {
    //  if(rho[a] != rhop[a]){
    //    printf("Warning!");
    //    printf("\n");
    //    break;
    //  }
    //}

    //print_polyveck(t1);
    
    //printf("Secret Key: ");
    //for(size_t k = 0; k < CRYPTO_SECRETKEYBYTES; ++k) {
    //  printf("%02x", sk[k]);
    //}
    //printf("\n");

    crypto_sign(sm, &smlen, m, MLEN, sk);
    unpack_sig(c, &z, &h, sm);
    
    //printf("c: ");
    //for(size_t k = 0; k < 32; ++k) {
    //  printf("%02x", c[k]);
    //}
    //printf("\n");
    //printf("%ld:",i);
    //printf("\n");
    //print_polyvecl(s1);
    



    polyvecl_ntt(&s1);
    //print_polyvecl(s1);

    //polyvecl_invntt_tomont(&s1);
    //print_polyvecl(s1);



    poly_challenge(&cp,c);
    //print_poly(cp);
    poly_ntt(&cp);
    polyvecl_pointwise_poly_montgomery(&z2, &cp, &s1);


    polyvecl_invntt_tomont(&z2);
    const polyvecl* y_ptr = get_intermediate_vector();
    memcpy(&y, y_ptr, sizeof(polyvecl));
    //print_polyvecl(y);
    polyvecl_add(&z2, &z2, &y);
    polyvecl_reduce(&z2);

    ret = crypto_sign_open(m2, &mlen, sm, smlen, pk);

    if(ret) {
      fprintf(stderr, "Verification failed\n");
      return -1;
    }
    if(smlen != MLEN + CRYPTO_BYTES) {
      fprintf(stderr, "Signed message lengths wrong\n");
      return -1;
    }
    if(mlen != MLEN) {
      fprintf(stderr, "Message lengths wrong\n");
      return -1;
    }
    for(j = 0; j < MLEN; ++j) {
      if(m2[j] != m[j]) {
        fprintf(stderr, "Messages don't match\n");
        return -1;
      }
    }

    randombytes((uint8_t *)&j, sizeof(j));
    do {
      randombytes(&b, 1);
    } while(!b);
    sm[j % (MLEN + CRYPTO_BYTES)] += b;
    ret = crypto_sign_open(m2, &mlen, sm, smlen, pk);
    if(!ret) {
      fprintf(stderr, "Trivial forgeries possible\n");
      return -1;
    }
    //printf("%d\n",CRYPTO_PUBLICKEYBYTES);
  }

  //printf("CRYPTO_PUBLICKEYBYTES = %d\n", CRYPTO_PUBLICKEYBYTES);
  //printf("CRYPTO_SECRETKEYBYTES = %d\n", CRYPTO_SECRETKEYBYTES);
  //printf("CRYPTO_BYTES = %d\n", CRYPTO_BYTES);

  return 0;
}
