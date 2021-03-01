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
		generate_impulse = true;
	} else if (event_mouse.is_valid() && event_mouse->get_button_index() == 1 && !event_mouse->is_pressed()) {
		Godot::print("Hide Bubble");
		bubbleControl->_disappear();
		apply_impulse = true;
		generate_impulse = false;
	}
}

void Player::_process(const real_t delta) {
	if (is_on_floor()) {
	}
	if (apply_impulse) {
		move_and_slide(Vector2(std::abs(impulse) * 5000.0, -1 * std::abs(impulse) * 5000.0), get_local_mouse_position());
		apply_impulse = false;
		impulse = 0.0;
		impulse_time = 0.0;
	}

	if (generate_impulse) {
		impulse_time += delta;
		impulse = Math::sin(impulse_time + delta);
		bubbleControl->_set_oscillation(impulse);
		Godot::print(Utils::gdt_string(impulse));
	}
}

void Player::_init() {
	impulse = 0.0;
	impulse_time = 0.0;
	apply_impulse = false;
	generate_impulse = false;
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
