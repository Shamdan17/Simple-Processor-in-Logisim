#include <bits/stdc++.h>
#define LL long long
#define PI pair<int,int>
#define PL pair<LL,LL>
#define st first
#define nd second
#define all(x) x.begin(),x.end()

using namespace std;

map<string, string> op;

//Operations in order
string operations[]{
	"add", //0
	"sub", //1
	"mult", //2
	"and", //3
	"or", //4
	"addi", //5
	"sll", //6
	"slt", //7
	"mfhi", //8
	"mflo", //9
	"lw", //10
	"sw", //11
	"beq", //12
	"blez", //13
	"j", //14
	"myIns", //15		
};

int indexOf(string st){
	for(int i=0;i<16;i++){
		if(st == operations[i]){
			return i;
		}
	}
	return -1;
}

// length should be multiple of 4
string toHex(string a, int length){
	long val = 0;
	string result = "";
	for(int i=0;i<length;i++){
		val*=2;
		val += (a[i]-'0');
		if(i%4==3){
			if(val <10){
				result += to_string(val);
			}else{
				result += (char)('a'+(val-10));
			}
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

// returns a string of given length of 0's 
string zeros(int length){
	string result = "";
	for(int i=0;i<length;i++){
		result += "0";
	}
	return result;
}

// supported format: instr rd, rs, rt
string get3Registers(){
	string result="";
	int rs, rt, rd;
	scanf("%d, %d, %d", &rd, &rs, &rt);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5) + toBinary(rt,5) + toBinary(rd,5) + zeros(11);
	return result;
}

// supported format: instr rs, rt
string get2Registers(){
	string result="";
	int rs, rt;
	scanf("%d, %d", &rs, &rt);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5) + toBinary(rt,5) + zeros(16);
	return result;
}

// supported format: instr rd, rs, I
string get2RegistersImm(){
	string result="";
	int rs, rt, imm;
	scanf("%d, %d, %d", &rt, &rs, &imm);
	// convert to binary
	result= toBinary(rs,5) + toBinary(rt,5) + toBinary(imm,16);
	return result;
}

// supported format: instr rd, rs, shamt
string get2RegistersShamt(){
	string result="";
	int rs, rt, shamt;
	scanf("%d, %d, %d", &rt, &rs, &shamt);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5)  + zeros(5) + toBinary(rt,5)+ toBinary(shamt,5) + zeros(6);
	return result;
}

// supported format: instr rd
string get1Register(){
	string result="";
	int rd;
	scanf("%d", &rd);
	// convert to binary and fill to 26 bits with zeroes
	result= zeros(10) + toBinary(rd,5) + zeros(11);
	return result;
}

// supported format: instr rd, i(rs)
string getLoadStore(){
	string result="";
	int rd, rs, imm;
	scanf("%d, %d(%d)", &rd, &imm , &rs);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5) + toBinary(rd,5) + toBinary(imm,16);
	return result;
}

// TODO: Handle branches and jumps
// supported format: beq rs, rt, offset
string get2RegistersBeq(){
	string result="";
	int rs, rt, offset;
	scanf("%d, %d, %d", &rs, &rt, &offset);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5)  + toBinary(rt,5)+ toBinary(offset/4,16);
	return result;
}

// supported format: blez rs, offset
string get1RegistersBlez(){
	string result="";
	int rs, offset;
	scanf("%d, %d", &rs, &offset);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(rs,5)  + zeros(5) + toBinary(offset/4,16);
	return result;
}

// supported format: j address
string 	getJump(){
	string result="";
	int offset;
	scanf("%d", &offset);
	// convert to binary and fill to 26 bits with zeroes
	result= toBinary(offset/4,26);
	return result;
}

int main(){
	for(int i=0;i<16;i++){
		op[operations[i]] = toBinary(i,6);
	}
	int counter = 0;
	string hm;
	cin >> hm;
	while(hm!="EOF"){
		switch(indexOf(hm)){
			case 0:
			case 1:
			case 3:
			case 4:
			case 7:
				cout << op[hm] << get3Registers() << endl;
				break;
			case 2:
				cout << op[hm] << get2Registers() << endl;
				break;
			case 5:
				cout << op[hm] << get2RegistersImm() << endl;
				break;
			case 6:
				cout << op[hm] << get2RegistersShamt() << endl;
				break;
			case 8:
			case 9:
				cout << op[hm] << get1Register() << endl;
				break;
			case 10:
			case 11:
				cout << op[hm] << getLoadStore() << endl;
				break;
			case 12:
				cout << op[hm] << get2RegistersBeq() << endl;
				break;
			case 13:
				cout << op[hm] << get1RegistersBlez() << endl;
				break;
			case 14:
				cout << op[hm] << getJump() << endl;
				break;
			case -1:
				return 0;
		}
		cin >> hm;
	}
	cout << "EOF" << endl;
}