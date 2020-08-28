

#include<bits/stdc++.h>
#include "phase1.h"
// #include "code_conv.h"
// #include "make_map.h"
// #include "conv_binary.h"
// #include "machine_conv.h"
// #include "memoryclass.h"
using namespace std;

void phase1::phase_1()
{
	//control_phase1 = control_phase;
	make_map objmakemap;
	conv_binary objconvbinary;
	machinecode objmachinecode;
	original objoriginal;
	objmakemap.create_map();
	objoriginal.compatible_original();
	objoriginal.calc_label(objmakemap,objconvbinary);
	objmachinecode.conv_to_mac_code(objmakemap,objconvbinary);
	//stalls = objoriginal.STALLS();
}
int main()
{
	phase1 objphase;
	objphase.phase_1();
	return 0;
}

// int phase1:: Stalls()
// {
// 	return stalls;
// }