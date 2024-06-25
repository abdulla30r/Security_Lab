#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int main()
{
    mpz_t p,q,lamda,n,p_1,q_1,g,n_n;
    mpz_inits(p,q,lamda,p_1,q_1,n,g,n_n,NULL);

    mpz_set_str(p, "13", 10);
    mpz_set_str(q, "17", 10);

    mpz_mul(n,p,q);
    mpz_mul(n_n,n,n);
    mpz_sub_ui(p_1,p,1);
    mpz_sub_ui(q_1,q,1);

    mpz_lcm(lamda,p_1,q_1);

    mpz_set_str(g,"4886",10);

    gmp_printf("lamda: %Zd \npublic: %Zd , %Zd\n", lamda, n,g);

    mpz_t c,m,dm,meu,r,g_m,r_m;
    mpz_inits(c,m,dm,meu,r,g_m,r_m,NULL);

    mpz_set_str(m,"123",10);
    mpz_set_str(r,"666",10);

    mpz_powm(g_m,g,m,n_n);
    mpz_powm(r_m,r,n,n_n);

    mpz_mul(c,g_m,r_m);
    mpz_mod(c,c,n_n);

    gmp_printf("m is %Zd \ncipher is %Zd \n", m, c);

    //meu = L(g_lamda mod n_2) modulu inverse n

    mpz_t g_lamda,c_lamda,L;
    mpz_inits(g_lamda,c_lamda,L,NULL);

    mpz_powm(g_lamda, g, lamda,n_n);
    mpz_sub_ui(g_lamda,g_lamda,1);
    mpz_div(g_lamda,g_lamda,n);
    mpz_invert(meu,g_lamda,n);

    // dm = L(c_lamda mod n_n) * meu mod n
    mpz_powm(c_lamda, c, lamda,n_n);
    mpz_sub_ui(c_lamda,c_lamda,1);
    mpz_div(c_lamda,c_lamda,n);

    mpz_mul(dm,c_lamda,meu);
    mpz_mod(dm,dm,n);
    gmp_printf("\nDeciphered message %Zd: ",dm);
}