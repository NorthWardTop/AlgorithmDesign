
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/******
问题描述
　　给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，
	每个十六进制数长度不超过100000。

输出格式
　　输出n行，每行为输入对应的八进制正整数。

　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。

样例输入
　　2
　　39
　　123ABC

样例输出
　　71
　　4435274

　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/ 

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
using namespace std;

string hex_to_bin(string const& hex)
{
	string bin = "\0";

	for (int j = 0; j < hex.length(); j++)
	{
		switch (hex.at(j))
		{
		case '0':bin += "0000"; break;
		case '1':bin += "0001"; break;
		case '2':bin += "0010"; break;
		case '3':bin += "0011"; break;
		case '4':bin += "0100"; break;
		case '5':bin += "0101"; break;
		case '6':bin += "0110"; break;
		case '7':bin += "0111"; break;
		case '8':bin += "1000"; break;
		case '9':bin += "1001"; break;
		case 'A':bin += "1010"; break;
		case 'B':bin += "1011"; break;
		case 'C':bin += "1100"; break;
		case 'D':bin += "1101"; break;
		case 'E':bin += "1110"; break;
		case 'F':bin += "1111"; break;
		default:break;
		}
	}
	cout << "hex_to_bin:" << bin << endl;
	return bin;
}

string bin_to_oct(const string& bin)
{
	string oct = "\0";
	int tmp = 0;
	//从第一个非0数开始变化
	int j = 0;
	for (j = 0; j < bin.length(); ++j)
		if (bin[j] == '1')
			break;
	//第一次循环每三位一次 
	for (int i = j; i < bin.length(); i += 3)
	{
		tmp = 0;
		tmp += bin[i] == '1' ? 4 : 0;
		tmp += bin[i + 1] == '1' ? 2 : 0;
		tmp += bin[i + 2] == '1' ? 1 : 0;
		oct += 48 + tmp; //当前8进制tmp转化为字符'8' 
	}

	cout << "bin_to_oct:" << oct << endl;
	return oct;
}



int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string* hex = new string[n];
	string* bin = new string[n];
	string* oct = new string[n];
	if (hex == NULL || bin == NULL || oct == NULL)
		cout << "申请失败!";
	*hex = "\0";
	*bin = "\0";
	*oct = "\0";
	string c;
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		hex[i] = c;
	}

	for (int i = 0; i < n; ++i)
	{
		bin[i] = hex_to_bin(hex[i]);
		oct[i] = bin_to_oct(bin[i]);
	}

	for (int i = 0; i < n; ++i)
		cout << oct[i] << ' ';


	delete [] hex;
	delete [] oct;
	delete [] bin;
	system("pause");
	return 0;
}




