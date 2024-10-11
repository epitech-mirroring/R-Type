/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOEncoder.hpp
*/

#ifndef DTOENCODER_HPP
#define DTOENCODER_HPP

#include "IDTOEncoder.hpp"
#include "DTORegistry.hpp"

class DTOEncoder final : public IDTOEncoder {
public:
	DTOEncoder();
	explicit DTOEncoder(DTORegistry *dtoRegistry);
	~DTOEncoder() override = default;

	[[nodiscard]] std::vector<char> encode(IDTO &dto) const override;

	[[nodiscard]] DTORegistry &getDTORegistry() const;
	void setDTORegistry(DTORegistry *dtoRegistry);

private:
	DTORegistry *_dtoRegistry;

};

#endif //DTOENCODER_HPP
