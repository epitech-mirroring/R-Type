/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef NETWORKEXCEPTION_HPP
#define NETWORKEXCEPTION_HPP

#include "StellarForge/Common/IError.hpp"
#include <string>

/**
 * @class NetworkException
 * @brief Exception class for network errors
 * @details This class is used to define the network errors
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class NetworkException final : public IError {
public:
 /**
  * @brief Default constructor
  * @details This constructor initializes the NetworkException with a message
  * @param message std::string, the message
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */
 explicit NetworkException(std::string message);

 /**
  * @brief Default destructor
  * @details This destructor clears the NetworkException
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */
 ~NetworkException() override = default;

 /**
  * @brief Get the error message
  * @details This function returns the error message
  * @return const char*, the error message
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */

 [[nodiscard]] const char *what() const noexcept override;

private:
 /**
  * @brief The error message
  */
 std::string _message;
};


#endif //NETWORKEXCEPTION_HPP
