//
// Created by acroquelois on 01/03/2021.
//

#include "Camera.h"
#include "Player.h"

using namespace godot;

void Camera::_init() {
	_shift_from_bottom = 200;
}

void Camera::_ready() {
	auto *gamestate = get_tree()->get_root()->get_node("Gamestate");
	gamestate->connect("level", )
}

void Camera::_process(const real_t delta) {
	auto *playerParentNode = (get_tree()->get_root()->get_node("World/Level")->get_child(0)->get_node("PlayerStart"));
	if (playerParentNode != nullptr) {
		if (playerParentNode->get_child_count() != 0) {
			Player *player = Object::cast_to<Player>(playerParentNode->get_child(0));
			Vector2 newPosition = Vector2(player->get_global_position().x, player->get_global_position().y - _shift_from_bottom);
			this->set_position(newPosition);
		}
	}
}

void Camera::_register_methods() {
	register_method("_process", &Camera::_process);
	register_method("_ready", &Camera::_ready);
	register_method("_init", &Camera::_init);
}