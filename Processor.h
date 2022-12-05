#pragma once
#include <string>
#include <vector>
#include "Memory.h"
#include "Register.h"
#include "Assembler.h"
#include "Instruction.h"
#include "BaseConversion.h"
using std::string;
using std::vector;


class Processor
{
private:
	Memory memory;
	Register AX, BX, CX, DX, SP, BP, SI, DI;
	bool CF, OF;
	Assembler assembler;
	vector<Instruction> instructions;
	int PC;

public:
	Processor();
	string getDataFromMemory(string);
	string getRegisterData2(string);
	string getFlagData(string);
	string getMachineCode();

	void setRegisterData(string, string, string);
	string getRegisterData(string, string);

	void Assemble(string);
	void Execute();
	void ExecuteAll();
	void mov();
	void add();
	void and();
	void or();
	void xor();
	void not();
	void inc();
	void neg();
	void shl();
	void shr();
	void rol();
	void ror();
	void clc();
	void Reset();
};





Processor::Processor() {
	CF = 0;
	OF = 0;
	PC = 0;
}



string Processor::getDataFromMemory(string address) {
	return memory.Read(address);
}


string Processor::getRegisterData2(string reg) {
	if (reg == "AX") {
		return AX.data;
	}
	else if (reg == "BX") {
		return BX.data;
	}
	else if (reg == "CX") {
		return CX.data;
	}
	else if (reg == "DX") {
		return DX.data;
	}
	else if (reg == "SP") {
		return SP.data;
	}
	else if (reg == "BP") {
		return BP.data;
	}
	else if (reg == "SI") {
		return SI.data;
	}
	else if (reg == "DI") {
		return DI.data;
	}
	return "";
}


string Processor::getFlagData(string flag) {
	if (flag == "CF") {
		return CF ? "1" : "0";
	}
	else if (flag == "OF") {
		return OF ? "1" : "0";
	}
	return "";
}


string Processor::getMachineCode() {
	return assembler.MachineCode;
}





void Processor::Assemble(string AssemblyCode) {
	PC = 0;
	assembler.ConvertToMachineCode(AssemblyCode, instructions);
}



void Processor::ExecuteAll() {
	PC = 0;
	for (int i = 0; i < instructions.size(); i++) {
		Execute();
	}
}


void Processor::Execute() {
	if (PC >= instructions.size()) {
		throw "No more instructions to execute.";
	}

	if (instructions[PC].opcode == "000000") {
		mov();
	}
	else if (instructions[PC].opcode == "000001") {
		add();
	}
	else if (instructions[PC].opcode == "000010") {
		rol();
	}
	else if (instructions[PC].opcode == "000110") {
		and();
	}
	else if (instructions[PC].opcode == "000111") {
		or();
	}
	else if (instructions[PC].opcode == "000111") {
		or ();
	}
	else if (instructions[PC].opcode == "001000") {
		xor();
	}
	else if (instructions[PC].opcode == "001001") {
		not();
	}
	else if (instructions[PC].opcode == "001101") {
		neg();
	}
	else if (instructions[PC].opcode == "001011") {
		shl();
	}
	else if (instructions[PC].opcode == "001010") {
		shr();
	}
	else if (instructions[PC].opcode == "000100") {
		ror();
	}
	else if (instructions[PC].opcode == "001110") {
		clc();
	}
	PC++;
}



void Processor::clc() {
	CF = 0;
}


void Processor::mov() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp= instructions[PC].displacement;
	data = instructions[PC].data;

	//Immediate
	if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
	
		data = BinToHex(byte1 + byte2);
		setRegisterData(data, reg, w);
	}
	//Register Indirect (Memory by register).
	else if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		if (d == "0") {
			data = getRegisterData(reg, w);
			memory.Write(address, data);
		}
		else {
			data = memory.Read(address);
			setRegisterData(data, reg, w);
		}
	}
	//No displacement.
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);
		
		while (address.length() < 5) {
			address = '0' + address;
		}
		if (d == "0") {
			memory.Write(address, getRegisterData(reg, w));
		}
		else {
			setRegisterData(memory.Read(address), reg, w);
		}
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		if (d == "0") {
			memory.Write(address, getRegisterData(reg, w));
		}
		else {
			setRegisterData(memory.Read(address), reg, w);
		}
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));

		if (d == "0") {
			memory.Write(address, getRegisterData(reg, w));
		}
		else {
			setRegisterData(memory.Read(address), reg, w);
		}
	}
	//r_m is a register.
	else if (mod == "11") {
		setRegisterData(getRegisterData(r_m, w), reg, w);
	}
}



void Processor::add() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;
	
	//Immediate
	if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		
		data = BinToHex(byte1 + byte2);
		data = Add_Hex(data, getRegisterData(reg, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		setRegisterData(data, reg, w);
	}
	//Register Indirect (Memory by register).
	else if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = Add_Hex(memory.Read(address), getRegisterData(reg, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//No displacement.
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);
		while (address.length() < 5) {
			address = '0' + address;
		}
		data = Add_Hex(memory.Read(address), getRegisterData(reg, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = '0' + Add_Hex(memory.Read(address), getRegisterData(reg, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = Add_Hex(memory.Read(address), getRegisterData(reg, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		if (d == "0") {
			memory.Write(address, getRegisterData(reg, w));
		}
		else {
			setRegisterData(memory.Read(address), reg, w);
		}
	}
	//r_m is a register.
	else if (mod == "11") {
		data = Add_Hex(getRegisterData(reg, w), getRegisterData(r_m, w));
		if (w == "0" && data.length() > 2) {
			data.replace(0, 1, "");
		}
		else if (w == "1" && data.length() > 4) {
			data.replace(0, 1, "");
		}
		setRegisterData(data, reg, w);
	}
}






void Processor::and() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	//Immediate
	if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);

		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), byte1+byte2);
		setRegisterData(BinToHex(data), reg, w);
	}
	//Register Indirect (Memory by register).
	else if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//No displacement.
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);

		while (address.length() < 5) {
			address = '0' + address;
		}
		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//r_m is a register.
	else if (mod == "11") {
		data = BitwiseAND(HexToBin(getRegisterData(reg, w)), HexToBin(getRegisterData(r_m, w)));
		data = BinToHex(data);
		setRegisterData(getRegisterData(r_m, w), reg, w);
	}
}




void Processor:: or() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	//Immediate
	if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);

		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), byte1 + byte2);
		setRegisterData(BinToHex(data), reg, w);
	}
	//Register Indirect (Memory by register).
	else if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//No displacement.
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);

		while (address.length() < 5) {
			address = '0' + address;
		}
		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//r_m is a register.
	else if (mod == "11") {
		data = BitwiseOR(HexToBin(getRegisterData(reg, w)), HexToBin(getRegisterData(r_m, w)));
		data = BinToHex(data);
		setRegisterData(getRegisterData(r_m, w), reg, w);
	}
}



void Processor:: xor() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	//Immediate
	if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);

		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), byte1 + byte2);
		setRegisterData(BinToHex(data), reg, w);
	}
	//Register Indirect (Memory by register).
	else if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//No displacement.
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);

		while (address.length() < 5) {
			address = '0' + address;
		}
		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), HexToBin(memory.Read(address)));
		data = BinToHex(data);
		if (d == "0") {
			memory.Write(address, data);
		}
		else {
			setRegisterData(data, reg, w);
		}
	}
	//r_m is a register.
	else if (mod == "11") {
		data = BitwiseXOR(HexToBin(getRegisterData(reg, w)), HexToBin(getRegisterData(r_m, w)));
		data = BinToHex(data);
		setRegisterData(getRegisterData(r_m, w), reg, w);
	}
}



void Processor::inc() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	//Register Indirect (Memory by register).
	if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = Add_Hex(memory.Read(address), "1");
		memory.Write(address, data);
	}
	//direct [1234h] 
	else if (mod == "00" && !disp.empty()) {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);
		while (address.length() < 5) {
			address = '0' + address;
		}
		data = Add_Hex(memory.Read(address), "1");
		memory.Write(address, data);
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = "0" + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = Add_Hex(memory.Read(address), "1");
		memory.Write(address, data);
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = "0" + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = Add_Hex(memory.Read(address), "1");
		memory.Write(address, data);
	}
	//register
	else if (mod == "11") {
		data = Add_Hex(getRegisterData(r_m, w), "1");
		//System::Windows::Forms::MessageBox::Show(toSystemString(data));
		setRegisterData(data, reg, w);
	}
}




void Processor::not() {
	string opcode, mod, d, w, reg, r_m, disp, data;
	string byte1, byte2, address;
	opcode = instructions[PC].opcode;
	d = instructions[PC].d;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	//Register Indirect (Memory by register).
	if (mod == "00" && disp.empty() && data.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = BitwiseNOT(HexToBin(memory.Read(address)));
		data = BinToHex(data);
		memory.Write(address, data);
	}
	//direct [1234h] 
	else if (mod == "00" && !disp.empty()) {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);
		while (address.length() < 5) {
			address = '0' + address;
		}
		data = BitwiseNOT(HexToBin(memory.Read(address)));
		data = BinToHex(data);
		memory.Write(address, data);
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = "0" + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = BitwiseNOT(HexToBin(memory.Read(address)));
		data = BinToHex(data);
		memory.Write(address, data);
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = "0" + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = BitwiseNOT(HexToBin(memory.Read(address)));
		data = BinToHex(data);
		memory.Write(address, data);
	}
	//register
	else if (mod == "11") {
		data = BitwiseNOT(HexToBin(getRegisterData(r_m, w)));
		data = BinToHex(data);
		setRegisterData(data, reg, w);
	}
}



void Processor::neg() {

	string opcode, mod, w, reg, r_m, disp;
	string byte1, byte2, address, data;
	opcode = instructions[PC].opcode;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;

	//Register Indirect (Memory by register).
	if (mod == "00" && disp.empty()) {
		address = '0' + getRegisterData(r_m, "1");
		data = BinToHex(TwosComplement(HexToBin(memory.Read(address))));
		if (data.length() > 4) {
			data.replace(0, 1, "");
		}
		memory.Write(address, data);
	}
	// no displacement
	else if (mod == "00") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = BinToHex(byte1 + byte2);

		while (address.length() < 5) {
			address = '0' + address;
		}
		data = BinToHex(TwosComplement(HexToBin(memory.Read(address))));
		if (data.length() > 4) {
			data.replace(0, 1, "");
		}
		memory.Write(address, data);
	}
	//8-bit displacement.
	else if (mod == "01") {
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(disp));
		data = BinToHex(TwosComplement(HexToBin(memory.Read(address))));
		if (data.length() > 4) {
			data.replace(0, 1, "");
		}
		memory.Write(address, data);
	}
	//16-bit displacement.
	else if (mod == "10") {
		byte1 = disp.substr(9, 8);
		byte2 = disp.substr(0, 8);
		address = '0' + Add_Hex(getRegisterData(r_m, "1"), BinToHex(byte1 + byte2));
		data = BinToHex(TwosComplement(HexToBin(memory.Read(address))));
		if (data.length() > 4) {
			data.replace(0, 1, "");
		}
		memory.Write(address, data);
	}
	//Register.
	else if (mod == "11") {
		data = BinToHex(TwosComplement(HexToBin(getRegisterData(r_m, w))));
		if (data.length() > 4) {
			data.replace(0, 1, "");
		}
		setRegisterData(data, r_m, w);
	}
}




void Processor::shl() {
	string opcode, mod, w, reg, r_m, disp;
	string byte1, byte2, address, data, shifted_data;
	int cldata;
	opcode = instructions[PC].opcode;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	if (mod == "11" && data.empty()) {
		shifted_data = HexToBin(getRegisterData(r_m, w));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			if (shifted_data[0] == '0') {
				CF = 0;
			}
			else {
				CF = 1;
			}
			shifted_data = ShiftLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "11" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		shifted_data = HexToBin(getRegisterData(r_m, w));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			if (shifted_data[0] == '0') {
				CF = 0;
			}
			else {
				CF = 1;
			}
			shifted_data = ShiftLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "00" && data.empty()) {
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			if (shifted_data[0] == '0') {
				CF = 0;
			}
			else {
				CF = 1;
			}
			shifted_data = ShiftLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
	else if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			if (shifted_data[0] == '0') {
				CF = 0;
			}
			else {
				CF = 1;
			}
			shifted_data = ShiftLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
}



void Processor::shr() {
	string opcode, mod, w, reg, r_m, disp;
	string byte1, byte2, address, data, shifted_data;
	int cldata;
	opcode = instructions[PC].opcode;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	if (mod == "11" && data.empty()) {
		shifted_data = HexToBin(getRegisterData(r_m, w));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = ShiftRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "11" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		shifted_data = HexToBin(getRegisterData(r_m, w));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = ShiftRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "00" && data.empty()) {
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = ShiftRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
	else if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = ShiftRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
}



void Processor::rol() {
	string opcode, mod, w, reg, r_m, disp;
	string byte1, byte2, address, data, shifted_data;
	int cldata;
	opcode = instructions[PC].opcode;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	if (mod == "11" && data.empty()) {
		shifted_data = HexToBin(getRegisterData(r_m, w));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = RotateLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "11" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		shifted_data = HexToBin(getRegisterData(r_m, w));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = RotateLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "00" && data.empty()) {
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = RotateLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
	else if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = RotateLeft(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
}



void Processor::ror() {
	string opcode, mod, w, reg, r_m, disp;
	string byte1, byte2, address, data, shifted_data;
	int cldata;
	opcode = instructions[PC].opcode;
	w = instructions[PC].w;
	mod = instructions[PC].mod;
	reg = instructions[PC].reg;
	r_m = instructions[PC].r_m;
	disp = instructions[PC].displacement;
	data = instructions[PC].data;

	if (mod == "11" && data.empty()) {
		shifted_data = HexToBin(getRegisterData(r_m, w));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = RotateRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "11" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		shifted_data = HexToBin(getRegisterData(r_m, w));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = RotateRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		setRegisterData(shifted_data, r_m, w);
	}
	else if (mod == "00" && data.empty()) {
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		cldata = HexToDec(getRegisterData("001", "0"));
		for (int i = 0; i < cldata; i++) {
			shifted_data = RotateRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
	else if (mod == "00" && !data.empty()) {
		byte1 = data.substr(9, 8);
		byte2 = data.substr(0, 8);
		data = byte1 + byte2;
		address = '0' + getRegisterData(r_m, w);
		shifted_data = HexToBin(memory.Read(address));
		for (int i = 0; i < HexToDec(BinToHex(data)); i++) {
			shifted_data = RotateRight(shifted_data);
		}
		shifted_data = BinToHex(shifted_data);
		memory.Write(address, shifted_data);
	}
}




void Processor::setRegisterData(string data, string regcode, string w) {
	if (regcode == "000") {
		if (w == "0") {
			AX.setLowerByte(data);
		}
		else if (w == "1") {
			AX.setData(data);
		}
	}
	else if (regcode == "001") {
		if (w == "0") {
			CX.setLowerByte(data);
		}
		else if (w == "1") {
			CX.setData(data);
		}
	}
	else if (regcode == "010") {
		if (w == "0") {
			DX.setLowerByte(data);
		}
		else if (w == "1") {
			DX.setData(data);
		}
	}
	else if (regcode == "011") {
		if (w == "0") {
			BX.setLowerByte(data);
		}
		else if (w == "1") {
			BX.setData(data);
		}
	}
	else if (regcode == "100") {
		if (w == "0") {
			AX.setHigherByte(data);
		}
		else if (w == "1") {
			SP.setData(data);
		}
	}
	else if (regcode == "101") {
		if (w == "0") {
			CX.setHigherByte(data);
		}
		else if (w == "1") {
			BP.setData(data);
		}
	}
	else if (regcode == "110") {
		if (w == "0") {
			DX.setHigherByte(data);
		}
		else if (w == "1") {
			SI.setData(data);
		}
	}
	else if (regcode == "111") {
		if (w == "0") {
			BX.setHigherByte(data);
		}
		else if (w == "1") {
			DI.setData(data);
		}
	}
}



string Processor::getRegisterData(string regcode, string w) {
	if (regcode == "000") {
		if (w == "0") {
			return AX.getLowerByte();
		}
		else if (w == "1") {
			return AX.getData();
		}
	}
	else if (regcode == "001") {
		if (w == "0") {
			return CX.getLowerByte();
		}
		else if (w == "1") {
			return CX.getData();
		}
	}
	else if (regcode == "010") {
		if (w == "0") {
			return DX.getLowerByte();
		}
		else if (w == "1") {
			return DX.getData();
		}
	}
	else if (regcode == "011") {
		if (w == "0") {
			return BX.getLowerByte();
		}
		else if (w == "1") {
			return BX.getData();
		}
	}
	else if (regcode == "100") {
		if (w == "0") {
			return AX.getHigherByte();
		}
		else if (w == "1") {
			return SP.getData();
		}
	}
	else if (regcode == "101") {
		if (w == "0") {
			return CX.getHigherByte();
		}
		else if (w == "1") {
			return BP.getData();
		}
	}
	else if (regcode == "110") {
		if (w == "0") {
			return DX.getHigherByte();
		}
		else if (w == "1") {
			return SI.getData();
		}
	}
	else if (regcode == "111") {
		if (w == "0") {
			return BX.getHigherByte();
		}
		else if (w == "1") {
			return DI.getData();
		}
	}
	return "";
}



void Processor::Reset() {
	AX.setData("0000");
	BX.setData("0000");
	CX.setData("0000");
	DX.setData("0000");
	SP.setData("0000");
	BP.setData("0000");
	SI.setData("0000");
	DI.setData("0000");

	CF = 0;
	OF = 0;
	
	for (int i = 0; i < 10; i++) {
		memory.Write("0000" + std::to_string(i), "0000");
	}
	memory.Write("0000A", "0000");
	memory.Write("0000B", "0000");
	memory.Write("0000C", "0000");
	memory.Write("0000D", "0000");
	memory.Write("0000E", "0000");
	memory.Write("0000F", "0000");
}