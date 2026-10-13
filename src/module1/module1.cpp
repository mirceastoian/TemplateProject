#include <module1/summary.hpp>

#include "module1_detail.hpp"

#include <string>

namespace module1 {

std::string MakeSummary()
{
    return detail::MakeMessage("module1");
}

} // namespace module1
