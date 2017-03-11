#include <iostream>
#include <string>

using namespace std;

int solve(string str){
	int num = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] >= '0'&&str[i] <= '9'){
			num = num * 10 + str[i] - '0';
		}
	}
	return (str[0] == '-') ? (-num) : num;
}

int main(){
	int a, b;
	string str_a, str_b;
	while (cin >> str_a >> str_b){
		a = solve(str_a);
		b = solve(str_b);
		cout << a + b << endl;
	}
	system("pause");
}

