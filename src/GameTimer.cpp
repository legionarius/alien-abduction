//
// Created by nahalu on 01/03/2021.
//

#include "GameTimer.h"

using namespace godot;

void GameTimer::_init() {
	ms = 0;
	s = 0;
	m = 0;
}

void GameTimer::_ready() {
	label = Object::cast_to<Label>(get_node("GameTimerLabel"));
	timer = Object::cast_to<Timer>(get_node("GameClock"));
	GameState *gameState = Object::cast_to<GameState>(get_tree()->get_root()->get_node("GameState"));
	gameState->connect("_increment_level", this, "_start_timer");
	gameState->connect("_game_finished", this, "_stop_timer");
}

void GameTimer::_process(const real_t delta) {
	std::stringstream s_string;
	std::stringstream ms_string;
	std::stringstream m_string;

	if (ms > 9) {
		s += 1;
		ms = 0;
	}

	if (s > 59) {
		m += 1;
		s = 0;
	}

	ms_string << ms << "0";
	s_string << std::setw(2) << std::setfill('0') << s;
	m_string << std::right << std::setw(2) << std::setfill('0') << m;
	std::string timer_string = m_string.str() + ":" + s_string.str() + ":" + ms_string.str();
	label->set_text(timer_string.c_str());
}

void GameTimer::_on_Timer_timeout() {
	ms += 1;
}

void GameTimer::_start_timer() {
	timer->start();
}

void GameTimer::_stop_timer() {
	timer->set_paused(true);
}

void GameTimer::_register_methods() {
	register_method("_init", &GameTimer::_init);
	register_method("_ready", &GameTimer::_ready);
	register_method("_process", &GameTimer::_process);
	register_method("_on_Timer_timeout", &GameTimer::_on_Timer_timeout);
	register_method("_start_timer", &GameTimer::_start_timer);
	register_method("_stop_timer", &GameTimer::_stop_timer);
}