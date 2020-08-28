 #include<bits/stdc++.h>
// #include "machine_conv.h"
//#include "make_map.h"
using namespace std;


// make_map:: make_map(){}


// string make_map:: bin_to_hex(string strBin)              //copied from stack overflow
// {
// 	string rest("0x");
// 	cout<<rest<<endl;
// 	string temp;
// 	int len = strBin.length()/4;
// 	for (int i=0;i<strBin.length();i+=4)
// 	{
// 		tmp = strBin.substr(i,4);
// 		if (!tmp.compare("0000")){rest = rest + "0";}
// 		else if (!tmp.compare("0001")){rest = rest + "1";}
// 		else if (!tmp.compare("0010")){rest = rest + "2";}
// 		else if (!tmp.compare("0011")){rest = rest + "3";}
// 		else if (!tmp.compare("0100")){rest = rest + "4";}
// 		else if (!tmp.compare("0101")){rest = rest + "5";}
// 		else if (!tmp.compare("0110")){rest = rest + "6";}
// 		else if (!tmp.compare("0111")){rest = rest + "7";}
// 		else if (!tmp.compare("1000")){rest = rest + "8";}
// 		else if (!tmp.compare("1001")){rest = rest + "9";}
// 		else if (!tmp.compare("1010")){rest = rest + "A";}
// 		else if (!tmp.compare("1011")){rest = rest + "B";}
// 		else if (!tmp.compare("1100")){rest = rest + "C";}
// 		else if (!tmp.compare("1101")){rest = rest + "D";}
// 		else if (!tmp.compare("1110")){rest = rest + "E";}
// 		else if (!tmp.compare("1111")){rest = rest + "F";}
// 		else{continue;}
// 	}
// 	return rest;
// }
string conv(string reg)
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
int main()
{
	//make_map abj;
	cout<<conv("x13")<<endl;
}