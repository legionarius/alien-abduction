//
// Created by bogdan on 02/03/2021.
//

#include "FadeScreen.h"

using namespace godot;

void godot::FadeScreen::_init() {
}

void FadeScreen::fade_to_black() {
	play("fade_in_fade_out");
}

void godot::FadeScreen::_register_methods() {
	register_method("_init", &FadeScreen::_init);
}
