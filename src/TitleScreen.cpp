//
// Created by bogdan on 24/02/2021.
//

#include "TitleScreen.h"

using namespace godot;

void TitleScreen::_init() {
}

void TitleScreen::_ready() {
	Button *exitBtn = cast_to<Button>(get_node("VBoxContainer/Exit"));
	Button *startBtn = cast_to<Button>(get_node("VBoxContainer/Start"));
	GameState *gameState = cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	sound = cast_to<AudioStreamPlayer>(get_node("Sound"));
	exitBtn->connect("pressed", this, "_exit");
	startBtn->connect("pressed", this, "_start");
	gameState->connect("update_volume", this, "_update_sound_volume");
}

void TitleScreen::_exit() {
	get_tree()->quit();
}

void TitleScreen::_start() {
	get_tree()->change_scene("entity/MainScene/MainScene.tscn");
}

void TitleScreen::_input(const Ref<InputEvent> event) {
	Ref<InputEventKey> event_key = event;
	// Escape code taken from keyboard.h in Godot
	// TODO : include file in project
	if (event_key.is_valid() && event_key->is_pressed() && event_key->get_scancode() == ((1 << 24) | 0x01)) {
		_exit();
	}
}

void TitleScreen::_update_sound_volume(float_t volume) {
	sound->set_volume_db(volume);
}

void TitleScreen::_register_methods() {
	register_method("_init", &TitleScreen::_init);
	register_method("_ready", &TitleScreen::_ready);
	register_method("_exit", &TitleScreen::_exit);
	register_method("_start", &TitleScreen::_start);
	register_method("_input", &TitleScreen::_input);
	register_method("_update_sound_volume", &TitleScreen::_update_sound_volume);
}
