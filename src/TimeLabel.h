//
// Created by bogdan on 04/03/2021.
//

#ifndef WEEKLY_GAMEJAM_190_TIMELABEL_H
#define WEEKLY_GAMEJAM_190_TIMELABEL_H

#include <Godot.hpp>
#include <Label.hpp>

namespace godot {
class TimeLabel : public Label {
	GODOT_CLASS(TimeLabel, Label);

	String _label_to_show;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _set_time_label(String label);
};
} // namespace godot

#endif //WEEKLY_GAMEJAM_190_TIMELABEL_H
