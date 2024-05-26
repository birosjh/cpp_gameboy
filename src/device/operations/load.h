#include <string>
#include <cstdint>

// Load Operation Functions

namespace LD {
    uint16_t single(std::string in_register);
    uint16_t single_from_register(std::string in_register, std::string load_register);
    uint16_t single_from_address(std::string in_register, std::string address_register);
    uint16_t single_from_address(std::string address_register, std::string symbol, std::string load_register);
    uint16_t single_to_address(std::string address_register, std::string load_register);
    uint16_t single_to_address(std::string address_register, std::string symbol, std::string load_register);
    uint16_t single_to_address(std::string address_register);

    uint16_t pair(std::string double_register);
    uint16_t pair_to_next(std::string double_register);
}

        