#!/usr/bin/sh

while (( $# ))

do
	case "$1" in

		--native | -n)
			if [[ "$OSTYPE" == "linux-gnu"* ]]; then
				scons platform=linux
			elif [[ "$OSTYPE" == "darwin"* ]]; then
				scons platform=osx
			else
				scons platform=windows
			fi
			exit 0
			;;

		--godot-cpp | -gc)
			if [[ "$OSTYPE" == "linux-gnu"* ]]; then
				cd godot-cpp; scons platform=linux generate_bindings=yes bits=64 use_custom_api_file=yes custom_api_file=../api.json -j4
			elif [[ "$OSTYPE" == "darwin"* ]]; then
				cd godot-cpp; scons platform=osx generate_bindings=yes bits=64 use_custom_api_file=yes custom_api_file=../api.json -j4
			else
				cd godot-cpp; scons platform=windows generate_bindings=yes bits=64 use_custom_api_file=yes custom_api_file=../api.json -j4
			fi
			exit 0
			;;

		--json-api | -ja)
			godot --gdnative-generate-json-api api.json
			exit 0
			;;

		esac
	done
