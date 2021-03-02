//
// Created by nahalu on 01/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_GAMETIMER_H
#define WEEKLY_GAMEJAM_190_GAMETIMER_H

#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Timer.hpp>

namespace godot {

class GameTimer : public Control {
	GODOT_CLASS(GameTimer, Control);

	Label *label;
	Timer *timer;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(const real_t delta);
	void _on_Timer_timeout();
};

} // namespace godot

#endif //WEEKLY_GAMEJAM_190_GAMETIMER_H
