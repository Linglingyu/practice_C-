#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Solution {
public:
	/**
	* ����������ζ����Ʊ��λ����ͬ������
	*
	* @param m ����m
	* @param n ����n
	* @return ����
	*/
	int countBitDiff(int m, int n) {
		int temp;
		temp = m^n;
		int count=0;
		while (temp){
			temp = temp&(temp - 1);
			count++;
		}
		return count;
	}
};

int main(){
	int lt = time(NULL);
	srand(lt);
	int m = (rand()<<16)+(rand());
	int n = (rand() << 16) + (rand());

	int res;
	Solution s;
	res=s.countBitDiff(1999, 2299);
	cout << res << endl;
	

	system("pause");
}