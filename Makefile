arduino: compile_arduino flash_arduino monitor_arduino
esp32: compile_esp32 flash_esp32 monitor_esp32

compile_arduino:
	arduino-cli compile --fqbn arduino:avr:leonardo .

flash_arduino:
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:leonardo .

monitor_arduino:
	arduino-cli monitor -p /dev/ttyACM0


compile_esp32:
	arduino-cli compile --fqbn esp32:esp32:nodemcu-32s .

flash_esp32:
	arduino-cli upload -p /dev/ttyUSB1 --fqbn esp32:esp32:nodemcu-32s .

monitor_esp32:
	arduino-cli monitor -p /dev/ttyUSB1

