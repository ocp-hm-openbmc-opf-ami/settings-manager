/*
// Copyright (c) 2019-2022 Intel Corporation
//
// This software and the related documents are Intel copyrighted
// materials, and your use of them is governed by the express license
// under which they were provided to you ("License"). Unless the
// License provides otherwise, you may not use, modify, copy, publish,
// distribute, disclose or transmit this software or the related
// documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no
// express or implied warranties, other than those that are expressly
// stated in the License.
*/

#include "interface.hpp"
#include "defaults.hpp"

int main()
{
    boost::asio::io_context io;
    auto systemBus = std::make_shared<sdbusplus::asio::connection>(io);
    systemBus->request_name("xyz.openbmc_project.Settings");

    sdbusplus::asio::object_server objServer(systemBus);

    std::vector<SettingsInterface> settings;
    loadSettings(objServer, settings);
    io.run();

    return 0;
}
