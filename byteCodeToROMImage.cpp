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

int main(){
	string hm;
	cin >> hm;
	cout << "v2.0 raw" << endl;
	while(hm!="EOF"){
		cout << toHex(hm,32) << " ";
		cin >> hm;
	}
	cout << endl;
}