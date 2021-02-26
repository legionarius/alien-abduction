//
// Created by bogdan on 25/02/2021.
//

#ifndef GAMEJAM_TRAINING_GAMESTATE_H
#define GAMEJAM_TRAINING_GAMESTATE_H

#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <Node.hpp>
#include <Ref.hpp>

namespace godot {
class GameState : public Node {
	GODOT_CLASS(GameState, Node);

public:
	static void _register_methods();
	void _init();
	void _input(const Ref<InputEvent> event);
};
} // namespace godot

#endif //GAMEJAM_TRAINING_GAMESTATE_H
