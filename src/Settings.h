//
// Created by acroquelois on 08/05/2021.
//

#ifndef WEEKLY_GAMEJAM_190_SETTINGS_H
#define WEEKLY_GAMEJAM_190_SETTINGS_H

#include "GameState.h"

#include <Control.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Slider.hpp>
#include <Viewport.hpp>

namespace godot {

class Settings : public Control {
	GODOT_CLASS(Settings, Control);

	GameState *gameState;
	Slider *soundSlider;
public:

	static void _register_methods();
	void _init();
	void _ready();
	void _update_volume(float_t volume);
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_SETTINGS_H
