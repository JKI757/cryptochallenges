//
//  main.cpp
//  crypto_challenge
//
//  Created by josh on 5/3/13.
//  Copyright (c) 2013 josh. All rights reserved.
//

#include <iostream>
#include <cstddef>

#include "cryptochallenge1-7.hpp"

using namespace std;

int main(int argc, const char * argv[])
{

    const string RESULT = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    
    const string INPUT ="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
//challenge 1
    cout << "Challenge 1" << endl;
    cout << encodeBase64(pack(INPUT)) << endl;
    
    cout << decodeBase64(RESULT) << endl;
  
    cout << "End Challenge 1" << endl << endl;
//challenge 2
    cout << "Start Challenge 2" << endl;
    const string c2INPUT="1c0111001f010100061a024b53535009181c";
    const string c2RESULT="746865206b696420646f6e277420706c6179";
    const string c2KEY="686974207468652062756c6c277320657965";
    
    cout << hexXor(c2INPUT, c2KEY) << endl;
    cout << "End Challenge 2"<< endl;
    
    cout << "Start Challenge 3"<<endl;
    
    const string c3INPUT = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    
    for (int i=0; i < c3INPUT.length(); i++){
        
    }
    return 0;
}

