//
// Created by bogdan on 02/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_MAINSCENE_H
#define WEEKLY_GAMEJAM_190_MAINSCENE_H

#include "GameState.h"
#include <Godot.hpp>
#include <Node2D.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

namespace godot {
class MainScene : public Node2D {
	GODOT_CLASS(MainScene, Node2D);

public:
	static void _register_methods();
	void _init();
	void _ready();
};
} // namespace godot

#endif //WEEKLY_GAMEJAM_190_MAINSCENE_H
