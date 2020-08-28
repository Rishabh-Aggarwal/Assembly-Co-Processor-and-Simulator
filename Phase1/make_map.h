#ifndef MAKE_MAP_H
#define MAKE_MAP_H

#include<bits/stdc++.h>
using namespace std;

class make_map
{
	
	public:
		static map<string,string> mtype; //for determining format(R,S,I,SB,U,UJ)
		static map<string,string> mopcode;
		static map<string,string> mfunc3;
		static map<string,string> mfunc7;
		make_map();
		void create_map();
		
		~make_map();
};

#endif
