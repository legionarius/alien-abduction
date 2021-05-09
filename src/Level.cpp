//
// Created by bogdan on 27/02/2021.
//

#include "Level.h"

using namespace godot;

void Level::_init() {
	is_started = false;
}

void Level::_ready() {
	Area2D *finishZone = Object::cast_to<Area2D>(get_node("FinishZone"));
	finishZone->connect("body_entered", this, "_finish_level");
}

void Level::_finish_level() {
	emit_signal("level_finished");
}

void Level::_register_methods() {
	register_method("_init", &Level::_init);
	register_method("_ready", &Level::_ready);
	register_method("_finish_level", &Level::_finish_level);
	register_signal<Level>("level_finished");
}
