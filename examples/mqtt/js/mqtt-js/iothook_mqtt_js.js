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
  toastr.info("MQTT Broker connect");
}

function onMessageArrived(message) {
  var msg =  message.payloadString;
  var topic_sub = document.getElementById("topic_sub").value;
  console.log("onMessageArrived:" + msg);
  msg_counter++;
  $('<tr><td>#'+ msg_counter + ' ' + topic_sub + ' ' + msg +'</td></tr>')
  .hide()
  .prependTo('table tbody')
  .fadeIn("slow");
}

function onConnectionLost(responseObject){
    toastr.danger("MQTT Broker connection lost " + +responseObject.errorMessage);
}

function publish(){
  var topic_pub = document.getElementById("topic_pub").value;
  var msg_pub = document.getElementById("msg_pub").value;

  message = new Paho.MQTT.Message(msg_pub);
  message.destinationName = topic_pub;
  mqtt.send(message);
  toastr.info("MQTT Client " + topic_pub + " " + msg_pub + " published");
  console.log("publish");
}

function subscribe(){
  var topic_sub = document.getElementById("topic_sub").value;
  mqtt.subscribe(topic_sub);
  toastr.info("MQTT Client " + topic_sub + " subscribed");
  console.log("subscribe");
}

function disconnect(){
  mqtt.disconnect();
  document.getElementById("connect").innerHTML = "Connect";
  toastr.info("MQTT Broker disconnect");
  console.log("disconnect");
}

$(document).ready(function () {
  document.getElementById("client_id").value = ('clientId-' + randomString(10));
});

function MQTTconnect() {
var client_id = document.getElementById("client_id").value;
var host= document.getElementById("host").value;
var port=Number(document.getElementById("port").value);

console.log("connecting to " + host + " " + port);
mqtt = new Paho.MQTT.Client(host, port, client_id);
mqtt.onMessageArrived = onMessageArrived;
mqtt.onConnectionLost = onConnectionLost;

var options = {
    useSSL:true,
    timeout: 3,
    onSuccess: onConnect,
};

mqtt.connect(options); //connect
}
