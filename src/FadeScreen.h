//
// Created by bogdan on 02/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_FADESCREEN_H
#define WEEKLY_GAMEJAM_190_FADESCREEN_H

#include <AnimationPlayer.hpp>
#include <ColorRect.hpp>
#include <Godot.hpp>

namespace godot {
class FadeScreen : public AnimationPlayer {
	GODOT_CLASS(FadeScreen, AnimationPlayer);

	bool fadeIn;

public:
	void fade_to_black();

	static void _register_methods();
	void _init();
};
} // namespace godot

#endif //WEEKLY_GAMEJAM_190_FADESCREEN_H
