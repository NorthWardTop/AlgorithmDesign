
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/******
��������
��������n��ʮ��������������������Ƕ�Ӧ�İ˽�������

�����ʽ
��������ĵ�һ��Ϊһ��������n ��1<=n<=10����
����������n�У�ÿ��һ����0~9����д��ĸA~F��ɵ��ַ�������ʾҪת����ʮ��������������
	ÿ��ʮ�����������Ȳ�����100000��

�����ʽ
�������n�У�ÿ��Ϊ�����Ӧ�İ˽�����������

������ע�⡿
���������ʮ��������������ǰ��0������012A��
��������İ˽�����Ҳ������ǰ��0��

��������
����2
����39
����123ABC

�������
����71
����4435274

��������ʾ��
�����Ƚ�ʮ��������ת����ĳ������������ĳ������ת���ɰ˽��ơ�
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
	//�ӵ�һ����0����ʼ�仯
	int j = 0;
	for (j = 0; j < bin.length(); ++j)
		if (bin[j] == '1')
			break;
	//��һ��ѭ��ÿ��λһ�� 
	for (int i = j; i < bin.length(); i += 3)
	{
		tmp = 0;
		tmp += bin[i] == '1' ? 4 : 0;
		tmp += bin[i + 1] == '1' ? 2 : 0;
		tmp += bin[i + 2] == '1' ? 1 : 0;
		oct += 48 + tmp; //��ǰ8����tmpת��Ϊ�ַ�'8' 
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
		cout << "����ʧ��!";
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




