//
// Created by bogdan on 25/02/2021.
//

#include "GameState.h"

using namespace godot;

void GameState::_init() {
	level_count = 2;
	current_level_id = 0;
}

void GameState::_ready() {
}

void GameState::_input(const Ref<InputEvent> event) {
}

void GameState::_start_game() {
	_load_level();
	is_started = true;
	emit_signal("_game_started");
}

void GameState::_load_level() {
	if (current_level_id < level_count) {
		_remove_level();
		current_level_id += 1;
		_add_level(current_level_id);
	} else {
		emit_signal("_game_finished");
		Label *label = Object::cast_to<Label>(get_tree()->get_root()->get_node("World/HUDLayer/GameTimer/GameTimerLabel"));
		Ref<PackedScene> endScreen = ResourceLoader::get_singleton()->load("entity/EndScreen/EndScreen.tscn");
		Node *endScreenNode = endScreen->instance();
		TimeLabel *timeLabel = Object::cast_to<TimeLabel>(endScreenNode->get_node("Time"));
		timeLabel->_set_time_label(label->get_text());
		get_tree()->_change_scene(endScreenNode);
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
	_connect_level(current_level);
	level_node->add_child(current_level);
	emit_signal("_increment_level");
}

void GameState::_remove_level() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	if (level_node->get_child_count() > 0) {
		auto current_level = level_node->get_child(0);
		_disconnect_level(current_level);
		level_node->remove_child(current_level);
		current_level->queue_free();
	} else {
		Godot::print("No level to remove");
	}
}

void GameState::_connect_level(Node *p_level) {
	//TODO:	level_node->get_child(0)->connect("level_started", this, );
	p_level->connect("ready", this, "_spawn_player");
	p_level->connect("level_finished", this, "_next_level");
	// p_level->connect("level_started", this, )
}

void GameState::_disconnect_level(Node *p_level) {
	if (p_level != nullptr) {
		//TODO:	p_level->disconnect("level_started", this, );
		//TODO:	p_level->disconnect("level_finished", this, );
	} else {
		Godot::print("No level to disconnect");
	}
}

void GameState::_spawn_player() {
	auto level_node = get_tree()->get_root()->get_node("World/Level");
	auto current_level = level_node->get_child(0);
	auto spawn_point = current_level->get_node("PlayerStart");
	if (spawn_point != nullptr) {
		Ref<PackedScene> player_res = ResourceLoader::get_singleton()->load("entity/Player/Character.tscn");
		auto *player = player_res->instance();
		player->connect("ready", this, "_player_ready");
		spawn_point->add_child(player);
	} else {
		Godot::print("NO SPAWN POINT !");
	}
}

void GameState::_next_level() {
	emit_signal("camera_end_focus");
	_remove_player_from_tree();
	call_deferred("_load_level");
}

void GameState::_player_ready() {
	emit_signal("camera_start_focus");
}

void GameState::_remove_player_from_tree() {
	auto *playerParentNode = get_tree()->get_root()->get_node("World/Level")->get_child(0)->get_node("PlayerStart");
	if (playerParentNode != nullptr) {
		if (playerParentNode->get_child_count() != 0) {
			playerParentNode->get_child(0)->free();
		}
	}
}

void GameState::_update_sound_volume(float_t volume) {
	sound_volume = volume;
	emit_signal("update_volume", volume);
}

float_t GameState::_get_sound_volume() {
	return sound_volume;
}

void GameState::_register_methods() {
	register_method("_init", &GameState::_init);
	register_method("_ready", &GameState::_ready);
	register_method("_input", &GameState::_input);
	register_method("_spawn_player", &GameState::_spawn_player);
	register_method("_player_ready", &GameState::_player_ready);
	register_method("_next_level", &GameState::_next_level);
	register_method("_load_level", &GameState::_load_level);
	register_signal<GameState>("_game_started");
	register_signal<GameState>("_game_finished");
	register_signal<GameState>("_increment_level");
	register_signal<GameState>("camera_start_focus");
	register_signal<GameState>("camera_end_focus");
	register_signal<GameState>("update_volume", "volume", GODOT_VARIANT_TYPE_REAL);
}