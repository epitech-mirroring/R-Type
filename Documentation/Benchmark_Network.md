# Why Network is Used for Our Project

## Network Definition:
An interconnected or interrelated chain, group, or system.

Networking plays a crucial role in this project, facilitating communication between clients and the server. The core functionality of the network is to establish connections, manage data exchange, and ensure smooth communication between multiple clients and the central server. This network infrastructure forms the backbone of our game’s protocol, enabling real-time interaction.

In a basic client-server model:
- **Server** (Game logic, etc...):
    - Handles multiple client connections and disconnections.
    - Receives data from clients (e.g., player actions, requests).
    - Processes and broadcasts updates to clients (e.g., game state changes).


- **Client** (Game rendering, interface with user, etc...):
    - Connects to the server to send and receive game information.
    - Sends requests or actions to the server (e.g., move commands).
    - Receives updates and renders them to the user (e.g., player positions, mob movements, etc...).
    - Requests to connect to the server.
    - Sends a disconnect message to the server.

    

## Definition of the Objectives

The objective of this benchmark is to compare the different network libraries and evaluate possible solutions to create our protocol.
Specifically, we aim to evaluate the performance, scalability, and usability of various network libraries.

--- 
# Network benchmarking:
For this benchmark i asume you know a litle bit about network programming in c/c++.
To make a litle reminder, here is a simple example of a client-server application in c++ using the Unix BSD Socket API.
We deal with **sockets**, which are the endpoints of a bidirectional communication channel.

<p>
    <img src="https://www.bogotobogo.com/cplusplus/images/socket/Socket_API.png" alt>
    <em>The socket usage, and terms linked to it</em>
</p>

## What is a socket ?
A socket is one endpoint (A network device) of a two-way communication link between two programs running on the network.
A socket is bound to a **IP** and **port number** so that the TCP or UDP layer can identify the application that data is destined to.

<p>
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png" alt>
  <em> Example of socket connection between client and server</em>
</p>

## What is a OSI model ?
Is a conceptual framework that standardizes the functions of a network into seven distinct layers, 
from physical data transmission to application-level interactions. 
It helps guide the design and understanding of how different networking protocols and devices communicate with each other, ensuring interoperability across diverse systems and technologies.
Each layer serves a specific role, such as managing physical connections, routing data, or enabling software applications to exchange information.

<p>
    <img src="https://media.fs.com/images/community/upload/kindEditor/202107/29/original-seven-layers-of-osi-model-1627523878-JYjV8oybcC.png" alt>
    <em>The socket usage, and terms linked to it</em>
</p>

## Where is the socket in the OSI model ?

Here you can see that the socket is in the session layer.
The session layer is responsible for establishing, maintaining, and terminating connections between applications.

<p>
    <img src="https://jmvidal.cse.sc.edu/talks/javasockets/osiSockets.gif" alt>
    <em>OSI Model</em>
</p>

(TCP or UDP is defined in the transport layer)

---


### Goals:
- **Determine the best combination** of performance, speed, scalability, integration, and usability for our protocol.
- Ensure the benchmark takes cross-platform compatibility between Windows and Linux into account.


---

## Definition of the Metrics

We will use the following metrics to evaluate the performance of the network libraries:
- **Latency**: The time taken for data to travel from client to server and back.
- **Bandwidth**: The data transfer rate over a network connection.
- **CPU Usage**: The amount of processing power used by the networking operations.
- **Memory Usage**: The amount of system memory consumed.
- **Network Usage**: The amount of network resources utilized (data sent/received).
- **Packet Loss**: The rate at which packets fail to reach their destination.
- **Scalability**: How well the library handles a growing number of clients or data size.
- **Integration**: How well the library integrates with C++ and other project requirements.
- **Usability**: The ease of use and learning curve for developers.
- **(Security)**: Optional metric, depending on the protocol's needs.
- **(Reliability)**: Optional metric, measuring how well the system maintains connections over time.

---

## Scope of the Benchmarking

The benchmark will focus on the following network libraries:
- **ASIO (Asio C++ Library)**: An asynchronous I/O library that is cross-platform and designed to be efficient and lightweight.
- **Winsock (Windows Socket API)**: The primary network interface for Windows systems, optimized for the platform.
- **Unix BSD Socket (Unix Socket API)**: The standard network interface for Unix-like systems (Linux, macOS, etc.).

**Key Notes**:
- **ASIO**: A cross-platform library that compiles easily on both Windows and Linux.
- **Winsock** and **Unix BSD Socket**: Handle networking differently, requiring abstraction layers for full cross-platform compatibility.

---

# Benchmark Results (Placeholder)

### Performance Metrics:

| Metric             | ASIO         | Winsock      | Unix BSD Socket |
|--------------------|--------------|--------------|----------------|
| **Latency (1KB)**  | 0.04ms       | 0.04ms       | 0.06ms         |
| **Latency (1MB)**  | 0.2ms        | 0.3ms        | 0.5ms          |
| **CPU Usage**      | less than 1% | less than 1% | less than 1%   |

---


## Conclusion: Choosing ASIO

In our benchmarking analysis, the **ASIO C++ library** stands out as the most suitable choice for implementing our custom network protocol.
It offers significant advantages over alternatives like Winsock and Unix BSD Sockets, particularly in terms of **cross-platform compatibility** and **asynchronous programming support**. 
ASIO excels in handling both **TCP** and **UDP** connections efficiently through event-driven operations, making it ideal for scalable applications such as multiplayer games.
Its non-blocking I/O operations and integration with modern C++ standards (**C++11/14/17**) enable high performance without relying on platform-specific APIs, allowing us to maintain a **unified codebase** for both Windows and Linux.

While Winsock is limited to Windows and Unix BSD Sockets require platform-specific handling, ASIO ensures **consistent behavior** across multiple platforms, simplifying development.
Considering its balance of performance, scalability, and ease of use, ASIO is the best option to deliver a high-performance, cross-platform network solution for our project.


# Sources Used

- [Differences between Winsock and Unix BSD Sockets](https://handsonnetworkprogramming.com/articles/differences-windows-winsock-linux-unix-bsd-sockets-compatibility/)
- [Sockets in C++ (API is called BSD Sockets)](https://www.reddit.com/r/learnprogramming/comments/rcur02/sockets_in_c/)
- [Usage of ASIO for a Client-Server Application](https://www.youtube.com/watch?v=2hNdkYInj4g)
- [Discussion about ASIO Being Bloated](https://www.reddit.com/r/cpp/comments/h0954a/asio_makes_for_a_bloated_networking_standard/)
- [Discussion about the Speed of ASIO and ZeroMQ](https://stackoverflow.com/questions/42195738/is-zeromq-slower-than-boost-asio)
