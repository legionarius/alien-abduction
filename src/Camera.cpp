//
// Created by acroquelois on 01/03/2021.
//

#include "Camera.h"

using namespace godot;

void Camera::_init() {
	_shift_from_bottom = 200;
}

void Camera::_ready() {
	GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	if (gameState != nullptr) {
		gameState->connect("camera_start_focus", this, "_start_focus_player");
		gameState->connect("camera_end_focus", this, "_end_focus_player");
	}
	Area2D *outLeft = Object::cast_to<Area2D>(get_node("OutLeft"));
	Area2D *outRight = Object::cast_to<Area2D>(get_node("OutRight"));
	outLeft->connect("body_entered", this, "_player_out");
	outRight->connect("body_entered", this, "_player_out");
}

void Camera::_process(const real_t delta) {
	if (_player != nullptr && _player->is_visible()) {
		Vector2 newPosition = Vector2(get_position().x, _player->get_global_position().y - _shift_from_bottom);
		set_position(newPosition);
	}
}

void Camera::_start_focus_player() {
	auto *playerParentNode = get_tree()->get_root()->get_node("World/Level")->get_child(0)->get_node("PlayerStart");
	if (playerParentNode != nullptr) {
		if (playerParentNode->get_child_count() != 0) {
			_player = Object::cast_to<Player>(playerParentNode->get_child(0));
			set_position(Vector2(_player->get_global_position().x, get_position().y));
		}
	}
}

void Camera::_end_focus_player() {
	_player = nullptr;
}

void Camera::_player_out(Node *node) {
	Player *player = Object::cast_to<Player>(node);
	if (player != nullptr) {
		_player->reset_position();
	}
}

void Camera::_register_methods() {
	register_method("_process", &Camera::_process);
	register_method("_ready", &Camera::_ready);
	register_method("_init", &Camera::_init);
	register_method("_start_focus_player", &Camera::_start_focus_player);
	register_method("_end_focus_player", &Camera::_end_focus_player);
	register_method("_player_out", &Camera::_player_out);
}