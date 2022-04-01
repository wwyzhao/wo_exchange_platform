#include<string>
#include<vector>
#include<iostream>
using namespace std;
#ifndef _CAL_H_
#define _CAL_H_
typedef long long ll;
struct Stack{
	int top;
	char buffer[100];
};
struct Stack1 {
	int top;
	double buffer[100];
};


bool Push(Stack& s, char strx);
bool Pop(Stack& s, char& strx);
bool GetTop(Stack& s, char & strx);
//bool GetTop1(Stack1& s1, ll& strx);
void Append(char str[],char strx);
int isp(char str);
int icp(char str);
void DoOperator(Stack1& s1, char op);
string cal(string Tempstr, Stack &s, Stack1 &s1);

#endif // _CAL_H_