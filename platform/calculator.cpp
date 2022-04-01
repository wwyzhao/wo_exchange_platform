#include<iostream>
#include<string>
#include<vector>
#include "calculator.h"
using namespace std;

bool Push(Stack& s, char strx) {
	if (s.top == 100 - 1)
		return false;
	else {
		s.top++;
		s.buffer[s.top] = strx;
		return true;
	}
}
bool Pop(Stack& s, char& strx) {
	if (s.top == -1)
		return false;
	else {
		strx = s.buffer[s.top];
		s.top--;
		return true;
	}
}
bool GetTop(Stack& s, char & strx) {
	if (s.top == -1)return false;
	strx = s.buffer[s.top];
	return true;
}
//bool GetTop1(Stack1& s1, double& strx) {
//	if (s1.top == -1)return false;
//	strx = s1.buffer[s1.top];
//	return true;
//}
//void Append(string str1,char strx) {
//	str1[str1.length()] = strx;
//}
int isp(char str) {
	switch (str) {
	case '(':return 1;
	case '+':return 3;
	case '-':return 3;
	case 'x':return 5;
	case '/':return 5;
	case ')':return 6;
	case '#':return 0;
	}
}

int icp(char str) {
	switch (str) {
	case '(':return 6;
	case '+':return 2;
	case '-':return 2;
	case 'x':return 4;
	case '/':return 4;
	case ')':return 1;
	case '#':return 0;
	}
}

void DoOperator(Stack1& s1, char op) {
	double left, right;
	double result, value;
	//double left1, right1;
	right = s1.buffer[s1.top];
	s1.top--;
	//right1 = 1double * (right - '0');
	left = s1.buffer[s1.top];
	s1.top--;
	//left1 = 1double * (left - '0');
	switch (op) {
	case '+':value = left + right; s1.top++; s1.buffer[s1.top] = value; break;
	case '-':value = left - right; s1.top++; s1.buffer[s1.top] = value; break;
	case 'x':value = left * right; s1.top++; s1.buffer[s1.top] = value; break;
	case '/':{if(right==0.0){cout<<"Divided by 0.0!"<<endl;}else{value=left/right;s1.top++; s1.buffer[s1.top] = value; }break;}
	}
}

string cal(string Tempstr, Stack &s, Stack1 &s1) {
	vector<string>Backstr;//后缀表达式
	Tempstr[Tempstr.length()] = '#';
	s.top = -1;
	s1.top = -1;
	Push(s, '#');
	Backstr.push_back(to_string( '#'));
	char x; 
	int num, flag=0;
	for (int i = 0; i < Tempstr.length(); ++i) {
		while (s.top != -1) {
			if(Tempstr[i]>='0'&&Tempstr[i]<='9')
			{
				num*=10;
				num+=(Tempstr[i]-'0');
				flag=1;
				break;
			}
			else {
				if(flag){
					Backstr.push_back(to_string(num));
					num=0;
					flag=0;
				}
				char strx, op;
				GetTop(s, strx);
				if (isp(strx) < icp(Tempstr[i])) { Push(s, Tempstr[i]); break; }
				else if (isp(strx) > icp(Tempstr[i])) { Pop(s, op); Backstr.push_back(to_string(op));}
				else {
					Pop(s, op);
					if (op == '(' || op == '#') break;
				}
			}
		}
	}
	Backstr.push_back(to_string('#'));
	//for(int i=0;i<Backstr.size();++i)cout<<Backstr[i]<<endl;
	//cout<<Backstr<<endl;
	int j = 1;
	//double num;
	//string temp;
	while (Backstr[j] != to_string('#')) {
		if(Backstr[j]!=to_string('+') && Backstr[j]!=to_string('-') && Backstr[j]!=to_string('x') && Backstr[j]!=to_string('/')){s1.top++; s1.buffer[s1.top] = stod(Backstr[j]);}
		else{DoOperator(s1,Backstr[j][0]); break;}
		j++;
	}
	//cout<<s1.buffer[s1.top]<<endl;
	return to_string(s1.buffer[s1.top]);
}
