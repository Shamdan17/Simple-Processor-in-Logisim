#include <bits/stdc++.h>
using namespace std;

// length should be multiple of 4
string toHex(string a, int length){
	long val = 0;
	string result = "";
	for(int i=0;i<4*(length/4);i++){
		val*=2;
		val += (a[i]-'0');
		if(i%4==3){
			if(val <10){
				result += to_string(val);
			}else{
				result += (char)('a'+(val-10));
			}
			val = 0;
		}
	}
	return result;
}

string toBinary(int a, int length){
	string result = "";
	if(a<0){
		return toBinary((1<<31) + a, length);
	}
	for(int i=0;i<length;i++){
		if(a%2==1){
			result="1"+result;
		}else{
			result="0"+result;
		}
		a/=2;
	}
	return result;
}

int main(){
	string hm;
	cin >> hm;
	cout << "v2.0 raw" << endl;
	while(hm!="EOF"){
		int cur = stoi(hm);
		cout << toHex(toBinary(cur, 16),16) << " ";
		cin >> hm;
	}
	cout << endl;
}