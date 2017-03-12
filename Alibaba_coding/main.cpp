#include <iostream>
#include <vector>
#include <numeric>
#include<limits>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int Decode(string in) {
	string out;
	int ind;
	if(in[0]=='0'&& in.length()==8)
		ind=1;
	else if(in[3]=='0' && in.length()==16)
		ind=2;
	else if(in[4]=='0'&& in.length()==24)
		ind=3;
	else if(in[5]=='0'&& in.length()==32)
		ind=4;
	else
		ind=5;
	int tmp=0;
	switch(ind){
	case 1:{
		for(int i=1;i<=7;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,7-i);
		break;}
	case 2:{
		for(int i=3;i<=7;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,13-i);
		for(int i=10;i<16;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,15-i);
		if(tmp<128) return -1;
		break;}
	case 3:{
		for(int i=4;i<=7;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,19-i);
		for(int i=10;i<16;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,21-i);
		for(int i=18;i<24;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,23-i);
		if(tmp<2048) return -1;
		break;}
	case 4:{
		for(int i=5;i<8;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,25-i);
		for(int i=10;i<16;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,27-i);
		for(int i=18;i<24;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,29-i);
		for(int i=26;i<32;i++)
		tmp=tmp+(in[i]-'0')*pow(2.0,31-i);
		if(tmp<65536) return -1;
		break;}
	default:
		{
		cout<<"bad input!"<<endl;
		break;}
	}
	return tmp;
}
int main() {
    int res;
    string _in;
    getline(cin, _in);

    res = Decode(_in);
	if(res==-1)
		cout<<"error input"<<endl;
	else
		cout << res << endl;
    
    getchar();
    return 0;

}
