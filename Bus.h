//
// Created by raffael on 11/30/19.
//

#ifndef NES_BUS_H
#define NES_BUS_H


#include <array>
#include "CPU6502.h"
#include <cstdint>
    class Bus {
    public:
        Bus();

        ~Bus();

        CPU6502 cpu;
        std::array<uint8_t, 64 * 1024> ram;
        void write(uint16_t addr, uint8_t data);
        uint8_t read(uint16_t addr, bool readOnly = false);

    };


#endif //ES_BUS_H
