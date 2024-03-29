# 
#  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
#  
#  This file is part of the mod.io SDK.
#  
#  Distributed under the MIT License. (See accompanying file LICENSE or 
#   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
# 

add_library(asio INTERFACE)

#note the trailing slash
#install(FILES "${CMAKE_CURRENT_LIST_DIR}/asio/asio/LICENSE_1_0.txt"
#    DESTINATION "licenses/asio/")

target_include_directories(asio INTERFACE ${CMAKE_CURRENT_LIST_DIR}/asio/asio/include)
target_compile_definitions(asio INTERFACE 
    -DASIO_STANDALONE
    -DASIO_HAS_STD_ADDRESSOF
    -DASIO_HAS_STD_ARRAY
    -DASIO_HAS_CSTDINT
    -DASIO_HAS_STD_SHARED_PTR
    -DASIO_HAS_STD_TYPE_TRAITS
    -DASIO_HAS_VARIADIC_TEMPLATES
    -DASIO_HAS_STD_FUNCTION
    -DASIO_HAS_STD_CHRONO
    -DASIO_HAS_MOVE
    -DASIO_NO_DEFAULT_LINKED_LIBS
    -DASIO_DISABLE_IOCP
    -DASIO_NO_DEPRECATED
    -DBOOST_ALL_NO_LIB
)
