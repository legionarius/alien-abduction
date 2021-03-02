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

void Player::_physics_process(const real_t delta) {
	if (generate_impulse) {
		impulse_time += delta;
		impulse = Math::sin(impulse_time + delta);
		bubbleControl->_set_oscillation(impulse);
	}

	if (apply_impulse) {
		direction = get_local_mouse_position().normalized();
		motion.x = direction.x * (_jump_force.x * std::abs(impulse));
		motion.y = direction.y * std::abs(impulse) * _jump_force.y;
		apply_impulse = false;
		impulse = 0.0;
		impulse_time = 0.0;
	}

	motion.y += _gravity;
	motion.x -= motion.x * _inertia * std::abs(direction.x) * delta;

	move_and_slide(motion, floor);
}

void Player::_init() {
	impulse = 0.0;
	impulse_time = 0.0;
	motion = Vector2(0, 0);
	direction = Vector2(0, 0);
	apply_impulse = false;
	generate_impulse = false;
	_gravity = 30;
	_inertia = 2.0;
	_jump_force = Vector2(600.0, 1000.0);
}

void Player::_ready() {
	bubbleControl = Object::cast_to<BubbleControl>(get_node("CollisionShape2D/Bubble"));
}

void Player::_register_methods() {
	register_method("_init", &Player::_init);
	register_method("_ready", &Player::_ready);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_input", &Player::_input);
	register_property("gravity", &Player::_gravity, 30.f);
	register_property("inertia", &Player::_inertia, 2.f);
	register_property("jump_force", &Player::_jump_force, Vector2(600.0, 1000.0));
}
