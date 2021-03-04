//
// Created by nahalu on 04/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_TRANSITIONSCREEN_H
#define WEEKLY_GAMEJAM_190_TRANSITIONSCREEN_H

#include "GameState.h"
#include "UILevel.h"
#include <AnimationPlayer.hpp>
#include <Godot.hpp>
#include <Label.hpp>

namespace godot {
class TransitionScreen : public AnimationPlayer {
	GODOT_CLASS(TransitionScreen, AnimationPlayer);

	GameState *gameState;
	Label *label;
	Label *labelTransition;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void show_transition_screen();
};
} // namespace godot
#endif //WEEKLY_GAMEJAM_190_TRANSITIONSCREEN_H
