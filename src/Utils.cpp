//
// Created by bogdan on 27/02/2021.
//

#include "Utils.h"

using namespace godot;

const String Utils::gdt_string(int value) {
	return String(std::to_string(value).c_str());
}

const String Utils::gdt_string(uint16_t value) {
	return String(std::to_string(value).c_str());
}

const String Utils::gdt_string(real_t value) {
	return String(std::to_string(value).c_str());
}
