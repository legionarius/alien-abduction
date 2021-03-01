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

namespace godot {

class Camera : public Camera2D {
	GODOT_CLASS(Camera, Camera2D);

public:
	// Godot methods
	static void _register_methods();
	void _init();
	void _ready();
	void _process(const real_t delta);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_CAMERA_H
