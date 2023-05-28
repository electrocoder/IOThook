var mqtt;
var reconnectTimeout = 2000;
var msg_counter = 0;


function randomString(length) {
  var text = "";
  var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  for (var i = 0; i < length; i++)
    text += possible.charAt(Math.floor(Math.random() * possible.length));
  return text;
}


function onConnect() {
  console.log("onConnect");
  document.getElementById("connect").innerHTML = "Connected";
}


function onMessageArrived(message) {
  var msg = message.payloadString;
  // var topic_sub = document.getElementById("topic_sub").value;
  console.log("onMessageArrived:" + msg);
}


function onConnectionLost(responseObject) {
  console.log("MQTT Broker connection lost " + +responseObject.errorMessage);
}

function mqttPublish() {
  var topic_pub = "testtopic";
  var msg_pub = "test";

  message = new Paho.MQTT.Message(msg_pub);
  message.destinationName = topic_pub;
  mqtt.send(message);
  console.log("publish");
}


function mqttSubscribe() {
  var topic_sub = "testtopic/#";
  mqtt.subscribe(topic_sub);
  document.getElementById("subscribe").innerHTML = "Subscribed";
  console.log("subscribe");
}


function mqttDisconnect() {
  mqtt.disconnect();
  document.getElementById("connect").innerHTML = "Connect";
  document.getElementById("subscribe").innerHTML = "Subscribe";
  console.log("disconnect");
}


function mqttConnect() {
  var client_id = "clientId-ZRBQ1xt4DK";
  var host = "broker.emqx.io";
  var port = 8083;
  var host = "broker.hivemq.com";
  var port = 8000;
  var host = "mqtt.eclipse.org";
  var port = 1883;

  console.log("connecting to " + host + " " + port);
  mqtt = new Paho.MQTT.Client(host, port, client_id);
  mqtt.onMessageArrived = onMessageArrived;
  mqtt.onConnectionLost = onConnectionLost;

  var options = {
    useSSL: false,
    timeout: 3,
    onSuccess: onConnect,
  };

  mqtt.connect(options); //connect
}
