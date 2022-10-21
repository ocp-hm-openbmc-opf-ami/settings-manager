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

#pragma once

#include <vector>

template <typename T> struct is_vector : std::false_type
{
};

template <typename T> struct is_vector<std::vector<T>> : std::true_type
{
};

template <typename T> constexpr bool is_vector_v = is_vector<T>::value;
