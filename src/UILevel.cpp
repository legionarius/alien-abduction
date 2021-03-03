//
// Created by nahalu on 03/03/2021.
//

#include "UILevel.h"

using namespace godot;

void UILevel::_init() {}

void UILevel::_process(const real_t delta) {}

void UILevel::_ready() {
	level_id = 0;
	label = Object::cast_to<Label>(get_node("UILevelLabel"));
	gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	if (gameState != nullptr) {
		gameState->connect("_increment_level", this, "_incrementLevel");
	}
}

void UILevel::_incrementLevel() {
	level_id++;

	std::stringstream s_string;
	s_string << "Level " << level_id;
	std::string test = s_string.str();
	label->set_text(test.c_str());
}

void UILevel::_register_methods() {
	register_method("_init", &UILevel::_init);
	register_method("_ready", &UILevel::_ready);
	register_method("_process", &UILevel::_process);
	register_method("_incrementLevel", &UILevel::_incrementLevel);
	register_signal<UILevel>("_increment_level");
}