//
// Created by acroquelois on 08/05/2021.
//

#include "Settings.h"

using namespace godot;

void Settings::_init() {

}

void Settings::_ready() {
	soundSlider = cast_to<Slider>(get_node("SoundSlider"));
	gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	soundSlider->connect("value_changed", this, "_update_volume");
}

void Settings::_update_volume(float_t volume) {
	gameState->_update_sound_volume(volume);
}

void Settings::_register_methods() {
	register_method("_init", &Settings::_init);
	register_method("_ready", &Settings::_ready);
	register_method("_update_volume", &Settings::_update_volume);
}