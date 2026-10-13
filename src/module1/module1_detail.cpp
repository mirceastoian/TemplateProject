#include "module1_detail.hpp"

namespace module1::detail {

std::string MakeMessage(const std::string& module_name)
{
    return "Hello from " + module_name;
}

} // namespace module1::detail
