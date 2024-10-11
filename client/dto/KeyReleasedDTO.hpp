/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** KeyReleasedDTO.hpp
*/

#ifndef KEYRELEASEDDTO_HPP
#define KEYRELEASEDDTO_HPP

#include "APlayerDTO.hpp"

/**
 * @class KeyReleasedDTO
 * @brief Class for Key Released DTO
 * @inherit APlayerDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class KeyReleasedDTO final: public APlayerDTO {
public:
	/**
	 * @brief The constructor of the KeyReleasedDTO class
	 * @note This constructor is used for deserialization
	 * (all the attributes are set to default values)
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	KeyReleasedDTO();

	/**
	 * @brief The constructor of the KeyReleasedDTO class
	 * @param playerID The id of the entity
	 * @param key The type of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Aubane NOURRY
	 */
	KeyReleasedDTO(int playerID, std::string key);

	/**
     * @brief The destructor of the KeyReleasedDTO class
     * @version v0.1.0
     * @since v0.1.0
	 * @author Aubane NOURRY
     */
	~KeyReleasedDTO() override = default;

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
     * @brief Set the key of the entity
     * @param key The key of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
     void setKey(std::string key);

     /**
      * @brief Get the key of the entity
      * @return The key of the entity
      * @version v0.1.0
      * @since v0.1.0
      * @author Aubane NOURRY
      */
     [[nodiscard]] std::string getKey() const;

private:
     /**
     * @brief The key of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
     std::string _key;
};

#endif //KEYRELEASEDDTO_HPP
