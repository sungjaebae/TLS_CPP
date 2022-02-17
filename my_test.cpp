#include<iostream>
#include"src/mpz.h"
#include"src/diffie.h"
#include"src/rsa.h"
#include"src/aes.h"
#include"src/naes.h"
#include"src/sha1.h"
#include"src/hmac.h"
#include"src/prf.h"
#include <boost/ut.hpp>
#include <algorithm>
using namespace boost::ut;
using namespace::boost::ut::spec;
suite Chapter1=[]{
  describe("mpz")=[]{
    uint8_t arr[8];
	mpz_class a{"0x1234567890abcdef"};
	mpz2bnd(a, arr, arr + 8);
	// expect(std::equal(arr,arr+sizeof(uint8_t)*8, a));
  mpz_class b = bnd2mpz(arr, arr + 8);
  std::cout<<std::hex<<a<<std::endl; //1234567890abcdef 출력
  std::cout<<b<<std::endl; //1234567890abcdef 출력
  it("should equal") =[a,b]{
    expect(a==b);
    };
  };
  describe("diffie hellman")=[]{
    DiffieHellman Alice, Bob;
    Alice.set_peer_pubkey(Bob.y);
    Bob.set_peer_pubkey(Alice.y);
    it("should equal")=[Alice, Bob]{
      expect(Alice.K==Bob.K);
    };
  };

};

int main() {
}