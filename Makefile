all: compile flash monitor

compile:
	arduino-cli compile --fqbn esp32:esp32:nodemcu-32s .

flash:
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:nodemcu-32s .

monitor:
	arduino-cli monitor -p /dev/ttyUSB0

