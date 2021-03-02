//
// Created by bogdan on 25/02/2021.
//

#ifndef GAMEJAM_TRAINING_GAMESTATE_H
#define GAMEJAM_TRAINING_GAMESTATE_H

#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <iomanip>

namespace godot {
class GameState : public Node {
	GODOT_CLASS(GameState, Node);

	const std::string base_level_name = "Level";
	int level_count;
	int current_level_id;
	bool is_started;

	std::string _get_level_path(int level_id);
	void _load_level();
	void _add_level(int level_id);
	void _connect_level();
	void _disconnect_level();
	void _remove_level();
	void _spawn_player();

public:
	void _start_game();
	void _player_ready();
	void _remove_player();
	static void _register_methods();
	void _init();
	void _ready();
	void _input(const Ref<InputEvent> event);
};
} // namespace godot

#endif //GAMEJAM_TRAINING_GAMESTATE_H
