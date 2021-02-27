//
// Created by bogdan on 27/02/2021.
//

#include "BubbleControl.h"

using namespace godot;

void BubbleControl::_init() {
	radius = 0;

	Godot::print(get_position());
	Godot::print(get_begin());
}

void BubbleControl::_draw() {
	_draw_circle_arc(get_position(), radius, -2, 360, Color(0.244, 0.5, 0.6));
}

void BubbleControl::_draw_circle_arc(Vector2 center, const real_t radius, int start_angle, int end_angle, Color color) {
	float nb_points = 128;
	PoolVector2Array points_arc = PoolVector2Array();

	for (int i = 0; i < nb_points; ++i) {
		float anglePoint = Math::deg2rad(start_angle + i * (end_angle - start_angle) / nb_points - 90.0);
		points_arc.append(center + Vector2(Math::cos(anglePoint), Math::sin(anglePoint)) * radius);
	}

	for (int i = 0; i < nb_points - 1; ++i) {
		draw_line(points_arc[i], points_arc[i + 1], color, 2.0, true);
	}
}

void BubbleControl::_process(const real_t delta) {
	if (!animation_timer->is_stopped() && radius <= max_radius) {
		radius = radius + 300 * delta;
		update();
	}
}

void BubbleControl::_appear() {
	animation_timer->start();
	show();
}

void BubbleControl::_disappear() {
	animation_timer->stop();
	radius = 0;
	hide();
}

void BubbleControl::_ready() {
	Godot::print("Maximum radius = " + Utils::gdt_string(max_radius));
	steps = max_radius / bubble_time;
	_init_bubble_timer();
}

void BubbleControl::_init_bubble_timer() {
	animation_timer = Timer()._new();
	animation_timer->set_one_shot(true);
	animation_timer->set_wait_time(bubble_time);
	add_child(animation_timer);
}

void BubbleControl::_register_methods() {
	register_method("_process", &BubbleControl::_process);
	register_method("_ready", &BubbleControl::_ready);
	register_method("_init", &BubbleControl::_init);
	register_method("_draw", &BubbleControl::_draw);
	register_property("radius", &BubbleControl::max_radius, 20.f);
	register_property("animation_opening_time", &BubbleControl::bubble_time, 2.f);
}