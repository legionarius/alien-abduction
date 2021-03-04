//
// Created by nahalu on 04/03/2021.
//

#include "TransitionScreen.h"

using namespace godot;

void TransitionScreen::_init() {}

void TransitionScreen::_ready() {
	label = Object::cast_to<Label>(get_tree()->get_root()->get_node("World/Camera2D/GameTimer/GameTimerLabel"));
	gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	labelTransition = Object::cast_to<Label>(get_node("TransitionLabel"));
	if (gameState != nullptr) {
		gameState->connect("_show_transition_screen", this, "show_transition_screen");
	}
}

void TransitionScreen::show_transition_screen() {
	if (label != nullptr && labelTransition != nullptr) {
		Godot::print(label->get_text());
		labelTransition->set_text(label->get_text());
	}
	play("transition_screen");
}

void TransitionScreen::_register_methods() {
	register_method("_init", &TransitionScreen::_init);
	register_method("_ready", &TransitionScreen::_ready);
	register_method("show_transition_screen", &TransitionScreen::show_transition_screen);
}