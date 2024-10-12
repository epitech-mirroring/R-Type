/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerActionStopDTO.hpp
*/

#ifndef PLAYERACTIONSTOPDTO_HPP
#define PLAYERACTIONSTOPDTO_HPP

#include "APlayerDTO.hpp"

/**
 * @class PlayerActionStopDTO
 * @brief Class for Player Action Stop DTO
 * @inherit APlayerDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class PlayerActionStopDTO final: public APlayerDTO {
public:
	/**
	 * @brief The constructor of the PlayerActionStopDTO class
	 * @note This constructor is used for deserialization
	 * (all the attributes are set to default values)
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerActionStopDTO();

	/**
	 * @brief The constructor of the PlayerActionStopDTO class
	 * @param playerID The id of the entity
	 * @param action The action of the player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerActionStopDTO(int playerID, PlayerAction action);

	/**
     * @brief The destructor of the PlayerActionStopDTO class
     * @version v0.1.0
     * @since v0.1.0
	 * @author Aubane NOURRY
     */
	~PlayerActionStopDTO() override = default;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
	IDTO *clone() override;

	/**
     * @brief Serialize the DTO to a vector of char (binary)
     * @return The serialized entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    std::vector<char> serializePlayer() override;

	/**
     * @brief Deserialize the DTO from a vector of char (binary)
     * @note It will fill the attributes of the DTO with the data
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
	void deserializePlayer(std::vector<char>& data) override;

     /**
     * @brief Set the action of the player
     * @param action The action of the player
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
     void setAction(PlayerAction action);

     /**
      * @brief Get the action of the player
      * @return The action of the player
      * @version v0.1.0
      * @since v0.1.0
      * @author Aubane NOURRY
      */
     [[nodiscard]] PlayerAction getAction() const;

private:
     PlayerAction _action; /*!< The action of the player */
};

#endif //PLAYERACTIONSTOPDTO_HPP
