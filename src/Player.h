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
#include <Ref.hpp>

namespace godot {

class Player : public KinematicBody2D {
	GODOT_CLASS(Player, KinematicBody2D);

	BubbleControl *bubbleControl;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
	void _process(const real_t delta);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_PLAYER_H
