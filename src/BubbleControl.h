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

	void _draw_circle_arc(Vector2 center, real_t radius, Color color);
	Timer *animation_timer;
	real_t radius;
	uint16_t steps;
	void _init_bubble_timer();
	real_t bubble_time;
	Vector2 oscillation;

public:
	Color outline_color;
	Color fill_color;
	Color line_color;
	real_t max_radius;

	void _appear();
	void _disappear();
	void _set_oscillation(real_t generated);

	// Godot methods
	static void _register_methods();
	void _process(const real_t delta);
	void _init();
	void _ready();
	void _draw();
};

} // namespace godot
#endif //WEEKLY_GAMEJAM_190_BUBBLECONTROL_H
