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
	/**
     * @class Server
     * @brief Class that manages the server
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	class Server {
	public:
		/**
         * @brief The constructor of the Server class
         * @param tcpPort The TCP port
         * @param udpPort The UDP port
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		Server(unsigned short tcpPort, unsigned short udpPort);

		/**
         * @brief The destructor of the Server class
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		~Server();

		/**
         * @brief The run server function
         * It runs the server
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void runServer();

		/**
         * @brief The stop server function
         * It stops the server
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void createBufferedEntities() const;

		/**
         * @brief The delete buffered entities function
         * It deletes the buffered entities
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void deleteBufferedEntities();

		/**
         * @brief The function that creates a new player
         * @note This function creates a new player inside the game logic
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		[[nodiscard]] int createNewPlayer();

		/**
         * @brief The function that deletes a player
         * @note This function deletes a player inside the game logic
         * @param playerId The id of the player to delete
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
        void deletePlayer(int playerId) const;
		
		/**
         * @brief The function that handles the received DTOs
         * @note This function handles the received DTOs from the network
         * (and applies the changes to the game logic)
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void handleReceivedDTOs() const;

		/**
         * @brief The function that sends the update entities
         * @details This function sends the update entities to the clients
         * about the speed update of the game
         * @note sendDTOToAllClients can be declined for each type of DTO
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void sendDTOToAllClients(GameSpeedDTO *gameSpeedDTO) const;

	private:
		/**
         * @brief The send update entities function
         * It sends the update entities
         * @version v0.1.0
         * @since v0.1.0
         * @author Marius PAIN
         */
		void sendUpdateEntities() const;

		/**
         * @brief The network of the server
         */
		Network::Server *_network;

		/**
         * @brief The game logic of the server
         */
		GameLogic *_gameLogic;

		/**
         * @brief The encoder for the DTOs
         */
		DTOEncoder *_encoder;

		/**
         * @brief The decoder for the DTOs
         */
		DTODecoder *_decoder;

		/**
         * @brief The delta time for the network
         */
		float _deltaTimeNetwork;

		/**
         * @brief The minimum delta time for the network
         */
		float _minDeltaTimeNetwork;

		/**
         * @brief The running state
         * @details True if the server is running, false otherwise
         */
		bool _isRunning;

		/**
         * @brief The TCP port of the server
         */
		unsigned short _tcpPort;

		/**
         * @brief The UDP port of the server
         */
		unsigned short _udpPort;

		/**
         * @brief The network thread
         * @details The thread that runs the network to keep the server open
         */
		std::thread *_networkThread{};

		/**
         * @brief The players
         * @details The list of the players
         */
		std::vector<int> _players;

		/**
         * @brief The game started state
         * @details True if the game has started, false otherwise
         */
		bool _gameStarted;
	};
}

#endif //SERVER_HPP
