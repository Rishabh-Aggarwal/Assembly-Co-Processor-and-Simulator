#ifndef ORIGINAL_TO_BASIC_H
#define ORIGINAL_TO_BASIC_H

#include "code_conv.h"
#include "make_map.h"
#include "conv_binary.h"
#include "machine_conv.h"
#include "memoryclass.h"
#include <bits/stdc++.h>
using namespace std;

class original:public make_map
{
	map < string ,int > mlabel ;
public:
	original();
	void compatible_original();
	void calc_label(make_map,conv_binary);
	~original();

};
#endif
