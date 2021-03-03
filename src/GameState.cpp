//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {
	level_count = 1;
	current_level_id = 0;
}

void GameState::_ready() {}

void GameState::_input(const Ref<InputEvent> event) {
}

void GameState::_start_game() {
	_load_level();
	_spawn_player();
	is_started = true;
	emit_signal("_game_started");
}

void GameState::_load_level() {
	if (current_level_id < level_count) {
		_disconnect_level();
		_remove_level();
		current_level_id += 1;
		_add_level(current_level_id);
		_connect_level();
	} else {
		emit_signal("_game_finished");
	}
}

std::string GameState::_get_level_path(int level_id) {
	std::stringstream level_name;
	level_name << "entity/Levels/Level" << std::setw(2) << std::setfill('0') << current_level_id << ".tscn";
	return level_name.str();
}

void GameState::_add_level(int level_id) {
	auto level_path = _get_level_path(level_id);
	Ref<PackedScene> level_res = ResourceLoader::get_singleton()->load(level_path.c_str());
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	auto current_level = level_res->instance();
	level_node->add_child(current_level);
	emit_signal("_increment_level");
}

void GameState::_remove_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	if (level_node->get_child_count() > 0) {
		auto current_level = level_node->get_child(0);
		level_node->remove_child(current_level);
	} else {
		Godot::print("No level to remove");
	}
}

void GameState::_connect_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");

	//TODO:	level_node->get_child(0)->connect("level_started", this, );
	//TODO:	level_node->get_child(0)->connect("level_finished", this, );
}

void GameState::_disconnect_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	if (level_node->get_child_count() > 0) {
		auto current_level = level_node->get_child(0);
		//TODO:	current_level->disconnect("level_started", this, );
		//TODO:	current_level->disconnect("level_finished", this, );
	} else {
		Godot::print("No level to disconnect");
	}
}

void GameState::_spawn_player() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	auto current_level = level_node->get_child(0);
	auto spawn_point = current_level->get_node("PlayerStart");
	if (spawn_point != nullptr) {
		Ref<PackedScene> player_res = ResourceLoader::get_singleton()->load("entity/Player/Player.tscn");
		Node *playerInstance = player_res->instance();
		playerInstance->connect("ready", this, "_player_ready");
		playerInstance->connect("tree_exited", this, "_player_remove");
		spawn_point->add_child(playerInstance);
	} else {
		Godot::print("NO SPAWN POINT !");
	}
}

void GameState::_player_ready() {
	emit_signal("camera_start_focus");
}

void GameState::_player_remove() {
	emit_signal("camera_end_focus");
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_method("_player_ready", &GameState::_player_ready);
	register_method("_player_remove", &GameState::_player_remove);
	register_signal<GameState>("_game_started");
	register_signal<GameState>("_game_finished");
	register_signal<GameState>("_increment_level");
	register_signal<GameState>("camera_start_focus");
	register_signal<GameState>("camera_end_focus");
}