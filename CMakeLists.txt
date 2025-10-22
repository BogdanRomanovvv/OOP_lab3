cmake_minimum_required(VERSION 3.14)
project(OOP_Lab3 VERSION 1.0.0 LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Настройка путей
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

# Включение директорий с заголовочными файлами
include_directories(${INCLUDE_DIR})

# Список исходных файлов библиотеки
set(LIB_SOURCES
    ${SRC_DIR}/Triangle.cpp
    ${SRC_DIR}/Square.cpp
    ${SRC_DIR}/Octagon.cpp
    ${SRC_DIR}/FigureArray.cpp
)

# Создание статической библиотеки
add_library(figures_lib STATIC ${LIB_SOURCES})

# Основная программа
add_executable(lab3_main ${SRC_DIR}/main.cpp)
target_link_libraries(lab3_main figures_lib)

# Опции для тестов
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    # Подключение Google Test
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    
    # Для Windows: предотвращение перезаписи параметров компилятора родительского проекта
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    
    FetchContent_MakeAvailable(googletest)
    
    # Включение тестирования
    enable_testing()
    
    # Список тестовых файлов
    set(TEST_SOURCES
        ${TEST_DIR}/test_triangle.cpp
        ${TEST_DIR}/test_square.cpp
        ${TEST_DIR}/test_octagon.cpp
        ${TEST_DIR}/test_array.cpp
    )
    
    # Создание исполняемого файла для тестов
    add_executable(lab3_tests ${TEST_SOURCES})
    
    # Линковка с библиотекой и Google Test
    target_link_libraries(lab3_tests 
        figures_lib
        GTest::gtest_main
    )
    
    # Добавление тестов в CTest
    include(GoogleTest)
    gtest_discover_tests(lab3_tests)
    
    # Вывод сообщения
    message(STATUS "Tests enabled. Use 'ctest' to run tests.")
endif()

# Установка флагов компиляции для разных компиляторов
if(MSVC)
    target_compile_options(figures_lib PRIVATE /W4)
else()
    target_compile_options(figures_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()
