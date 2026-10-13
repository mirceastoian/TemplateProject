#include <module2/application.hpp>

#include <module1/summary.hpp>

#include "application_detail.hpp"

namespace module2 {

void Run()
{
    detail::PrintMessage(module1::MakeSummary());
}

} // namespace module2
