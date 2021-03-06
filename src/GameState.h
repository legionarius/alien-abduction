//
// Created by bogdan on 25/02/2021.
//

#ifndef GAMEJAM_TRAINING_GAMESTATE_H
#define GAMEJAM_TRAINING_GAMESTATE_H

#include "TimeLabel.h"
#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Label.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <iomanip>
#include <sstream>

namespace godot {
class GameState : public Node {
	GODOT_CLASS(GameState, Node);

	const std::string base_level_name = "Level";
	int level_count;
	int current_level_id;
	bool is_started;
	float_t sound_volume = 1.f;

public:
	std::string _get_level_path(int level_id);
	void _load_level();
	void _add_level(int level_id);
	void _connect_level(Node *p_level);
	void _disconnect_level(Node *p_level);
	void _remove_level();
	void _remove_player_from_tree();
	void _update_sound_volume(float_t volume);
	float_t _get_sound_volume();
	void _start_game();
	void _spawn_player();
	void _player_ready();
	void _next_level();
	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
};
} // namespace godot

#endif //GAMEJAM_TRAINING_GAMESTATE_H
