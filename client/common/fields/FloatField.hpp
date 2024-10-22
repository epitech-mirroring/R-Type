/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef FLOATFIELD_HPP
#define FLOATFIELD_HPP
#include "AField.hpp"

#include <functional>


class FloatField final : public AField {
protected:
    std::function<void(float)> _setCallback;
    std::function<float()> _getCallback;

public:
    /**
     * @brief Constructor for FloatField.
     * @param name The name of the field.
     * @param description A brief description of the field.
     * @param setCallback The callback function to set the value of the field.
     * @param getCallback The callback function to get the value of the field.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the FloatField with the given name and description.
     */
    FloatField(const std::string &name, const std::string &description,
               const std::function<void(float)> &setCallback = nullptr,
               const std::function<float()> &getCallback = nullptr);

    void updateValue(std::any value) override;

    [[nodiscard]] std::any getValue() const override;
};

#endif //FLOATFIELD_HPP
