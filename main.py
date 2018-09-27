from flask import Flask, request, render_template
import serial
import time
app = Flask(__name__)

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
@app.route("/", methods=['GET', 'POST'])
def test():
    #data = ser.readline().decode('utf-8')
    data = "test"
    if request.method == 'POST':
        if request.form["submit"] == "blink":
            data = "blink"
            ser.write(b'1')
        elif request.form["submit"] == "solid":
            data = "solid"
            ser.write(b'2')



    return render_template('base.html', values = data)

if __name__=='__main__':
    app.run(debug = True)
