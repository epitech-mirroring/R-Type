/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** UUID
*/

#ifndef UUID_HPP
#define UUID_HPP

#include <array>
#include <iostream>
#include <random>

/**
 * @brief UUID class
 * @details This class is used to generate and manage UUIDs
 * @note This class is a wrapper around the stduuid library
 * @version 0.1.0
 * @since 0.1.0
 * @author Marius PAIN
 */
class UUID {
public:
 /**
  * @brief Default constructor
  * @details This constructor initializes the UUID with a nil UUID
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 UUID();

 /**
  * @brief Copy constructor
  * @details This constructor initializes the UUID with the UUID from the given UUID
  * @param uuid UUID, the UUID to copy
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 UUID(const UUID &uuid) = default;

 /**
  * @brief Move constructor
  * @details This constructor initializes the UUID with the UUID from the given UUID
  * @param uuid UUID, the UUID to move
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 UUID(UUID &&uuid) noexcept;

 /**
  * @brief Default destructor
  * @details This destructor clears the UUID
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 ~UUID() = default;

 /**
  * @brief Get the UUID as a string
  * @details This function returns the UUID as a string
  * @return std::string, the UUID as a string
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getUuidString() const;

 /**
  * @brief Generate a UUID
  * @details This function generates a UUID
  * @throw UUIDException if an error occurs (UUID generation failed, etc.)
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 void generateUuid();

 /**
  * @brief Copy a UUID
  * @details This function copies the UUID from the given UUID
  * @param uuid UUID, the UUID to copy
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 void copyUuid(const UUID &uuid);

 /**
  * @brief Compare a UUID
  * @details This function compares the UUID with the given UUID
  * @param uuid UUID, the UUID to compare
  * @return bool, true if the UUIDs are equal, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] bool compareUuid(const UUID &uuid) const;

 /**
  * @brief Check if the UUID is a nil UUID
  * @details This function checks if the UUID is a nil UUID
  * @return bool, true if the UUID is a nil UUID, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] bool isNullUuid() const;

 /**
  * @brief Set the UUID from a string
  * @details This function sets the UUID from the given string
  * @param uuid std::string, the UUID as a string
  * @throw UUIDException if an error occurs(Invalid string format, etc.)
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 void setUuidFromString(const std::string &uuid);

 /**
  * @brief Assignment operator
  * @details This operator assigns the UUID from the given UUID
  * @param uuid UUID, the UUID to assign
  * @return UUID&, the assigned UUID
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 UUID &operator=(const UUID &uuid);

 /**
  * @brief Equality operator
  * @details This operator checks if the UUIDs are equal
  * @param uuid UUID, the UUID to compare
  * @return bool, true if the UUIDs are equal, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 UUID &operator=(UUID &&uuid) noexcept;

 /**
  * @brief Equality operator
  * @details This operator checks if the UUIDs are equal
  * @param uuid UUID, the UUID to compare
  * @return bool, true if the UUIDs are equal, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 bool operator==(const UUID &uuid) const;

 /**
  * @brief Inequality operator
  * @details This operator checks if the UUIDs are not equal
  * @param uuid UUID, the UUID to compare
  * @return bool, true if the UUIDs are not equal, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 bool operator!=(const UUID &uuid) const;

 /**
  * @brief Less than operator
  * @details This operator checks if the UUID is less than the given UUID
  * @param uuid UUID, the UUID to compare
  * @return bool, true if the UUID is less than the given UUID, false otherwise
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 bool operator<(const UUID &uuid) const;

 /**
  * @brief Output stream operator
  * @details This operator outputs the UUID to the given output stream
  * @param ostream std::ostream&, the output stream
  * @param uuid UUID, the UUID to output
  * @return std::ostream&, the output stream
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 friend std::ostream &operator<<(std::ostream &ostream, const UUID &uuid);

private:
 /**
  * @brief UUID
  * @details This variable holds the UUID
  * @version 0.1.0
  * @since 0.1.0
  * @author Marius PAIN
  */
 std::array<char, 36> _uuid{};
};

template <>
struct std::hash<UUID> {
 std::size_t operator()(const UUID &uuid) const noexcept {
  // Use the built-in hash function of uuids::uuid or hash based on its string representation
  return std::hash<std::string>{}(uuid.getUuidString());
 }
};

#endif // UUID_HPP
