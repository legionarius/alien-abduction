//
// Created by nahalu on 01/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_GAMETIMER_H
#define WEEKLY_GAMEJAM_190_GAMETIMER_H

#include "GameState.h"
#include <Control.hpp>
#include <Godot.hpp>
#include <Label.hpp>
#include <Timer.hpp>
#include <iomanip>

namespace godot {

class GameTimer : public Control {
	GODOT_CLASS(GameTimer, Control);

	GameTimer *gameTimer;
	Label *label;
	Timer *timer;
	int ms;
	int s;
	int m;

public:
	void _start_timer();
	void _stop_timer();

	static void _register_methods();
	void _init();
	void _ready();
	void _process(const real_t delta);
	void _on_Timer_timeout();
};

} // namespace godot

#endif //WEEKLY_GAMEJAM_190_GAMETIMER_H
