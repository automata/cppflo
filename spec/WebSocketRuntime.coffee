WebSocketClient = require('websocket').client

client = new WebSocketClient()

client.on 'connectFailed', (error) ->
  console.log('Connect Error: ' + error.toString())

client.on 'connect', (connection) ->
  console.log('WebSocket Client Connected')
  connection.on 'error', (error) ->
    console.log("Connection Error: " + error.toString())
  connection.on 'close', () ->
    console.log('echo-protocol Connection Closed')
  connection.on 'message', (message) ->
    if message.type is'utf8'
      console.log("Received: '" + message.utf8Data + "'")

  sendNumber = ->
    if connection.connected
      number = Math.round(Math.random() * 0xFFFFFF)
      connection.sendUTF(number.toString())
      setTimeout(sendNumber, 1000)
  sendNumber()

client.connect('ws://localhost:9002/')
