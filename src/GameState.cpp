//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {}

void GameState::_input(const Ref<InputEvent> event) {}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_input", &GameState::_input);
}