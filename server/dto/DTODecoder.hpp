/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTODecoder.hpp
*/

#ifndef DTODECODER_HPP
#define DTODECODER_HPP

#include "IDTODecoder.hpp"
#include "DTORegistry.hpp"

class DTODecoder final: public IDTODecoder {
public:
	DTODecoder();
	explicit DTODecoder(DTORegistry *dtoRegistry);
	~DTODecoder() override = default;

	IDTO *decode(std::vector<char> &data) const override;


	[[nodiscard]] DTORegistry &getDTORegistry() const;
	void setDTORegistry(DTORegistry *dtoRegistry);

private:
	DTORegistry *_dtoRegistry;
};

#endif //DTODECODER_HPP
