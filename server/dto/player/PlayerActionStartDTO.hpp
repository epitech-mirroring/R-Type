/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerActionStartDTO.hpp
*/

#ifndef PLAYERACTIONSTARTDTO_HPP
#define PLAYERACTIONSTARTDTO_HPP

#include "APlayerDTO.hpp"

/**
 * @class PlayerActionStartDTO
 * @brief Class for Player Action Start DTO
 * @inherit APlayerDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class PlayerActionStartDTO final: public APlayerDTO {
public:
	/**
	 * @brief The constructor of the PlayerActionStartDTO class
	 * @note This constructor is used for deserialization
	 * (all the attributes are set to default values)
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerActionStartDTO();

	/**
	 * @brief The constructor of the PlayerActionStartDTO class
	 * @param playerID The id of the entity
	 * @param action The action of the player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	PlayerActionStartDTO(int playerID, PlayerAction action);

	/**
     * @brief The destructor of the PlayerActionStartDTO class
     * @version v0.1.0
     * @since v0.1.0
	 * @author Aubane NOURRY
     */
	~PlayerActionStartDTO() override = default;

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

#endif //PLAYERACTIONSTARTDTO_HPP
