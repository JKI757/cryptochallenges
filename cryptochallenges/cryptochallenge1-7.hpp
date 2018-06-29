//
//  cryptochallenge1-7.hpp
//  crypto_challenge
//
//  Created by Joshua on 6/17/18.
//  Copyright © 2018 josh. All rights reserved.
//

#ifndef cryptochallenge1_7_hpp
#define cryptochallenge1_7_hpp

#include <cstdio>
#include <string>
#include <iostream>
#include <bitset>


std::string pack(std::string in);
std::string unpack(std::string in);

//challenge 1
const std::string base64IndexTable="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

char ctohex(char c);
char hextoc(char c);
char sixfourtoint(char c);
void printByte(char c);
int byteToInt(char c);
char hiByte(char c);
char loByte(char c);

std::string encodeBase64(std::string in);
std::string decodeBase64(std::string in);


//challenge 2
char bitXor(char c1, char c2);
std::string hexXor(std::string in1, std::string in2);


// challenge 3

std::string extendString(char in, int length);

int englishText(std::string s);



//challenge 4
std::string singleXorTest(std::string in);


#endif /* cryptochallenge1_7_hpp */
