#pragma once

#ifndef SLOTS_INTERFACE_H
#define SLOTS_INTERFACE_H

class SlotMachineInterface
{
public:
    virtual ~SlotMachineInterface() = default;

   

    virtual void update_balance(const double val) = 0;

};

#endif // !SLOTS_INTERFACE_H
