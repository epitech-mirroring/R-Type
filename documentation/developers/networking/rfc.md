
Internet Engineering Task Force (IETF)                              R-Type Team
Request for Comments: N/A                                             October 2024
Category: Experimental

Network Communication Protocol for R-Type Game
================================================

Status of This Memo:
-------------------
This document specifies an experimental protocol for the R-Type game project. It
details the binary communication format used between the game server and clients,
which relies on UDP for transmitting game state and TCP for managing client
connections and disconnections.

Abstract:
---------
This memo describes a network protocol designed for a multiplayer network game
similar to R-Type. The protocol uses UDP for high-speed transmission of real-time
game data and TCP for reliable handling of client connections and disconnections.
This protocol supports multiple clients connected to a central server, which manages
their interactions.

1. Introduction
---------------
The R-Type network game requires efficient and real-time data transmission between
a server and multiple clients. The protocol described in this RFC outlines how the
server and clients interact using two different transport-layer protocols (TCP and
UDP) to balance reliability with performance.

2. Protocol Overview
---------------------
The network communication is based on binary communication using the following:
- **TCP** is used for connection management: when clients connect or disconnect
  from the server.
- **UDP** is used for high-frequency game state transmission (e.g., movement and
  game actions).

3. Connection Management (TCP)
-------------------------------
Clients connect to the server using TCP for reliable connection setup. The steps are:
1. The client sends a connection request to the server on the specified TCP port.
2. The server assigns a unique client ID and sends it to the client.
3. Once the connection is established, the client begins to use UDP for game data
   transmission.
4. Disconnection is handled via TCP by sending a termination message ("exit") to
   the server.

4. Game Data Transmission (UDP)
-------------------------------
Once the client has connected using TCP, all further communication for game data
(e.g., player movements, actions, game updates) occurs over UDP. The client sends
binary-encoded packets to the server at regular intervals, and the server responds
with game state updates.

### Packet Format:
All packets exchanged via UDP have the following binary format:

```
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Client ID (32 bits)                     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Action Data (variable size)             |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

- **Client ID**: The unique ID assigned to the client by the server.
- **Action Data**: Encoded game data (e.g., position, movement, actions).

5. Error Handling and Reconnection
----------------------------------
In the event of packet loss (since UDP is used), no retransmission mechanism is
in place. The game compensates for lost packets by relying on frequent updates
and approximating missing data based on the last known state.

In case of disconnection, the client must reconnect using the TCP protocol to
request a new session.

6. Example Scenario
-------------------
### Client Connection:
1. The client connects to the server via TCP at port 8080.
2. The server assigns a client ID (e.g., 5) and sends it to the client.
3. The client switches to UDP to transmit game data at port 9000.

### Game Data Transmission:
- The client sends binary-encoded packets to the server over UDP every 15 ms,
  containing movement and action data.

7. Future Considerations
------------------------
- The protocol could be enhanced with a lightweight reliability layer on top of
  UDP to improve robustness in poor network conditions.
- Compression could be applied to reduce packet sizes for higher efficiency.

8. Security Considerations
--------------------------
The protocol currently has no encryption. Future implementations may consider
adding encryption to both TCP and UDP data streams to prevent packet tampering.

9. Conclusion
-------------
This document describes a simple yet effective binary protocol for handling
multiplayer game communication in the R-Type project. While the current
implementation focuses on performance, future iterations may incorporate
additional features like reliability improvements and security enhancements.
