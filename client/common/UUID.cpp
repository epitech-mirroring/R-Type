/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** Uuid
*/

#include "UUID.hpp"
#include "UUIDException.hpp"

UUID::UUID() {
    this->_uuid.fill('0');
    this->_uuid.at(8) = '-';
    this->_uuid.at(13) = '-';
    this->_uuid.at(18) = '-';
    this->_uuid.at(23) = '-';
}

UUID::UUID(UUID &&uuid) noexcept : _uuid(uuid._uuid) {
    uuid._uuid.fill('0');
    uuid._uuid.at(8) = '-';
    uuid._uuid.at(13) = '-';
    uuid._uuid.at(18) = '-';
    uuid._uuid.at(23) = '-';
}

std::string UUID::getUuidString() const {
    std::string uuidString;
    for (const auto &character: this->_uuid) {
        uuidString += character;
    }
    return uuidString;
}

void UUID::generateUuid() {
    try {
        std::random_device randD;
        std::mt19937 gen(randD());
        unsigned int currentGen = 0;
        char currentChar = 0;

        for (auto &elem: this->_uuid) {
            currentGen = (static_cast<unsigned int>(gen())) % 16;
            if (currentGen < 10) {
                currentChar = static_cast<char>(48 + currentGen);
            } else {
                currentChar = static_cast<char>(97 + (currentGen - 10));
            }
            elem = currentChar;
        }
        this->_uuid.at(8) = '-';
        this->_uuid.at(13) = '-';
        this->_uuid.at(18) = '-';
        this->_uuid.at(23) = '-';
    } catch (const std::exception &e) {
        throw UUIDException(
            "Error while generating UUID : " + std::string(e.what()));
    }
}

void UUID::copyUuid(const UUID &uuid) {
    this->_uuid = uuid._uuid;
}

bool UUID::compareUuid(const UUID &uuid) const {
    return this->_uuid == uuid._uuid;
}

bool UUID::isNullUuid() const {
    return this->getUuidString() == "00000000-0000-0000-0000-000000000000";
}

void UUID::setUuidFromString(const std::string &uuid) {
    if (uuid.size() != 36) {
        throw UUIDException("Invalid UUID format");
    }
    for (size_t i = 0; i < uuid.size(); i++) {
        switch (i) {
        case 8:
        case 13:
        case 18:
        case 23:
            if (uuid.at(i) != '-') {
                throw UUIDException("Invalid UUID format");
            }
            this->_uuid.at(i) = '-';
            break;
        default:
            if ((uuid.at(i) < '0' || uuid.at(i) > '9') &&
                (uuid.at(i) < 'a' || uuid.at(i) > 'f')) {
                throw UUIDException("Invalid UUID format");
            }
            this->_uuid.at(i) = uuid.at(i);
        }
    }
}

UUID &UUID::operator=(const UUID &uuid) {
    if (this == &uuid) {
        return *this;
    }
    this->_uuid = uuid._uuid;
    return *this;
}

bool UUID::operator==(const UUID &uuid) const {
    return this->_uuid == uuid._uuid;
}

bool UUID::operator!=(const UUID &uuid) const {
    return this->_uuid != uuid._uuid;
}

bool UUID::operator<(const UUID &uuid) const {
    for (size_t i = 0; i < this->_uuid.size(); i++) {
        if (this->_uuid.at(i) < uuid._uuid.at(i)) {
            return true;
        }
        if (this->_uuid.at(i) > uuid._uuid.at(i)) {
            return false;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &ostream, const UUID &uuid) {
    ostream << uuid.getUuidString();
    return ostream;
}

UUID &UUID::operator=(UUID &&uuid) noexcept {
    if (this != &uuid) {
        this->_uuid = uuid._uuid;
        uuid._uuid.fill('0');
        uuid._uuid.at(8) = '-';
        uuid._uuid.at(13) = '-';
        uuid._uuid.at(18) = '-';
        uuid._uuid.at(23) = '-';
    }
    return *this;
}
