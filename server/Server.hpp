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
#include "dto/DTODecoder.hpp"
#include "dto/DTOEncoder.hpp"
#include "dto/entity/EntityPositionDTO.hpp"
#include "dto/entity/EntityCreationDTO.hpp"
#include "dto/entity/EntityDeletionDTO.hpp"

namespace RType
{
	class Server {
	public:
		Server(unsigned short  tcpPort, unsigned short  udpPort);
		~Server();

		void runServer();

		void createBufferedEntities();
		void deleteBufferedEntities();

		[[nodiscard]] int createNewPlayer() const;

	private:
		void sendUpdateEntities();

		Network::Server *_network;
		GameLogic *_gameLogic;
		DTOEncoder *_encoder;
		DTODecoder *_decoder;

		float _deltaTimeNetwork;
		float _minDeltaTimeNetwork;
		bool _isRunning;
		unsigned short _tcpPort;
		unsigned short _udpPort;

		std::thread *_networkThread;
	};
}

#endif //SERVER_HPP
