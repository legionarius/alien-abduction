//
// Created by bogdan on 27/02/2021.
//

#ifndef WEEKLY_GAMEJAM_190_BUBBLECONTROL_H
#define WEEKLY_GAMEJAM_190_BUBBLECONTROL_H

#include "Utils.h"
#include <Control.hpp>
#include <Godot.hpp>
#include <Timer.hpp>

namespace godot {

class BubbleControl : public Control {
	GODOT_CLASS(BubbleControl, Control);

	void _draw_circle_arc(Vector2 center, const real_t radius, int start_angle, int end_angle, Color color);
	Timer *animation_timer;
	real_t radius;
	uint16_t steps;
	void _init_bubble_timer();

public:
	Color color;
	real_t bubble_time;
	real_t max_radius;

	void _appear();
	void _disappear();

	// Godot methods
	static void _register_methods();
	void _process(const real_t delta);
	void _init();
	void _ready();
	void _draw();
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_BUBBLECONTROL_H
