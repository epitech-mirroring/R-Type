/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** GraphicsException
*/

#ifndef GRAPHICSEXCEPTION_HPP
#define GRAPHICSEXCEPTION_HPP

#include "common/IError.hpp"
#include <string>

/**
 * @class GraphicsException
 * @brief Exception class for Graphics errors
 * @details This class is used to throw Graphics errors
 * @version 0.1.0
 * @since 0.1.0
 * @author Aubane NOURRY
 */
class GraphicsException final : public IError {
public:
 /**
  * @brief Default constructor
  * @details This constructor initializes the GraphicsException with a message
  * @param message std::string, the message
  * @version 0.1.0
  * @since 0.1.0
  * @author Aubane NOURRY
  */
 explicit GraphicsException(std::string message);

 /**
     * @brief Default constructor
     * @details This constructor initializes the GraphicsException with a message
     * @param message const char*, the message
     * @version 0.1.0
     * @since 0.1.0
     * @author Aubane NOURRY
     */
    explicit GraphicsException(const char* message);

    /**
  * @brief Default destructor
  * @details This destructor clears the GraphicsException
  * @version 0.1.0
  * @since 0.1.0
  * @author Aubane NOURRY
  */
 ~GraphicsException() override = default;

 /**
  * @brief Get the error message
  * @details This function returns the error message
  * @return const char*, the error message
  * @version 0.1.0
  * @since 0.1.0
  * @author Aubane NOURRY
  */
 [[nodiscard]] const char *what() const noexcept override;

private:
 /**
  * @brief The error message
  */
 std::string _message;
};

#endif // GRAPHICSEXCEPTION_HPP
