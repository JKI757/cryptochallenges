//
//  cryptochallenge1-7.cpp
//  crypto_challenge
//
//  Created by Joshua on 6/17/18.
//  Copyright © 2018 josh. All rights reserved.
//

#include "cryptochallenge1-7.hpp"

std::string pack(std::string in){//pack the hex character input into a string of bytes.
    std::string tempString="";
    for (int i=0; i<in.length(); i=i+2){
        tempString+=(ctohex(in[i])<<4) | (ctohex(in[i+1]));
    }
    return tempString;
}
int byteToInt(char c){
    return((int)std::bitset<8>(c).to_ulong());
}

void printByte(char c){
    std::cout << std::bitset<8>(c) << std::endl ;
}
char ctohex(char c){
    if ((c>='0' & c<='9'))
        return (c&0xf);
    else if (c>='a' &  c<='f')
        return(c-0x57);
    else if (c>='A' &  c<='F')
        return(c-0x37);
    else
        return (0xff);
}

char hextoc(char c){
    if ((c>=0x0 & c<=0x9))
        return (c+0x30);
    else if (c>=0xa &  c<=0xf)
        return(c+(0x41-0xa));
    else
        return (0xff);
}

char sixfourtoint(char c){
    //returns an index into the base64 character array
    if ((c>='0' & c<='9'))
        return (c+0x4); //need to return an index of 53 for character '0', counting up to '9'
    else if (c>='a' &  c<='z')
        return(c-0x47);
    else if (c>='A' &  c<='Z')
        return(c-0x41);
    else if (c == '+')
        return (0x3f);
    else if (c == '/')
        return (0x40);
    else
        return (0xff);
}

char hiByte(char c){
    return((c>>4));
}
char loByte(char c){
    return (c&0xf);
}


std::string encodeBase64(std::string in){
    
    std::string inBytes = "";
    std::string outBytes="";
    
    int i=0;
    std::string localConvertedString="";
    
    
    while (i<in.size()){
        inBytes=in.substr(i,i+3);
        
        outBytes[0] = (inBytes[0]>>2); //store top 6 bits of the first input byte
        //first base64 byte complete
        
        outBytes[1]=((inBytes[0]&0x03)<<4) | (inBytes[1]>>4);  //get bottom two bits of byte 1 & top 4 bits of byte 2
        //second base64 byte complete
        
        outBytes[2]=((inBytes[1]&0x0f)<<2) | ((inBytes[2]&0xc0)>>6) ; //get bottom 4 bits of inbyte 2, clear top two empty bits
        //cout << byteToInt(outBytes[2]) << endl;
        //third base64 byte complete
        
        outBytes[3]= inBytes[2]&0x3f;//clear top two bits
        //fourth base64 byte complete
        
        for (int j=0; j<4; j++){
            localConvertedString+=base64IndexTable[byteToInt(outBytes[j])];
        }
        
        i=i+3;
    }
    
    return (localConvertedString);
}

std::string decodeBase64(std::string in){
    char k;
    std::string tempString1="";
    std::string tempString2="";
    
    
    for (int j=0; j<in.length();j=j+4){
        tempString1="";
        k = sixfourtoint(in[j]);
        tempString1+=k<<2;
        
        k = sixfourtoint(in[j+1]);
        tempString1[0] = tempString1[0]|(k>>4);
        tempString1+=k<<4;
        
        k = sixfourtoint(in[j+2]);
        tempString1[1]=tempString1[1]|(k>>2&0x0f);
        tempString1[2]+=k<<6;
        
        k = sixfourtoint(in[j+3]);
        tempString1[2]=tempString1[2]|(k&0x3f);
        
        //split up the bytes and put them into the return string
        tempString2+=hextoc((tempString1[0]&0xf0)>>4);
        tempString2+=hextoc(tempString1[0]&0x0f);
        tempString2+=hextoc((tempString1[1]&0xf0)>>4);
        tempString2+=hextoc(tempString1[1]&0x0f);
        tempString2+=hextoc((tempString1[2]&0xf0)>>4);
        tempString2+=hextoc(tempString1[2]&0x0f);
        
    }
    
    return (tempString2);
    
}




//challenge 2

std::string unpack(std::string in){
    std::string t1="";
    
    for (int i=0; i<in.length();i++){
        t1+=hextoc((in[i]&0xf0)>>4);
        t1+=hextoc(in[i]&0x0f);
    }
    return t1;
}
char bitXor(char c1, char c2){
    return (c1 ^ c2);
}
std::string hexXor(std::string in1, std::string in2){
    std::string t1;
    std::string t2;
    std::string t3="";
    
    t1 = pack(in1);
    t2 = pack (in2);
    
    for (int i=0; i<t1.length();i++){
        t3+=bitXor(t1[i], t2[i]);
    }
    return (unpack(t3));
}


std::string extendString(std::string in, int length){
    
    return (in);
}


