//
// Created by nahalu on 01/03/2021.
//

#include "GameTimer.h"
#include <iomanip>

using namespace godot;

void GameTimer::_init() {
}

void GameTimer::_ready() {
	label = Object::cast_to<Label>(get_node("GameTimerLabel"));
	timer = Object::cast_to<Timer>(get_node("GameClock"));
	ms = 0;
	s = 0;
	m = 0;
	_start_timer();
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

void GameTimer::_pause_timer() {
	timer->stop();
}

String GameTimer::GetElapsedTime() {
	return String::num_int64(m) + ":" + String::num_int64(s) + ":" + String::num_int64(ms);
}

void GameTimer::_register_methods() {
	register_method("_init", &GameTimer::_init);
	register_method("_ready", &GameTimer::_ready);
	register_method("_process", &GameTimer::_process);
	register_method("_on_Timer_timeout", &GameTimer::_on_Timer_timeout);
	register_signal<GameTimer>("timer_started");
	register_signal<GameTimer>("timer_paused");
}