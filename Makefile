serial:
	pyserial-miniterm /dev/ttyUSB0 9600
compile:
	arduino-cli compile --fqbn arduino:avr:nano .

upload:compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:nano .
