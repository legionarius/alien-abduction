//
// Created by acroquelois on 01/03/2021.
//

#include "Camera.h"

using namespace godot;

void Camera::_init() {
	_shift_from_bottom = 200;
}

void Camera::_ready() {
	_gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	if (_gameState != nullptr) {
		Godot::print("Gamestate found");
		_gameState->connect("level_started", this, "_start_focus_player");
	}
}

void Camera::_process(const real_t delta) {
	if (_player != nullptr) {
		Vector2 newPosition = Vector2(_player->get_global_position().x, _player->get_global_position().y - _shift_from_bottom);
		this->set_position(newPosition);
	}
}

void Camera::_start_focus_player() {
	Godot::print("Start focus");
	auto *playerParentNode = (get_tree()->get_root()->get_node("World/Level")->get_child(0)->get_node("PlayerStart"));
	if (playerParentNode != nullptr) {
		if (playerParentNode->get_child_count() != 0) {
			_player = Object::cast_to<Player>(playerParentNode->get_child(0));
		}
	}
}

void Camera::_end_focus_player() {
	_player = nullptr;
}

void Camera::_register_methods() {
	register_method("_process", &Camera::_process);
	register_method("_ready", &Camera::_ready);
	register_method("_init", &Camera::_init);
	register_method("_start_focus_player", &Camera::_start_focus_player);
	register_method("_end_focus_player", &Camera::_end_focus_player);
}