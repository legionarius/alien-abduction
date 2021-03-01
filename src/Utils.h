//
// Created by bogdan on 27/02/2021.
//

#ifndef WEEKLY_GAMEJAM_190_UTILS_H
#define WEEKLY_GAMEJAM_190_UTILS_H

#include <Godot.hpp>
#include <String.hpp>

namespace godot {
class Utils {
public:
	static const String gdt_string(int value);
	static const String gdt_string(uint16_t value);
	static const String gdt_string(real_t value);
};
} // namespace godot

#endif //WEEKLY_GAMEJAM_190_UTILS_H
