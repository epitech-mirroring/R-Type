/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOException.hpp
*/

#ifndef DTOEXCEPTION_HPP
#define DTOEXCEPTION_HPP

#include "StellarForge/common/IError.hpp"
#include <string>

/**
 * @class DTOException
 * @brief Class for DTO exceptions
 * @inherit IError
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class DTOException final : public IError {
public:
	/**
     * @brief The constructor of the DTOException class
     * @param message The message of the exception
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    explicit DTOException(std::string message);

	/**
     * @brief The destructor of the DTOException class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~DTOException() override = default;

	/**
     * @brief Get the message of the exception
     * @return The message of the exception
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] const char *what() const noexcept override;

private:
	/**
     * @brief The message of the exception
     */
    std::string _message;
};

#endif //DTOEXCEPTION_HPP
