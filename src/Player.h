//
// Created by bogdan on 27/02/2021.
//

#ifndef WEEKLY_GAMEJAM_190_PLAYER_H
#define WEEKLY_GAMEJAM_190_PLAYER_H

#include "BubbleControl.h"
#include <AnimationPlayer.hpp>
#include <Area2D.hpp>
#include <Godot.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <InputEventMouseButton.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <Math.hpp>
#include <Position2D.hpp>
#include <Ref.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

namespace godot {

class Player : public KinematicBody2D {
	GODOT_CLASS(Player, KinematicBody2D);

	BubbleControl *bubbleControl;
	AnimationPlayer *animationPlayer;
	bool cliffhanger;
	real_t _cliffhanger_time;
	real_t impulse_time;
	real_t impulse;
	bool generate_impulse;
	bool apply_impulse;
	Vector2 motion;
	Vector2 direction;
	Vector2 scale;
	real_t _gravity;
	real_t _bubble_gravity;
	real_t _inertia;
	Vector2 _jump_force;
	real_t _climb_speed;
	const Vector2 floor = Vector2(0, -1);

public:
	void reset_position();
	void _activate_cliffhanger();

	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
	void _physics_process(const real_t delta);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_PLAYER_H
