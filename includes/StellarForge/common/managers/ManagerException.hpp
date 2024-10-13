/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** ManagerException.hpp
*/

#ifndef MANAGEREXCEPTION_HPP
#define MANAGEREXCEPTION_HPP

#include "common/IError.hpp"

#include <string>

/**
 * @class ManagerException
 * @brief Exception class for Manager errors
 * @details This class is used to throw Manager errors
 * @version 0.1.0
 * @since 0.1.0
 * @author Aubane NOURRY
 */
class ManagerException final : public IError {
public:
 /**
  * @brief Default constructor
  * @details This constructor initializes the ManagerException with a message
  * @param message std::string, the message
  * @version 0.1.0
  * @since 0.1.0
  * @author Aubane NOURRY
  */
 explicit ManagerException(std::string message);

 /**
  * @brief Default destructor
  * @details This destructor clears the ManagerException
  * @version 0.1.0
  * @since 0.1.0
  * @author Aubane NOURRY
  */
 ~ManagerException() override = default;

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

#endif // MANAGEREXCEPTION_HPP
