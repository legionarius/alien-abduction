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
		motion.y = direction.y * std::abs(impulse) * _jump_force.y;
		animationPlayer->play("JumpToWall");

		if(isScaleXInversed) {
			motion.x = - direction.x * (_jump_force.x * std::abs(impulse));

			if (direction.x > 0) {
				// Gauche
				if (isOrientedRight){
					_flip_player();
					isOrientedRight = false;
				}
			}

			else if (direction.x < 0) {
				// Droite
				if (!isOrientedRight){
					_flip_player();
					isOrientedRight = true;
				}
			}
		} else {
			motion.x = direction.x * (_jump_force.x * std::abs(impulse));

			if (direction.x < 0) {
				//Gauche
				if (isOrientedRight){
					_flip_player();
					isOrientedRight = false;
				}
			}

			else if (direction.x > 0) {
				// Droite
				if (!isOrientedRight){
					_flip_player();
					isOrientedRight = true;
				}
			}
		}
	}

	if (is_on_wall() && apply_impulse) {
		motion.y += _bubble_gravity;
	} else if (is_on_wall() && !apply_impulse) {
		animationPlayer->play("WalkOnWall");
		motion.y = _climb_speed;
		motion.x = direction.x;
	} else {
		motion.y += _gravity;
	}

	if (cliffhanger) {
		// Give time to player to jump before
		// making him fall.
		if ((_cliffhanger_time += delta) > 0.5f) {
			Godot::print("AAAAAAH ADRIENNE !");
			motion.x = direction.x * -60.0;
			cliffhanger = false;
			_cliffhanger_time = 0;
		}
	}
	// Player is stopped on floor
	else if (is_on_floor() && !apply_impulse) {
		motion.x = 0;
		animationPlayer->play("Idle");
	}

	move_and_slide(motion, floor);

	if (apply_impulse) {
		// Reset Cliffhanger
		cliffhanger = false;
		_cliffhanger_time = 0;
		// Reset Impulse
		apply_impulse = false;
		impulse = 0.0;
		impulse_time = 0.0;
	}
}

void Player::reset_position() {
	motion.x = 0;
	set_position(Vector2::ZERO);
}
void Player::_flip_player() {
	this->apply_scale(Vector2(-1,1));
	isScaleXInversed = !isScaleXInversed;
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
	_cliffhanger_time = 0;
	_jump_force = Vector2(800.0, 1200.0);
}

void Player::_ready() {
	bubbleControl = Object::cast_to<BubbleControl>(get_node("CollisionShape2D/Bubble"));
	animationPlayer = Object::cast_to<AnimationPlayer>(get_node("AnimationPlayer"));
	animationPlayer->play("Idle");
	Area2D *area2d = Object::cast_to<Area2D>(get_parent()->get_parent()->get_node("CliffhangerArea"));
	area2d->connect("body_entered", this, "_activate_cliffhanger");
}

void Player::_activate_cliffhanger() {
	cliffhanger = true;
	Godot::print("CLIFFHANGER YIPIKAY MOTHERFUCKER !");
}

void Player::_register_methods() {
	register_method("_init", &Player::_init);
	register_method("_ready", &Player::_ready);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_input", &Player::_input);
	register_method("reset_position", &Player::reset_position);
	register_method("_activate_cliffhanger", &Player::_activate_cliffhanger);
	register_property("gravity", &Player::_gravity, 30.f);
	register_property("inertia", &Player::_inertia, 2.f);
	register_property("climb_speed", &Player::_climb_speed, -150.f);
	register_property("jump_force", &Player::_jump_force, Vector2(800.0, 1200.0));
}
