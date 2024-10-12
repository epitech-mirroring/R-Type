/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** APlayerDTO.hpp
*/

#ifndef APLAYERDTO_HPP
#define APLAYERDTO_HPP

#include "../IDTO.hpp"
#include "PlayerActionEnum.hpp"
#include "../../utils/BinaryVector.hpp"

/**
 * @class APlayerDTO
 * @brief Class for Player DTO
 * @inherit IDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class APlayerDTO : public IDTO {
public:
	/**
     * @brief The destructor of the APlayerDTO class
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
	~APlayerDTO() override = default;

	/**
	 * @brief Serialize the DTO to a vector of char (binary)
	 * @return The serialized Player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
    std::vector<char> serialize() final;

	/**
	 * @brief Deserialize the DTO from a vector of char (binary)
	 * @param data The data to deserialize
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	void deserialize(std::vector<char> &data) final;

	/**
	 * @brief Clone the DTO (create a new instance of the DTO)
	 * @return The cloned DTO
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	IDTO *clone() override = 0;

	/**
	 * @brief Set the id of the Player
	 * @param playerId The id of the Player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	void setPlayerId(int playerId);

	/**
	 * @brief Get the id of the Player
	 * @return The id of the Player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	[[nodiscard]] int getPlayerId() const;

protected:
	/**
	 * @brief The constructor of the APlayerDTO class
	 * @param playerId The id of the Player
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	APlayerDTO(int playerId);

	/**
     * @brief Serialize the Player to a vector of char (binary)
     * @return The serialized Player
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    virtual std::vector<char> serializePlayer() = 0;

	/**
     * @brief Deserialize the Player from a vector of char (binary)
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    virtual void deserializePlayer(std::vector<char> &data) = 0;

	/**
     * @brief The id of the Player
     */
    int _p;
};

#endif //APLAYERDTO_HPP
