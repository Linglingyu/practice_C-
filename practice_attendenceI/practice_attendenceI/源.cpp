#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	string *s= new string[n+1];

	for (int i = 0; i < n+1; i++){
		getline(cin, s[i]);
	}

	for (int k = 1; k < n+1;k++){
		int count_A = 0;
		for (int j = 0; j < s[k].length(); j++){
//			cout << s[j] << endl;
			if (s[k][j] == 'A'){
				count_A++;
			}
			if (count_A == 2){
				cout << "NO"<<endl;
				break;
			}

			if (s[k].compare(j, 3, "LLL") == 0){
				cout << "NO"<<endl;
				break;
			}

			if (j == s[k].length()-1)
			cout << "YES" << endl;

		}
	}
	system("pause");

	return 0;
}