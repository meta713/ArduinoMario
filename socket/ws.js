const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 3333 });
const arduinoPort = "/dev/tty.usbmodem1421";

console.log("ws start!");

wss.on('connection', function connection(ws) {
  //シリアル通信の開始
  const SerialPort = require('serialport');
  const port = new SerialPort(arduinoPort, {
    baudRate: 9600
  });

  port.on('open', function () {
    console.log("serialport opened");
  });

  port.on('data', function (data) {
    console.log('Data from serialport: ' + data);
  });

  ws.on('message', function incoming(message) {
    console.log('received message: %s', message);
    if(message === "1UP") port.write(new Buffer("1UP\n"), function(err, res){
      console.log(err);
    });
  });

  ws.on('close', function(){
    port.close(function (err) {
      console.log('port closed', err);
    });
  });
});
