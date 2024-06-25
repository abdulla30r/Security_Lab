#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int main(){
    mpz_t p,q,n,p_1,q_1,phi,e,d,m,c,dm,tmp;
    mpz_inits(p,q,n,p_1,q_1,phi,e,d,m,c,dm,tmp,NULL);

    mpz_set_str(p, "656692050181897513638241554199181923922955921760928836766304161790553989228223793461834703506872747071705167995972707253940099469869516422893633357693", 10);
    mpz_set_str(q, "204616454475328391399619135615615385636808455963116802820729927402260635621645177248364272093977747839601125961863785073671961509749189348777945177811", 10);

    mpz_sub_ui(p_1,p,1);
    mpz_sub_ui(q_1,q,1);

    mpz_mul(phi,p_1,q_1);
    mpz_mul(n,p,q);

    mpz_set_str(e,"18532395500947174450709383384936679868383424444311405679463280782405796233163977",10);
    mpz_gcd(tmp,e,phi);

    while(mpz_cmp_ui(tmp,1)!=0){
        mpz_nextprime(e,e);
        mpz_gcd(tmp,e,phi);
    }

    mpz_invert(d,e,phi);

    gmp_printf("Private Key: %Zd \nPublic Key: %Zd\n",d,e);

    mpz_set_str(m,"123",10);
    
    mpz_powm(c,m,e,n);
    mpz_powm(dm,c,d,n);

    gmp_printf("\nCiphered: %Zd \nPlain: %Zd\n",c,dm);

}