/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameSpeedDTO.hpp
*/

#ifndef GAMESPEEDDTO_HPP
#define GAMESPEEDDTO_HPP

#include "GameSpeedEnum.hpp"
#include "../IDTO.hpp"

/**
 * @class GameSpeedDTO
 * @brief Class for Game Speed DTO
 * @inherit IDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class GameSpeedDTO : public IDTO {
public:
	/**
     * @brief The constructor of the GameSpeedDTO class
     * @note This constructor is used for deserialization
     * (all the attributes are set to default values)
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	GameSpeedDTO();

	/**
     * @brief The constructor of the GameSpeedDTO class
     * @note This constructor is used for serialization
     * (all the attributes are set to the given values)
     * @param speed The speed of the game
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	GameSpeedDTO(GameSpeedEnum speed);

	/**
     * @brief The destructor of the GameSpeedDTO class
     * @note This destructor is default
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~GameSpeedDTO() override = default;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    IDTO *clone() override;

	/**
     * @brief Serialize the DTO to a vector of char (binary)
     * @return The serialized entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    std::vector<char> serialize() override;

	/**
     * @brief Deserialize the DTO from a vector of char (binary)
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void deserialize(std::vector<char> &data) override;

	/**
     * @brief Get the speed of the game
     * @return The speed of the game
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] GameSpeedEnum getSpeed() const;

	/**
     * @brief Set the speed of the game
     * @param speed The speed of the game
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setSpeed(GameSpeedEnum speed);

private:
	/**
     * @brief The speed of the game
     */
	GameSpeedEnum speed;

};



#endif //GAMESPEEDDTO_HPP
