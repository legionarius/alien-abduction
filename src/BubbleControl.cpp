//
// Created by bogdan on 27/02/2021.
//

#include "BubbleControl.h"

using namespace godot;

void BubbleControl::_init() {
	radius = 0;
}

void BubbleControl::_draw() {
	_draw_circle_arc(get_position(), radius, outline_color);
	draw_circle(get_position(), radius, fill_color);
	Vector2 mouse_position = get_local_mouse_position().normalized() * oscillation;
	draw_line(get_position(), mouse_position, line_color, 3.0, true);
}

void BubbleControl::_draw_circle_arc(Vector2 center, const real_t radius, const Color color) {
	const int nb_points = 128;
	const int start_angle = -2;
	const int end_angle = 360;
	PoolVector2Array points_arc = PoolVector2Array();

	for (int i = 0; i < nb_points; ++i) {
		float anglePoint = Math::deg2rad(start_angle + static_cast<float>(i) * (end_angle - start_angle) / nb_points - 90.f);
		points_arc.append(center + Vector2(Math::cos(anglePoint), Math::sin(anglePoint)) * radius);
	}

	for (int i = 0; i < nb_points - 1; ++i) {
		draw_line(points_arc[i], points_arc[i + 1], color, 2.0, true);
	}
}

void BubbleControl::_process(const real_t delta) {
	if (is_visible()) {
		if (!animation_timer->is_stopped()) {
			radius = radius + steps * delta;
			update();
		}
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
	hide();
	oscillation = Vector2(max_radius - 2, max_radius - 2);
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
	register_property("circle_radius", &BubbleControl::max_radius, 20.f);
	register_property("animation_time", &BubbleControl::bubble_time, 2.f);
	register_property("outline_color", &BubbleControl::outline_color, Color(1.f, 1.f, 1.f));
	register_property("fill_color", &BubbleControl::fill_color, Color(1.f, 1.f, 1.f, 0.1f));
	register_property("line_color", &BubbleControl::line_color, Color(0.f, 0.f, 0.f));
}
void BubbleControl::_set_oscillation(real_t generated) {
	real_t absolute = std::abs(generated);
	oscillation = Vector2(max_radius - 2, max_radius - 2) * absolute;
}
