
////////////////////////////////////////////////////////////////////////////////

// COMPANY:		COSIC, KU Leuven 
// AUTHOR:		Victor Arribas

////////////////////////////////////////////////////////////////////////////////

// BSD 3-Clause License

// Copyright (c) 2019, Victor Arribas
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

////////////////////////////////////////////////////////////////////////////////

#include "conversions.h"

bool charToBool(char s)
{
	return s == '0' ? 0:1;
};


uint64_t binToDec(std::string bin_num){
	
	uint64_t dec_number = 0;

	for (size_t i = 0; i < bin_num.size(); ++i)
	{
		if (bin_num[i] == '1')
		{
			dec_number += (uint64_t)pow(2.0, (double)(bin_num.size()-1-i));
		}
	}

	return dec_number;
};


std::string decToBin(size_t dec, size_t size){
  
  std::string r = "";
  size_t siz = 0;
  
  do {
    r=(dec%2==0 ?"0":"1")+r; 
    dec/=2;
  }while (dec != 0);
  
  siz = r.size();
  //Apped zeros in the left till reaching the required size
  while(siz != size){
    r="0"+r;
    ++siz;
  }
  
  return r;
};


std::string hex_to_bin(std::string hexNum){
	
	std::string binNum = "";

	for (size_t i = 0; i < hexNum.size(); ++i)
	{
		if (hexNum[i] == '0') binNum += "0000";
		else if (hexNum[i] == '1') binNum += "0001";
		else if (hexNum[i] == '2') binNum += "0010";
		else if (hexNum[i] == '3') binNum += "0011";
		else if (hexNum[i] == '4') binNum += "0100";
		else if (hexNum[i] == '5') binNum += "0101";
		else if (hexNum[i] == '6') binNum += "0110";
		else if (hexNum[i] == '7') binNum += "0111";
		else if (hexNum[i] == '8') binNum += "1000";
		else if (hexNum[i] == '9') binNum += "1001";
		else if ((hexNum[i] == 'A') or (hexNum[i] == 'a')) binNum += "1010";
		else if ((hexNum[i] == 'B') or (hexNum[i] == 'b')) binNum += "1011";
		else if ((hexNum[i] == 'C') or (hexNum[i] == 'c')) binNum += "1100";
		else if ((hexNum[i] == 'D') or (hexNum[i] == 'd')) binNum += "1101";
		else if ((hexNum[i] == 'E') or (hexNum[i] == 'e')) binNum += "1110";
		else if ((hexNum[i] == 'F') or (hexNum[i] == 'f')) binNum += "1111";
	}

	return binNum;
};


std::string bin_to_hex(std::string binNum){

	std::string hexNum = "";
	std::string binString = binNum;

	while ((binString.size() % 4) != 0){
		binString = '0' + binString;
	}

	for (size_t i = 0; i < binString.size()/4; ++i)
	{
		std::string bits = "";

		for (int j = 0; j < 4; ++j)
		{
			bits += binString[4*i+j];
		}

		if (bits == "0000") hexNum += '0';
		else if (bits == "0001") hexNum += '1';
		else if (bits == "0010") hexNum += '2';
		else if (bits == "0011") hexNum += '3';
		else if (bits == "0100") hexNum += '4';
		else if (bits == "0101") hexNum += '5';
		else if (bits == "0110") hexNum += '6';
		else if (bits == "0111") hexNum += '7';
		else if (bits == "1000") hexNum += '8';
		else if (bits == "1001") hexNum += '9';
		else if (bits == "1010") hexNum += 'A';
		else if (bits == "1011") hexNum += 'B';
		else if (bits == "1100") hexNum += 'C';
		else if (bits == "1101") hexNum += 'D';
		else if (bits == "1110") hexNum += 'E';
		else if (bits == "1111") hexNum += 'F';
	}

	return hexNum;

}