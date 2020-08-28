#include<bits/stdc++.h>
#include "original_to_basic.h"
#include "make_map.h"
#include "machine_conv.h"
#include "memoryclass.h"
using namespace std;

original::original(){}

void original:: compatible_original(make_map obj)
{
	string line,str;
   	char imm[1000];
   	int i=0,j=0,l=0,k=0,temp;
   	ifstream fpr("original.txt",ios::in);
   	ofstream fpw("compatible_original.txt",ios::out);
    while ( getline (fpr,line) )
    {
    	temp=0;
        char line2[1000];
        while(i<line.length()){
            if(line[i]==',')
            {
                line2[i]=' ';
                i++;
                k=0;
            }
            else if(line[i]=='#')
                break;
            else if(line[i]==' ')
            {
                k=0;
                line2[i]=' ';
                i++;
            }
            else if(line[i]=='(')
            {
                temp=1;
                j=i-k;
                i++;
                while(line[i]!=')'){
                        line2[j]=line[i];
                        j++;
                        i++;
                }    
                line2[j]=' ';
                j++;
                l=0;
                while(l<k)
                {
                    line2[j]=imm[l];
                    l++;
                    j++;
                }
                break;
            }
            else
            {
                imm[k]=line[i];
                line2[i]=line[i];
                i++; 
                k++;
            }
            temp=0;
        }
        l=0;
        if(temp==0)
            j=i;
        while(l<j){
            fpw<<line2[l];
            l++;
        }
        fpw<<endl;
        l=0;k=0;i=0;
    }
  	fpr.close();
   	fpw.close();



   	ifstream file("compatible_original.txt",ios::in);
    if(!file)
        cout<<"compatible_original not readed"<<endl;
    ofstream file2("original_code.txt",ios::out);
    string line_;
    while( getline(file, line_) )
    {
        stringstream  line ;
        line<<line_;
        string str;
        while( line>>str )
        {
            if(str!="lw"&&str!="lb"&&str!="li")
            {
                file2<<str<<" ";
            }
            else if(str=="lw"||str=="lb")
            {
                string sstr1,sstr2,sstr3;
                line>>sstr1>>sstr2;
                if( line>>sstr3 )
                {
                    file2<<str<<" "<<sstr1<<" "<<sstr2<<" "<<sstr3;
                    break;
                }
                else
                {
                    file2<<"la "<<sstr1<<" "<<sstr2<<endl;
                    file2<<str<<" "<<sstr1<<" "<<sstr1<<" 0";
                    break;
                }
            }
            else
            {
                string sstr1,sstr2;
                line>>sstr1>>sstr2;
                file2<<"addi "<<sstr1<<" x0 "<<sstr2;
            }
        }
        file2<<endl;
    }
    file.close();
    file2.close();
    
}

void original::calc_label(make_map obj,int control_phase1)
{


	string ins_name;
	ifstream original_codefp("original_code.txt",ios::in);  // reading assembly code

	if(control_phase1 ==0)
	{	
		original_codefp.close();
		original_codefp.open("original_code.txt",ios::in);  // reading assembly code
	}
	
	if(!original_codefp)
	cout<<"original_code.txt not readed"<<endl;
	else
	{
		int countpc=0;
		while(original_codefp>>ins_name)
		{
			if(ins_name[0]=='#')
				continue;
			// checking whether this is instruction or label bcz all instruction are mapped with type
			else
			{
				string label ;
				if(obj.mtype.count(ins_name)==0)
				{
					label = ins_name ;
					original_codefp>>ins_name;
				}
				string rs1,rs2,rd;
				string imm;
				string type;
				if(obj.mtype.count(ins_name)==0)
					type="A";
				else
					type = obj.mtype.find(ins_name)->second;
				if(type=="R")
				{
					original_codefp>>rd>>rs1>>rs2;
					string rs_2;
					int i=0;
					for(i=0;i<rs2.length();i++)
					{
						if(rs2[i]=='#')
							break;
					}
					rs_2=rs2.substr(0,i);

					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
				}
				else if(type=="I")
				{
					original_codefp>>rd>>rs1>>imm;
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
				}
				else if(type=="S")
				{
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					original_codefp>>rs2>>rs1>>imm;
				}
				else if(type=="SB")
				{
					string imm ;
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					original_codefp>>rs1>>rs2>>imm;
				}
				else if(type=="U")
				{
					string imm ;
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					original_codefp>>rd>>imm;
				}
				else if(type=="UJ")
				{
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					original_codefp>>rd>>imm;
				}
				else if(type=="P")
				{
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					original_codefp>>rd>>imm;
				}
				else if(type=="exit")
				{
					if ( label [label.length()-1] == ':')
					{
						mlabel.insert( pair<string,int>(label.substr(0,label.length()-1),4*countpc) );
					}
					countpc++;
					string readexit;
					original_codefp>>readexit;	
				}
			}
		}
	}
	original_codefp.close();
	
	
	memoryclass obj_mem_class;
	obj_mem_class.memory_handling();


	ifstream original_codefp1("original_code.txt",ios::in);  // reading assembly code
	if(control_phase1 ==0)
	{
		original_codefp1.close();
		original_codefp1.open("original_code.txt",ios::in);  // reading assembly code
	}
	ofstream basic_codefp("basic_code.txt",ios::out);  
	if(!original_codefp1)
		cout<<"original_code.txt not readed"<<endl;	
	else
	{

		int counter=-4;
		while(original_codefp1>>ins_name)
		{
			if(obj.mtype.count(ins_name)!=0)
			{
				counter+=4;
			}
			if(mlabel.count(ins_name)==0)
			{
				ins_name.append(":");
				if(obj_mem_class.data_row.count(ins_name)==0)
					basic_codefp<<ins_name.substr(0,ins_name.length()-1)<<" ";
				else
				{
					int immid;
					int row=obj_mem_class.data_row.find(ins_name)->second;
					int col=obj_mem_class.data_column.find(ins_name)->second;
					immid=(row*4)+(col/2);
					basic_codefp<<immid<<" ";
				}

			}
			else
			{
				basic_codefp<<(mlabel.find(ins_name)->second)-counter<<" ";
			}
		}
	}
	original_codefp1.close();
	basic_codefp.close();

}	


original::~original(){}
