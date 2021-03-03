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
	}

	if (is_on_wall() && apply_impulse) {
		motion.y += _bubble_gravity;
	} else if (is_on_wall() && !apply_impulse) {
		motion.y = _climb_speed;
		motion.x = direction.x;
	} else {
		motion.y += _gravity;
	}

	// Player should fall if colliding with a floor
	// different from the bottom floor.
	// Using -50 to be generous with the collision
	// detection time.
	if (is_on_floor() && get_position().y < -50.f) {
		motion.x = direction.x * -40.0;
	}
	// Player is stopped on floor
	else if (is_on_floor() && !apply_impulse) {
		motion.x = 0;
	}

	move_and_slide(motion, floor);

	// Reset Impulse
	if (apply_impulse) {
		apply_impulse = false;
		impulse = 0.0;
		impulse_time = 0.0;
	}
}

void Player::reset_position() {
	motion.x = 0;
	set_position(Vector2::ZERO);
}

void Player::_init() {
	impulse = 0.0;
	impulse_time = 0.0;
	motion = Vector2(0, 0);
	direction = Vector2(0, 0);
	apply_impulse = false;
	generate_impulse = false;
	_gravity = 30;
	_bubble_gravity = 10;
	_inertia = 2.0;
	_climb_speed = -150.0;
	_jump_force = Vector2(800.0, 1200.0);
}

void Player::_ready() {
	bubbleControl = Object::cast_to<BubbleControl>(get_node("CollisionShape2D/Bubble"));
}

void Player::_register_methods() {
	register_method("_init", &Player::_init);
	register_method("_ready", &Player::_ready);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_input", &Player::_input);
	register_method("reset_position", &Player::reset_position);
	register_property("gravity", &Player::_gravity, 30.f);
	register_property("inertia", &Player::_inertia, 2.f);
	register_property("climb_speed", &Player::_climb_speed, -150.f);
	register_property("jump_force", &Player::_jump_force, Vector2(800.0, 1200.0));
}
