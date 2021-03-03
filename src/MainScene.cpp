//
// Created by bogdan on 02/03/2021.
//

#include "MainScene.h"

using namespace godot;

void MainScene::_init() {}

void MainScene::_ready() {
	auto gameState = Object::cast_to<GameState>(get_node("/root/GameState"));
	gameState->_start_game();
}

void MainScene::_register_methods() {
	register_method("_init", &MainScene::_init);
	register_method("_ready", &MainScene::_ready);
}
