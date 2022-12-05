#pragma once
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using std::string;
using std::map;



string DecToHex(int dec) {
    std::stringstream ss;
    ss << std::hex << dec;
    return ss.str();
}



int HexToDec(string hex) {
	return std::stoi(hex, nullptr, 16);
}


bool isHexValue(string value) {
    if (value[0] == '-') {
        value.replace(0, 1, "");
    }
	for (int i = 0; i < value.length(); i++) {
		if (!isdigit(value[i]) && (value[i] < 'a' || value[i] > 'f')) {
			return false;
		}
	}
	return true;
}

string HexToBin(string hex) {
    int i = 0;
    string bin = "";
    while (hex[i])
    {
        switch (hex[i])
        {
        case '0':
            bin += "0000";
            break;
        case '1':
            bin += "0001";
            break;
        case '2':
            bin += "0010";
            break;
        case '3':
            bin += "0011";
            break;
        case '4':
            bin += "0100";
            break;
        case '5':
            bin += "0101";
            break;
        case '6':
            bin += "0110";
            break;
        case '7':
            bin += "0111";
            break;
        case '8':
            bin += "1000";
            break;
        case '9':
            bin += "1001";
            break;
        case 'A':
        case 'a':
            bin += "1010";
            break;
        case 'B':
        case 'b':
            bin += "1011";
            break;
        case 'C':
        case 'c':
            bin += "1100";
            break;
        case 'D':
        case 'd':
            bin += "1101";
            break;
        case 'E':
        case 'e':
            bin += "1110";
            break;
        case 'F':
        case 'f':
            bin += "1111";
            break;
        }
        i++;
    }
    return bin;
}



string BinToHex(string bin) {
    string hex;
    std::stringstream ss;
    ss << std::hex << std::stoll(bin, NULL, 2);
    hex = ss.str();
    for (int i = 0; i < hex.size(); i++) {
        hex[i] = toupper(hex[i]);
    }
    return hex;
}




map<char, int> hex_value_of_dec(void)
{
    map<char, int> m{ { '0', 0 }, { '1', 1 },
                      { '2', 2 }, { '3', 3 },
                      { '4', 4 }, { '5', 5 },
                      { '6', 6 }, { '7', 7 },
                      { '8', 8 }, { '9', 9 },
                      { 'A', 10 }, { 'B', 11 },
                      { 'C', 12 }, { 'D', 13 },
                      { 'E', 14 }, { 'F', 15 } };

    return m;
}


map<int, char> dec_value_of_hex(void)
{
    map<int, char> m{ { 0, '0' }, { 1, '1' },
                      { 2, '2' }, { 3, '3' },
                      { 4, '4' }, { 5, '5' },
                      { 6, '6' }, { 7, '7' },
                      { 8, '8' }, { 9, '9' },
                      { 10, 'A' }, { 11, 'B' },
                      { 12, 'C' }, { 13, 'D' },
                      { 14, 'E' }, { 15, 'F' } };

    return m;
}


string Add_Hex(string a, string b)
{
    map<char, int> m = hex_value_of_dec();
    map<int, char> k = dec_value_of_hex();

    if (a.length() < b.length())
        swap(a, b);

    int l1 = a.length(), l2 = b.length();

    string ans = "";

    int carry = 0, i, j;

    for (i = l1 - 1, j = l2 - 1;
        j >= 0; i--, j--) {
        int sum = m[a[i]] + m[b[j]] + carry;
        int addition_bit = k[sum % 16];
        ans.push_back(addition_bit);
        carry = sum / 16;
    }

    while (i >= 0) {
        int sum = m[a[i]] + carry;
        int addition_bit = k[sum % 16];
        ans.push_back(addition_bit);
        carry = sum / 16;
        i--;
    }
    if (carry) {
        ans.push_back(k[carry]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



string TwosComplement(string str)
{
    int n = str.length();

    int i;
    for (i = n - 1; i >= 0; i--)
        if (str[i] == '1')
            break;

    if (i == -1)
        return '1' + str;

    for (int k = i - 1; k >= 0; k--)
    {
        if (str[k] == '1')
            str[k] = '0';
        else
            str[k] = '1';
    }

    return str;
}





string BitwiseAND(string op1, string op2) {
    string result = "";

    while (op1.size() < op2.size()) {
        op1 = '0' + op1;
    }
    while (op2.size() < op1.size()) {
        op2 = '0' + op2;
    }
    for (int i = 0; i < op1.size(); i++) {
        if (op1[i] == '1' && op2[i] == '1') {
            result += "1";
        }
        else {
            result += "0";
        }
    }

    return result;
}



string BitwiseOR(string op1, string op2) {
    string result = "";

    while (op1.size() < op2.size()) {
        op1 = '0' + op1;
    }
    while (op2.size() < op1.size()) {
        op2 = '0' + op2;
    }
    for (int i = 0; i < op1.size(); i++) {
        if (op1[i] == '0' && op2[i] == '0') {
            result += "0";
        }
        else {
            result += "1";
        }
    }

    return result;
}



string BitwiseXOR(string op1, string op2) {
    string result = "";

    while (op1.size() < op2.size()) {
        op1 = '0' + op1;
    }
    while (op2.size() < op1.size()) {
        op2 = '0' + op2;
    }
    for (int i = 0; i < op1.size(); i++) {
        if ((op1[i] == '0' && op2[i] == '0') || (op1[i] == '1' && op2[i] == '1')) {
            result += "0";
        }
        else {
            result += "1";
        }
    }

    return result;
}


string BitwiseNOT(string op) {
    string result;
    for (int i = 0; i < op.length(); i++) {
        if (op[i] == '0') {
            result += '1';
        }
        else {
            result += '0';
        }
    }
    return result;
}



string ShiftLeft(string op) {
    string result;
    result = op.replace(0, 1, "");
    result += "0";
    return result;
}


string ShiftRight(string op) {
    string result;
    op.pop_back();
    result = '0' + op;
    return result;
}


string RotateLeft(string op) {
    string result;
    char ch;
    ch = op[0];
    result = op.replace(0, 1, "") + ch;
    return result;
}


string RotateRight(string op) {
    string result;
    char ch;
    ch = op[op.length()-1];
    op.pop_back();
    result = ch + op;
    return result;
}

