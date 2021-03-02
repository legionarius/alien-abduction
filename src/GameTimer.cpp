//
// Created by nahalu on 01/03/2021.
//

#include "GameTimer.h"

using namespace godot;

int ms = 0;
int s = 0;
int m = 0;

void GameTimer::_init() {
}

void GameTimer::_ready() {
	label = Object::cast_to<Label>(get_node("GameTimerLabel"));
	timer = Object::cast_to<Timer>(get_node("GameClock"));
	timer->start();
}

void GameTimer::_process(const real_t delta) {
	if (ms > 9) {
		s += 1;
		ms = 0;
	}

	if (s > 59) {
		m += 1;
		s = 0;
	}

	label->set_text(String::num_int64(m) + ":" + String::num_int64(s) + ":" + String::num_int64(ms));
}

void GameTimer::_on_Timer_timeout() {
	ms += 1;
}

void GameTimer::_register_methods() {
	register_method("_init", &GameTimer::_init);
	register_method("_ready", &GameTimer::_ready);
	register_method("_process", &GameTimer::_process);
	register_method("_on_Timer_timeout", &GameTimer::_on_Timer_timeout);
}