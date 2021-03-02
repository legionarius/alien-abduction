//
// Created by acroquelois on 01/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_CAMERA_H
#define WEEKLY_GAMEJAM_190_CAMERA_H

#include <Camera2D.hpp>
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

#include "GameState.h"
#include "Player.h"

namespace godot {

class Camera : public Camera2D {
	GODOT_CLASS(Camera, Camera2D);

	real_t _shift_from_bottom;
	GameState *_gameState;
	Player *_player;

public:
	void _start_focus_player();
	void _end_focus_player();

	// Godot methods
	static void _register_methods();
	void _init();
	void _ready();
	void _process(const real_t delta);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_CAMERA_H
