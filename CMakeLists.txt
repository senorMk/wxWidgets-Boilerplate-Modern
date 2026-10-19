cmake_minimum_required(VERSION 3.24)
project(wxWidgetsBoilerplate VERSION 1.0.0 LANGUAGES CXX)

option(BOILERPLATE_USE_SYSTEM_WX "Use an installed wxWidgets library" OFF)

if(BOILERPLATE_USE_SYSTEM_WX)
    find_package(wxWidgets 3.2 REQUIRED COMPONENTS core base xrc)
    include(${wxWidgets_USE_FILE})
else()
    include(FetchContent)
    set(wxBUILD_SHARED OFF CACHE BOOL "" FORCE)
    set(wxBUILD_SAMPLES OFF CACHE BOOL "" FORCE)
    set(wxBUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(wxBUILD_DEMOS OFF CACHE BOOL "" FORCE)
    set(wxBUILD_PRECOMP OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(wxWidgets
        URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.12/wxWidgets-3.2.12.tar.bz2
        URL_HASH SHA256=a62719bb5e1dcc41c1a6fc1eecd499c7ee8521f70402c7b1bb3342a1e16344e0
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(wxWidgets)
endif()

add_executable(wxwidgets_boilerplate WIN32 MACOSX_BUNDLE
    App.cpp App.h
    AppFrame.cpp AppFrame.h
    AppFrameBase.cpp AppFrameBase.h
    AppFrameBase_bitmaps.cpp
)
target_compile_features(wxwidgets_boilerplate PRIVATE cxx_std_17)
set_target_properties(wxwidgets_boilerplate PROPERTIES
    CXX_EXTENSIONS OFF
    MACOSX_BUNDLE_BUNDLE_NAME "wxWidgets Boilerplate"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.wxwidgets-boilerplate"
    MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
)
if(BOILERPLATE_USE_SYSTEM_WX)
    target_link_libraries(wxwidgets_boilerplate PRIVATE ${wxWidgets_LIBRARIES})
else()
    target_link_libraries(wxwidgets_boilerplate PRIVATE wx::core wx::base wx::xrc)
endif()
if(MSVC)
    target_compile_options(wxwidgets_boilerplate PRIVATE /W4 /permissive-)
else()
    target_compile_options(wxwidgets_boilerplate PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
if(BUILD_TESTING)
    add_test(NAME app_smoke COMMAND wxwidgets_boilerplate --smoke-test)
    set_tests_properties(app_smoke PROPERTIES TIMEOUT 20)
endif()
