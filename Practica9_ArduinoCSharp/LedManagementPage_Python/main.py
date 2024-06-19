import tkinter as tk
import serial

# Set up the serial connection (use the exact port name)
ser = None
try:
    ser = serial.Serial('/dev/cu.usbmodem1401', 115200)
except serial.SerialException:
    print("Failed to connect to Arduino on /dev/cu.usbmodem101")
    exit()

# Create the main window
root = tk.Tk()
root.title("LED Control")

# Function to send command to Arduino
def send_command(command):
    if ser is not None:
        ser.write(command.encode())

# GUI widgets
turn_on_button = tk.Button(root, text="Turn LED ON", command=lambda: send_command('H'))
turn_on_button.pack(padx=20, pady=10)

turn_off_button = tk.Button(root, text="Turn LED OFF", command=lambda: send_command('L'))
turn_off_button.pack(padx=20, pady=10)

# Start the GUI event loop
root.mainloop()
