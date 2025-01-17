import RPi.GPIO as GPIO
import tkinter as tk

# Set up the GPIO mode
GPIO.setmode(GPIO.BCM)

# Define the GPIO pins for the LEDs
red_pin = 22
green_pin = 27
blue_pin = 17

# Set up the GPIO pins as outputs
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT)
GPIO.setup(blue_pin, GPIO.OUT)

# Set up PWM for each LED (frequency set to 100 Hz)
red_pwm = GPIO.PWM(red_pin, 100)
green_pwm = GPIO.PWM(green_pin, 100)
blue_pwm = GPIO.PWM(blue_pin, 100)

# Start PWM with 0% duty cycle (LEDs off)
red_pwm.start(0)
green_pwm.start(0)
blue_pwm.start(0)

# Function to update the brightness of LEDs
def update_leds():
    red_pwm.ChangeDutyCycle(red_slider.get())   # Set Red LED brightness
    green_pwm.ChangeDutyCycle(green_slider.get())  # Set Green LED brightness
    blue_pwm.ChangeDutyCycle(blue_slider.get())   # Set Blue LED brightness

# Function to exit and clean up
def exit_gui():
    red_pwm.stop()
    green_pwm.stop()
    blue_pwm.stop()
    GPIO.cleanup()
    root.destroy()

# Set up the GUI window
root = tk.Tk()
root.title("LED Brightness Control")

# Red LED slider
tk.Label(root, text="Red LED").pack()
red_slider = tk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=lambda x: update_leds())
red_slider.pack()

# Green LED slider
tk.Label(root, text="Green LED").pack()
green_slider = tk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=lambda x: update_leds())
green_slider.pack()

# Blue LED slider
tk.Label(root, text="Blue LED").pack()
blue_slider = tk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=lambda x: update_leds())
blue_slider.pack()

# Add an Exit button
tk.Button(root, text="Exit", command=exit_gui).pack()

# Start the GUI loop
root.mainloop()