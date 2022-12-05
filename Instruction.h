#pragma once
#include <string>
using std::string;



class Instruction
{
public:
	string opcode, d, w, mod, reg, r_m, displacement, data;

	Instruction();
	Instruction(string, string, string, string, string, string, string, string);
	void clear();
};




Instruction::Instruction() {
	opcode = "";
	d = "";
	w = "";
	mod = "";
	reg = "";
	r_m = "";
	displacement = "";
	data = "";
}


Instruction::Instruction(string opcode, string d, string w, string mod, string reg, string r_m, string displacement, string data) {
	this->opcode = opcode;
	this->d = d;
	this->w = w;
	this->mod = mod;
	this->reg = reg;
	this->r_m = r_m;
	this->displacement = displacement;
	this->data = data;
}


void Instruction::clear() {
	opcode.clear();
	d.clear();
	w.clear();
	mod.clear();
	reg.clear();
	r_m.clear();
	displacement.clear();
	data.clear();
}
