//
// Created by bogdan on 27/02/2021.
//

#ifndef WEEKLY_GAMEJAM_190_PLAYER_H
#define WEEKLY_GAMEJAM_190_PLAYER_H

#include "BubbleControl.h"
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
#include <VisibilityEnabler2D.hpp>

namespace godot {

class Player : public KinematicBody2D {
	GODOT_CLASS(Player, KinematicBody2D);

	BubbleControl *bubbleControl;
	VisibilityEnabler2D *visibilityNotifier2D;
	real_t impulse_time;
	real_t impulse;
	bool generate_impulse;
	bool apply_impulse;
	Vector2 motion;
	Vector2 direction;
	float _gravity;
	float _inertia;
	Vector2 _jump_force;
	const Vector2 floor = Vector2(0, -1);

public:
	void _not_visible_anymore();

	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
	void _physics_process(const real_t delta);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_PLAYER_H
