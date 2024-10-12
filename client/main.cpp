#include "../network/client/Client.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <UDP port> <TCP port>" << std::endl;
        return 1;
    }

    const std::string host = argv[1];
    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[2]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[3]));

    try {
        Network::Client client(host, UDP_port, TCP_port);
        std::cout << "Client trying to connect to server..." << std::endl;
        client.connect();


        const std::vector message = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!' };

        while(true){
            client.add_to_send_queue(message);
            sleep(1);

            if(client.get_size_recv_queue() > 0) {
                std::vector<char> const data = client.get_next_recv_queue();
                std::cout << "data received: " << "\n";
                for (const auto& byte : data) {
                    std::cout << byte;
                }
                std::cout << std::endl;
            }
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
