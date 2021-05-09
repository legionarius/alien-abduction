//
// Created by bogdan on 02/03/2021.
//

#include "MainScene.h"

using namespace godot;

void MainScene::_init() {}

void MainScene::_ready() {
	auto gameState = cast_to<GameState>(get_node("/root/GameState"));
	AudioStreamPlayer *sound = cast_to<AudioStreamPlayer>(get_node("Sound"));
	sound->set_volume_db(gameState->_get_sound_volume());
	gameState->_start_game();
}

void MainScene::_register_methods() {
	register_method("_init", &MainScene::_init);
	register_method("_ready", &MainScene::_ready);
}
