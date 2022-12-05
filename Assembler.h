#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Instruction.h"
#include "BaseConversion.h"
using std::string;
using std::vector;
using std::queue;
#include "StringConversion.h"


class Assembler
{
public:
	std::string MachineCode;

	void ConvertToMachineCode(string, vector<Instruction>&);
	bool isRegister(string);
	bool isMemoryByRegister(string);
	bool isMemoryAddress(string);
	bool is8BitDisplacement(string);
	bool is16BitDisplacement(string);

	int getRegisterBits(string);
	string getRegisterCode(string);

	void mov(string, string, Instruction&);
	void inc(string, Instruction&);
	void movzx(string, string, Instruction&);
	void shl(string, string, Instruction&);
};





void Assembler::ConvertToMachineCode(string AssemblyCode, vector<Instruction>& instructions) {
	MachineCode.clear();
	instructions.clear();
	string opcode, operand1, operand2;
	Instruction instruction;
	queue<char> Q;
	bool comma;
	int i, j;

	//Converting all the code in lowercase.
	for (i = 0; i < AssemblyCode.length(); i++) {
		AssemblyCode[i] = tolower(AssemblyCode[i]);
	}

	if (!AssemblyCode.empty() && AssemblyCode.back() != '\n') {
		AssemblyCode += '\n';
	}

	i = 0;
	while (i < AssemblyCode.length()) {
		opcode.clear();
		operand1.clear();
		operand2.clear();
		instruction.clear();
		comma = false;

		while (AssemblyCode[i] != '\n') {
			Q.push(AssemblyCode[i]);
			if (AssemblyCode[i] == ',')
				comma = true;
			i++;
		}
		i++;


		//Ignoring spaces before opcode.
		while (!Q.empty() && (Q.front() == ' ' || Q.front() == '\t')) Q.pop();

		//Ignoring empty lines.
		if (Q.empty()) {
			continue;
		}

		while (!Q.empty() && Q.front() != ' ' && Q.front() != '\t') {
			opcode += Q.front();
			Q.pop();
		}
		//Ignoring spaces after opcode.
		while (!Q.empty() && (Q.front() == ' ' || Q.front() == '\t')) Q.pop();

		if (comma) {
			while (Q.front() != ',') {
				operand1 += Q.front();
				Q.pop();
			}
			//For comma.
			Q.pop();
			//Ignoring spaces after comma.
			while (!Q.empty() && (Q.front() == ' ' || Q.front() == '\t')) Q.pop();

			while (!Q.empty()) {
				operand2 += Q.front();
				Q.pop();
			}
		}
		if (!comma) {
			while (!Q.empty() && Q.front() != ' ' && Q.front() != '\t') {
				operand1 += Q.front();
				Q.pop();
			}
		}
		
		//Removing trailing spaces in operand1.
		for (j = operand1.length()-1; j >= 0; j--) {
			if (operand1[j] == ' ' || operand1[j] == '\t') {
				operand1.replace(j, 1, "");
			}
			else {
				break;
			}
		}
		//Removing trailing spaces in operand2.
		for (j = operand2.length()-1; j >= 0; j--) {
			if (operand2[j] == ' ' || operand2[j] == '\t') {
				operand2.replace(j, 1, "");
			}
			else {
				break;
			}
		}


		//System::Windows::Forms::MessageBox::Show(toSystemString('-' + opcode + '-' + operand1 + '-' + operand2 + '-'));

		
		//1
		if (opcode == "mov") {
			instruction.opcode = "000000";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			mov(operand1, operand2, instruction);
		}
		//2
		else if (opcode == "add") {
			instruction.opcode = "000001";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			mov(operand1, operand2, instruction);
		}
		//3
		else if (opcode == "rol") {
			instruction.opcode = "000010";
			instruction.reg = "000";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			shl(operand1, operand2, instruction);
		}
		//4
		else if (opcode == "inc") {
			instruction.opcode = "000011";
			instruction.reg = "000";
			if (!operand2.empty() || comma) {
				throw "Error: There should be only one operand.";
			}
			inc(operand1, instruction);
		}
		//5
		else if (opcode == "ror") {
			instruction.opcode = "000100";
			instruction.reg = "001";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			shl(operand1, operand2, instruction);
		}
		//6
		else if (opcode == "nop") {
			if (!operand1.empty() || !operand2.empty() || comma) {
				throw "Error: There should be no operands.";
			}
			instruction.opcode = "000101";
		}
		//7
		else if (opcode == "and") {
			instruction.opcode = "000110";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Operands missing.";
			}
			mov(operand1, operand2, instruction);
		}
		//8
		else if (opcode == "or") {
			instruction.opcode = "000111";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Operands missing.";
			}
			mov(operand1, operand2, instruction);
		}
		//9
		else if (opcode == "xor") {
			instruction.opcode = "001000";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Operands missing.";
			}
			mov(operand1, operand2, instruction);
		}
		//10
		else if (opcode == "not") {
			instruction.opcode = "001001";
			instruction.reg = "010";
			if (!operand2.empty() || comma) {
				throw "Error: There should be only one operand.";
			}
			inc(operand1, instruction);
		}
		//11
		else if (opcode == "shr") {
			instruction.opcode = "001010";
			instruction.reg = "101";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			shl(operand1, operand2, instruction);
		}
		//12
		else if (opcode == "shl") {
			instruction.opcode = "001011";
			instruction.reg = "100";
			if (operand1.empty() || operand2.empty()) {
				throw "Error: Missing operands.";
			}
			shl(operand1, operand2, instruction);
		}
		//13
		else if (opcode == "hlt") {
			instruction.opcode = "001100";
			if (!operand1.empty() || !operand2.empty() || comma) {
				throw "Error: There should be no operands.";
			}
		}
		//14
		else if (opcode == "neg") {
			instruction.opcode = "001101";
			instruction.reg = "011";
			if (operand1.empty()) {
				throw "Error: Operand is missing.";
			}
			else if (!operand2.empty() || comma) {
				throw "Error: There should be only one operand.";
			}
			inc(operand1, instruction);
		}
		//15
		else if (opcode == "clc") {
			instruction.opcode = "001110";
			if (!operand1.empty() || !operand2.empty()) {
				throw "Error: There should be no operands.";
			}
		}
		else {
			throw "Error: Invalid instruction";
		}

		MachineCode += instruction.opcode + ' ' + instruction.d + instruction.w;
		MachineCode += ' ' + instruction.mod + ' ' + instruction.reg + ' ' + instruction.r_m;
		MachineCode += ' ' + instruction.displacement + instruction.data + '\n';

		instructions.push_back(Instruction(instruction));
	}

}



void Assembler::mov(string operand1, string operand2, Instruction& instruction) {
	string byte3, byte4, complement;

	//Immediate
	if (isRegister(operand1) && isHexValue(operand2)) {
		if (getRegisterBits(operand1) == 16 && HexToDec(operand2) > 65535) {
			throw "Error: Immediate value cannot fit in 16 bits.";
		}
		else if (getRegisterBits(operand1) == 8 && HexToDec(operand2) > 255) {
			throw "Error: Immediate value cannot fit in 8 bits.";
		}

		instruction.d = "1";
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = "000";
		
		if (operand2[0] == '-') {
			operand2.replace(0, 1, "");
				
		if (instruction.w == "1") {
			while (operand2.length() < 4) {
					operand2 = '0' + operand2;
			}
			complement = TwosComplement(HexToBin(operand2));
			byte3 = complement.substr(8, 8);
			byte4 = complement.substr(0, 8);
		}		
		else {
			while (operand2.length() < 2) {
				operand2 = '0' + operand2;
			}
			complement = TwosComplement(HexToBin(operand2));
			byte3 = complement.substr(0, 8);
		}
		instruction.data = byte3 + ' ' + byte4;
		}
		else {
			if (operand2.length() == 1 || operand2.length() == 2) {
				if (operand2.length() == 1)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2);
			}
			else if (operand2.length() == 3 || operand2.length() == 4) {
				if (operand2.length() == 3)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2.substr(2, 2));
				byte4 = HexToBin(operand2.substr(0, 2));
			}
			instruction.data = byte3 + ' ' + byte4;
		}
	}

	//Register Direct
	else if (isRegister(operand1) && isRegister(operand2)) {
		if (getRegisterBits(operand1) != getRegisterBits(operand2)) {
			throw "Error: Register sizes are not equal";
		}

		instruction.d = "1";
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}

		instruction.mod = "11";
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = getRegisterCode(operand2);
	}

	//Register Indirect
	else if (isMemoryByRegister(operand1) && isRegister(operand2)) {
		instruction.d = "0";

		if (getRegisterBits(operand2) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand2);
		
		operand1.replace(0, 1, "");
		operand1.pop_back();
		instruction.r_m = getRegisterCode(operand1);
	}
	else if (isMemoryByRegister(operand2) && isRegister(operand1)) {
		instruction.d = "1";

		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand1);

		operand2.replace(0, 1, "");
		operand2.pop_back();
		instruction.r_m = getRegisterCode(operand2);
	}
	
	//Register Relative
	else if (isRegister(operand1) && (is8BitDisplacement(operand2) || is16BitDisplacement(operand2))) {
		instruction.d = "1";
		
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		if (is8BitDisplacement(operand2)) {
			instruction.mod = "01";
		}
		else {
			instruction.mod = "10";
		}
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = getRegisterCode(operand2.substr(1, 2));

		operand2.replace(0, 4, "");
		operand2.pop_back();
		byte3 = HexToBin(operand2.substr(2, 2));
		byte4 = HexToBin(operand2.substr(0, 2));
		
		instruction.displacement = byte3 + ' ' + byte4;
	}
	else if (isRegister(operand2) && (is8BitDisplacement(operand1) || is16BitDisplacement(operand1))) {
		instruction.d = "0";

		if (getRegisterBits(operand2) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		if (is8BitDisplacement(operand1)) {
			instruction.mod = "01";
		}
		else {
			instruction.mod = "10";
		}
		instruction.reg = getRegisterCode(operand2);
		instruction.r_m = getRegisterCode(operand1.substr(1, 2));

		operand1.replace(0, 4, "");
		operand1.pop_back();
		byte3 = HexToBin(operand1.substr(2, 2));
		byte4 = HexToBin(operand1.substr(0, 2));

		instruction.displacement = byte3 + ' ' + byte4;
	}

	//Direct
	else if (isMemoryAddress(operand1) && isRegister(operand2)) {
		instruction.d = "0";

		if (getRegisterBits(operand2) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand2);
		instruction.r_m = "110";

		operand1.replace(0, 2, "");
		operand1.pop_back();
		byte3 = HexToBin(operand1.substr(2, 2));
		byte4 = HexToBin(operand1.substr(0, 2));
		instruction.displacement = byte3 + ' ' + byte4;
	}
	else if (isMemoryAddress(operand2) && isRegister(operand1)) {
		instruction.d = "1";

		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = "110";

		operand2.replace(0, 2, "");
		operand2.pop_back();
		byte3 = HexToBin(operand2.substr(2, 2));
		byte4 = HexToBin(operand2.substr(0, 2));
		instruction.displacement = byte3 + ' ' + byte4;
	}

}



void Assembler::inc(string operand1, Instruction& instruction) {
	string byte3, byte4;
	instruction.d = "1";

	if(isRegister(operand1)) {
		instruction.mod = "11";
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.r_m = getRegisterCode(operand1);
	}
	else if (isMemoryByRegister(operand1)) {
		instruction.mod = "00";
		instruction.w = "0";
		operand1.replace(0, 1, "");
		operand1.pop_back();
		instruction.r_m = getRegisterCode(operand1);
	}
	else if (isMemoryAddress(operand1)) {
		instruction.mod = "00";
		instruction.w = "0";
		instruction.r_m = "110";
	
		operand1.replace(0, 2, "");
		operand1.pop_back();
		byte3 = HexToBin(operand1.substr(2, 2));
		byte4 = HexToBin(operand1.substr(0, 2));
		instruction.displacement = byte3 + ' ' + byte4;
	}
	else if (is8BitDisplacement(operand1)) {
		instruction.mod = "01";
		instruction.w = "0";
		instruction.r_m = getRegisterCode(operand1.substr(1, 2));

		operand1.replace(0, 4, "");
		operand1.pop_back();
		byte3 = HexToBin(operand1.substr(0, 2));
		instruction.displacement = byte3;
	}
	else if (is16BitDisplacement(operand1)) {
		instruction.mod = "10";
		instruction.w = "0";
		instruction.r_m = getRegisterCode(operand1.substr(1, 2));

		operand1.replace(0, 4, "");
		operand1.pop_back();
		byte3 = HexToBin(operand1.substr(2, 2));
		byte4 = HexToBin(operand1.substr(0, 2));
		instruction.displacement = byte3 + ' ' + byte4;
	}
	else {
		throw "Invalid operand";
	}
}


void Assembler::movzx(string operand1, string operand2, Instruction& instruction) {
	string byte3, byte4;

	if (isRegister(operand1) && isRegister(operand2)) {
		if (getRegisterBits(operand1) != getRegisterBits(operand2)) {
			throw "Register sizes are not equal";
		}

		instruction.d = "1";
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}

		instruction.mod = "11";
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = getRegisterCode(operand2);
	}
	else if (isRegister(operand1) && isMemoryAddress(operand2)) {
		instruction.d = "1";

		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "00";
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = "110";

		operand2.replace(0, 2, "");
		operand2.pop_back();
		byte3 = HexToBin(operand2.substr(2, 2));
		byte4 = HexToBin(operand2.substr(0, 2));
		instruction.displacement = byte3 + ' ' + byte4;
	}
	else if (isRegister(operand1) && (is8BitDisplacement(operand2) || is16BitDisplacement(operand2))) {
		instruction.d = "1";

		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		if (is8BitDisplacement(operand2)) {
			instruction.mod = "01";
		}
		else {
			instruction.mod = "10";
		}
		instruction.reg = getRegisterCode(operand1);
		instruction.r_m = "111";

		operand2.replace(0, 4, "");
		operand2.pop_back();
		byte3 = HexToBin(operand2.substr(2, 2));
		byte4 = HexToBin(operand2.substr(0, 2));

		instruction.displacement = byte3 + ' ' + byte4;
	}
	else {
		throw "Error: Invalid operands.";
	}
}




void Assembler::shl(string operand1, string operand2, Instruction& instruction) {
	string byte3, byte4;
	instruction.d = "0";
	if (isRegister(operand1) && (isHexValue(operand2) || operand2 == "cl")) {
		if (getRegisterBits(operand1) == 8) {
			instruction.w = "0";
		}
		else {
			instruction.w = "1";
		}
		instruction.mod = "11";
		instruction.r_m = getRegisterCode(operand1);

		if (isHexValue(operand2)) {
			if (operand2.length() == 1 || operand2.length() == 2) {
				if (operand2.length() == 1)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2);
			}
			else if (operand2.length() == 3 || operand2.length() == 4) {
				if (operand2.length() == 3)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2.substr(2, 2));
				byte4 = HexToBin(operand2.substr(0, 2));
			}
			instruction.data = byte3 + ' ' + byte4;
		}
	}
	else if (isMemoryByRegister(operand1) && (isHexValue(operand2) || operand2 == "cl")) {
		instruction.w = "1";
		instruction.mod = "00";
		operand1.replace(0, 1, "");
		operand1.pop_back();
		instruction.r_m = getRegisterCode(operand1);

		if (isHexValue(operand2)) {
			if (operand2.length() == 1 || operand2.length() == 2) {
				if (operand2.length() == 1)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2);
			}
			else if (operand2.length() == 3 || operand2.length() == 4) {
				if (operand2.length() == 3)
					operand2 = '0' + operand2;
				byte3 = HexToBin(operand2.substr(2, 2));
				byte4 = HexToBin(operand2.substr(0, 2));
			}
			instruction.data = byte3 + ' ' + byte4;
		}
	}
	else {
		throw "Error: Invalid operands.";
	}
}




int Assembler::getRegisterBits(string reg) {
	if (reg.length() == 2) {
		if (reg[0] == 'a' || reg[0] == 'b' || reg[0] == 'c' || reg[0] == 'd') {
			if (reg[1] == 'l' || reg[1] == 'h') {
				return 8;
			}
			else if (reg[1] == 'x') {
				return 16;
			}
		}
		else if ((reg[0] == 's' || reg[0] == 'b') && reg[1] == 'p') {
			return 16;
		}
		else if ((reg[0] == 's' || reg[0] == 'd') && reg[1] == 'i') {
			return 16;
		}
	}
	return -1;
}


string Assembler::getRegisterCode(string reg) {
	if (reg == "al" || reg == "ax") {
		return "000";
	}
	else if (reg == "cl" || reg == "cx") {
		return "001";
	}
	else if (reg == "dl" || reg == "dx") {
		return "010";
	}
	else if (reg == "bl" || reg == "bx") {
		return "011";
	}
	else if (reg == "ah" || reg == "sp") {
		return "100";
	}
	else if (reg == "ch" || reg == "bp") {
		return "101";
	}
	else if (reg == "dh" || reg == "si") {
		return "110";
	}
	else if (reg == "bh" || reg == "di") {
		return "111";
	}
	return "";
}



bool Assembler::isRegister(string reg) {
	if (reg.length() == 2) {
		if (reg[0] == 'a' || reg[0] == 'b' || reg[0] == 'c' || reg[0] == 'd') {
			if (reg[1] == 'l' || reg[1] == 'h' || reg[1] == 'x') {
				return true;
			}
		}
		else if ((reg[0] == 's' || reg[0] == 'b') && reg[1] == 'p') {
			return true;
		}
		else if ((reg[0] == 's' || reg[0] == 'd') && reg[1] == 'i') {
			return true;
		}
	}

	return false;
}


bool Assembler::isMemoryByRegister(string memreg) {
	if (memreg.front() == '[' && memreg.back() == ']') {
		memreg.replace(0, 1, "");
		memreg.pop_back();
		if (isRegister(memreg)) {
			return true;
		}
	}

	return false;
}


bool Assembler::isMemoryAddress(string mem) {
	if (mem.front() == '[' && mem.back() == ']') {
		mem.replace(0, 1, "");
		mem.pop_back();
		if (mem.length() == 5 && isHexValue(mem)) {
			return true;
		}
	}

	return false;
}




bool Assembler::is8BitDisplacement(string op) {
	if (op.front() == '[' && op.back() == ']') {
		op.replace(0, 1, "");
		op.pop_back();
		if (isRegister(op.substr(0, 2)) && (op[2] == '+' || op[2] == '-')) {
			op.replace(0, 3, "");
			if (isHexValue(op) && op.length() == 2) {
				return true;
			}
		}
	}
	return false;
}


bool Assembler::is16BitDisplacement(string op) {
	if (op.front() == '[' && op.back() == ']') {
		op.replace(0, 1, "");
		op.pop_back();
		if (isRegister(op.substr(0, 2)) && (op[2] == '+' || op[2] == '-')) {
			op.replace(0, 3, "");
			if (isHexValue(op) && op.length() == 4) {
				return true;
			}
		}
	}
	return false;
}


