//
// Created by bogdan on 04/03/2021.
//

#include "TimeLabel.h"
void godot::TimeLabel::_register_methods() {
	register_method("_init", &TimeLabel::_init);
	register_method("_ready", &TimeLabel::_ready);
}
void godot::TimeLabel::_init() {
	_label_to_show = String("Test");
}

void godot::TimeLabel::_ready() {
	set_text(_label_to_show);
}
void godot::TimeLabel::_set_time_label(String label) {
	_label_to_show = String("Total time : " + label);
}
