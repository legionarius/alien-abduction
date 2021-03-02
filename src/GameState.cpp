//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {
	level_count = 1;
	current_level_id = 0;
}

void GameState::_ready() {
	_start_game();
}

void GameState::_input(const Ref<InputEvent> event) {}

void GameState::_start_game() {
	_load_level();
	spawn_player();
	emit_signal("_game_started");
}

void GameState::_load_level() {
	if (current_level_id < level_count) {
		Godot::print("load_level");
		disconnect_level();
		remove_level();
		current_level_id += 1;
		add_level(current_level_id);
		connect_level();
	} else {
		emit_signal("_game_finished");
	}
}

std::string GameState::get_level_path(int level_id) {
	std::stringstream level_name;
	level_name << "entity/Levels/Level" << std::setw(2) << std::setfill('0') << current_level_id << ".tscn";
	return level_name.str();
}

void GameState::add_level(int level_id) {
	auto level_path = get_level_path(level_id);
	Ref<PackedScene> level_res = ResourceLoader::get_singleton()->load(level_path.c_str());
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	auto current_level = level_res->instance();
	level_node->add_child(current_level);
}

void GameState::remove_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	if (level_node->get_child_count() > 0) {
		auto current_level = level_node->get_child(0);
		level_node->remove_child(current_level);
	} else {
		Godot::print("No level to remove");
	}
}

void GameState::connect_level() {
	Godot::print("signal: level_started");
	//auto level_node = get_tree()->get_root()->get_node("World/Level");
	emit_signal("level_started");
	//TODO:	level_node->get_child(0)->connect("level_started", this, );
	//TODO:	level_node->get_child(0)->connect("level_finished", this, );
}

void GameState::disconnect_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	if (level_node->get_child_count() > 0) {
		emit_signal("level_finished");
		auto current_level = level_node->get_child(0);
		//TODO:	current_level->disconnect("level_started", this, );
		//TODO:	current_level->disconnect("level_finished", this, );
	} else {
		Godot::print("No level to disconnect");
	}
}

void GameState::spawn_player() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	auto current_level = level_node->get_child(0);
	auto spawn_point = current_level->get_node("PlayerStart");
	if (spawn_point != nullptr) {
		Ref<PackedScene> player_res = ResourceLoader::get_singleton()->load("entity/Player/Player.tscn");
		spawn_point->add_child(player_res->instance());
	} else {
		Godot::print("NO SPAWN POINT !");
	}
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_signal<GameState>("_game_started");
	register_signal<GameState>("_game_finished");
	register_signal<GameState>("level_started");
	register_signal<GameState>("level_finished");
}