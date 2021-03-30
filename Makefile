serial:
	pyserial-miniterm /dev/ttyACM0 115200
compile:
	arduino-cli compile --fqbn arduino:avr:leonardo .

upload:compile
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:leonardo .
