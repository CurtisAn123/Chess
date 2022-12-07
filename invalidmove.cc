#include "invalidmove.h"

InvalidMove::InvalidMove(std::string msg): msg{msg} {}

std::string InvalidMove::getMsg() { return msg; }
