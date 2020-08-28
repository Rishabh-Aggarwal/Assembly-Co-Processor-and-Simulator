#include<bits/stdc++.h>
//#include "phase1.h"
#include "code_conv.h"
#include "make_map.h"
#include "conv_binary.h"
#include "machine_conv.h"
#include "memoryclass.h"
using namespace std;
#define maxbitset 32
machinecode:: machinecode()							//intialising function variables
{
	rs1='\0';
	rs2='\0';
	rd='\0';
	imm=0;
}

string machinecode:: discard_zeroes(int cnt){
	bitset<maxbitset> objbit(cnt);
	string sobjbit = objbit.to_string();
	int j=0;
	for(j=0;j<sobjbit.length();j=j+4)
	{
		string tmp = sobjbit.substr(j,4);
		if (tmp.compare("0000"))
			break;
	}
	string sobjbit_1;
	if(j==sobjbit.length())
		sobjbit_1="0000";
	else
		sobjbit_1 =sobjbit.substr(j,sobjbit.length()-j);
	return sobjbit_1;
}

void machinecode:: conv_to_mac_code(make_map obj, conv_binary obj2)
{
    ifstream basic_codefp("basic_code.txt",ios::in);	
	string ins_name;
	ofstream machine_codefp("machine_code.txt",ios::out);  //write
	if(!basic_codefp)
		cout<<"basic_code.txt not readed"<<endl;
	else
	{
		int countpc=0;
		while(basic_codefp>>ins_name)
		{
			//cout<<"*"<<endl;
				if(obj.mtype.count(ins_name)==0)
				{	
					basic_codefp>>ins_name;
				}
				//cout<<"ins_name"<<ins_name<<endl;
				string rs1,rs2,rd;
				int imm;
				string type;
				if(obj.mtype.count(ins_name)==0)
					type="A";
				else
					type = obj.mtype.find(ins_name)->second;
				//cout<<type<<endl;
				if(type=="R")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rd>>rs1>>rs2;
					machine_codefp<<obj2.funcR(ins_name,rd,rs1,rs2)<<endl;
				}
				else if(type=="I")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rd>>rs1>>imm;
					machine_codefp<<obj2.funcI(ins_name,rd,rs1,imm)<<endl;
				}
				else if(type=="S")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rs2>>rs1>>imm;
					machine_codefp<<obj2.funcS(ins_name,rs2,rs1,imm)<<endl;
				}
				else if(type=="SB")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rs1>>rs2>>imm;
					machine_codefp<<obj2.funcSB(ins_name,rs1,rs2,imm)<<endl;
				}
				else if(type=="U")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rd>>imm;
					machine_codefp<<obj2.funcU(ins_name,rd,imm)<<endl;
				}
				else if(type=="UJ")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rd>>imm;
					machine_codefp<<obj2.funcUJ(ins_name,rd,imm)<<endl;
				}
				else if(type=="P")
				{
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>rd>>imm;
					machine_codefp<<obj2.funcP(ins_name,rd,imm)<<endl;
				}
				else if(type=="exit")
				{
					string readexit;
					string sobjbit_1=discard_zeroes(countpc*4);
					machine_codefp<<obj2.bin_to_hex(sobjbit_1)<<" ";
					countpc++;
					basic_codefp>>readexit;
					machine_codefp<<"0xEF000011";
				}
			
		}
	}
	basic_codefp.close();
	machine_codefp.close();
}

machinecode::~machinecode(){}
