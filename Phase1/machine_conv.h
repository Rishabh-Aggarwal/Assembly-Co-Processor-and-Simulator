#ifndef MACHINE_CONV_H
#define MACHINE_CONV_H

#include<bits/stdc++.h>
#include "make_map.h"
#include "code_conv.h"
#include "conv_binary.h"
using namespace std;

class machinecode : public make_map
{
	string rs1,rs2,rd;
	int imm;
    
	public:
		machinecode();
		void conv_to_mac_code(make_map , conv_binary);
		string discard_zeroes(int);
		~machinecode();
};
#endif
