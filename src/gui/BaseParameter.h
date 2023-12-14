#ifndef SRC_GUI_BASEPARAMETER_H
#define SRC_GUI_BASEPARAMETER_H

#include <memory>

class BaseParameter {
public:
    typedef std::unique_ptr<BaseParameter> Ptr;
};

#endif // SRC_GUI_BASEPARAMETER_H
