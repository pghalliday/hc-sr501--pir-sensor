.PHONY: all compile deploy listen

all: deploy listen

arduino/arduino.arduino.avr.uno.elf: arduino/arduino.ino
	arduino-cli compile --fqbn arduino:avr:uno arduino

compile: arduino/arduino.arduino.avr.uno.elf

deploy: compile
	arduino-cli upload -p /dev/cu.usbmodem14201 --fqbn arduino:avr:uno arduino

listen:
	stty -f /dev/cu.usbmodem14201 9600
	cat /dev/cu.usbmodem14201
