/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Server.hpp
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include "GameLogic.hpp"
#include "server/Server.hpp"
#include "../network/protocol/dto/DTODecoder.hpp"
#include "../network/protocol/dto/DTOEncoder.hpp"
#include "../network/protocol/dto/entity/EntityPositionDTO.hpp"
#include "../network/protocol/dto/entity/EntityCreationDTO.hpp"
#include "../network/protocol/dto/entity/EntityDeletionDTO.hpp"

namespace RType
{
	class Server {
	public:
		Server(unsigned short tcpPort, unsigned short udpPort);
		~Server();

		void runServer();

		void createBufferedEntities() const;
		void deleteBufferedEntities() const;

		[[nodiscard]] int createNewPlayer() const;

		void handleClientInput() const;

	private:
		void sendUpdateEntities() const;

		Network::Server *_network;
		GameLogic *_gameLogic;
		DTOEncoder *_encoder;
		DTODecoder *_decoder;

		float _deltaTimeNetwork;
		float _minDeltaTimeNetwork;
		bool _isRunning;
		unsigned short _tcpPort;
		unsigned short _udpPort;

		std::thread *_networkThread{};
	};
}

#endif //SERVER_HPP
