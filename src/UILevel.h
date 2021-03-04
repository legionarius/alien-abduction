//
// Created by nahalu on 03/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_UILEVEL_H
#define WEEKLY_GAMEJAM_190_UILEVEL_H

#include "GameState.h"
#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>

namespace godot {

class UILevel : public Control {
	GODOT_CLASS(UILevel, Control);

	UILevel *uiLevel;
	Label *label;
	GameState *gameState;
	int level_id;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(const real_t delta);
	void _incrementLevel();
};
} // namespace godot
#endif //WEEKLY_GAMEJAM_190_UILEVEL_H
