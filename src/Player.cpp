//
// Created by bogdan on 27/02/2021.
//

#include "Player.h"

using namespace godot;

void Player::_input(const Ref<InputEvent> event) {
	Ref<InputEventMouseButton> event_mouse = event;
	if (event_mouse.is_valid() && event_mouse->get_button_index() == 1 && event_mouse->is_pressed()) {
		Godot::print("Show Bubble");
		bubbleControl->_appear();
	} else if (event_mouse.is_valid() && event_mouse->get_button_index() == 1 && !event_mouse->is_pressed()) {
		Godot::print("Hide Bubble");
		bubbleControl->_disappear();
	}
}
void Player::_process(const real_t delta) {
}
void Player::_init() {
}

void Player::_ready() {
	bubbleControl = Object::cast_to<BubbleControl>(get_node("CollisionShape2D/Bubble"));
}

void Player::_register_methods() {
	register_method("_init", &Player::_init);
	register_method("_ready", &Player::_ready);
	register_method("_process", &Player::_process);
	register_method("_input", &Player::_input);
}
