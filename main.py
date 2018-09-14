from flask import Flask, request, render_template
import serial
import time
app = Flask(__name__)

ser = serial.Serial('/dev/ttyACM3', 9600, timeout=1)
@app.route("/", methods=['GET', 'POST'])
def test():
    test_data = []
    data = ser.readline().decode('utf-8')
    test_data.append(data)
    if request.method == 'POST':
        if request.form["submit"] == "blink":
            ser.write(b'1')
        elif request.form["submit"] == "solid":
            ser.write(b'2')


    return render_template('base.html', values = data)

if __name__=='__main__':
    app.run(debug = True)
