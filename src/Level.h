//
// Created by bogdan on 27/02/2021.
//

#ifndef WEEKLY_GAMEJAM_190_LEVEL_H
#define WEEKLY_GAMEJAM_190_LEVEL_H

#include <Area2D.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
class Level : public Node2D {
	GODOT_CLASS(Level, Node);

	bool is_started;

public:
	void _finish_level();

	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //WEEKLY_GAMEJAM_190_LEVEL_H
