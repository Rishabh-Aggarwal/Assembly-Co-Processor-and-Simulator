#include<bits/stdc++.h>
//#include "phase1.h"
#include "code_conv.h"
#include "make_map.h"
#include "conv_binary.h"
#include "machine_conv.h"
#include "memoryclass.h"
using namespace std;


make_map:: make_map(){}

map<string,string> make_map :: mtype;
map<string,string> make_map :: mopcode;
map<string,string> make_map :: mfunc3;
map<string,string> make_map :: mfunc7;



void make_map:: create_map()
{
	/*for R type*/
	ifstream Rfp("R_instructions.txt",ios::in);
	string ins_name,func7,func3,opcode,type;
	int imm;
	if(!Rfp)
		cout<<"R instructions not read"<<endl;
	else
	{
		while(Rfp>>ins_name>>opcode>>func3>>func7)
		{
			type="R";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
			make_map::mfunc7.insert( pair<string,string>(ins_name,func7) );
			make_map::mfunc3.insert( pair<string,string>(ins_name,func3) );
		}
	}
	Rfp.close();

	/*for I type*/
	ifstream Ifp("I_instructions.txt",ios::in);
	if(!Ifp)
		cout<<"I instructions not read"<<endl;
	else
	{
		while(Ifp>>ins_name>>opcode>>func3)
		{
			type="I";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
			make_map::mfunc3.insert( pair<string,string>(ins_name,func3) );
		}
	}
	Ifp.close();

	/*for S type*/
	ifstream Sfp("S_instructions.txt",ios::in);
	if(!Sfp)
		cout<<"S instructions not read"<<endl;
	else
	{
		while(Sfp>>ins_name>>opcode>>func3)
		{
			type="S";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
			make_map::mfunc3.insert( pair<string,string>(ins_name,func3) );
		}
	}
	Sfp.close();

	/*for SB type*/
	ifstream SBfp("SB_instructions.txt",ios::in);
	if(!SBfp)
		cout<<"SB instructions not read"<<endl;
	else
	{
		while(SBfp>>ins_name>>opcode>>func3)
		{
			type="SB";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
			make_map::mfunc3.insert( pair<string,string>(ins_name,func3) );
		}
	}
	SBfp.close();

	/*for U type*/
	ifstream Ufp("U_instructions.txt",ios::in);
	if(!Ufp)
		cout<<"U instructions not read"<<endl;
	else
	{
		while(Ufp>>ins_name>>opcode)
		{
			type="U";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
		}
	}
	Ufp.close();

	/*for UJ type*/
	ifstream UJfp("UJ_instructions.txt",ios::in);
	if(!UJfp)
		cout<<"UJ instructions not read"<<endl;
	else
	{
		while(UJfp>>ins_name>>opcode)
		{
			type="UJ";
			make_map::mtype.insert( pair<string,string>(ins_name,type) );
			make_map::mopcode.insert( pair<string,string>(ins_name,opcode) );
		}
	}
	UJfp.close();

	/*for P type    To handle pseudo instruction "la"   */
	make_map::mtype.insert( pair<string,string>("la","P") );
	make_map::mopcode.insert( pair<string,string>("la","0000000") );
	
	//as last instruction of machine code
	make_map::mtype.insert( pair<string,string>("swi","exit") ); // 0xEF000011  <=  swi 0x11
	
}

make_map:: ~make_map(){}