/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** FileField.hpp
*/

#ifndef FILEFIELD_HPP
#define FILEFIELD_HPP

#include "../AField.hpp"

/**
 * @class FileField
 * @brief Represents a field that holds a file path.
 * @details This class inherits from AField and is used to store and manage a file path field.
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class FileField : public AField
{
public:
 /**
  * @brief Constructor for FileField.
  * @param name The name of the field.
  * @param description A brief description of the field.
  * @details Initializes the FileField with the given name and description.
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 FileField(std::string name, std::string description);
};

#endif //FILEFIELD_HPP
