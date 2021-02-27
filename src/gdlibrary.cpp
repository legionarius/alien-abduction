//
// Created by bogdan on 11/02/2021.
//

#include "BubbleControl.h"
#include "GameState.h"
#include "Player.h"
#include "Level.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT
godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);
	godot::register_class<godot::BubbleControl>();
	godot::register_class<godot::GameState>();
	godot::register_class<godot::Level>();
	godot::register_class<godot::Player>();
}