//
// Created by acroquelois on 01/03/2021.
//

#include "Camera.h"
#include "Player.h"

using namespace godot;

void Camera::_init() {
}

void Camera::_ready() {
}

void Camera::_process(const real_t delta) {
	auto *playerParentNode = (get_tree()->get_root()->get_node("World/Level")->get_child(0)->get_node("PlayerStart"));
	if (playerParentNode != nullptr) {
		if (playerParentNode->get_child_count() != 0) {
			Player *player = Object::cast_to<Player>(playerParentNode->get_child(0));
			this->set_position(player->get_position());
		}
	}
}

void Camera::_register_methods() {
	register_method("_process", &Camera::_process);
	register_method("_ready", &Camera::_ready);
	register_method("_init", &Camera::_init);
}