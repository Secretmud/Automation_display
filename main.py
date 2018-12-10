from flask import Flask, request, render_template
import serial
import requests
import time
app = Flask(__name__)

#ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
@app.route("/", methods=['GET', 'POST'])
def test():
    led = "STANDBY - Default mode"
 #   led = ser.readline().decode('utf-8')
    if request.method == 'POST':
        if request.form["submit"] == "blink":
            led = "blink"
  #          ser.write(b'1')
        elif request.form["submit"] == "solid":
            led = "solid"
   #         ser.write(b'2')
        elif request.form["submit"] == "Up":
            led = "Moving arm - UP"
    #        ser.write(b'3')
        elif request.form["submit"] == "Down":
            led = "Moving arm - DOWN"
     #       ser.write(b'4')
        elif request.form["submit"] == "Left":
            led = "Moving arm - LEFT"
      #      ser.write(b'5')
        elif request.form["submit"] == "Right":
            led = "Moving arm - RIGHT"
       #     ser.write(b'6')


    return render_template('base.html', values = led)

if __name__=='__main__':
    app.run(debug = True)
