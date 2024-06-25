#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int main(){
    mpz_t p,g,r,d,x,m,c1,c2,dm,tmp;
    mpz_inits(p,g,r,d,x,m,c1,c2,dm,tmp,NULL);

    mpz_set_str(p, "656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693", 10);
    mpz_set_str(g,"3",10);  //primitive
    mpz_set_str(r,"765",10);  //random
    mpz_set_str(m,"123",10);  //message

    mpz_set_str(x,"123456789012345678901234567890",10); //private key
    mpz_powm(d,g,x,p);      // d-> public key

    gmp_printf("Private key: %Zd \nPublic Key: %Zd \n",x,d);

    //encryption
    mpz_powm(c1,g,r,p);

    mpz_powm(c2,d,r,p);
    mpz_mod(tmp,m,p);
    mpz_mul(tmp,c2,tmp);
    mpz_mod(c2,tmp,p);

    gmp_printf("\nCiphered(c1): %Zd\nCiphered(c2): %Zd\n",c1,c2);

    //decryption
    mpz_neg(x,x);
    mpz_powm(tmp,c1,x,p);
    mpz_mod(dm,c2,p);
    mpz_mul(dm,dm,tmp);
    mpz_mod(dm,dm,p);

    gmp_printf("\nPlain : %Zd",dm);
}