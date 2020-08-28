#include<bits/stdc++.h>
//#include "phase1.h"
#include "code_conv.h"
#include "make_map.h"
#include "conv_binary.h"
#include "machine_conv.h"
#include "memoryclass.h"
using namespace std;

conv_binary :: conv_binary(){}

conv_binary :: ~conv_binary(){}

string conv_binary:: bin_to_hex(string strBin) //copied from stack overflow
{
	string rest("0x");
	string tmp;
	//int len = strBin.length()/4;
	for (int i=0;i<strBin.length();i+=4)
	{
		tmp = strBin.substr(i,4);
		if (!tmp.compare("0000")){rest = rest + "0";}
		else if (!tmp.compare("0001")){rest = rest + "1";}
		else if (!tmp.compare("0010")){rest = rest + "2";}
		else if (!tmp.compare("0011")){rest = rest + "3";}
		else if (!tmp.compare("0100")){rest = rest + "4";}
		else if (!tmp.compare("0101")){rest = rest + "5";}
		else if (!tmp.compare("0110")){rest = rest + "6";}
		else if (!tmp.compare("0111")){rest = rest + "7";}
		else if (!tmp.compare("1000")){rest = rest + "8";}
		else if (!tmp.compare("1001")){rest = rest + "9";}
		else if (!tmp.compare("1010")){rest = rest + "A";}
		else if (!tmp.compare("1011")){rest = rest + "B";}
		else if (!tmp.compare("1100")){rest = rest + "C";}
		else if (!tmp.compare("1101")){rest = rest + "D";}
		else if (!tmp.compare("1110")){rest = rest + "E";}
		else if (!tmp.compare("1111")){rest = rest + "F";}
		else{continue;}
	}
	return rest;
}


string conv_binary::reg_to_binary(string reg)
{
	int num;
	int length = reg.length();
	if(length==2)
	{
		num = int(reg[1])-48;
	}
	else if(length==3 && (int)reg[1]>48)
	{
		num= (int)reg[1]-48;
		num = num*10 + (int)reg[2]-48;
		
	}
	bitset<5> res(num);
	return res.to_string();
}

/*for R type*/
string conv_binary:: funcR(string ins_name, string rd,string rs1,string rs2)
{
	
	
	string func7 = (make_map::mfunc7).find(ins_name)->second;
	string result = func7;
	string s2 = reg_to_binary(rs2);
	result.append(s2);
	string s1 = reg_to_binary(rs1);
	result.append(s1);
	string func3 = make_map::mfunc3.find(ins_name)->second;
	result.append(func3);
	string des = reg_to_binary(rd);
	result.append(des);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);
	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*for I type*/
string conv_binary:: funcI(string ins_name,string rd,string rs1,int imm)
{
	
	
	
	
	bitset<12> res(imm);
	string imm1 = res.to_string();
	string result = imm1;
	string s1 = reg_to_binary(rs1);
	result.append(s1);
	string func3 = make_map::mfunc3.find(ins_name)->second;
	result.append(func3);
	string des = reg_to_binary(rd);
	result.append(des);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);

	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*S type*/
string conv_binary:: funcS(string ins_name,string rs2,string rs1,int imm)
{
	
	bitset<12> out(imm);
	string immg1 = out.to_string();
	string leftimmg=immg1.substr(0, 7);// 0 to 6
	string rightimmg=immg1.substr(7, 5);//7 to 11
	string result = leftimmg;
	string s2 = reg_to_binary(rs2);
	result.append(s2);
	string s1 = reg_to_binary(rs1);
	result.append(s1);
	string func3 = make_map::mfunc3.find(ins_name)->second;
	result.append(func3);
	result.append(rightimmg);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);
	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*for SB type*/
string conv_binary:: funcSB(string ins_name,string rs1,string rs2,int imm)
{
	
	
	
	
	//to make imm of 13 bit and discard LSB of imm
	bitset<13> res(imm);
	string immg = res.to_string();
	string leftimm1=immg.substr(0, 1);
	string leftimm2=immg.substr(2, 6);
	string result = leftimm1;
	result.append(leftimm2);
	string s2 = reg_to_binary(rs2);
	result.append(s2);
	string s1 = reg_to_binary(rs1);
	result.append(s1);
	string func3 = make_map::mfunc3.find(ins_name)->second;
	result.append(func3);
	string rightimm1=immg.substr(8, 4);
	string rightimm2=immg.substr(1, 1);//8 to 11 and 1 =>4:1|11
	result.append(rightimm1);
	result.append(rightimm2);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);
	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*for U type*/
string conv_binary:: funcU(string ins_name,string rd,int imm)
{
	
	bitset<20> res(imm);
	string imm1 = res.to_string();
	string result = imm1;
	string des = reg_to_binary(rd);
	result.append(des);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);
	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*for UJ type*/
string conv_binary:: funcUJ(string ins_name,string rd,int imm)
{
	
	string opcode = make_map::mopcode.find(ins_name)->second;
	string des = reg_to_binary(rd);
	//to make imm of 21 bit and discard LSB of imm
	bitset<21> res(imm);
	string imm1 = res.to_string();
	string first=imm1.substr(0, 1),second=imm1.substr(10, 10);// 0 and 10 to 19 =>20|10:1
	string third=imm1.substr(9, 1),fourth=imm1.substr(1, 8);// 9 and 1 to 8 =>11|19:12
	string result = first;
	result.append(second);
	result.append(third);
	result.append(fourth);
	result.append(des);
	result.append(opcode);
	result = bin_to_hex(result);
	//cout<<result<<endl;
	return result;
}

/*for P type    To handle pseudo instruction "la"   */
string conv_binary:: funcP(string ins_name,string rd,int imm)
{
	
	
	bitset<20> res(imm);
	string imm1 = res.to_string();
	string result = imm1;
	string des = reg_to_binary(rd);
	result.append(des);
	string opcode = make_map::mopcode.find(ins_name)->second;
	result.append(opcode);
	result = bin_to_hex(result);
	return result;
}