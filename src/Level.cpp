//
// Created by bogdan on 27/02/2021.
//

#include "Level.h"

using namespace godot;

void Level::_init() {
	is_started = false;
}

void Level::_ready() {
	Godot::print("Level ready");
	Area2D *startZone = Object::cast_to<Area2D>(get_node("StartZone"));
	Area2D *finishZone = Object::cast_to<Area2D>(get_node("FinishZone"));
	startZone->connect("body_entered", this, "_start_level");
	finishZone->connect("body_entered", this, "_finish_level");
}

void Level::_start_level() {
	if (!is_started) {
		is_started = true;
		emit_signal("level_started");
	}
}

void Level::_finish_level() {
	emit_signal("level_finished");
}

void Level::_register_methods() {
	register_method("_init", &Level::_init);
	register_method("_ready", &Level::_ready);
	register_method("_start_level", &Level::_start_level);
	register_method("_finish_level", &Level::_finish_level);
	register_signal<Level>("level_started");
	register_signal<Level>("level_finished");
}
