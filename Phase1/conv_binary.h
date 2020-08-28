#ifndef CONV_BINARY_H
#define CONV_BINARY_H

#include<bits/stdc++.h>
using namespace std;

class conv_binary
{
	public:
		conv_binary();
		string bin_to_hex(string sBinary);
		string reg_to_binary(string s);
		string funcR(string ins_name, string rd,string rs1,string rs2);
		string funcI(string ins_name,string rd,string rs1,int imm);
		string funcS(string ins_name,string rs2,string rs1,int imm);
		string funcSB(string ins_name,string rs1,string rs2,int imm);
		string funcU(string ins_name,string rd,int imm);
		string funcUJ(string ins_name,string rd,int imm);
		string funcP(string ins_name,string rd,int imm);
		~conv_binary();
};
#endif