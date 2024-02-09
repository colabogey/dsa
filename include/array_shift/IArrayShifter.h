#pragma once

class IArrayShifter {
  public:
    virtual~IArrayShifter() = default;
    virtual void ShiftRight() = 0;
    virtual void ShiftLeft() = 0;
};

